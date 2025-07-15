char __thiscall Scaleform::Render::MatrixPoolImpl::EntryHandleTable::allocEntryPage(
        Scaleform::Render::MatrixPoolImpl::EntryHandleTable *this)
{
  Scaleform::Render::MatrixPoolImpl::HandlePageBase *v2; // eax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v4; // edx
  int v5; // esi
  unsigned int *p_UseCount; // ecx

  v2 = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)this->pHeap->Alloc(this->pHeap, 2032, 2048, 0);
  if ( !v2 )
    return 0;
  v2->pTable = this;
  v2->UseCount = 0;
  v4 = 0;
  v5 = 503;
  p_UseCount = &v2[101].UseCount;
  do
  {
    *p_UseCount = (unsigned int)v4;
    v4 = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)p_UseCount;
    --v5;
    --p_UseCount;
  }
  while ( v5 );
  v2->pFreeList = v4;
  v2->pPrev = this->PartiallyFreePages.Root.pPrev;
  v2->pNext = (Scaleform::Render::MatrixPoolImpl::HandlePageBase *)&this->PartiallyFreePages;
  this->PartiallyFreePages.Root.pPrev->pNext = v2;
  this->PartiallyFreePages.Root.pPrev = v2;
  return 1;
}
