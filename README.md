[![Travis CI](https://api.travis-ci.org/openscad/openscad.png)](https://travis-ci.org/openscad/openscad)
[![Coverity Status](https://scan.coverity.com/projects/2510/badge.svg)](https://scan.coverity.com/projects/2510)
[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/openscad/openscad/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

# What is OpenSCAD Server?
[![Flattr this git repo](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=openscad&url=http://openscad.org&title=OpenSCAD&language=&tags=github&category=software)

OpenSCAD Server is a fork that splits off the OpenSCAD parser from the GUI and
provides a simple socket interface instead. As it is not currently clear to me what
the state of the OpenSCAD multicore support is considerable room exists for 
performance improvesments. Also note that this is not a mature well tested stack 
and that a lot of the mess left over from pulling out the X11 and QT code is still 
left floating around in various directories. The socket code needs to be tightened
up and tested. 

# Getting started

Hand rolled makefile. Don't ./configure just make. 

YOU WILL NEED TO MANUALLY MAKE AN OBJECTS DIR for this to build. 

THIS IS NOT CURRENTLY CONFIGURED TO BUILD FOR WINDOWS. 

