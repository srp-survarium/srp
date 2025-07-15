void __usercall Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::freePages(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *this@<ecx>,
        int a2@<edi>)
{
  _DWORD *v2; // esi
  void *v3; // eax

  v2 = *(_DWORD **)a2;
  v3 = 0;
  if ( *(_DWORD *)a2 )
  {
    do
    {
      if ( v3 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
      v3 = v2;
      v2 = (_DWORD *)*v2;
    }
    while ( v2 );
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
      v3 = 0;
    }
  }
  *(_DWORD *)a2 = v3;
  *(_DWORD *)(a2 + 4) = v3;
}


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
