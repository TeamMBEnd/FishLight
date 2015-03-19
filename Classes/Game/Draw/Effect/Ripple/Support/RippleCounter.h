#ifndef RIPPLECOUNTER_H
#define RIPPLECOUNTER_H

class RippleCounter{

public:
	static void init(){ 
		g_RippleCount = 0; 
	};

	static void add(){ 
		if (g_RippleCount <= 8){
			++g_RippleCount;
		}
	};

	static int g_RippleCount;
};

#endif