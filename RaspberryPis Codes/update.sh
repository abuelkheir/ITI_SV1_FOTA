#!/bin/bash

echo '5s'
env sleep 5



script -c '/usr/bin/python3 /home/michael/FOTA/fetchupdatedonl.py' -a /home/michael/FetchUpdatelog.log

script -c '/usr/bin/python3 /home/michael/FOTA/decrypt.py' -a /home/michael/decrypt.log

script -c '/usr/bin/python3 /home/michael/FOTA/SendUpdate.py' -a /home/michael/SendUpdatelog.log

