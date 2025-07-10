Scaleform::SysMemMapperWinAPI *__thiscall Scaleform::SysMemMapperWinAPI::`scalar deleting destructor'(
        Scaleform::SysMemMapperWinAPI *this,
        char a2)
{
  this->__vftable = (Scaleform::SysMemMapperWinAPI_vtbl *)&Scaleform::SysMemMapper::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
