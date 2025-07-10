unsigned __int8 *__thiscall Scaleform::Render::LinearHeap::allocFromLastPage(
        Scaleform::Render::LinearHeap *this,
        int size)
{
  Scaleform::Render::LinearHeap::PageType *pLastPage; // eax

  pLastPage = this->pLastPage;
  if ( pLastPage->pEnd - pLastPage->pFree < size )
  {
    if ( pLastPage->pFree == pLastPage->pStart )
    {
      if ( pLastPage->pEnd - pLastPage->pFree < size )
        Scaleform::Render::LinearHeap::allocPage(this, size);
      this->pLastPage->pFree += size;
      return this->pLastPage->pStart;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    pLastPage->pFree += size;
    return &this->pLastPage->pFree[-size];
  }
}
