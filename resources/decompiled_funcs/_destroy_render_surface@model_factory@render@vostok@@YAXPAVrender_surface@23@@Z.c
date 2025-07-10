void __usercall vostok::render::model_factory::destroy_render_surface(vostok::render::render_surface *v@<eax>)
{
  vostok::render::grass_render_model *m_object; // ebx
  char *v3; // edi
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi

  m_object = vostok::render::g_allocator.m_object;
  if ( v )
  {
    v3 = __RTCastToVoid((void **)&v->__vftable);
    ((void (__thiscall *)(vostok::render::render_surface *, _DWORD))v->~vostok::render::render_surface)(v, 0);
    if ( v3 )
    {
      m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
    }
  }
}
