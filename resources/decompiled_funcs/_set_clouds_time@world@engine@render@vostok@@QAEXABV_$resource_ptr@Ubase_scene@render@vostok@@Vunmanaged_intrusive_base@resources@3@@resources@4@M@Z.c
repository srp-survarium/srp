void __userpurge vostok::render::engine::world::set_clouds_time(
        vostok::render::engine::world *this@<ecx>,
        const vostok::render::cloud_key_parameters *a2@<edi>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        float time)
{
  if ( LODWORD(in_scene->m_object[3].m_last_fail_of_increasing_quality) )
    vostok::render::clouds::set_time(
      (vostok::render::clouds *)this,
      a2,
      time,
      (vostok::render::clouds *)LODWORD(in_scene->m_object[3].m_last_fail_of_increasing_quality));
}
