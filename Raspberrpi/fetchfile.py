from ftplib import FTP
import os

# Define FTP server details
server = 'abuelkheir.freevar.com'
username = 'abuelkheir.freevar.com'
password = '123456'  # Replace with your FTP password

# Login to the FTP server
ftp = FTP(server)
ftp.login(user=username, passwd=password)

# Change to the directory where the file is located
ftp.cwd('embedded')

# Define file paths
absolute_path = os.path.dirname(__file__)
relative_path = "Updatefile"
full_path = os.path.join(absolute_path, relative_path)

# Define the remote and local file paths
remote_filename = 'weird.hex'
local_file_path = os.path.join(full_path, remote_filename)  # The local file path

# Create the local directory if it doesn't exist
os.makedirs(full_path, exist_ok=True)

# Download the file
with open(local_file_path, 'wb') as local_file:
    ftp.retrbinary('RETR ' + remote_filename, local_file.write)

# Close the FTP connection
ftp.quit()
