/**@addtogroup Debugging
   @brief Functions used for debugging.
   @date 2008-2020
   @copyright Oleander Software, Ltd.
   @author Blake Madden
   @details This program is free software; you can redistribute it and/or modify
    it under the terms of the BSD License.
* @{*/

#ifndef __DEBUG_LOGIC_H__
#define __DEBUG_LOGIC_H__

/**
\def NON_UNIT_TEST_ASSERT(expression)
    If unit test symbol (`__UNITTEST`) is defined, then does nothing; otherwise asserts.
    This is useful for suppressing asserts when unit testing, but enabling them in regular debug builds.
* @} */

//----------------------------------------------------------------------
#ifdef __UNITTEST
    #define NON_UNIT_TEST_ASSERT(x) ((void)0)
#else
    #define NON_UNIT_TEST_ASSERT(x) assert(x)
#endif

#endif //__DEBUG_LOGIC_H__
