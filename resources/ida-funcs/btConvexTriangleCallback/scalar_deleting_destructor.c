btConvexTriangleCallback *__thiscall btConvexTriangleCallback::`scalar deleting destructor'(
        btConvexTriangleCallback *this,
        char a2)
{
  btConvexTriangleCallback::~btConvexTriangleCallback(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
