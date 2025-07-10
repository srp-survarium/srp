Scaleform::GFx::AS3::ValueRegisterFile::Page *__thiscall Scaleform::GFx::AS3::ValueRegisterFile::NewPage(
        Scaleform::GFx::AS3::ValueRegisterFile *this,
        unsigned __int16 pageSize)
{
  Scaleform::GFx::AS3::ValueRegisterFile::Page *result; // eax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *pNext; // edx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v4; // ecx

  if ( pageSize > this->MaxReservedPageSize )
    return Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(this, pageSize);
  result = this->pReserved;
  if ( !result )
    return Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(this, pageSize);
  while ( result->PageSize < pageSize )
  {
    result = result->pNext;
    if ( !result )
      return Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(this, pageSize);
  }
  pNext = result->pNext;
  if ( result == this->pReserved )
  {
    this->pReserved = pNext;
    if ( pNext )
      pNext->pPrev = 0;
    result->pNext = 0;
  }
  else
  {
    result->pPrev->pNext = pNext;
    v4 = result->pNext;
    if ( v4 )
      v4->pPrev = result->pPrev;
    result->pNext = 0;
    result->pPrev = 0;
  }
  return result;
}
