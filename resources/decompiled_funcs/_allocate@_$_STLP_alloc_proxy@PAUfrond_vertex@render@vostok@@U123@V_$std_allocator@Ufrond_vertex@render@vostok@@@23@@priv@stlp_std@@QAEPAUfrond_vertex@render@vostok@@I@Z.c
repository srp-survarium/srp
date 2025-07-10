vostok::render::frond_vertex *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::render::frond_vertex *,vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::render::frond_vertex *,vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // esi
  int v8; // [esp+0h] [ebp-8h] BYREF
  unsigned int v9; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v9 = __n;
  v3 = __n == 0;
  v8 = 1;
  v4 = (unsigned int *)&v8;
  if ( !v3 )
    v4 = &v9;
  v5 = 56 * *v4;
  m_object = vostok::render::g_allocator.m_object;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v5 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v5 )
    return (vostok::render::frond_vertex *)vostok_mspace_malloc(
                                             (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                             v5);
  else
    return 0;
}
