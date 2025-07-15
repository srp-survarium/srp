btGjkConvexCast *__thiscall btContinuousConvexCollision::`scalar deleting destructor'(btGjkConvexCast *this, char a2)
{
  this->__vftable = (btGjkConvexCast_vtbl *)&btConvexCast::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
