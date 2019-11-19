EDP(Primera Parte).png : EDP.dat EDP.py
	python EDP.py
	
EDP.dat : EDP.x
	./EDP.x 0 >> EDP.dat

EDP.x : EDP.cpp
	c++ EDP.cpp -o EDP.x