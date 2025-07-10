Scaleform::SysAllocWinAPI *__thiscall Scaleform::SysAllocWinAPI::`scalar deleting destructor'(
        Scaleform::SysAllocWinAPI *this,
        char a2)
{
  this->Mapper.__vftable = (Scaleform::SysMemMapperWinAPI_vtbl *)&Scaleform::SysMemMapper::`vftable';
  this->__vftable = (Scaleform::SysAllocWinAPI_vtbl *)&Scaleform::SysAllocBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
