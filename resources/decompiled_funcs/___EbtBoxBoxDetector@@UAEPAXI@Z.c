SphereTriangleDetector *__thiscall btBoxBoxDetector::`vector deleting destructor'(
        SphereTriangleDetector *this,
        char a2)
{
  this->__vftable = (SphereTriangleDetector_vtbl *)&btDiscreteCollisionDetectorInterface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
