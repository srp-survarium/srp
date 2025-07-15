void __thiscall vostok::render::shader_binary_source_cook::destroy_resource(
        vostok::render::shader_binary_source_cook *this,
        vostok::resources::unmanaged_resource *resource_to_destroy)
{
  void *m_flags; // eax
  int m_reconstruction_info_actuality_tick; // eax

  if ( resource_to_destroy[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags )
  {
    m_flags = (void *)resource_to_destroy[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    if ( m_flags )
    {
      pt3free(m_flags);
      resource_to_destroy[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = 0;
    }
    resource_to_destroy[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = 0;
  }
  m_reconstruction_info_actuality_tick = resource_to_destroy[1].m_reconstruction_info_actuality_tick;
  if ( m_reconstruction_info_actuality_tick )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)m_reconstruction_info_actuality_tick + 8))(resource_to_destroy[1].m_reconstruction_info_actuality_tick);
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, _DWORD))resource_to_destroy->~vostok::resources::resource_base)(
    resource_to_destroy,
    0);
}
