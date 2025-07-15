vostok::render::res_state *__usercall vostok::render::resource_manager::create_state@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::state_descriptor *descriptor@<eax>)
{
  ID3D11RasterizerState *state; // ebx
  ID3D11DepthStencilState *v5; // ebp
  _DWORD *v6; // eax
  ID3D11BlendState *v7; // ecx
  _DWORD *v8; // esi
  vostok::render::vector<vostok::render::res_state *> *p_m_states; // edi
  void **M_finish; // eax
  bool v12; // [esp+0h] [ebp-14h]
  ID3D11BlendState *blend_state; // [esp+10h] [ebp-4h] BYREF

  state = vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC>::get_state(
            &descriptor->m_rasterizer_desc,
            &this->m_rs_cache);
  v5 = vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::get_state(
         &descriptor->m_depth_stencil_desc,
         &this->m_dss_cache);
  blend_state = vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC>::get_state(
                  &descriptor->m_effect_desc,
                  &this->m_bs_cache);
  v6 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x18u);
  if ( v6 )
  {
    v7 = blend_state;
    v6[4] = descriptor->m_stencil_ref;
    *v6 = 0;
    v6[1] = state;
    v6[2] = v5;
    v6[3] = v7;
    *((_BYTE *)v6 + 20) = 0;
    v8 = v6;
  }
  else
  {
    v8 = 0;
  }
  p_m_states = &this->m_states;
  *((_BYTE *)v8 + 20) = 1;
  M_finish = p_m_states->_M_impl._M_finish;
  blend_state = (ID3D11BlendState *)v8;
  if ( M_finish == p_m_states->_M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)v7,
      (int)p_m_states,
      M_finish,
      (void *const *)&blend_state,
      (const stlp_std::__true_type *)1,
      1,
      v12);
  }
  else
  {
    *M_finish = v8;
    ++p_m_states->_M_impl._M_finish;
  }
  return (vostok::render::res_state *)v8;
}
