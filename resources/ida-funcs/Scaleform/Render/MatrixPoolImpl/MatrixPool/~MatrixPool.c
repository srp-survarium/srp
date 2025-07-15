void __thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::~MatrixPool(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this)
{
  Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *p_DataPages; // ebx
  Scaleform::Render::MatrixPoolImpl::DataPage *pNext; // edi
  Scaleform::Render::MatrixPoolImpl::DataPage *pLastFreedPage; // eax

  p_DataPages = &this->DataPages;
  this->__vftable = (Scaleform::Render::MatrixPoolImpl::MatrixPool_vtbl *)&Scaleform::Render::MatrixPoolImpl::MatrixPool::`vftable';
  if ( (Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *)this->DataPages.Root.pNext != &this->DataPages )
  {
    do
    {
      pNext = this->DataPages.Root.pNext;
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->Scaleform::ListNode<Scaleform::Render::MatrixPoolImpl::DataPage>::$95A64ED5797A13A53B8ABC5B6A0E3FA8::pPrev = pNext->pPrev;
      pLastFreedPage = this->pLastFreedPage;
      this->AllocatedSpace -= 4080;
      --this->DataPageCount;
      if ( pLastFreedPage )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pLastFreedPage);
      this->pLastFreedPage = pNext;
    }
    while ( (Scaleform::List<Scaleform::Render::MatrixPoolImpl::DataPage,Scaleform::Render::MatrixPoolImpl::DataPage> *)p_DataPages->Root.pNext != p_DataPages );
  }
  if ( this->pLastFreedPage )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pLastFreedPage);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
