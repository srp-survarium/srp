unsigned __int8 *__thiscall Scaleform::GFx::DataAllocator::OverflowAlloc(
        Scaleform::GFx::DataAllocator *this,
        unsigned int bytes)
{
  Scaleform::GFx::DataAllocator::Block *v3; // eax
  unsigned __int8 *result; // eax
  char *v5; // eax

  if ( bytes > 0xFFA )
  {
    v3 = (Scaleform::GFx::DataAllocator::Block *)this->pHeap->Alloc(this->pHeap, bytes + 4, 0);
    if ( v3 )
    {
      v3->pNext = this->pAllocations;
      this->pAllocations = v3;
      return (unsigned __int8 *)&v3[1];
    }
    return 0;
  }
  if ( bytes > this->BytesLeft )
  {
    v5 = (char *)this->pHeap->Alloc(this->pHeap, 8184, 0);
    if ( !v5 )
      return 0;
    *(_DWORD *)v5 = this->pAllocations;
    this->pAllocations = (Scaleform::GFx::DataAllocator::Block *)v5;
    this->pCurrent = (unsigned __int8 *)(v5 + 4);
    this->BytesLeft = 8180;
  }
  result = this->pCurrent;
  this->BytesLeft -= bytes;
  this->pCurrent = &result[bytes];
  return result;
}
