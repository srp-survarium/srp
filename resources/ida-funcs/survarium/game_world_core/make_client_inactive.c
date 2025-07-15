void __usercall survarium::game_world_core::make_client_inactive(
        survarium::game_world_core *this@<edx>,
        survarium::base_player *player@<eax>)
{
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **p_m_active_clients; // edi
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > *v3; // [esp-4h] [ebp-14h]
  const vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *v4; // [esp+8h] [ebp-8h] BYREF
  client_id_predicate __comp[4]; // [esp+Ch] [ebp-4h] BYREF

  this->m_active_clients_mask &= ~(1 << player->id);
  __comp[0] = 0;
  v3 = *(vostok::buffer_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> > **)__comp;
  p_m_active_clients = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&this->m_active_clients;
  v4 = stlp_std::lower_bound<vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *,unsigned char,client_id_predicate>(
         this->m_active_clients.m_begin,
         this->m_active_clients.m_end,
         &player->id);
  *(_DWORD *)__comp = v4 + 1;
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base>>::erase(
    v3,
    p_m_active_clients,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)&v4,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)__comp);
}
