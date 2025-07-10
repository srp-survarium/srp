Scaleform::SysAllocStatic *__thiscall Scaleform::SysAllocMapper::`scalar deleting destructor'(
        Scaleform::SysAllocStatic *this,
        char a2)
{
  this->__vftable = (Scaleform::SysAllocStatic_vtbl *)&Scaleform::SysAllocBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
