void __thiscall Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::freePages(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126> *this,
        bool keepLast)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *pPages; // esi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *v4; // eax

  pPages = this->pPages;
  v4 = 0;
  if ( this->pPages )
  {
    do
    {
      if ( v4 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
      v4 = pPages;
      pPages = pPages->pNext;
    }
    while ( pPages );
    if ( v4 )
    {
      if ( keepLast )
      {
        v4->Count = 0;
        this->pLast = v4;
        this->pPages = v4;
        return;
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
      v4 = 0;
    }
  }
  this->pLast = v4;
  this->pPages = v4;
}
