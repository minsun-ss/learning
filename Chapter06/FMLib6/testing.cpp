#include "testing.h"
#include "stdafx.h"
using namespace std;

/*  Whether debug messages are enabled */
static bool debugEnabled = true;
 
bool isDebugEnabled() {
    return debugEnabled;
}
 
void setDebugEnabled( bool enable ) {
    debugEnabled = enable;
}
