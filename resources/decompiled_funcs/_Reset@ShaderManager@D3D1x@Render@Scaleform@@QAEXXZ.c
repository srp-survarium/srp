void __usercall Scaleform::Render::D3D1x::ShaderManager::Reset(
        Scaleform::Render::D3D1x::ShaderManager *this@<ecx>,
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *a2@<eax>)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page **p_pLast; // ebx
  unsigned int i; // esi
  const Scaleform::Render::D3D1x::VertexShaderDesc *v5; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page **v6; // ebx
  unsigned int j; // esi
  const Scaleform::Render::D3D1x::FragShaderDesc *v8; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *pPages; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *v10; // ecx

  p_pLast = &a2[5385].pLast;
  for ( i = 0; i < 232; ++i )
  {
    v5 = Scaleform::Render::D3D1x::VertexShaderDesc::Descs[i];
    if ( v5 && v5->pBinary )
    {
      if ( *p_pLast )
        ((void (__stdcall *)(Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *))(*p_pLast)->pNext->Items[0].pKey)(*p_pLast);
      *p_pLast = 0;
    }
    p_pLast += 17;
  }
  v6 = &a2[3].pLast;
  for ( j = 0; j < 598; ++j )
  {
    v8 = Scaleform::Render::D3D1x::FragShaderDesc::Descs[j];
    if ( v8 && v8->pBinary )
    {
      if ( *v6 )
        ((void (__stdcall *)(Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *))(*v6)->pNext->Items[0].pKey)(*v6);
      *v6 = 0;
    }
    v6 += 18;
  }
  pPages = a2[7357].pPages;
  if ( pPages )
    ((void (__stdcall *)(Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *))pPages->pNext->Items[0].pKey)(a2[7357].pPages);
  a2[7357].pPages = 0;
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::freePages(&this->VFormats.KeyBuffer, (int)a2);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    v10,
    a2 + 1);
}
