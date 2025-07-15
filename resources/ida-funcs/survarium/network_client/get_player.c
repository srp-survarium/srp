vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__thiscall survarium::network_client::get_player(
        survarium::network_client *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *result,
        unsigned __int8 id)
{
  survarium::base_player *v3; // eax

  v3 = survarium::game_world_core::player(this->m_match.m_object->m_game_world_core, id);
  vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
    result,
    (vostok::particle::particle_system_instance_impl *)v3);
  return result;
}
