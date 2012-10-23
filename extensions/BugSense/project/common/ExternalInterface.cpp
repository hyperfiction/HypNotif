

#ifndef IPHONE
#define IMPLEMENT_API
#endif

#include <hx/CFFI.h>
#include <stdio.h>
#include "BugSense.h"

using namespace hyperfiction;
extern "C"{
	
	int BugSense_register_prims(){
		printf("BugSenseExtension: register_prims()\n");
		return 0;
	}
}
#ifdef IPHONE

	static value BugSense_run_bugtracker( value sCode ){
		run_bug_tracker( val_string( sCode ) );
		return alloc_null( );
	}
	DEFINE_PRIM( BugSense_run_bugtracker , 1 );

#endif
