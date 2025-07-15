void __userpurge survarium::object_particle_visual::tick(
        survarium::object_particle_visual *this@<ecx>,
        bool a2@<dil>,
        const unsigned int __formal,
        const unsigned int current_time_ms)
{
  vostok::math::float4x4 *p_m_transform; // edi
  float in_time; // [esp+0h] [ebp-14h]

  p_m_transform = &this->m_transform;
  in_time = (double)current_time_ms * 0.001;
  survarium::object_track::evaluate(this->m_track, &this->m_transform, in_time);
  vostok::render::scene_renderer::update_particle_system_instance(
    (vostok::render::scene_renderer *)&this->m_game_scene->m_render_scene,
    *(boost::_bi::bind_t<void,boost::_mfi::mf6<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &,vostok::math::float4x4 const &,bool,bool>,boost::_bi::list7<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1>,boost::arg<2>,boost::_bi::value<bool>,boost::_bi::value<bool> > > **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene,
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_particle_system_instance_ptr,
    p_m_transform,
    p_m_transform,
    a2);
}
