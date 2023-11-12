#!/bin/bash

echo '5s'
env sleep 5


python3 /home/michael/FOTA/fetchupdatedonl.py
/usr/bin/python3 /home/michael/FOTA/fetchupdatedonl.py > /home/michael/FetchUpdatelog.log 2>&1


python3 /home/michael/FOTA/SendUpdate.py
/usr/bin/python3 /home/michael/FOTA/SendUpdate.py > /home/michael/SendUpdatelog.log 2>&1