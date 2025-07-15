void __thiscall vostok::particle::register_particles_cooker(survarium::game_camera *ecx0)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  vostok::particle::particle_system_instance_cook *v3; // [esp+14h] [ebp-4h]

  if ( !particles_cooker_registered )
  {
    survarium::weapon_user_dead_state::finalize(ecx0);
    v3 = (vostok::particle::particle_system_instance_cook *)operator new(
                                                              0x20u,
                                                              &vostok::particle::s_particle_cook_object);
    if ( v3 )
      vostok::particle::particle_system_instance_cook::particle_system_instance_cook(v3);
    survarium::weapon_user_dead_state::finalize(v1);
    vostok::threading::interlocked_exchange_pointer(&vostok::particle::s_particle_cook_object.m_initialized, 1);
    survarium::weapon_user_dead_state::finalize(v2);
    vostok::resources::register_cook(vostok::particle::s_particle_cook_object.m_variable);
    particles_cooker_registered = 1;
  }
}
