void __thiscall Scaleform::GFx::PathAllocator::Clear(Scaleform::GFx::PathAllocator *this)
{
  Scaleform::GFx::PathAllocator::Page *pFirstPage; // eax
  Scaleform::GFx::PathAllocator::Page *pNext; // esi

  pFirstPage = this->pFirstPage;
  if ( this->pFirstPage )
  {
    do
    {
      pNext = pFirstPage->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pFirstPage);
      pFirstPage = pNext;
    }
    while ( pNext );
  }
  this->pFirstPage = 0;
  this->pLastPage = 0;
  this->FreeBytes = 0;
}
