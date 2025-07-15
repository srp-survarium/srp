void __thiscall Scaleform::Render::LinearHeap::ClearAndRelease(Scaleform::Render::LinearHeap *this)
{
  unsigned int MaxPages; // eax
  Scaleform::Render::LinearHeap::PageType *v3; // edi
  Scaleform::MemoryHeap *pHeap; // ecx

  MaxPages = this->MaxPages;
  if ( MaxPages )
  {
    v3 = &this->pPagePool[MaxPages - 1];
    do
    {
      --this->MaxPages;
      if ( v3->pStart )
        this->pHeap->Free(this->pHeap, v3->pStart);
      --v3;
    }
    while ( this->MaxPages );
    pHeap = this->pHeap;
    --this->MaxPages;
    pHeap->Free(pHeap, this->pPagePool);
  }
  this->pLastPage = 0;
  this->pPagePool = 0;
  this->MaxPages = 0;
}
