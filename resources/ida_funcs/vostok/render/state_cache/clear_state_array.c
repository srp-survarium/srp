void __usercall vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::clear_state_array(
        vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  unsigned int i; // ebx
  int v3; // eax
  _DWORD *v4; // edi

  for ( i = 0; i < (a2[1] - *a2) >> 3; ++i )
  {
    v3 = *(_DWORD *)(*a2 + 8 * i + 4);
    v4 = (_DWORD *)(*a2 + 8 * i + 4);
    if ( v3 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*(_DWORD *)(*a2 + 8 * i + 4));
      *v4 = 0;
    }
  }
  if ( *a2 != a2[1] )
    a2[1] = *a2;
}
