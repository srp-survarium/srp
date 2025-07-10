void __thiscall vostok::particle::particle_action_initial_color::init(
        vostok::particle::particle_action_initial_color *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  float linear_emitter_time; // [esp+0h] [ebp-1ACh]
  vostok::math::float4 v7; // [esp+4h] [ebp-1A8h]
  vostok::particle::enum_evaluate_time_type v8; // [esp+14h] [ebp-198h]
  vostok::math::float4 result; // [esp+188h] [ebp-24h] BYREF
  _BYTE v11[20]; // [esp+198h] [ebp-14h] BYREF

  v11[19] = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v5 )
    survarium::weapon_user_dead_state::finalize(v4);
  v7 = *(vostok::math::float4 *)vostok::math::float4::float4(
                                  (vostok::math::float4 *)v4,
                                  (int)v11,
                                  *(int *)&FLOAT_0_0,
                                  0.0,
                                  0.0,
                                  1.0,
                                  COERCE_FLOAT(1));
  linear_emitter_time = vostok::particle::particle_emitter_instance::get_linear_emitter_time(instance);
  P->color = *vostok::particle::curve_line_color::evaluate(&this->m_init_color, &result, linear_emitter_time, v7, v8);
}
