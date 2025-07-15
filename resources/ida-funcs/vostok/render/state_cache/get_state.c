ID3D11BlendState *__userpurge vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::get_state@<eax>(
        const D3D11_BLEND_DESC *desc@<eax>,
        vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC> *this)
{
  unsigned int hash; // ebp
  vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC> *v4; // ecx
  ID3D11BlendState *result; // eax
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *M_finish; // eax
  ID3D11BlendState *state; // esi
  _BYTE v8[268]; // [esp-108h] [ebp-120h] BYREF
  unsigned int v9; // [esp+4h] [ebp-14h]
  bool v10; // [esp+8h] [ebp-10h]
  vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record rec; // [esp+10h] [ebp-8h] BYREF

  hash = vostok::render::state_utils::get_hash(desc);
  result = vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::find(v4, desc, hash);
  if ( !result )
  {
    qmemcpy(v8, desc, 0x108u);
    rec.crc = hash;
    vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::create_state(
      *(vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC> **)v8,
      *(D3D11_BLEND_DESC *)&v8[4],
      &rec.state);
    M_finish = (vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *)this->states._M_impl._M_finish;
    state = rec.state;
    if ( M_finish == (vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *)this->states._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record> > *)this,
        M_finish,
        (const vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *)&rec,
        *(const stlp_std::__true_type **)&v8[264],
        v9,
        v10);
    }
    else
    {
      *(vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record *)M_finish = rec;
      ++this->states._M_impl._M_finish;
    }
    return state;
  }
  return result;
}


ID3D11DepthStencilState *__userpurge vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::get_state@<eax>(
        const D3D11_DEPTH_STENCIL_DESC *desc@<eax>,
        vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC> *this)
{
  unsigned int hash; // ebp
  vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC> *v4; // ecx
  ID3D11DepthStencilState *result; // eax
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *M_finish; // eax
  ID3D11DepthStencilState *state; // esi
  _BYTE v8[56]; // [esp-34h] [ebp-4Ch] BYREF
  unsigned int v9; // [esp+4h] [ebp-14h]
  bool v10; // [esp+8h] [ebp-10h]
  vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::state_record rec; // [esp+10h] [ebp-8h] BYREF

  hash = vostok::render::state_utils::get_hash(desc);
  result = vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::find(v4, desc, hash);
  if ( !result )
  {
    qmemcpy(v8, desc, 0x34u);
    rec.crc = hash;
    vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::create_state(
      *(vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC> **)v8,
      *(D3D11_DEPTH_STENCIL_DESC *)&v8[4],
      &rec.state);
    M_finish = (vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *)this->states._M_impl._M_finish;
    state = rec.state;
    if ( M_finish == (vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *)this->states._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record> > *)this,
        M_finish,
        (const vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *)&rec,
        *(const stlp_std::__true_type **)&v8[52],
        v9,
        v10);
    }
    else
    {
      *(vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::state_record *)M_finish = rec;
      ++this->states._M_impl._M_finish;
    }
    return state;
  }
  return result;
}


ID3D11RasterizerState *__userpurge vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::get_state@<eax>(
        const D3D11_RASTERIZER_DESC *desc@<eax>,
        vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> *this)
{
  unsigned int hash; // esi
  ID3D11RasterizerState *result; // eax
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *M_finish; // eax
  ID3D11RasterizerState *state; // esi
  _BYTE v7[44]; // [esp-28h] [ebp-40h]
  const stlp_std::__true_type *v8; // [esp+0h] [ebp-18h]
  unsigned int v9; // [esp+4h] [ebp-14h]
  bool v10; // [esp+8h] [ebp-10h]
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record rec; // [esp+10h] [ebp-8h] BYREF

  hash = vostok::render::state_utils::get_hash(desc);
  result = vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::find(this, desc, hash);
  if ( !result )
  {
    *(_QWORD *)v7 = *(_QWORD *)&desc->FillMode;
    *(_QWORD *)&v7[8] = *(_QWORD *)&desc->FrontCounterClockwise;
    *(_QWORD *)&v7[16] = *(_QWORD *)&desc->DepthBiasClamp;
    *(_QWORD *)&v7[24] = *(_QWORD *)&desc->DepthClipEnable;
    rec.crc = hash;
    *(_QWORD *)&v7[32] = *(_QWORD *)&desc->MultisampleEnable;
    vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::create_state(
      *(vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> **)v7,
      *(D3D11_RASTERIZER_DESC *)&v7[4],
      &rec.state);
    M_finish = this->states._M_impl._M_finish;
    state = rec.state;
    if ( M_finish == this->states._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record>>::_M_insert_overflow(
        &this->states._M_impl,
        M_finish,
        &rec,
        v8,
        v9,
        v10);
    }
    else
    {
      *M_finish = rec;
      ++this->states._M_impl._M_finish;
    }
    return state;
  }
  return result;
}


ID3D11SamplerState *__userpurge vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state@<eax>(
        const D3D11_SAMPLER_DESC *desc@<eax>,
        vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *this)
{
  unsigned int hash; // ebp
  vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> *v4; // ecx
  ID3D11SamplerState *result; // eax
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *M_finish; // eax
  ID3D11SamplerState *state; // esi
  _BYTE v8[56]; // [esp-34h] [ebp-4Ch] BYREF
  unsigned int v9; // [esp+4h] [ebp-14h]
  bool v10; // [esp+8h] [ebp-10h]
  vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::state_record rec; // [esp+10h] [ebp-8h] BYREF

  hash = vostok::render::state_utils::get_hash(desc);
  result = vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::find(v4, desc, hash);
  if ( !result )
  {
    qmemcpy(v8, desc, 0x34u);
    rec.crc = hash;
    vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::create_state(
      *(vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC> **)v8,
      *(D3D11_SAMPLER_DESC *)&v8[4],
      &rec.state);
    M_finish = (vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *)this->states._M_impl._M_finish;
    state = rec.state;
    if ( M_finish == (vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *)this->states._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::state_record>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record,vostok::render::std_allocator<vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record> > *)this,
        M_finish,
        (const vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::state_record *)&rec,
        *(const stlp_std::__true_type **)&v8[52],
        v9,
        v10);
    }
    else
    {
      *(vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::state_record *)M_finish = rec;
      ++this->states._M_impl._M_finish;
    }
    return state;
  }
  return result;
}
