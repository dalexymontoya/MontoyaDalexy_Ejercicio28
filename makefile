lacosamasdificildelmundo.png : grafica.py datos.dat 
	python grafica.py

datos.dat : a.out 
	./a.out > datos.dat
	
a.out : proyectil.cpp
	c++ ESTE.cpp

