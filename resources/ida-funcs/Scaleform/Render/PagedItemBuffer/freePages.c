void __thiscall Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *this,
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *keepLast)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *v2; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *pPages; // esi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *v4; // ebp
  unsigned int v5; // edi
  Scaleform::RefCountVImpl **p_pSysFormat; // ebx

  v2 = keepLast;
  pPages = keepLast->pPages;
  v4 = 0;
  if ( keepLast->pPages )
  {
    do
    {
      v5 = 0;
      if ( pPages->Count )
      {
        p_pSysFormat = (Scaleform::RefCountVImpl **)&pPages->Items[0].Value.pSysFormat;
        do
        {
          if ( *p_pSysFormat )
            Scaleform::RefCountImpl::Release(*p_pSysFormat);
          ++v5;
          p_pSysFormat += 5;
        }
        while ( v5 < pPages->Count );
      }
      if ( v4 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
      v4 = pPages;
      pPages = pPages->pNext;
    }
    while ( pPages );
    if ( v4 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
      keepLast->pPages = 0;
      keepLast->pLast = 0;
      return;
    }
    v2 = keepLast;
  }
  v2->pLast = 0;
  v2->pPages = 0;
}


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
