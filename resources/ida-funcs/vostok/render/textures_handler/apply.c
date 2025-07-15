void __usercall vostok::render::textures_handler<1>::apply(
        vostok::render::textures_handler<1> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  ID3D11ShaderResourceView **v3; // esi
  vostok::render::textures_handler<0> *v4; // ecx
  int v5; // eax
  bool v6; // cc
  signed int v7; // ebx
  ID3D11ShaderResourceView *const *v8; // esi
  int out_num_textures; // [esp+Ch] [ebp-4h] BYREF

  v3 = (ID3D11ShaderResourceView **)(a2 + 3);
  memset((int)(a2 + 3), 0, 0x200u);
  vostok::render::textures_handler<1>::fill_changes_buffer(v4, a2, v3, (vostok::render::res_texture *)&out_num_textures);
  v5 = a2[1];
  if ( out_num_textures > v5 )
  {
    v6 = v5 < out_num_textures - v5;
    v7 = a2[1];
    out_num_textures -= v5;
    if ( v6 )
    {
      v8 = (ID3D11ShaderResourceView *const *)&a2[v5 + 3];
      do
      {
        if ( *v8 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->PSSetShaderResources(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v7,
            1u,
            v8);
        ++v7;
        ++v8;
      }
      while ( v7 < out_num_textures );
    }
  }
  a2[2] = 0;
  a2[1] = 0;
}


void __usercall vostok::render::textures_handler<2>::apply(
        vostok::render::textures_handler<2> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  ID3D11ShaderResourceView **v3; // esi
  vostok::render::textures_handler<0> *v4; // ecx
  int v5; // eax
  bool v6; // cc
  signed int v7; // ebx
  ID3D11ShaderResourceView *const *v8; // esi
  int out_num_textures; // [esp+Ch] [ebp-4h] BYREF

  v3 = (ID3D11ShaderResourceView **)(a2 + 3);
  memset((int)(a2 + 3), 0, 0x200u);
  vostok::render::textures_handler<1>::fill_changes_buffer(v4, a2, v3, (vostok::render::res_texture *)&out_num_textures);
  v5 = a2[1];
  if ( out_num_textures > v5 )
  {
    v6 = v5 < out_num_textures - v5;
    v7 = a2[1];
    out_num_textures -= v5;
    if ( v6 )
    {
      v8 = (ID3D11ShaderResourceView *const *)&a2[v5 + 3];
      do
      {
        if ( *v8 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->GSSetShaderResources(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v7,
            1u,
            v8);
        ++v7;
        ++v8;
      }
      while ( v7 < out_num_textures );
    }
  }
  a2[2] = 0;
  a2[1] = 0;
}


void __usercall vostok::render::textures_handler<0>::apply(
        vostok::render::textures_handler<0> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  ID3D11ShaderResourceView **v3; // esi
  vostok::render::textures_handler<0> *v4; // ecx
  int v5; // eax
  bool v6; // cc
  signed int v7; // ebx
  ID3D11ShaderResourceView *const *v8; // esi
  int out_num_textures; // [esp+Ch] [ebp-4h] BYREF

  v3 = (ID3D11ShaderResourceView **)(a2 + 3);
  memset((int)(a2 + 3), 0, 0x200u);
  vostok::render::textures_handler<1>::fill_changes_buffer(v4, a2, v3, (vostok::render::res_texture *)&out_num_textures);
  v5 = a2[1];
  if ( out_num_textures > v5 )
  {
    v6 = v5 < out_num_textures - v5;
    v7 = a2[1];
    out_num_textures -= v5;
    if ( v6 )
    {
      v8 = (ID3D11ShaderResourceView *const *)&a2[v5 + 3];
      do
      {
        if ( *v8 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->VSSetShaderResources(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v7,
            1u,
            v8);
        ++v7;
        ++v8;
      }
      while ( v7 < out_num_textures );
    }
  }
  a2[2] = 0;
  a2[1] = 0;
}
