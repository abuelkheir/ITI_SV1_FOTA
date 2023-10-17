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

# Define the remote and local file paths
remote_filename = 'weird.hex'
local_path = '/home/ahmed/HexFile/' + remote_filename  # Adjust the local path for Raspberry Pi

# Download the file
with open(local_path, 'wb') as local_file:
    ftp.retrbinary('RETR ' + remote_filename, local_file.write)

# Close the FTP connection
ftp.quit()
