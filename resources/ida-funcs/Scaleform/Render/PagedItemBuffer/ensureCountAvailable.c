void __thiscall Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::ensureCountAvailable(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126> *this,
        unsigned int count)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *pLast; // edi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *v4; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *v5; // eax

  pLast = this->pLast;
  if ( pLast )
  {
    if ( count + pLast->Count > 0x7E )
    {
      v5 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 1016, 0);
      this->pLast = v5;
      pLast->pNext = v5;
      this->pLast->pNext = 0;
      this->pLast->Count = 0;
    }
  }
  else
  {
    v4 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 1016, 0);
    this->pPages = v4;
    this->pLast = v4;
    v4->pNext = 0;
    this->pLast->Count = 0;
  }
}
