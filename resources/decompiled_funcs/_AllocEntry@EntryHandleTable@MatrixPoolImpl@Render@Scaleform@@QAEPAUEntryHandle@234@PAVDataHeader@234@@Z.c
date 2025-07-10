Scaleform::Render::MatrixPoolImpl::EntryHandle *__thiscall Scaleform::Render::MatrixPoolImpl::EntryHandleTable::AllocEntry(
        Scaleform::Render::MatrixPoolImpl::EntryHandleTable *this,
        Scaleform::Render::MatrixPoolImpl::DataHeader *header)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *result; // eax
  Scaleform::Render::MatrixPoolImpl::HandlePageBase *pNext; // ecx
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // edx

  if ( (Scaleform::List<Scaleform::Render::MatrixPoolImpl::HandlePage,Scaleform::Render::MatrixPoolImpl::HandlePageBase> *)this->PartiallyFreePages.Root.pNext == &this->PartiallyFreePages
    && !Scaleform::Render::MatrixPoolImpl::EntryHandleTable::allocEntryPage(this) )
  {
    return 0;
  }
  pNext = this->PartiallyFreePages.Root.pNext;
  result = pNext->pFreeList;
  pHeader = result->pHeader;
  ++pNext->UseCount;
  pNext->pFreeList = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)pHeader;
  if ( !result->pHeader )
  {
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::Render::MatrixPoolImpl::HandlePageBase>::$100264D7F6BD7FB1D268588F766D014E::pPrev = pNext->pPrev;
    pNext->pPrev = this->FullPages.Root.pPrev;
    pNext->pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->FullPages;
    this->FullPages.Root.pPrev->pNext = pNext;
    this->FullPages.Root.pPrev = pNext;
  }
  result->pHeader = header;
  return result;
}
