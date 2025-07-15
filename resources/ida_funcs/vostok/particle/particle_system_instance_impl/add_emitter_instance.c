void __thiscall vostok::particle::particle_system_instance_impl::add_emitter_instance(
        vostok::particle::particle_system_instance_impl *this,
        unsigned int lod_index,
        vostok::particle::particle_emitter_instance *new_instance)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  new_instance->m_particle_system_instance = this;
  vostok::intrusive_list<vostok::particle::particle_emitter_instance,vostok::particle::particle_emitter_instance *,224,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &this->m_lods[lod_index].m_emitter_instance_list,
    (survarium::game_camera *)new_instance,
    0);
  if ( this->m_is_playing )
    vostok::particle::particle_system_instance_impl::prepare_render_resources(this);
}
