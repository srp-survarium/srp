void __usercall vostok::render::resource_manager::release_impl(
        const vostok::render::res_texture *texture@<eax>,
        vostok::render::resource_manager *this)
{
  vostok::render::grass_render_model *m_object; // ebx
  _BYTE *v4; // edi
  void *m_reconstruction_info_actuality_tick_high; // esi

  m_object = vostok::render::g_allocator.m_object;
  if ( texture )
  {
    v4 = __RTCastToVoid((void **)&texture->__vftable);
    ((void (__thiscall *)(const vostok::render::res_texture *, _DWORD))texture->~vostok::render::res_texture)(
      texture,
      0);
    if ( v4 )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v4);
    }
  }
}
