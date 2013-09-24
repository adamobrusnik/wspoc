#!/bin/bash
echo "------------------------\nRunning wsdl2h\n------------------------"
wsdl2h test.wsdl

echo "------------------------\nRunning soapcpp2\n------------------------"
soapcpp2 -i -I/usr/share/gsoap/import test.h
