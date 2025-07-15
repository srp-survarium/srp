vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__userpurge survarium::game_world_core::active_player_ptr@<eax>(
        survarium::game_world_core *this@<ecx>,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<eax>,
        vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *result,
        unsigned __int8 player_id)
{
  const vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *v5; // eax

  v5 = stlp_std::lower_bound<vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *,unsigned char,client_id_predicate>(
         (const vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)result[12353].m_object,
         (const vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)result[12354].m_object,
         &player_id);
  if ( v5 == (const vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)result[12354].m_object
    || v5->m_object->id != player_id )
  {
    vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
      a2,
      0);
  }
  else
  {
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      a2,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v5);
  }
  return a2;
}
