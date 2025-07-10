stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *__thiscall stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>::operator=(
        stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *this,
        const stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *__x,
        const stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *__xa)
{
  unsigned __int8 *M_finish; // ebp
  unsigned __int8 *M_start; // esi
  unsigned int v5; // edi
  unsigned __int8 *v6; // eax
  vostok::render::streaming_texture_instance *v7; // ecx
  vostok::render::streaming_texture_instance *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  unsigned __int8 *v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // ebp
  unsigned int v14; // eax
  unsigned __int8 *v15; // esi
  unsigned __int8 *v16; // eax
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *v17; // [esp+0h] [ebp-10h]
  const stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *__xb; // [esp+18h] [ebp+8h]

  if ( __xa == __x )
    return (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)__x;
  M_finish = (unsigned __int8 *)__xa->_M_finish;
  M_start = (unsigned __int8 *)__xa->_M_start;
  v5 = (M_finish - (unsigned __int8 *)__xa->_M_start) / 24;
  if ( v5 <= __x->_M_end_of_storage._M_data - __x->_M_start )
  {
    v11 = (unsigned __int8 *)__x->_M_start;
    v12 = __x->_M_finish - __x->_M_start;
    if ( v12 < v5 )
    {
      v14 = 24 * v12;
      if ( v14 )
        memmove(v11, M_start, v14);
      v15 = (unsigned __int8 *)__xa->_M_finish;
      v16 = (unsigned __int8 *)&__xa->_M_start[__x->_M_finish - __x->_M_start];
      if ( v15 != v16 )
        memcpy((unsigned __int8 *)__x->_M_finish, v16, v15 - v16);
    }
    else
    {
      v13 = M_finish - M_start;
      if ( v13 )
        memmove(v11, M_start, v13);
    }
    __x->_M_finish = &__x->_M_start[v5];
    return (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)__x;
  }
  v6 = (unsigned __int8 *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate(
                            v5,
                            v17);
  v7 = (vostok::render::streaming_texture_instance *)v6;
  __xb = (const stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)v6;
  if ( M_finish != M_start )
  {
    memcpy(v6, M_start, M_finish - M_start);
    v7 = (vostok::render::streaming_texture_instance *)__xb;
  }
  v8 = __x->_M_start;
  if ( __x->_M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
    v7 = (vostok::render::streaming_texture_instance *)__xb;
  }
  __x->_M_end_of_storage._M_data = &v7[v5];
  __x->_M_start = v7;
  __x->_M_finish = &v7[v5];
  return (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)__x;
}
