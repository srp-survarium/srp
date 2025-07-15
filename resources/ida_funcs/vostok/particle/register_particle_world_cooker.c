void __cdecl vostok::particle::register_particle_world_cooker()
{
  survarium::game_camera *v0; // ecx
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  vostok::particle *v3; // [esp+0h] [ebp-18h]
  vostok::particle *v4; // [esp+0h] [ebp-18h]
  vostok::particle::particle_world_cooker *v5; // [esp+14h] [ebp-4h]

  if ( !cooker_registered )
  {
    vostok::particle::register_particles_cooker(v3);
    vostok::particle::register_particles_system_cooks(v4);
    survarium::weapon_user_dead_state::finalize(v0);
    v5 = (vostok::particle::particle_world_cooker *)operator new(
                                                      0x20u,
                                                      &vostok::particle::s_particle_world_cooker_object);
    if ( v5 )
      vostok::particle::particle_world_cooker::particle_world_cooker(v5);
    survarium::weapon_user_dead_state::finalize(v1);
    vostok::threading::interlocked_exchange_pointer(&vostok::particle::s_particle_world_cooker_object.m_initialized, 1);
    survarium::weapon_user_dead_state::finalize(v2);
    vostok::resources::register_cook(vostok::particle::s_particle_world_cooker_object.m_variable);
    cooker_registered = 1;
  }
}
