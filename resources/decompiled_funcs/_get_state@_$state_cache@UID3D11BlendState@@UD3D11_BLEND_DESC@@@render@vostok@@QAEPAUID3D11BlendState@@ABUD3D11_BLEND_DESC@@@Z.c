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
