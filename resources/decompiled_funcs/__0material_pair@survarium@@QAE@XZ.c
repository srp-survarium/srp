void __thiscall survarium::material_pair::material_pair(survarium::material_pair *this)
{
  vostok::memory::base_allocator **v1; // eax
  boost::_bi::list1<vostok::network_core::packet_reader &> *v3; // [esp+10h] [ebp-8h] BYREF
  vostok::memory::base_allocator *v4; // [esp+14h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)survarium::g_allocator.f_.f_,
    &v3);
  v4 = *v1;
  this->m_particles._M_impl._M_start = 0;
  this->m_particles._M_impl._M_finish = 0;
  this->m_particles._M_impl._M_end_of_storage.m_allocator = v4;
  this->m_particles._M_impl._M_end_of_storage._M_data = 0;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_sound_emitter);
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_decal1);
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_decal2);
  this->m_current_particle_idx = 0;
}
