void __userpurge survarium::game_world_core::make_client_active(
        vostok::particle::particle_system_instance_impl *player@<eax>,
        survarium::game_world_core *this)
{
  survarium::game_world_core *v2; // ebx
  vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *m_begin; // ecx
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> > *v5; // ecx
  _BYTE *v6; // [esp+Ch] [ebp-8h]
  unsigned int count; // [esp+10h] [ebp-4h] BYREF

  v2 = this;
  m_begin = this->m_active_clients.m_begin;
  LOBYTE(this) = 0;
  v6 = &player->m_lods[1].m_emitter_instance_list.gap4;
  count = (unsigned int)stlp_std::lower_bound<vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *,unsigned char,client_id_predicate>(
                          m_begin,
                          v2->m_active_clients.m_end,
                          &player->m_lods[1].m_emitter_instance_list.gap4);
  vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
    player);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base>>::insert(
    v5,
    &v2->m_active_clients.m_begin,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&count,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  v2->m_active_clients_mask |= 1 << *v6;
}
