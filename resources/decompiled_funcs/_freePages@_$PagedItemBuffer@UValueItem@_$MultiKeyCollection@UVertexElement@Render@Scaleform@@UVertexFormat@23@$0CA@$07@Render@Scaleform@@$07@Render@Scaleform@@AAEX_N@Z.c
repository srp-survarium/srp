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
