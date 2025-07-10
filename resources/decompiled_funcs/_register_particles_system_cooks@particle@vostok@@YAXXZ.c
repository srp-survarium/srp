void __thiscall vostok::particle::register_particles_system_cooks(survarium::game_camera *ecx0)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  vostok::particle::particle_system_cook *v6; // [esp+2Ch] [ebp-8h]
  vostok::particle::particle_system_wrapper_cook *v7; // [esp+30h] [ebp-4h]

  if ( !particles_system_cooker_registered )
  {
    survarium::weapon_user_dead_state::finalize(ecx0);
    v7 = (vostok::particle::particle_system_wrapper_cook *)operator new(
                                                             0x20u,
                                                             &vostok::particle::s_particle_system_wrapper_cook);
    if ( v7 )
      vostok::particle::particle_system_wrapper_cook::particle_system_wrapper_cook(v7);
    survarium::weapon_user_dead_state::finalize(v1);
    vostok::threading::interlocked_exchange_pointer(&vostok::particle::s_particle_system_wrapper_cook.m_initialized, 1);
    survarium::weapon_user_dead_state::finalize(v2);
    v6 = (vostok::particle::particle_system_cook *)operator new(0x20u, &vostok::particle::s_particle_system_cook);
    if ( v6 )
      vostok::particle::particle_system_cook::particle_system_cook(v6);
    survarium::weapon_user_dead_state::finalize(v3);
    vostok::threading::interlocked_exchange_pointer(&vostok::particle::s_particle_system_cook.m_initialized, 1);
    survarium::weapon_user_dead_state::finalize(v4);
    vostok::resources::register_cook(vostok::particle::s_particle_system_wrapper_cook.m_variable);
    survarium::weapon_user_dead_state::finalize(v5);
    vostok::resources::register_cook(vostok::particle::s_particle_system_cook.m_variable);
    particles_system_cooker_registered = 1;
  }
}
