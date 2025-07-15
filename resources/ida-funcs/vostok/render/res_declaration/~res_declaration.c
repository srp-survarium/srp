void __usercall vostok::render::res_declaration::~res_declaration(
        vostok::render::res_declaration *this@<ecx>,
        stlp_std::reverse_iterator<vostok::render::signature_layout_pair *> *a2@<edi>)
{
  char *current; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  char *v4; // eax
  malloc_state *v5; // esi

  current = (char *)a2[4].current;
  if ( current )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, current);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::signature_layout_pair *>,vostok::render::signature_layout_pair>(
    a2[2],
    a2[1]);
  v4 = (char *)a2[1].current;
  if ( v4 )
  {
    v5 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v5, v4);
  }
}
