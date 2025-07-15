void __userpurge vostok::particle::particle_action_animated_source::update(
        vostok::particle::particle_action_animated_source *this@<ecx>,
        unsigned int a2@<edi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  float v5; // xmm0_4
  double lifetime; // st7
  unsigned int m_seed; // esi
  vostok::math::curve_line_ranged_xyz_float *v8; // ecx
  float v9; // [esp+8h] [ebp-2Ch]
  vostok::math::float3 v10; // [esp+18h] [ebp-1Ch] BYREF
  vostok::math::float3 v11; // [esp+24h] [ebp-10h] BYREF
  vostok::particle::particle_action_animated_source *v12; // [esp+30h] [ebp-4h]

  v5 = s_bm_current_air_resistance;
  lifetime = P->lifetime;
  P->old_surface_scale = P->surface_scale;
  v9 = lifetime;
  m_seed = P->m_seed;
  v12 = this;
  v11.x = v5;
  v11.y = v5;
  v11.z = v5;
  vostok::particle::base_particle::get_linear_lifetime_impl((vostok::particle::base_particle *)this, (int)P, v9);
  P->surface_scale = *vostok::math::curve_line_ranged_xyz_float::evaluate(
                        v8,
                        (int)&v12->m_scale,
                        v5,
                        &v10,
                        v5,
                        &v11,
                        m_seed,
                        a2);
}
