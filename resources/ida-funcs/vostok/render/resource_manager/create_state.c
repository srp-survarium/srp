vostok::render::res_state *__thiscall vostok::render::resource_manager::create_state(
        vostok::render::resource_manager *this,
        vostok::render::state_descriptor *descriptor,
        const D3D11_RASTERIZER_DESC *desc)
{
  vostok::render::state_descriptor *v4; // edi
  vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32> *v6; // ecx
  vostok::buffer_vector<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32>::state_record> *v7; // ecx
  vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32> *v8; // ecx
  ID3D11BlendState *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // esi
  ID3D11BlendState *v11; // edi
  char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // ecx
  vostok::render::res_state *result; // eax
  unsigned int AntialiasedLineEnable; // ebx
  _BYTE v16[44]; // [esp-2Ch] [ebp-6Ch] BYREF
  const char *v17; // [esp+0h] [ebp-40h]
  const char *v18; // [esp+4h] [ebp-3Ch]
  unsigned int v19; // [esp+8h] [ebp-38h]
  _BYTE v20[40]; // [esp+Ch] [ebp-34h] BYREF
  _DWORD v21[2]; // [esp+34h] [ebp-Ch] BYREF
  unsigned int hash; // [esp+3Ch] [ebp-4h]
  ID3D11DepthStencilState *state; // [esp+48h] [ebp+8h]
  ID3D11RasterizerState *desca; // [esp+4Ch] [ebp+Ch]

  v4 = descriptor;
  hash = vostok::render::state_utils::get_hash(desc);
  desca = vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32>::find(
            (vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32> *)((char *)descriptor
                                                                                          + (_DWORD)&loc_901B6
                                                                                          + 2),
            desc,
            hash);
  if ( !desca )
  {
    v21[1] = hash;
    qmemcpy(v20, desc, sizeof(v20));
    *(_DWORD *)v16 = v21;
    qmemcpy(&v16[4], desc, 0x28u);
    vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32>::create_state(
      0,
      *(D3D11_RASTERIZER_DESC *)v16,
      *(ID3D11RasterizerState ***)&v16[40]);
    desca = (ID3D11RasterizerState *)v21[0];
    vostok::buffer_vector<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32>::state_record>::push_back(
      v7,
      (const vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC,32>::state_record *)((char *)descriptor + (_DWORD)&loc_901B6 + 2),
      v20);
    v4 = descriptor;
  }
  state = vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32>::get_state(
            v6,
            (const vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32>::state_record *)((char *)v4 + (_DWORD)&loc_907C3 + 1),
            (const D3D11_DEPTH_STENCIL_DESC *)&desc[1]);
  v9 = vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32>::get_state(
         v8,
         (const vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32>::state_record *)((char *)&loc_90F50
                                                                                                 + (_DWORD)v4),
         (const D3D11_BLEND_DESC *)&desc[2].DepthBias);
  v10 = vostok::render::g_allocator;
  v11 = v9;
  v12 = type_info::raw_name(&vostok::render::res_state `RTTI Type Descriptor');
  result = (vostok::render::res_state *)vostok::memory::doug_lea_allocator::malloc_impl(
                                          v13,
                                          (int)v10,
                                          0x18u,
                                          v12,
                                          v17,
                                          v18,
                                          v19);
  if ( result )
  {
    AntialiasedLineEnable = desc[8].AntialiasedLineEnable;
    result->m_reference_count = 0;
    result->m_rasterizer_state = desca;
    result->m_depth_stencil_state = state;
    result->m_blend_state = v11;
    result->m_stencil_ref = AntialiasedLineEnable;
    result->m_is_registered = 0;
  }
  else
  {
    result = 0;
  }
  result->m_is_registered = 1;
  return result;
}
