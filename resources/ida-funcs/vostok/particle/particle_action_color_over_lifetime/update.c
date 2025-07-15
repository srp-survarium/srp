void __thiscall vostok::particle::particle_action_color_over_lifetime::update(
        vostok::particle::particle_action_color_over_lifetime *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time_delta)
{
  double lifetime; // st7
  float v5; // xmm0_4
  float v7; // [esp+4h] [ebp-2Ch]
  vostok::math::float4_pod v8; // [esp+10h] [ebp-20h] BYREF
  vostok::math::float4 v9; // [esp+20h] [ebp-10h] BYREF

  lifetime = P->lifetime;
  memset(&v8, 0, 12);
  v5 = s_bm_current_air_resistance;
  v7 = lifetime;
  v8.w = s_bm_current_air_resistance;
  vostok::particle::base_particle::get_linear_lifetime_impl((vostok::particle::base_particle *)this, (int)P, v7);
  P->color = *vostok::particle::color_matrix::evaluate(
                &this->m_color_over_life,
                v5,
                &v9,
                COERCE_CONST_VOSTOK_MATH_FLOAT4_(P->target_color_y_position),
                &v8);
}
