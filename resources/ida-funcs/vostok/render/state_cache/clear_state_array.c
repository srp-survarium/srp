void __usercall vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32>::clear_state_array(
        vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  _DWORD *v2; // ebx
  unsigned int v3; // [esp+8h] [ebp-8h]
  int v4; // [esp+Ch] [ebp-4h]

  v3 = 0;
  if ( (a2[1] - *a2) / 272 )
  {
    v4 = 0;
    do
    {
      v2 = (_DWORD *)(v4 + *a2 + 264);
      if ( *v2 )
      {
        (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v2 + 8))(*v2);
        *v2 = 0;
      }
      ++v3;
      v4 += 272;
    }
    while ( v3 < (a2[1] - *a2) / 272 );
  }
  if ( *a2 != a2[1] )
    a2[1] = *a2;
}


void __usercall vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32>::clear_state_array(
        vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int v2; // ebx
  _DWORD *v3; // edi
  unsigned int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < (a2[1] - *a2) / 60; v2 += 60 )
  {
    v3 = (_DWORD *)(v2 + *a2 + 52);
    if ( *v3 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v3 + 8))(*v3);
      *v3 = 0;
    }
    ++i;
  }
  if ( *a2 != a2[1] )
    a2[1] = *a2;
}


void __usercall vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32>::clear_state_array(
        vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int v2; // ebx
  _DWORD *v3; // edi
  unsigned int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < (a2[1] - *a2) / 48; v2 += 48 )
  {
    v3 = (_DWORD *)(v2 + *a2 + 40);
    if ( *v3 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v3 + 8))(*v3);
      *v3 = 0;
    }
    ++i;
  }
  if ( *a2 != a2[1] )
    a2[1] = *a2;
}
