void __thiscall vostok::particle::lod_entry::lod_entry(vostok::particle::lod_entry *this)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v1; // ecx
  survarium::game_camera *v2; // ecx

  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v1, &this->m_emitter_instance_list.m_size);
  survarium::weapon_user_dead_state::finalize(v2);
  this->m_emitter_instance_list.m_first = 0;
  this->m_emitter_instance_list.m_last = 0;
}
