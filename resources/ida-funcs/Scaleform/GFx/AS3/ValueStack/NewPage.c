Scaleform::GFx::AS3::ValueStack::Page *__thiscall Scaleform::GFx::AS3::ValueStack::NewPage(
        Scaleform::GFx::AS3::ValueStack *this,
        unsigned __int16 pageSize)
{
  Scaleform::GFx::AS3::ValueStack::Page *result; // eax
  unsigned __int16 v3; // si
  Scaleform::GFx::AS3::ValueStack::Page *pNext; // edx
  Scaleform::GFx::AS3::ValueStack::Page *v5; // ecx

  result = this->pReserved;
  if ( result )
  {
    while ( result->PageSize < pageSize )
    {
      result = result->pNext;
      if ( !result )
        goto LABEL_4;
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
      v5 = result->pNext;
      if ( v5 )
        v5->pPrev = result->pPrev;
      result->pNext = 0;
      result->pPrev = 0;
    }
  }
  else
  {
LABEL_4:
    v3 = pageSize;
    if ( pageSize <= 0x40u )
      v3 = 64;
    result = (Scaleform::GFx::AS3::ValueStack::Page *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        16 * (v3 - 1) + 40,
                                                        0);
    result->PageSize = v3;
    result->ReservationNum = 0;
  }
  return result;
}
