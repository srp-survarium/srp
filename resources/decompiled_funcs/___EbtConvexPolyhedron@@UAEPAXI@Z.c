btConvexPolyhedron *__thiscall btConvexPolyhedron::`vector deleting destructor'(btConvexPolyhedron *this, char a2)
{
  btConvexPolyhedron::~btConvexPolyhedron(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
