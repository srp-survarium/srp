void __thiscall Scaleform::Render::LinearHeap::allocPage(Scaleform::Render::LinearHeap *this, unsigned int size)
{
  Scaleform::Render::LinearHeap::PageType *pLastPage; // eax
  unsigned int v4; // edi

  pLastPage = this->pLastPage;
  if ( pLastPage->pStart )
    ((void (__stdcall *)(unsigned __int8 *))this->pHeap->Free)(pLastPage->pStart);
  v4 = this->Granularity * ((this->Granularity + size - 1) / this->Granularity);
  this->pLastPage->pFree = (unsigned __int8 *)this->pHeap->Alloc(this->pHeap, v4, 0);
  this->pLastPage->pStart = this->pLastPage->pFree;
  this->pLastPage->pEnd = &this->pLastPage->pStart[v4];
}
