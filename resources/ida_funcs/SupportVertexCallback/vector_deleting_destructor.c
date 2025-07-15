btGImpactTriangleCallback *__thiscall SupportVertexCallback::`vector deleting destructor'(
        btGImpactTriangleCallback *this,
        char a2)
{
  this->__vftable = (btGImpactTriangleCallback_vtbl *)&btTriangleCallback::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
