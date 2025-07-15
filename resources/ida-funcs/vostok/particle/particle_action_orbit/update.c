void __userpurge vostok::particle::particle_action_orbit::update(
        vostok::particle::particle_action_orbit *this@<ecx>,
        unsigned int a2@<edi>,
        int a3@<esi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  vostok::particle::base_particle *v7; // ecx
  vostok::math::curve_line_ranged_xyz_float *v8; // ecx
  float duration; // xmm1_4
  vostok::math::curve_line_ranged_xyz_float *v10; // ecx
  vostok::math::curve_line_ranged_xyz_float *v11; // ecx
  vostok::math::curve_line_ranged_xyz_float *p_m_rotation; // edi
  vostok::math::curve_line_ranged_xyz_float *v13; // ecx
  vostok::math::float4x4 *v14; // eax
  float z; // xmm1_4
  float y; // xmm2_4
  float x; // xmm3_4
  __m128i v18; // xmm0
  __m128i x_low; // xmm0
  float v20; // xmm1_4
  float v21; // xmm1_4
  __m128 v22; // xmm0
  __m128i v23; // xmm0
  vostok::math::curve_line_ranged_xyz_float *v24; // ecx
  unsigned int m_seed; // [esp+Ch] [ebp-E4h]
  unsigned int v26; // [esp+Ch] [ebp-E4h]
  unsigned int v27; // [esp+Ch] [ebp-E4h]
  unsigned int v28; // [esp+Ch] [ebp-E4h]
  unsigned int v29; // [esp+Ch] [ebp-E4h]
  long double v30; // [esp+10h] [ebp-E0h]
  long double v31; // [esp+10h] [ebp-E0h]
  long double v32; // [esp+10h] [ebp-E0h]
  long double v33; // [esp+10h] [ebp-E0h]
  unsigned int v34; // [esp+10h] [ebp-E0h]
  float lifetime; // [esp+1Ch] [ebp-D4h]
  float v36; // [esp+1Ch] [ebp-D4h]
  float v37; // [esp+20h] [ebp-D0h]
  float orbit_phi; // [esp+20h] [ebp-D0h]
  float v40; // [esp+24h] [ebp-CCh]
  float v41; // [esp+24h] [ebp-CCh]
  float v42; // [esp+28h] [ebp-C8h]
  float v43; // [esp+28h] [ebp-C8h]
  vostok::math::float3 v44; // [esp+2Ch] [ebp-C4h] BYREF
  vostok::math::float3 v45; // [esp+38h] [ebp-B8h] BYREF
  float orbit_tetha; // [esp+44h] [ebp-ACh]
  vostok::math::float3 v47; // [esp+48h] [ebp-A8h] BYREF
  vostok::math::float3 v48; // [esp+54h] [ebp-9Ch] BYREF
  vostok::math::float3 *p_position; // [esp+60h] [ebp-90h]
  vostok::math::float3 v50; // [esp+64h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v51; // [esp+70h] [ebp-80h] BYREF
  _BYTE v52[64]; // [esp+B0h] [ebp-40h] BYREF

  HIDWORD(v30) = a3;
  lifetime = P->lifetime;
  vostok::particle::base_particle::get_linear_lifetime_impl((vostok::particle::base_particle *)this, (int)P, lifetime);
  v37 = lifetime;
  vostok::particle::base_particle::get_linear_lifetime_impl(v7, (int)P, lifetime + time);
  duration = P->duration;
  v36 = lifetime + time;
  if ( duration > 0.0000099999997 )
  {
    v37 = (float)(s_bm_current_air_resistance / duration) * v37;
    v36 = (float)(s_bm_current_air_resistance / duration) * v36;
  }
  m_seed = P->m_seed;
  memset(&v45, 0, sizeof(v45));
  vostok::math::curve_line_ranged_xyz_float::evaluate(v8, (int)&this->m_radius, 0.0, &v44, v37, &v45, m_seed, a2);
  v42 = fsqrt((float)((float)(v44.z * v44.z) + (float)(v44.y * v44.y)) + (float)(v44.x * v44.x));
  if ( v42 >= 0.0000099999997 )
  {
    v26 = P->m_seed;
    memset(&v45, 0, sizeof(v45));
    vostok::math::curve_line_ranged_xyz_float::evaluate(
      v10,
      (int)&this->m_spin,
      0.0,
      &v50,
      v36,
      &v45,
      v26,
      LODWORD(v30));
    vostok::math::curve_line_ranged_base::evaluate(
      &this->m_speed.m_line,
      P->m_seed,
      v36,
      0.0,
      this->m_speed.m_evaluate_type,
      range_time_type);
    v27 = P->m_seed;
    v43 = 0.0 / v42;
    memset(&v45, 0, sizeof(v45));
    vostok::math::curve_line_ranged_xyz_float::evaluate(
      v11,
      (int)&this->m_radius,
      0.0,
      &v47,
      v36,
      &v45,
      v27,
      LODWORD(v30));
    v28 = P->m_seed;
    p_m_rotation = &this->m_rotation;
    memset(&v45, 0, sizeof(v45));
    vostok::math::curve_line_ranged_xyz_float::evaluate(
      v13,
      (int)&this->m_rotation,
      0.0,
      &v48,
      v37,
      &v45,
      v28,
      LODWORD(v30));
    v14 = vostok::math::create_rotation(&v48, (int)&this->m_rotation, (int)v52);
    vostok::math::try_invert4x4(v14, &v51);
    z = P->position.z;
    y = P->position.y;
    x = P->position.x;
    v48.x = (float)((float)((float)(v51.j.x * y) + (float)(v51.k.x * z)) + (float)(v51.i.x * x)) + v51.c.x;
    p_position = &P->position;
    v48.y = (float)((float)((float)(v51.i.y * x) + (float)(v51.j.y * y)) + (float)(v51.k.y * z)) + v51.c.y;
    v48.z = (float)((float)((float)(v51.i.z * x) + (float)(v51.j.z * y)) + (float)(v51.k.z * z)) + v51.c.z;
    orbit_phi = P->orbit_phi;
    orbit_tetha = P->orbit_tetha;
    v18 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(orbit_tetha));
    __libm_sse2_sin(v18);
    *(float *)v18.m128i_i32 = *(double *)v18.m128i_i64;
    v40 = *(float *)v18.m128i_i32;
    __libm_sse2_cos(v30);
    x_low = (__m128i)LODWORD(v48.x);
    v45.x = v48.x - (float)((float)(orbit_phi * v40) * v44.x);
    *(double *)x_low.m128i_i64 = orbit_phi;
    __libm_sse2_sin(x_low);
    v45.y = v48.y - (float)((float)(orbit_phi * v40) * v44.y);
    *(double *)x_low.m128i_i64 = orbit_tetha;
    __libm_sse2_cos(v31);
    v20 = *(double *)x_low.m128i_i64;
    *(float *)x_low.m128i_i32 = v48.z - (float)(v20 * v44.z);
    v21 = (float)((float)(v50.y * v43) * time) + orbit_phi;
    LODWORD(v45.z) = x_low.m128i_i32[0];
    v22 = (__m128)LODWORD(v50.x);
    v22.m128_f32[0] = (float)((float)(v50.x * v43) * time) + orbit_tetha;
    v41 = v22.m128_f32[0];
    LODWORD(P->orbit_tetha) = v22.m128_i32[0];
    P->orbit_phi = v21;
    v23 = (__m128i)_mm_cvtps_pd(v22);
    __libm_sse2_sin(v23);
    *(float *)v23.m128i_i32 = *(double *)v23.m128i_i64;
    orbit_tetha = *(float *)v23.m128i_i32;
    __libm_sse2_cos(v32);
    v44.x = (float)((float)(v21 * orbit_tetha) * v47.x) + v45.x;
    *(double *)v23.m128i_i64 = v21;
    __libm_sse2_sin(v23);
    v44.y = (float)((float)(v21 * orbit_tetha) * v47.y) + v45.y;
    __libm_sse2_cos(v33);
    v29 = P->m_seed;
    v44.z = (float)(v41 * v47.z) + v45.z;
    memset(&v47, 0, sizeof(v47));
    vostok::math::curve_line_ranged_xyz_float::evaluate(v24, (int)p_m_rotation, 0.0, &v50, v36, &v47, v29, v34);
    vostok::math::create_rotation(&v50, (int)p_m_rotation, (int)&v51);
    v47.x = (float)((float)((float)(v51.k.x * v44.z) + (float)(v51.j.x * v44.y)) + (float)(v51.i.x * v44.x)) + v51.c.x;
    v47.y = (float)((float)((float)(v51.k.y * v44.z) + (float)(v51.j.y * v44.y)) + (float)(v51.i.y * v44.x)) + v51.c.y;
    v47.z = (float)((float)((float)(v51.k.z * v44.z) + (float)(v51.j.z * v44.y)) + (float)(v51.i.z * v44.x)) + v51.c.z;
    *p_position = v47;
  }
}
