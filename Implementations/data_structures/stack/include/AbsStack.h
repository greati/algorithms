/*!
 <PRE>
 SOURCE FILE : AbsStack.h
 DESCRIPTION.: Stack abstract class interface - no implementation.
 AUTHOR......: Selan R. dos Santos
 LOCATION....: DIMAp/UFRN.
 SATARTED ON.: August/2005
 CHANGES.....: None.

 TO COMPILE..: Not to be compiled.
 OBS.........: Part of the LP1 Project.

 LAST UPDATE.: March 8th, 2007.
 LAST UPDATE.: April tth, 2015.
 </pre>
*/

#ifndef ABSSTACK_H_
#define ABSSTACK_H_


// ******************PUBLIC OPERATIONS*********************
// void push( x )         --> Insert x
// Object pop( )          --> Remove and return most recently inserted item
// Object top( )          --> Return most recently inserted item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************
// std::underflow_error thrown if needed.

template <class Object>
class AbsStack
{
  public:
  AbsStack( ) { }            // Default constructor
  virtual ~AbsStack() { }   // Default destructor

  // Basic members
  virtual void push( const Object & x ) = 0;
  virtual const Object & pop( ) = 0;
  virtual const Object & top( ) const = 0;

  virtual bool empty( ) const = 0;
  virtual void clear( ) = 0;

  private:
  // Disable copy constructor
  AbsStack( const AbsStack & ){ /* empty */}
};


#endif

/* --------------------- [ End of the AbsStack.h header ] ------------------- */
/* ========================================================================= */
