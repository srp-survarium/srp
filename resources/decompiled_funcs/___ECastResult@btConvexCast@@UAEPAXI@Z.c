btConvexCast::CastResult *__thiscall btConvexCast::CastResult::`vector deleting destructor'(
        btConvexCast::CastResult *this,
        char a2)
{
  this->__vftable = (btConvexCast::CastResult_vtbl *)&btConvexCast::CastResult::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
