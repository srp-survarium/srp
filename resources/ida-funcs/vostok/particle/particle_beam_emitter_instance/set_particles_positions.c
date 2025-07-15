void __userpurge vostok::particle::particle_beam_emitter_instance::set_particles_positions(
        vostok::particle::particle_beam_emitter_instance *this@<ecx>,
        vostok::particle::base_particle *a2@<edi>,
        unsigned int a3@<esi>,
        unsigned int gen_new,
        char a5)
{
  float *v5; // eax
  unsigned int v6; // xmm0_4
  unsigned int v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  int v10; // eax
  const vostok::math::float3 *v11; // esi
  vostok::math::enum_evaluate_time_type v12; // edi
  int v13; // eax
  vostok::particle::particle_beam_emitter_instance *i; // ecx
  vostok::math::float3_pod *max_value; // [esp+4h] [ebp-40h]
  vostok::particle::base_particle *v16; // [esp+8h] [ebp-3Ch]
  unsigned int v17; // [esp+Ch] [ebp-38h]
  vostok::math::float3 v18; // [esp+14h] [ebp-30h] BYREF
  vostok::math::float3 v19; // [esp+20h] [ebp-24h] BYREF
  vostok::math::float3 v20; // [esp+2Ch] [ebp-18h] BYREF
  float v21; // [esp+38h] [ebp-Ch]
  float v22; // [esp+3Ch] [ebp-8h]
  float v23; // [esp+40h] [ebp-4h]
  vostok::particle::particle_beam_emitter_instance *v24; // [esp+50h] [ebp+Ch]

  if ( *(_DWORD *)(gen_new + 496) >= 2u )
  {
    if ( a5 )
      vostok::particle::particle_beam_emitter_instance::generate_offsets(this, gen_new);
    v17 = a3;
    v16 = a2;
    v21 = *(float *)(gen_new + 592);
    v22 = *(float *)(gen_new + 596);
    v23 = *(float *)(gen_new + 600);
    v20.x = vostok::particle::random_float(0.0, 1.0);
    v20.y = vostok::particle::random_float(0.0, 1.0);
    v20.z = vostok::particle::random_float(0.0, 1.0);
    v5 = *(float **)(gen_new + 624);
    *(float *)&v6 = v5[1] * v21;
    *(float *)&v7 = v5[2] * v22;
    v19.x = *v5 * v23;
    *(_QWORD *)&v19.elements[1] = __PAIR64__(v7, v6);
    v20 = *vostok::math::float3_pod::normalize_safe(max_value, &v19, &v20.x);
    v8 = (float)(v20.z * v22) - (float)(v20.y * v23);
    v9 = (float)(v20.x * v23) - (float)(v20.z * v21);
    v19.x = (float)((float)((float)(v20.y * v21) - (float)(v20.x * v22)) * v22) - (float)(v9 * v23);
    v18.z = (float)(v20.y * v21) - (float)(v20.x * v22);
    v18.x = v8;
    v18.y = v9;
    v19.y = (float)(v8 * v23) - (float)(v18.z * v21);
    v10 = *(_DWORD *)(gen_new + 496) / *(_DWORD *)(*(_DWORD *)(gen_new + 484) + 8);
    v11 = 0;
    v19.z = (float)(v9 * v21) - (float)(v8 * v22);
    v12 = v10;
    v24 = 0;
    do
    {
      v13 = *(_DWORD *)(gen_new + 412);
      for ( i = 0; v13 && i != v24; i = (vostok::particle::particle_beam_emitter_instance *)((char *)i + 1) )
        v13 = *(_DWORD *)(v13 + 208);
      if ( (unsigned int)v12 >= 2 )
        vostok::particle::particle_beam_emitter_instance::apply_noise(
          i,
          *(float *)&gen_new,
          v12,
          *(float *)&v11,
          gen_new,
          v11,
          &v18,
          &v19.x,
          (float *)v13,
          v12,
          v16,
          v17);
      v24 = (vostok::particle::particle_beam_emitter_instance *)((char *)v24 + v12);
      v11 = (const vostok::math::float3 *)((char *)v11 + 1);
    }
    while ( (unsigned int)v11 < *(_DWORD *)(*(_DWORD *)(gen_new + 484) + 8) );
  }
}
