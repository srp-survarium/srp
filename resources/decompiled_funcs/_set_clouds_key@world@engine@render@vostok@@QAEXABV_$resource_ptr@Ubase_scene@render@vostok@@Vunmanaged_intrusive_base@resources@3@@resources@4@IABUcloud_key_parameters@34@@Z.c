void __thiscall vostok::render::engine::world::set_clouds_key(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        unsigned int index,
        const vostok::render::cloud_key_parameters *parameters)
{
  float m_last_fail_of_increasing_quality; // ecx

  m_last_fail_of_increasing_quality = in_scene->m_object[3].m_last_fail_of_increasing_quality;
  if ( m_last_fail_of_increasing_quality != 0.0 )
    qmemcpy((void *)(LODWORD(m_last_fail_of_increasing_quality) + 68 * index), parameters, 0x44u);
}
