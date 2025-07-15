void __userpurge vostok::particle::particle_action_orbit::init(
        vostok::particle::particle_action_orbit *this@<ecx>,
        unsigned int a2@<edi>,
        int a3@<esi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  vostok::math::curve_line_ranged_xyz_float *v7; // ecx
  __m128i v8; // xmm0
  int p_m_rotation; // edi
  vostok::math::curve_line_ranged_xyz_float *v10; // ecx
  vostok::math::float4x4 *v11; // esi
  vostok::math::float4x4 *v12; // eax
  vostok::math::float4x4 *v13; // eax
  unsigned int m_seed; // [esp+8h] [ebp-194h]
  unsigned int v15; // [esp+8h] [ebp-194h]
  unsigned int v16; // [esp+8h] [ebp-194h]
  long double v17; // [esp+Ch] [ebp-190h]
  unsigned int v18; // [esp+Ch] [ebp-190h]
  long double v19; // [esp+Ch] [ebp-190h]
  unsigned int v20; // [esp+Ch] [ebp-190h]
  vostok::math::float3 v21; // [esp+24h] [ebp-178h] BYREF
  vostok::math::float3 v22; // [esp+30h] [ebp-16Ch] BYREF
  float v23; // [esp+3Ch] [ebp-160h]
  float orbit_phi; // [esp+40h] [ebp-15Ch]
  vostok::particle::particle_action_orbit *v25; // [esp+44h] [ebp-158h]
  float orbit_tetha; // [esp+48h] [ebp-154h]
  vostok::math::float4x4 v27; // [esp+4Ch] [ebp-150h] BYREF
  vostok::math::float3 v28; // [esp+90h] [ebp-10Ch] BYREF
  vostok::math::float4x4 v29; // [esp+9Ch] [ebp-100h] BYREF
  _BYTE v30[64]; // [esp+DCh] [ebp-C0h] BYREF
  vostok::math::float4x4 v31; // [esp+11Ch] [ebp-80h] BYREF
  vostok::math::float4x4 v32; // [esp+15Ch] [ebp-40h] BYREF

  HIDWORD(v17) = a3;
  m_seed = P->m_seed;
  v25 = this;
  memset(&v21, 0, sizeof(v21));
  vostok::math::curve_line_ranged_xyz_float::evaluate(
    (vostok::math::curve_line_ranged_xyz_float *)this,
    (int)&this->m_spin_offset,
    0.0,
    &v22,
    0.0,
    &v21,
    m_seed,
    a2);
  v15 = P->m_seed;
  *(_QWORD *)&P->orbit_tetha = *(_QWORD *)&v22.x;
  memset(&v21, 0, sizeof(v21));
  vostok::math::curve_line_ranged_xyz_float::evaluate(v7, (int)&this->m_radius, 0.0, &v22, 0.0, &v21, v15, v18);
  orbit_phi = P->orbit_phi;
  orbit_tetha = P->orbit_tetha;
  v8 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(orbit_tetha));
  __libm_sse2_sin(v8);
  *(float *)v8.m128i_i32 = *(double *)v8.m128i_i64;
  v23 = *(float *)v8.m128i_i32;
  *(double *)v8.m128i_i64 = orbit_phi;
  __libm_sse2_cos(v17);
  *(float *)v8.m128i_i32 = *(double *)v8.m128i_i64;
  v21.x = (float)((float)(*(float *)v8.m128i_i32 * v23) * v22.x) + P->position.x;
  *(double *)v8.m128i_i64 = orbit_phi;
  __libm_sse2_sin(v8);
  *(float *)v8.m128i_i32 = *(double *)v8.m128i_i64;
  v21.y = (float)((float)(*(float *)v8.m128i_i32 * v23) * v22.y) + P->position.y;
  *(double *)v8.m128i_i64 = orbit_tetha;
  __libm_sse2_cos(v19);
  v16 = P->m_seed;
  *(float *)v8.m128i_i32 = *(double *)v8.m128i_i64;
  v21.z = (float)(*(float *)v8.m128i_i32 * v22.z) + P->position.z;
  memset(&v22, 0, sizeof(v22));
  p_m_rotation = (int)&v25->m_rotation;
  vostok::math::curve_line_ranged_xyz_float::evaluate(v10, (int)&v25->m_rotation, 0.0, &v28, 0.0, &v22, v16, v20);
  LODWORD(v22.x) = LODWORD(P->position.x) ^ _mask__NegFloat_;
  LODWORD(v22.y) = LODWORD(P->position.y) ^ _mask__NegFloat_;
  LODWORD(v22.z) = LODWORD(P->position.z) ^ _mask__NegFloat_;
  v11 = vostok::math::create_rotation(&v28, p_m_rotation, (int)v30);
  v12 = vostok::math::create_translation(&v22, &v31);
  vostok::math::mul4x3(v11, v12, &v29);
  v13 = vostok::math::create_translation(&P->position, &v32);
  vostok::math::mul4x3(v13, &v29, &v27);
  v22.x = (float)((float)((float)(v27.k.x * v21.z) + (float)(v27.j.x * v21.y)) + (float)(v27.i.x * v21.x)) + v27.c.x;
  v22.y = (float)((float)((float)(v27.k.y * v21.z) + (float)(v27.j.y * v21.y)) + (float)(v27.i.y * v21.x)) + v27.c.y;
  v22.z = (float)((float)((float)(v27.k.z * v21.z) + (float)(v27.j.z * v21.y)) + (float)(v27.i.z * v21.x)) + v27.c.z;
  P->position = v22;
}
