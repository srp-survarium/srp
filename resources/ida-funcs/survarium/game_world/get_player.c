survarium::base_player *__thiscall survarium::game_world::get_player(
        survarium::game_world *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> id)
{
  int v2; // esi

  v2 = *(_DWORD *)(*(int (__thiscall **)(_DWORD, vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *, vostok::particle::particle_system_instance_impl *))(**(_DWORD **)(*(_DWORD *)&this[-1].m_third_person_game_effect_presenters[11180] + 13912) + 72))(
                    *(_DWORD *)(*(_DWORD *)&this[-1].m_third_person_game_effect_presenters[11180] + 13912),
                    &id,
                    id.m_object);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&id);
  return (survarium::base_player *)v2;
}
