from ftplib import FTP
import os
from datetime import datetime, timedelta

import socket


def is_internet_on():
    try:
        # Attempt to connect to Google's DNS server (8.8.8.8) on port 53
        socket.create_connection(("8.8.8.8", 53), timeout=3)
        return True
    except OSError:
        pass
    return False





# Function to get the remote timestamp with an applied time offset
def get_remote_timestamp_with_offset(ftp, remote_filename, time_offset_seconds):
    remote_timestamp_str = ftp.voidcmd("MDTM " + remote_filename)[4:].strip()
    remote_timestamp = datetime.strptime(remote_timestamp_str, "%Y%m%d%H%M%S")
    remote_timestamp_corrected = remote_timestamp + \
        timedelta(seconds=time_offset_seconds)
    return remote_timestamp_corrected


def download_file(ftp, remote_filename, local_file_path):
    with open(local_file_path, 'wb') as local_file:
        ftp.retrbinary('RETR ' + remote_filename, local_file.write)


# Check pi connection
# Check if the internet is on
if is_internet_on():
    print("Pi connected to internet")
   
    
else:
    print("Pi disconnected from internet")
    with open("/home/michael/FOTA/Flag.txt", "w") as file:
        file.write("0")
        exit()


# Raspberry Pi-specific file path
absolute_path = '/home/michael/FOTA'  # Replace with your actual directory path
relative_path = "Updatefile"
full_path = os.path.join(absolute_path, relative_path)

server = 'abuelkheir.freevar.com'
username = 'abuelkheir.freevar.com'
password = '123456'

ftp = FTP(server)
ftp.login(user=username, passwd=password)
ftp.cwd('embedded')

remote_filename = 'encrypted_weird.enc'
local_directory = full_path
local_file_path = os.path.join(local_directory, remote_filename)

if os.path.exists(local_file_path):
    local_timestamp = os.path.getmtime(local_file_path)
    with open("/home/michael/FOTA/Flag.txt", "w") as file:
        file.write("1")
else:
    local_timestamp = 0

local_timestamp = datetime.fromtimestamp(local_timestamp)

# Calculate the time offset (in seconds) between your Raspberry Pi's time zone and the server's time zone
time_offset_seconds = 2 * 3600  # -2 hours, adjust as needed

# Get the remote timestamp with the time offset applied
remote_timestamp = get_remote_timestamp_with_offset(
    ftp, remote_filename, time_offset_seconds)

print("Remote Timestamp:", remote_timestamp)
print("Local Timestamp:", local_timestamp)

if remote_timestamp >= local_timestamp:
    print("An update is available. Downloading the file.")
    download_file(ftp, remote_filename, local_file_path)
    print("File downloaded successfully.")
    with open("/home/michael/FOTA/Flag.txt", "w") as file:
        file.write("1")
else:
    print("No update available. Local file is up to date.")
    with open("/home/michael/FOTA/Flag.txt", "w") as file:
        file.write("0")

ftp.quit()
