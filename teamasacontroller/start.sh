#!/bin/bash

echo "=========================="
echo "Starting App teamasacontroller for {APP_NAME_PRETTY}"


systemctl start teamasacontroller
systemctl start rosnodeChecker
