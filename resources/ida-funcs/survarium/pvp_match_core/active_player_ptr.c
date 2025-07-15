vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__userpurge survarium::pvp_match_core::active_player_ptr@<eax>(
        survarium::pvp_match_core *this@<ecx>,
        int a2@<eax>,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *result,
        unsigned __int8 player_id)
{
  survarium::game_world_core::active_player_ptr(
    (survarium::game_world_core *)this,
    result,
    *(vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> **)(a2 + 312),
    player_id);
  return result;
}
