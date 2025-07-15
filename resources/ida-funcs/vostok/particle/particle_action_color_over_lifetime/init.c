void __thiscall vostok::particle::particle_action_color_over_lifetime::init(
        vostok::particle::particle_action_color_over_lifetime *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time_delta)
{
  _BYTE *v4; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  P->target_color_y_position = vostok::particle::random_float(0.0, 1.0);
}
