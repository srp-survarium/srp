btSoftBodyTriangleCallback *__thiscall btSoftBodyTriangleCallback::`vector deleting destructor'(
        btSoftBodyTriangleCallback *this,
        char a2)
{
  btSoftBodyTriangleCallback::~btSoftBodyTriangleCallback(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
