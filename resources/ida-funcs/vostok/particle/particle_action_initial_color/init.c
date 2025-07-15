void __thiscall vostok::particle::particle_action_initial_color::init(
        vostok::particle::particle_action_initial_color *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  float v5; // xmm0_4
  int v6; // edx
  vostok::math::curve_line_color *v7; // ecx
  unsigned int v8; // [esp+10h] [ebp-2Ch]
  vostok::math::float4 v9; // [esp+2Ch] [ebp-10h] BYREF

  v5 = s_bm_current_air_resistance;
  v8 = LODWORD(s_bm_current_air_resistance);
  vostok::particle::particle_emitter_instance::get_linear_emitter_time((vostok::particle::particle_emitter_instance *)this);
  P->color = *vostok::math::curve_line_color::evaluate(
                v7,
                (vostok::math::float4 *)(v6 + 24),
                &v9,
                (vostok::math::float4)COERCE_UNSIGNED_INT(v5 * s_spot_max_distance),
                v8);
}
