[![Travis CI](https://api.travis-ci.org/openscad/openscad.png)](https://travis-ci.org/openscad/openscad)
[![Coverity Status](https://scan.coverity.com/projects/2510/badge.svg)](https://scan.coverity.com/projects/2510)
[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/openscad/openscad/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

# What is OpenSCAD Server?
[![Flattr this git repo](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=openscad&url=http://openscad.org&title=OpenSCAD&language=&tags=github&category=software)

OpenSCAD Server is a fork that splits off the OpenSCAD parser from the GUI and
provides a simple socket interface instead. 

I've been doing quite a bit of work on clustering the OpenSCAD server and I feel it works best this way. 

The current outstanding issue is that while the socket code ( based on boost ) supports multiple 
connections and seems very solid sadly all the rest of the OpenSCAD code are only partially in classes 
if at all and none of it is thread safe. This means quite a bit of work returning error messages to 
a connecting client if you want to run a single instance that handles many connections. 

I've had this running for some months now on a test server and it is actually quite stable. 
Work needs to be done on logging and error messages. This means a significant rewrite to move
the OpenSCAD in to a proper class based structure. 

# Getting started

At the moment the conHand rolled makefile. Don't ./configure just make. 

YOU WILL NEED TO MANUALLY MAKE AN OBJECTS DIR for this to build. 

THIS IS NOT CURRENTLY CONFIGURED TO BUILD FOR WINDOWS. 

