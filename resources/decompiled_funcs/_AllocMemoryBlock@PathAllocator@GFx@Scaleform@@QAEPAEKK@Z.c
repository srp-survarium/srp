Scaleform::GFx::PathAllocator::Page *__thiscall Scaleform::GFx::PathAllocator::AllocMemoryBlock(
        Scaleform::GFx::PathAllocator *this,
        unsigned int sizeForCurrentPage,
        unsigned int sizeInNewPage)
{
  unsigned int FreeBytes; // edi
  __int16 v5; // bx
  Scaleform::GFx::PathAllocator::Page *result; // eax
  Scaleform::GFx::PathAllocator::Page *v7; // ecx
  bool v8; // zf
  Scaleform::GFx::PathAllocator::Page *pLastPage; // eax
  unsigned int v10; // ecx

  FreeBytes = this->FreeBytes;
  v5 = sizeInNewPage;
  if ( this->pLastPage && FreeBytes >= sizeForCurrentPage )
  {
    v5 = sizeForCurrentPage;
LABEL_11:
    pLastPage = this->pLastPage;
    v10 = pLastPage->PageSize - FreeBytes;
    this->FreeBytes = FreeBytes - v5;
    return (Scaleform::GFx::PathAllocator::Page *)((char *)pLastPage + v10 + 8);
  }
  FreeBytes = this->DefaultPageSize;
  if ( sizeInNewPage > FreeBytes )
    FreeBytes = sizeInNewPage;
  result = (Scaleform::GFx::PathAllocator::Page *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    FreeBytes + 8,
                                                    0);
  if ( result )
  {
    result->pNext = 0;
    result->PageSize = FreeBytes;
    v7 = this->pLastPage;
    if ( v7 )
    {
      v7->pNext = result;
      this->pLastPage->PageSize -= this->FreeBytes;
    }
    v8 = this->pFirstPage == 0;
    this->pLastPage = result;
    if ( v8 )
      this->pFirstPage = result;
    goto LABEL_11;
  }
  return result;
}
