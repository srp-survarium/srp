void __thiscall Scaleform::SysAllocWinAPI::SysAllocWinAPI(
        Scaleform::SysAllocWinAPI *this,
        unsigned int granularity,
        unsigned int segSize)
{
  unsigned int *PrivateData; // ecx
  Scaleform::SysAllocMapper *v5; // eax

  PrivateData = this->PrivateData;
  this->pContainer = 0;
  this->__vftable = (Scaleform::SysAllocWinAPI_vtbl *)&Scaleform::SysAllocWinAPI::`vftable';
  this->Mapper.__vftable = (Scaleform::SysMemMapperWinAPI_vtbl *)&Scaleform::SysMemMapperWinAPI::`vftable';
  if ( PrivateData )
  {
    Scaleform::SysAllocMapper::SysAllocMapper(
      (Scaleform::SysAllocMapper *)PrivateData,
      &this->Mapper,
      segSize,
      granularity,
      1);
    this->pAllocator = v5;
  }
  else
  {
    this->pAllocator = 0;
  }
}
