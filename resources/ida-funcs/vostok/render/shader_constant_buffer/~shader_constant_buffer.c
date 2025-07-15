void __usercall vostok::render::shader_constant_buffer::~shader_constant_buffer(
        vostok::render::shader_constant_buffer *this@<ecx>,
        int a2@<edi>)
{
  int v2; // eax
  char *v3; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi

  v2 = *(_DWORD *)(a2 + 96);
  if ( v2 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(a2 + 96));
    *(_DWORD *)(a2 + 96) = 0;
  }
  v3 = *(char **)(a2 + 88);
  if ( v3 )
  {
    m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
    *(_DWORD *)(a2 + 88) = 0;
  }
}
