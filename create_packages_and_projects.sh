export LC_MESSAGES=$LANG
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
echo %%%% floribot_wiimote
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd floribot_wiimote
mkdir include
cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION=3.7
cd ..
export LC_MESSAGES=$LANG
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
echo %%%% floribot_navigation
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd floribot_navigation
mkdir include
cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION=3.7
cd ..
export LC_MESSAGES=$LANG
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
echo %%%% floribot_base
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd floribot_base
mkdir include
cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION=3.7
cd ..
export LC_MESSAGES=$LANG
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
echo %%%% floribot_robot
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd floribot_robot
mkdir include
cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION=3.7
cd ..
export LC_MESSAGES=$LANG
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
echo %%%% floribot_stage
echo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cd floribot_stage
mkdir include
cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_ECLIPSE_VERSION=3.7
cd ..
