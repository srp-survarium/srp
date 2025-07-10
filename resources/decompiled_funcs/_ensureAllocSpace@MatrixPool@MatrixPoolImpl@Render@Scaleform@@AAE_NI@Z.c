char __thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::ensureAllocSpace(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        unsigned int size)
{
  Scaleform::Render::MatrixPoolImpl::DataPage *pPrev; // eax
  Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *p_DataPages; // ecx
  Scaleform::Render::MatrixPoolImpl::DataPage *pSqueezePage; // eax
  Scaleform::Render::MatrixPoolImpl::DataPage *pAllocPage; // eax

  pPrev = this->DataPages.Root.pPrev;
  p_DataPages = &this->DataPages;
  if ( this->pAllocPage != pPrev
    && (Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *)p_DataPages->Root.pNext != p_DataPages )
  {
    this->pAllocPage = pPrev;
    if ( pPrev->FreeTail >= size )
      return 1;
  }
  if ( this->FreedSpace >= (3 * this->AllocatedSpace) >> 5 )
  {
    pSqueezePage = this->pSqueezePage;
    if ( !pSqueezePage
      || !Scaleform::Render::MatrixPoolImpl::MatrixPool::squeezeMemoryRange(
            this,
            pSqueezePage,
            this->DataPages.Root.pNext->pPrev,
            Squeeze_Incremental) )
    {
      Scaleform::Render::MatrixPoolImpl::MatrixPool::squeezeMemoryRange(
        this,
        this->DataPages.Root.pNext,
        this->DataPages.Root.pNext->pPrev,
        Squeeze_Incremental);
    }
  }
  pAllocPage = this->pAllocPage;
  if ( !pAllocPage || pAllocPage->FreeTail < size )
    return Scaleform::Render::MatrixPoolImpl::MatrixPool::allocDataPage(this);
  else
    return 1;
}
