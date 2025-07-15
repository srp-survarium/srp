void __userpurge vostok::sound::sound_scene::calculate_3d_pan(
        vostok::sound::sound_scene *this@<ecx>,
        long double a2@<esi:edi>,
        const vostok::sound::panning_lut *panning_lut,
        const vostok::sound::sound_instance_proxy_internal *proxy,
        const vostok::math::float3 *graph_position,
        vostok::math::float3 *distance,
        float attenuation,
        float *channels_result,
        float *lp_filter_result)
{
  float z; // eax
  float v10; // xmm0_4
  vostok::math::half_pod *v11; // ecx
  vostok::math::half_pod *v12; // ecx
  float v13; // xmm0_4
  vostok::math::half_pod *v14; // ecx
  vostok::math::half_pod *v15; // ecx
  vostok::math::half_pod *v16; // ecx
  vostok::math::half_pod *v17; // ecx
  float v18; // xmm0_4
  float y; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  vostok::math::float3 *listenet_position; // eax
  vostok::sound::sound_instance_proxy_internal *v25; // ecx
  vostok::math::float3 *volumetric_position; // esi
  vostok::math::half_pod *v27; // ecx
  vostok::math::half_pod *v28; // ecx
  vostok::math::float3 *v29; // eax
  float v30; // xmm5_4
  float v31; // xmm3_4
  unsigned int v32; // xmm1_4
  unsigned int v33; // xmm2_4
  vostok::math::float3_pod *v34; // ecx
  vostok::math::float3_pod *v35; // ecx
  double v36; // xmm0_8
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  bool v40; // cc
  double v41; // xmm0_8
  vostok::math::float3_pod *v42; // ecx
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  unsigned int v47; // eax
  float v48; // xmm2_4
  float v49; // xmm1_4
  float *v50; // eax
  unsigned int i; // ecx
  vostok::sound::sound_scene *v52; // ecx
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm0_4
  vostok::sound::sound_instance_proxy_internal *v56; // ecx
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm0_4
  float v60; // xmm0_4
  float v61; // xmm3_4
  float v62; // xmm4_4
  float v63; // xmm0_4
  unsigned int v64; // xmm2_4
  float v65; // xmm0_4
  float v67; // [esp+20h] [ebp-A8h]
  float v68; // [esp+20h] [ebp-A8h]
  float v69; // [esp+20h] [ebp-A8h]
  float v70; // [esp+20h] [ebp-A8h]
  float v71; // [esp+24h] [ebp-A4h]
  float v72; // [esp+24h] [ebp-A4h]
  float v73; // [esp+24h] [ebp-A4h]
  vostok::math::float3 listener_position; // [esp+28h] [ebp-A0h] BYREF
  vostok::math::float3 v75; // [esp+34h] [ebp-94h] BYREF
  float v76; // [esp+40h] [ebp-88h]
  float v77; // [esp+44h] [ebp-84h]
  vostok::math::float3 im; // [esp+48h] [ebp-80h] BYREF
  vostok::math::float3 v79; // [esp+54h] [ebp-74h] BYREF
  float v80; // [esp+60h] [ebp-68h]
  float v81; // [esp+64h] [ebp-64h]
  vostok::math::float3 result; // [esp+68h] [ebp-60h] BYREF
  float v83; // [esp+80h] [ebp-48h]
  float v84; // [esp+90h] [ebp-38h]
  float v85; // [esp+A0h] [ebp-28h]
  vostok::math::float3 v86; // [esp+BCh] [ebp-Ch] BYREF

  z = graph_position[10].z;
  v67 = FLOAT_360_0;
  v71 = FLOAT_360_0;
  v10 = 0.0;
  v76 = 0.0;
  v81 = z;
  if ( LODWORD(z) == 1 )
  {
    v67 = FLOAT_60_0;
    v71 = FLOAT_90_0;
    v10 = c_anim_center;
    v76 = c_anim_center;
  }
  vostok::math::half_pod::operator float((vostok::math::half_pod *)this, (unsigned __int16 *)&panning_lut->m_table[73]);
  v77 = v10;
  vostok::math::half_pod::operator float(v11, (unsigned __int16 *)&panning_lut->m_table[73] + 1);
  v80 = v10;
  vostok::math::half_pod::operator float(v12, (unsigned __int16 *)&panning_lut->m_table[74]);
  listener_position.z = v10;
  v13 = s_bm_current_air_resistance / fsqrt((float)((float)(v77 * v77) + (float)(v80 * v80)) + (float)(v10 * v10));
  v79.x = v13 * v77;
  v79.y = v80 * v13;
  v79.z = listener_position.z * v13;
  vostok::math::half_pod::operator float(v14, (unsigned __int16 *)&panning_lut->m_table[75]);
  v80 = v13;
  vostok::math::half_pod::operator float(v15, (unsigned __int16 *)&panning_lut->m_table[75] + 1);
  v77 = v13;
  vostok::math::half_pod::operator float(v16, (unsigned __int16 *)&panning_lut->m_table[76]);
  listener_position.z = v13;
  v18 = fsqrt((float)((float)(v80 * v80) + (float)(v77 * v77)) + (float)(v13 * v13));
  y = v79.y;
  listener_position.x = (float)(s_bm_current_air_resistance / v18) * v80;
  listener_position.y = v77 * (float)(s_bm_current_air_resistance / v18);
  listener_position.z = listener_position.z * (float)(s_bm_current_air_resistance / v18);
  v20 = (float)(listener_position.z * v79.y) - (float)(listener_position.y * v79.z);
  im.y = (float)(v79.z * listener_position.x) - (float)(listener_position.z * v79.x);
  im.x = v20;
  im.z = (float)(listener_position.y * v79.x) - (float)(v79.y * listener_position.x);
  v21 = s_bm_current_air_resistance / fsqrt((float)((float)(im.z * im.z) + (float)(im.y * im.y)) + (float)(v20 * v20));
  v79.y = im.y * v21;
  LODWORD(v22) = LODWORD(v79.x) ^ _mask__NegFloat_;
  LODWORD(v23) = LODWORD(v79.z) ^ _mask__NegFloat_;
  v79.x = v21 * v20;
  v79.z = im.z * v21;
  v83 = v22;
  LODWORD(v84) = LODWORD(y) ^ _mask__NegFloat_;
  v85 = v23;
  memset(&v75, 0, sizeof(v75));
  if ( v81 == 0.0 )
    goto LABEL_7;
  if ( LODWORD(v81) == 1 )
  {
    vostok::math::half_pod::operator float(v17, (unsigned __int16 *)&graph_position[6]);
    v80 = 0.0;
    vostok::math::half_pod::operator float(v27, (unsigned __int16 *)graph_position[6].elements + 1);
    v77 = 0.0;
    vostok::math::half_pod::operator float(v28, (unsigned __int16 *)&graph_position[6].elements[1]);
    memset(&im, 0, sizeof(im));
    memset(&v75, 0, sizeof(v75));
LABEL_7:
    volumetric_position = distance;
    goto LABEL_8;
  }
  listenet_position = vostok::sound::sound_scene::get_listenet_position(
                        (vostok::sound::sound_scene *)v17,
                        (int)panning_lut,
                        0.0,
                        &v86);
  volumetric_position = vostok::sound::sound_instance_proxy_internal::get_volumetric_position(
                          v25,
                          (int)graph_position,
                          &result,
                          listenet_position);
LABEL_8:
  im = *volumetric_position;
  v29 = vostok::sound::sound_scene::get_listenet_position(
          (vostok::sound::sound_scene *)v17,
          (int)panning_lut,
          0.0,
          &result);
  v30 = im.z - v29->z;
  v31 = im.x - v29->x;
  *(float *)&v32 = (float)((float)(v30 * listener_position.z) + (float)((float)(im.y - v29->y) * listener_position.y))
                 + (float)(v31 * listener_position.x);
  *(float *)&v33 = (float)((float)(v83 * v31) + (float)(v85 * v30)) + (float)(v84 * (float)(im.y - v29->y));
  im.x = (float)((float)(v30 * v79.z) + (float)((float)(im.y - v29->y) * v79.y)) + (float)(v31 * v79.x);
  *(_QWORD *)&im.elements[1] = __PAIR64__(v33, v32);
  result.x = (float)((float)(v75.z * v79.z) + (float)(v75.y * v79.y)) + (float)(v75.x * v79.x);
  result.y = (float)((float)(v75.z * listener_position.z) + (float)(v75.y * listener_position.y))
           + (float)(v75.x * listener_position.x);
  result.z = (float)((float)(v83 * v75.x) + (float)(v85 * v75.z)) + (float)(v84 * v75.y);
  v75 = result;
  LODWORD(listener_position.x) = LODWORD(im.x) ^ _mask__NegFloat_;
  LODWORD(listener_position.y) = v32 ^ _mask__NegFloat_;
  LODWORD(listener_position.z) = v33 ^ _mask__NegFloat_;
  vostok::math::float3_pod::normalize_safe(v34, &listener_position, &listener_position.x);
  vostok::math::float3_pod::normalize_safe(v35, &v75, &v75.x);
  v36 = (float)((float)((float)(listener_position.z * v75.z) + (float)(listener_position.y * v75.y))
              + (float)(listener_position.x * v75.x));
  __libm_sse2_acos();
  *(float *)&v36 = v36;
  v37 = *(float *)&v36 * 57.295776;
  if ( v37 < v67 || v71 < v37 )
  {
    v40 = v37 <= v71;
    v39 = s_bm_current_air_resistance;
    if ( v40 )
      v72 = s_bm_current_air_resistance;
    else
      v72 = (float)(v76 - s_bm_current_air_resistance) + s_bm_current_air_resistance;
  }
  else
  {
    v38 = (float)(v37 - v67) / (float)(v71 - v67);
    v72 = (float)((float)(v76 - s_bm_current_air_resistance) * v38) + s_bm_current_air_resistance;
    v39 = (float)(v38 * 0.0) + s_bm_current_air_resistance;
  }
  v68 = v39;
  v41 = listener_position.z;
  __libm_sse2_acos();
  v43 = s_bm_current_air_resistance;
  *(float *)&v41 = v41;
  v44 = *(float *)&v41 * 57.295776;
  if ( s_bm_current_air_resistance > attenuation )
    v44 = v44 * attenuation;
  if ( v44 <= 90.0 )
    v45 = v68;
  else
    v45 = (float)(s_bm_current_air_resistance - (float)((float)((float)(v44 - 90.0) * 0.011098779) * 0.25)) * v68;
  v46 = v72;
  v69 = v72;
  v80 = v45;
  if ( s_bm_current_air_resistance <= v72 )
  {
    v46 = s_bm_current_air_resistance;
    v69 = s_bm_current_air_resistance;
  }
  if ( v46 <= 0.0 )
    v69 = 0.0;
  if ( attenuation > s_bm_current_air_resistance )
    v43 = attenuation;
  if ( v43 > 0.0 )
  {
    memset(&listener_position, 0, sizeof(listener_position));
    vostok::math::float3_pod::normalize_safe(v42, &im, &listener_position.x);
  }
  v47 = vostok::sound::cart_to_lut_position(COERCE_FLOAT(LODWORD(im.z) ^ _mask__NegFloat_), im.x);
  v48 = fsqrt((float)(im.z * im.z) + (float)(im.x * im.x));
  v49 = sqrt(0.5);
  v50 = (float *)(&proxy->__vftable + 9 * v47 + 1);
  v73 = 0.0;
  v76 = 0.0;
  for ( i = 0; i < 2; ++i )
  {
    if ( i )
      v76 = (float)((float)((float)(v50[i] - v49) * v48) + v49) * v69;
    else
      v73 = (float)((float)((float)(*v50 - v49) * v48) + v49) * v69;
  }
  *(_QWORD *)&v75.x = __PAIR64__(LODWORD(v73), LODWORD(v76));
  __libm_sse2_cos(a2);
  v53 = fsqrt(v80);
  v54 = 0.0;
  v70 = 0.0;
  if ( v53 <= 0.0099999998 )
    v53 = FLOAT_0_0099999998;
  v55 = s_bm_current_air_resistance;
  if ( v53 < 0.99989998 )
  {
    v54 = (float)((float)(s_bm_current_air_resistance - (float)(v53 * (float)0.7123793063520574))
                - fsqrt(
                    (float)((float)((float)(s_bm_current_air_resistance - (float)0.7123793063520574) * v53) * 2.0)
                  - (float)((float)((float)(s_bm_current_air_resistance
                                          - (float)((float)0.7123793063520574 * (float)0.7123793063520574))
                                  * v53)
                          * v53)))
        / (float)(s_bm_current_air_resistance - v53);
    v70 = v54;
  }
  v77 = v54;
  if ( LODWORD(v81) != 2 )
    goto LABEL_46;
  vostok::sound::sound_scene::get_listenet_position(
    v52,
    (int)panning_lut,
    s_bm_current_air_resistance,
    &listener_position);
  vostok::sound::sound_instance_proxy_internal::get_volumetric_position(
    v56,
    (int)graph_position,
    &v79,
    &listener_position);
  v57 = graph_position[11].y;
  v58 = fsqrt(
          (float)((float)((float)(listener_position.z - v79.z) * (float)(listener_position.z - v79.z))
                + (float)((float)(listener_position.y - v79.y) * (float)(listener_position.y - v79.y)))
        + (float)((float)(listener_position.x - v79.x) * (float)(listener_position.x - v79.x)));
  if ( v58 <= v57 )
  {
    v60 = v58 / v57;
    v61 = v60 * v76;
    v62 = v60 * v73;
    v63 = s_bm_current_air_resistance - v60;
    *(float *)&v64 = v63 + v61;
    v40 = (float)(v63 + v61) <= s_bm_current_air_resistance;
    v65 = v63 + v62;
    *(_QWORD *)&v75.x = __PAIR64__(LODWORD(v65), v64);
    if ( !v40 )
      v75.x = s_bm_current_air_resistance;
    if ( v65 > s_bm_current_air_resistance )
      v75.y = s_bm_current_air_resistance;
    if ( vostok::math::float3_pod::is_similar(&listener_position, &v79, 0.0000099999997) )
      v77 = 0.0;
    v55 = s_bm_current_air_resistance;
LABEL_46:
    v59 = v55 - v77;
    *(_QWORD *)channels_result = *(_QWORD *)&v75.x;
    goto LABEL_47;
  }
  *channels_result = v76;
  channels_result[1] = v73;
  v59 = s_bm_current_air_resistance - v70;
LABEL_47:
  *lp_filter_result = v59;
}
