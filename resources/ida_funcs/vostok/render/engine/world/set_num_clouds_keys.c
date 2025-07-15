void __thiscall vostok::render::engine::world::set_num_clouds_keys(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        unsigned int num_keys)
{
  float m_last_fail_of_increasing_quality; // eax

  m_last_fail_of_increasing_quality = in_scene->m_object[3].m_last_fail_of_increasing_quality;
  if ( m_last_fail_of_increasing_quality != 0.0 )
    *(_DWORD *)(LODWORD(m_last_fail_of_increasing_quality) + 2176) = num_keys;
}
