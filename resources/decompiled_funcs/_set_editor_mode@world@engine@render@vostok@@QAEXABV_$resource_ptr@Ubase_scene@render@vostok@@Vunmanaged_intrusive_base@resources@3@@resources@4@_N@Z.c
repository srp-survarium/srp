void __thiscall vostok::render::engine::world::set_editor_mode(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        bool is_editor_mode)
{
  float m_last_fail_of_increasing_quality; // eax

  m_last_fail_of_increasing_quality = in_scene->m_object[3].m_last_fail_of_increasing_quality;
  if ( m_last_fail_of_increasing_quality != 0.0 )
    *(_BYTE *)(LODWORD(m_last_fail_of_increasing_quality) + 2728) = is_editor_mode;
}
