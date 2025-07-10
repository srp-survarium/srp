void __thiscall vostok::particle::particle_action_color_over_lifetime::update(
        vostok::particle::particle_action_color_over_lifetime *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time_delta)
{
  vostok::math::float4 *v4; // ecx
  _BYTE *v5; // eax
  vostok::particle::base_particle *v6; // ecx
  float y; // [esp+4h] [ebp-D0h]
  const vostok::math::float4 *y_4; // [esp+8h] [ebp-CCh]
  vostok::particle::particle_action_color_over_lifetime *thisb; // [esp+Ch] [ebp-C8h]
  vostok::math::float4 result; // [esp+B0h] [ebp-24h] BYREF
  _BYTE v12[20]; // [esp+C0h] [ebp-14h] BYREF

  v12[19] = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v5 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  y_4 = (const vostok::math::float4 *)vostok::math::float4::float4(
                                        v4,
                                        (int)v12,
                                        *(int *)&FLOAT_0_0,
                                        0.0,
                                        0.0,
                                        1.0,
                                        *(float *)&this);
  y = P->target_color_y_position;
  vostok::particle::base_particle::get_linear_lifetime(v6);
  P->color = *vostok::particle::color_matrix::evaluate(&thisb->m_color_over_life, &result, 0.0, y, y_4);
}
