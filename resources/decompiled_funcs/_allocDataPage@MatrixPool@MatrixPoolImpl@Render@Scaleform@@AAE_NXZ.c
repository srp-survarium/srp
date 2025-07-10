char __thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::allocDataPage(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this)
{
  Scaleform::Render::MatrixPoolImpl::DataPage *pLastFreedPage; // eax

  pLastFreedPage = this->pLastFreedPage;
  if ( pLastFreedPage )
  {
    this->pLastFreedPage = 0;
  }
  else
  {
    pLastFreedPage = (Scaleform::Render::MatrixPoolImpl::DataPage *)this->pHeap->Alloc(this->pHeap, 4096, 16, 0);
    if ( !pLastFreedPage )
      return 0;
  }
  pLastFreedPage->pPool = this;
  pLastFreedPage->FreeTail = 4080;
  pLastFreedPage->FreeMiddle = 0;
  pLastFreedPage->pPrev = this->DataPages.Root.pPrev;
  pLastFreedPage->pNext = (Scaleform::Render::MatrixPoolImpl::DataPage *)&this->DataPages;
  this->DataPages.Root.pPrev->pNext = pLastFreedPage;
  this->DataPages.Root.pPrev = pLastFreedPage;
  this->AllocatedSpace += 4080;
  ++this->DataPageCount;
  this->pAllocPage = pLastFreedPage;
  return 1;
}
