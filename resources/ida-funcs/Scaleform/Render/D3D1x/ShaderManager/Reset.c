void __usercall Scaleform::Render::D3D1x::ShaderManager::Reset(
        Scaleform::Render::D3D1x::ShaderManager *this@<ecx>,
        int a2@<eax>)
{
  _DWORD *v3; // esi
  unsigned int i; // ebx
  const Scaleform::Render::D3D1x::VertexShaderDesc *v5; // eax
  _DWORD *v6; // esi
  unsigned int j; // ebx
  const Scaleform::Render::D3D1x::FragShaderDesc *v8; // eax
  int v9; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *v10; // ecx

  v3 = (_DWORD *)(a2 + 43084);
  for ( i = 0; i < 232; ++i )
  {
    v5 = Scaleform::Render::D3D1x::VertexShaderDesc::Descs[i];
    if ( v5 && v5->pBinary )
    {
      if ( *v3 )
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v3 + 8))(*v3);
      *v3 = 0;
    }
    v3 += 17;
  }
  v6 = (_DWORD *)(a2 + 28);
  for ( j = 0; j < 598; ++j )
  {
    v8 = Scaleform::Render::D3D1x::FragShaderDesc::Descs[j];
    if ( v8 && v8->pBinary )
    {
      if ( *v6 )
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v6 + 8))(*v6);
      *v6 = 0;
    }
    v6 += 18;
  }
  v9 = *(_DWORD *)(a2 + 58856);
  if ( v9 )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v9 + 8))(*(_DWORD *)(a2 + 58856));
  *(_DWORD *)(a2 + 58856) = 0;
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::freePages(&this->VFormats.KeyBuffer, a2);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    v10,
    (Scaleform::RefCountVImpl ***)(a2 + 8));
}
