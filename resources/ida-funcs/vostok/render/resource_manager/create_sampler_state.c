ID3D11SamplerState *__userpurge vostok::render::resource_manager::create_sampler_state@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *sampler_props)
{
  vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32>::state_record **p_m_end; // ebx
  vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32>::state_record **v4; // esi
  ID3D11SamplerState *hash; // edi
  ID3D11SamplerState *v6; // esi
  vostok::buffer_vector<vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32>::state_record> *v7; // ecx
  D3D11_SAMPLER_DESC v9; // [esp-38h] [ebp-84h] BYREF
  _BYTE v10[52]; // [esp+10h] [ebp-3Ch] BYREF
  ID3D11SamplerState *ppIState[2]; // [esp+44h] [ebp-8h] BYREF
  vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *v12; // [esp+54h] [ebp+8h]

  p_m_end = &sampler_props->states.m_end;
  v4 = &sampler_props->states.m_end;
  v12 = (vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32> *)((char *)&loc_9315B + a2 + 1);
  hash = (ID3D11SamplerState *)vostok::render::state_utils::get_hash((const D3D11_SAMPLER_DESC *)v4);
  v6 = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32>::find(
         v12,
         (const D3D11_SAMPLER_DESC *)v4,
         (unsigned int)hash);
  if ( !v6 )
  {
    ppIState[1] = hash;
    qmemcpy(v10, p_m_end, sizeof(v10));
    qmemcpy((void *)&v9, p_m_end, sizeof(v9));
    vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32>::create_state(0, v9, ppIState);
    v6 = ppIState[0];
    vostok::buffer_vector<vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32>::state_record>::push_back(
      v7,
      (const vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC,32>::state_record *)v12,
      v10);
  }
  return v6;
}
