void __userpurge vostok::particle::particle_beam_emitter_instance::apply_noise(
        vostok::particle::particle_beam_emitter_instance *this@<ecx>,
        float a2@<ebx>,
        vostok::math::enum_evaluate_time_type a3@<edi>,
        float a4@<esi>,
        unsigned int beam_index,
        const vostok::math::float3 *up_vector,
        const vostok::math::float3 *right_vector,
        float *P,
        float *num_particles,
        unsigned int i,
        vostok::particle::base_particle *alpha,
        unsigned int p)
{
  int v12; // edx
  float y; // xmm1_4
  float z; // xmm2_4
  int v16; // eax
  float *v17; // ecx
  float v18; // xmm3_4
  int v19; // eax
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  int v26; // xmm4_4
  int v27; // xmm1_4
  int v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm6_4
  int v31; // ecx
  void *v32; // edi
  unsigned int v33; // esi
  vostok::math::curve_line_points<vostok::math::float3_pod,0> *v34; // ecx
  vostok::math::curve_line_points<vostok::math::float3_pod,0> *v35; // ecx
  unsigned int num_points; // edi
  int v37; // esi
  float *v38; // edx
  float *v39; // esi
  float *v40; // edi
  bool v41; // cf
  float *p_x; // eax
  float v43; // xmm2_4
  float v44; // xmm3_4
  _DWORD *v45; // edi
  vostok::math::float3_pod *v46; // eax
  float v47; // xmm0_4
  float *v48; // eax
  float *v49; // edi
  float v50; // [esp+0h] [ebp-6Ch]
  vostok::math::enum_evaluate_time_type v51; // [esp+10h] [ebp-5Ch]
  float v52; // [esp+14h] [ebp-58h]
  float v53; // [esp+18h] [ebp-54h]
  _DWORD v54[14]; // [esp+1Ch] [ebp-50h] BYREF
  float v55; // [esp+58h] [ebp-14h]
  vostok::math::float3_pod v56; // [esp+60h] [ebp-Ch] BYREF
  int v57; // [esp+6Ch] [ebp+0h]
  int v58; // [esp+70h] [ebp+4h]
  int v59; // [esp+74h] [ebp+8h]
  float v60; // [esp+78h] [ebp+Ch]
  float v61; // [esp+7Ch] [ebp+10h]
  float v62; // [esp+80h] [ebp+14h]
  float v63; // [esp+84h] [ebp+18h]
  float v64; // [esp+88h] [ebp+1Ch]
  float v65; // [esp+8Ch] [ebp+20h]
  float v66; // [esp+90h] [ebp+24h]
  float v67; // [esp+94h] [ebp+28h]
  float v68; // [esp+98h] [ebp+2Ch]
  vostok::math::float3 v69; // [esp+9Ch] [ebp+30h]
  float x; // [esp+A8h] [ebp+3Ch]
  float v71; // [esp+ACh] [ebp+40h]
  float v72; // [esp+B0h] [ebp+44h]
  int v73; // [esp+B4h] [ebp+48h]
  unsigned int v74; // [esp+B8h] [ebp+4Ch]
  float v75; // [esp+BCh] [ebp+50h]
  float v76; // [esp+C0h] [ebp+54h]
  float v77; // [esp+C4h] [ebp+58h]
  float v78; // [esp+C8h] [ebp+5Ch]
  unsigned int v79; // [esp+D4h] [ebp+68h]
  float v80; // [esp+D4h] [ebp+68h]
  unsigned int v81; // [esp+D8h] [ebp+6Ch]
  unsigned int j; // [esp+D8h] [ebp+6Ch]

  v12 = 48 * (_DWORD)up_vector;
  *(float *)&v74 = 0.0;
  v53 = a2;
  v79 = 0;
  v52 = a4;
  x = 0.0;
  v71 = 0.0;
  v72 = 0.0;
  v57 = 0;
  v58 = 0;
  v59 = 0;
  v51 = a3;
  v73 = 48 * (_DWORD)up_vector;
  do
  {
    v75 = *(float *)&v74;
    v63 = *(float *)(beam_index + 604);
    v75 = (double)v74 * 0.071428575;
    v64 = *(float *)(beam_index + 608);
    v65 = *(float *)(beam_index + 612);
    v66 = *(float *)(beam_index + 568);
    v67 = *(float *)(beam_index + 572);
    v68 = *(float *)(beam_index + 576);
    v76 = (float)(v66 * (float)(s_bm_current_air_resistance - v75)) + (float)(v63 * v75);
    v77 = (float)(v67 * (float)(s_bm_current_air_resistance - v75)) + (float)(v64 * v75);
    v78 = (float)(v68 * (float)(s_bm_current_air_resistance - v75)) + (float)(v65 * v75);
    if ( *(float *)&v74 != 0.0 && v74 != 14 )
    {
      y = right_vector->y;
      z = right_vector->z;
      v16 = *(_DWORD *)(beam_index + 624);
      v69 = *right_vector;
      v17 = (float *)(v16 + 12 * (v74 + 15 * (_DWORD)up_vector));
      v18 = *v17;
      v19 = *(_DWORD *)(beam_index + 616);
      v20 = s_bm_current_air_resistance - *v17;
      v21 = v69.x * *v17;
      v55 = v69.y * *v17;
      v22 = *(float *)(v19 + 44);
      v23 = (float)((float)((float)(COERCE_FLOAT(LODWORD(y) ^ _mask__NegFloat_) * v20) + v55) * v22) + v77;
      v24 = (float)((float)((float)(COERCE_FLOAT(LODWORD(z) ^ _mask__NegFloat_) * v20) + (float)(v69.z * v18)) * v22)
          + v78;
      v25 = (float)((float)(v20 * COERCE_FLOAT(LODWORD(v69.x) ^ _mask__NegFloat_)) + v21) * v22;
      v26 = *(_DWORD *)P;
      v77 = v23;
      v27 = *((_DWORD *)P + 1);
      v78 = v24;
      v28 = *((_DWORD *)P + 2);
      v60 = *P;
      v61 = P[1];
      v76 = v25 + v76;
      v29 = v17[1];
      v62 = P[2];
      v56.y = v61 * v29;
      v30 = *(float *)(v19 + 44);
      v76 = (float)((float)((float)((float)(s_bm_current_air_resistance - v29) * COERCE_FLOAT(v26 ^ _mask__NegFloat_))
                          + (float)(v60 * v29))
                  * v30)
          + v76;
      v77 = (float)((float)((float)(COERCE_FLOAT(v27 ^ _mask__NegFloat_) * (float)(s_bm_current_air_resistance - v29))
                          + (float)(v61 * v29))
                  * v30)
          + v77;
      v78 = (float)((float)((float)(COERCE_FLOAT(v28 ^ _mask__NegFloat_) * (float)(s_bm_current_air_resistance - v29))
                          + (float)(v62 * v29))
                  * v30)
          + v78;
    }
    *(float *)v54 = v76;
    *(float *)&v54[1] = v77;
    *(float *)&v54[2] = v78;
    *(float *)&v54[3] = v76;
    *(float *)&v54[4] = v77;
    *(float *)&v54[5] = v78;
    v31 = *(_DWORD *)(beam_index + 620);
    v54[6] = v57;
    v54[7] = v58;
    v54[8] = v59;
    *(float *)&v54[9] = x;
    *(float *)&v54[10] = v71;
    *(float *)&v54[11] = v72;
    v32 = (void *)(v79 + *(_DWORD *)(v31 + v12 + 32));
    ++v74;
    *(float *)&v54[12] = v75;
    v54[13] = 1;
    qmemcpy(v32, v54, 0x38u);
    v33 = v79;
    v79 += 56;
    v34 = *(vostok::math::curve_line_points<vostok::math::float3_pod,0> **)(*(_DWORD *)(beam_index + 620) + v12 + 32);
    *(_DWORD *)((char *)&v34[1].curve_time_max + v33) = 1;
  }
  while ( v79 < 0x348 );
  vostok::math::curve_line_points<vostok::math::float3_pod,0>::recalculate_ranges(
    v34,
    v12 + *(_DWORD *)(beam_index + 620));
  v35 = (vostok::math::curve_line_points<vostok::math::float3_pod,0> *)(v73 + *(_DWORD *)(beam_index + 620));
  v81 = 0;
  num_points = v35->num_points;
  if ( num_points )
  {
    while ( 1 )
    {
      v37 = (int)&v35->points.pointer[v81];
      v38 = (float *)(v37 + 24);
      v39 = (float *)(v37 + 36);
      if ( !v81 )
        break;
      v41 = v81 < num_points - 1;
      v40 = v38;
      if ( !v41 )
        goto LABEL_11;
      p_x = &v35->points.pointer[v81].upper_value.x;
      v43 = (float)(p_x[1] - *(p_x - 13)) + (float)(p_x[15] - p_x[1]);
      v44 = (float)(p_x[2] - *(p_x - 12)) + (float)(p_x[16] - p_x[2]);
      v76 = (float)((float)(*p_x - *(p_x - 14)) + (float)(p_x[14] - *p_x)) * 0.5;
      v77 = v43 * 0.5;
      v78 = v44 * 0.5;
      *v38 = v76;
      v38[1] = v77;
      v38[2] = v78;
      *v39 = v76;
      v39[1] = v77;
      v39[2] = v78;
LABEL_12:
      ++v81;
      num_points = v35->num_points;
      if ( v81 >= num_points )
        goto LABEL_13;
    }
    v40 = v39;
LABEL_11:
    *v40 = 0.0;
    v45 = v40 + 1;
    *v45 = 0;
    v45[1] = 0;
    goto LABEL_12;
  }
LABEL_13:
  for ( j = 0; j < i; *v49 = v72 )
  {
    v80 = (float)(i - 1);
    v50 = (double)j / v80;
    v46 = vostok::math::curve_line_points<vostok::math::float3_pod,0>::evaluate(
            v35,
            v73 + *(_DWORD *)(beam_index + 620),
            &v56,
            v50,
            *(vostok::math::float3_pod *)(beam_index + 568),
            v51,
            v52,
            v53);
    ++j;
    x = v46->x;
    v71 = v46->y;
    v47 = v46->z;
    v48 = (float *)*((_DWORD *)num_particles + 52);
    v72 = v47;
    num_particles[11] = x;
    num_particles[12] = v71;
    v49 = num_particles + 13;
    num_particles = v48;
  }
}
