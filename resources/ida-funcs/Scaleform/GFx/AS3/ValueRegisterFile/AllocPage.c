Scaleform::GFx::AS3::ValueRegisterFile::Page *__thiscall Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(
        Scaleform::GFx::AS3::ValueRegisterFile *this,
        unsigned __int16 pageSize)
{
  unsigned __int16 MaxAllocatedPageSize; // ax
  unsigned __int16 v3; // si
  Scaleform::GFx::AS3::ValueRegisterFile::Page *result; // eax

  MaxAllocatedPageSize = this->MaxAllocatedPageSize;
  if ( pageSize <= MaxAllocatedPageSize )
  {
    if ( MaxAllocatedPageSize <= 0x40u )
      MaxAllocatedPageSize = 64;
  }
  else
  {
    MaxAllocatedPageSize = (unsigned __int16)((pageSize + 64) / 64) << 6;
  }
  this->MaxAllocatedPageSize = MaxAllocatedPageSize;
  v3 = MaxAllocatedPageSize;
  result = (Scaleform::GFx::AS3::ValueRegisterFile::Page *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this,
                                                             2 * (9 * MaxAllocatedPageSize - 8) + 40,
                                                             0);
  result->PageSize = v3;
  result->ReservedNum = 0;
  result->CurrPos = 0;
  result->pCurrent = 0;
  return result;
}
