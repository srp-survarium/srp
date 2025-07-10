stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *__thiscall stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::operator=(
        stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *this,
        const stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *__x,
        const stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *__xa)
{
  vostok::render::shader_constant *M_start; // esi
  vostok::render::shader_constant *v5; // ecx
  unsigned int v6; // edi
  vostok::render::shader_constant *v7; // ebp
  vostok::render::shader_constant *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned int v11; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *v12; // [esp+0h] [ebp-10h]
  const vostok::render::shader_constant *__xb; // [esp+18h] [ebp+8h]

  if ( __xa == __x )
    return (stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *)__x;
  M_start = __xa->_M_start;
  __xb = __xa->_M_finish;
  v5 = __x->_M_start;
  v6 = __xb - M_start;
  if ( v6 <= __x->_M_end_of_storage._M_data - __x->_M_start )
  {
    v11 = __x->_M_finish - v5;
    if ( v11 >= v6 )
    {
      stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
        __xb,
        v5,
        M_start);
      __x->_M_finish = &__x->_M_start[v6];
      return (stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *)__x;
    }
    stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
      &M_start[v11],
      v5,
      M_start);
    stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
      __xa->_M_finish,
      __x->_M_finish,
      &__xa->_M_start[__x->_M_finish - __x->_M_start]);
    __x->_M_finish = &__x->_M_start[v6];
    return (stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *)__x;
  }
  v7 = (vostok::render::shader_constant *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate(
                                            __xb - M_start,
                                            v12);
  stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
    __xb,
    v7,
    M_start);
  v8 = __x->_M_start;
  if ( __x->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
  }
  __x->_M_end_of_storage._M_data = &v7[v6];
  __x->_M_start = v7;
  __x->_M_finish = &v7[v6];
  return (stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *)__x;
}
