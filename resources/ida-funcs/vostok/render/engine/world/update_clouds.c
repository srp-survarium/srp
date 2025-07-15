void __thiscall vostok::render::engine::world::update_clouds(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        vostok::render::cloud_parameters *parameters)
{
  int m_last_fail_of_increasing_quality_low; // esi

  m_last_fail_of_increasing_quality_low = LODWORD(in_scene->m_object[3].m_last_fail_of_increasing_quality);
  if ( m_last_fail_of_increasing_quality_low )
    vostok::render::clouds::initialize(
      (vostok::render::clouds *)this,
      m_last_fail_of_increasing_quality_low,
      parameters);
  else
    vostok::render::scene::add_clouds(
      (vostok::render::scene *)this,
      (vostok::render::scene *)in_scene->m_object,
      (vostok::render::clouds *)parameters);
}
