void __thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::MatrixPool(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::MemoryHeap *heap)
{
  this->__vftable = (Scaleform::Render::MatrixPoolImpl::MatrixPool_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->pHeap = heap;
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::MatrixPoolImpl::MatrixPool_vtbl *)&Scaleform::Render::MatrixPoolImpl::MatrixPool::`vftable';
  this->AllocatedSpace = 0;
  this->DataPageCount = 0;
  this->FreedSpace = 0;
  this->HandleTable.pHeap = heap;
  this->HandleTable.pPool = this;
  this->HandleTable.FullPages.Root.pPrev = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->HandleTable.FullPages;
  this->HandleTable.FullPages.Root.pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->HandleTable.FullPages;
  this->HandleTable.PartiallyFreePages.Root.pPrev = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->HandleTable.PartiallyFreePages;
  this->HandleTable.PartiallyFreePages.Root.pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->HandleTable.PartiallyFreePages;
  this->DataPages.Root.pPrev = (Scaleform::Render::MatrixPoolImpl::DataPage *)&this->DataPages;
  this->DataPages.Root.pNext = (Scaleform::Render::MatrixPoolImpl::DataPage *)&this->DataPages;
  this->pAllocPage = 0;
  this->pSqueezePage = 0;
  this->pLastFreedPage = 0;
}
