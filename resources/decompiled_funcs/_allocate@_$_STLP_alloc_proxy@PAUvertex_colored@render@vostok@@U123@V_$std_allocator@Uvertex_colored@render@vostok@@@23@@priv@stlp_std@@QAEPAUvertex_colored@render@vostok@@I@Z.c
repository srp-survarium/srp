vostok::render::vertex_colored *__usercall stlp_std::priv::_STLP_alloc_proxy<vostok::render::vertex_colored *,vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::render::vertex_colored *,vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  m_object = vostok::render::g_allocator.m_object;
  v7 = 16 * v5;
  if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v7 )
    v2 = 0;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v2;
  if ( v7 )
    return (vostok::render::vertex_colored *)vostok_mspace_malloc(
                                               (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                               v7);
  else
    return 0;
}
