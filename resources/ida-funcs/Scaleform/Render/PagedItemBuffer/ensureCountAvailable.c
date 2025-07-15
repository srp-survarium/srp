void __usercall Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::ensureCountAvailable(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  _DWORD *v2; // edi
  _DWORD *v3; // eax
  void *v4; // eax

  v2 = (_DWORD *)a2[1];
  if ( v2 )
  {
    if ( (unsigned int)(v2[1] + 1) > 8 )
    {
      v4 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, a2, 168, 0);
      a2[1] = v4;
      *v2 = v4;
      *(_DWORD *)a2[1] = 0;
      *(_DWORD *)(a2[1] + 4) = 0;
    }
  }
  else
  {
    v3 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, a2, 168, 0);
    *a2 = v3;
    a2[1] = v3;
    *v3 = 0;
    *(_DWORD *)(a2[1] + 4) = 0;
  }
}


void __userpurge Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::ensureCountAvailable(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *this@<ecx>,
        _DWORD *a2@<esi>,
        unsigned int count)
{
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  void *v5; // eax

  v3 = (_DWORD *)a2[1];
  if ( v3 )
  {
    if ( count + v3[1] > 0x20 )
    {
      v5 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, a2, 264, 0);
      a2[1] = v5;
      *v3 = v5;
      *(_DWORD *)a2[1] = 0;
      *(_DWORD *)(a2[1] + 4) = 0;
    }
  }
  else
  {
    v4 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, a2, 264, 0);
    *a2 = v4;
    a2[1] = v4;
    *v4 = 0;
    *(_DWORD *)(a2[1] + 4) = 0;
  }
}


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
