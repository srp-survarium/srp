void __userpurge stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::reserve(
        stlp_std::priv::_Impl_vector<vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __n)
{
  const vostok::render::shader_constant *v3; // esi
  int v4; // ebx
  vostok::render::shader_constant *v5; // ebp
  vostok::render::shader_constant *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *v8; // [esp+0h] [ebp-10h]
  const stlp_std::random_access_iterator_tag *v9; // [esp+0h] [ebp-10h]
  int *v10; // [esp+4h] [ebp-Ch]
  vostok::render::shader_constant *__last; // [esp+Ch] [ebp-4h]

  v3 = *(const vostok::render::shader_constant **)a2;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) / 24 < __n )
  {
    if ( __n > 0xAAAAAAA )
      stlp_std::__stl_throw_length_error("vector");
    __last = *(vostok::render::shader_constant **)(a2 + 4);
    v4 = __last - v3;
    v5 = (vostok::render::shader_constant *)stlp_std::priv::_STLP_alloc_proxy<vostok::render::shader_constant *,vostok::render::shader_constant,vostok::render::std_allocator<vostok::render::shader_constant>>::allocate(
                                              __n,
                                              v8);
    if ( v3 )
    {
      stlp_std::priv::__ucopy<vostok::render::shader_constant const *,vostok::render::shader_constant *,int>(
        v3,
        __last,
        v5,
        v9,
        v10);
      v6 = *(vostok::render::shader_constant **)a2;
      if ( *(_DWORD *)a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
      }
    }
    *(_DWORD *)a2 = v5;
    *(_DWORD *)(a2 + 4) = &v5[v4];
    *(_DWORD *)(a2 + 8) = &v5[__n];
  }
}
