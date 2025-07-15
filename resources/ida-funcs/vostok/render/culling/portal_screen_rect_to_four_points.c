char __usercall vostok::render::culling::portal_screen_rect_to_four_points@<al>(
        const vostok::math::float4x4 *inv_mat_vp@<eax>,
        const vostok::render::culling::aab_rect *limiting_rect@<ecx>,
        const vostok::render::culling::aab_rect *portal_rect,
        vostok::math::plane *portal_plane,
        vostok::math::float3 (*io_points)[4],
        vostok::render::culling::aab_rect *limited_rect)
{
  float x; // xmm1_4
  vostok::math::float2 *p_max; // edi
  float v9; // xmm0_4
  float v10; // xmm2_4
  bool v11; // cc
  float *v12; // esi
  float *v14; // ecx
  float y; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm5_4
  float z; // xmm4_4
  float v27; // xmm6_4
  float v28; // xmm5_4
  float w; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm6_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  float v34; // xmm6_4
  float v35; // xmm6_4
  float v36; // xmm6_4
  float v37; // xmm6_4
  float v38; // xmm1_4
  unsigned int v39; // xmm5_4
  unsigned int v40; // xmm1_4
  float v41; // xmm6_4
  float v42; // xmm1_4
  float v43; // xmm5_4
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm4_4
  float v48; // xmm5_4
  float v49; // xmm1_4
  unsigned int v50; // xmm2_4
  unsigned int v51; // xmm1_4
  float v52; // xmm4_4
  float v53; // xmm2_4
  float v54; // xmm3_4
  float v55; // xmm6_4
  float v56; // xmm1_4
  float v57; // xmm7_4
  float v58; // xmm6_4
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm2_4
  float v62; // xmm0_4
  vostok::math::float3 v63; // [esp+0h] [ebp-BCh] BYREF
  vostok::math::float3 v64; // [esp+Ch] [ebp-B0h] BYREF
  vostok::math::float3 v65; // [esp+18h] [ebp-A4h] BYREF
  vostok::math::float3 v66; // [esp+24h] [ebp-98h] BYREF
  vostok::math::float3 v67; // [esp+30h] [ebp-8Ch] BYREF
  vostok::math::float3 v68; // [esp+3Ch] [ebp-80h] BYREF
  vostok::math::float3 v69; // [esp+48h] [ebp-74h] BYREF
  vostok::math::float3 v70; // [esp+54h] [ebp-68h] BYREF
  float v71; // [esp+60h] [ebp-5Ch] BYREF
  float v72; // [esp+64h] [ebp-58h]
  float v73; // [esp+68h] [ebp-54h]
  float v74; // [esp+70h] [ebp-4Ch]
  float v75; // [esp+74h] [ebp-48h]
  float v76; // [esp+78h] [ebp-44h]
  float v77; // [esp+7Ch] [ebp-40h]
  float v78; // [esp+80h] [ebp-3Ch]
  float *v79; // [esp+84h] [ebp-38h]
  float v80; // [esp+88h] [ebp-34h]
  float v81; // [esp+8Ch] [ebp-30h]
  float v82; // [esp+90h] [ebp-2Ch]
  float v83; // [esp+94h] [ebp-28h]
  float v84; // [esp+98h] [ebp-24h]
  float v85; // [esp+9Ch] [ebp-20h]
  vostok::render::culling::aab_rect v86; // [esp+A0h] [ebp-1Ch]
  float v87; // [esp+B0h] [ebp-Ch]
  float v88; // [esp+B4h] [ebp-8h]
  float v89; // [esp+B8h] [ebp-4h]
  float *p_y; // [esp+C4h] [ebp+8h]
  float v91; // [esp+C4h] [ebp+8h]

  x = portal_rect->min.x;
  p_max = &limiting_rect->max;
  if ( limiting_rect->max.x <= portal_rect->min.x )
    return 0;
  v9 = limiting_rect->min.x;
  v10 = portal_rect->max.x;
  LODWORD(v85) = &portal_rect->max;
  if ( v10 <= v9 )
    return 0;
  v11 = limiting_rect->max.y <= portal_rect->min.y;
  p_y = &portal_rect->min.y;
  v79 = &limiting_rect->max.y;
  if ( v11 )
    return 0;
  v12 = &limiting_rect->min.y;
  if ( portal_rect->max.y <= limiting_rect->min.y )
    return 0;
  if ( v9 <= x )
    limiting_rect = portal_rect;
  v86.min.x = limiting_rect->min.x;
  if ( *v12 <= *p_y )
    v12 = p_y;
  v86.min.y = *v12;
  if ( *(float *)LODWORD(v85) <= p_max->x )
    p_max = (vostok::math::float2 *)LODWORD(v85);
  v14 = v79;
  v86.max.x = p_max->x;
  if ( portal_rect->max.y <= *v79 )
    v14 = &portal_rect->max.y;
  v86.max.y = *v14;
  *limited_rect = v86;
  y = limited_rect->min.y;
  v16 = limited_rect->min.x;
  v91 = limited_rect->max.y;
  v78 = limited_rect->max.x;
  v85 = fabs((float)(v78 - v16) * (float)(v91 - y));
  v81 = y;
  v87 = v16;
  if ( v85 < 0.0000099999997 )
    return 0;
  v17 = inv_mat_vp->j.x;
  v18 = (float)(inv_mat_vp->k.x * 0.0) + inv_mat_vp->c.x;
  v19 = inv_mat_vp->i.x * v16;
  v71 = v16;
  v20 = inv_mat_vp->k.y;
  v86.min.x = (float)(v19 + (float)(v17 * y)) + v18;
  v21 = inv_mat_vp->i.y * v16;
  v22 = v20 * 0.0;
  v88 = v18;
  v23 = inv_mat_vp->j.y;
  v24 = (float)(v21 + (float)(v23 * y)) + v22;
  v25 = inv_mat_vp->i.z * v16;
  v89 = v22;
  z = inv_mat_vp->j.z;
  v86.min.y = v24 + inv_mat_vp->c.y;
  v84 = inv_mat_vp->k.z * 0.0;
  v27 = inv_mat_vp->i.w * v16;
  v28 = (float)((float)(v25 + (float)(z * y)) + v84) + inv_mat_vp->c.z;
  v83 = inv_mat_vp->k.w * 0.0;
  v86.max.x = v28;
  w = inv_mat_vp->j.w;
  v30 = (float)((float)(v27 + (float)(w * y)) + v83) + inv_mat_vp->c.w;
  v67.x = (float)(s_bm_current_air_resistance / v30) * v86.min.x;
  v31 = s_bm_current_air_resistance / v30;
  v67.z = v31 * v86.max.x;
  v67.y = v31 * v86.min.y;
  v86.min.x = (float)((float)(v17 * v91) + (float)(inv_mat_vp->i.x * v87)) + v88;
  v86.min.y = (float)((float)((float)(v23 * v91) + (float)(inv_mat_vp->i.y * v87)) + v89) + inv_mat_vp->c.y;
  v86.max.x = (float)((float)((float)(z * v91) + (float)(inv_mat_vp->i.z * v87)) + v84) + inv_mat_vp->c.z;
  v32 = s_bm_current_air_resistance
      / (float)((float)((float)((float)(w * v91) + (float)(inv_mat_vp->i.w * v87)) + v83) + inv_mat_vp->c.w);
  v68.x = v32 * v86.min.x;
  v68.z = v32 * v86.max.x;
  v68.y = v32 * v86.min.y;
  v86.min.x = (float)((float)(v17 * v91) + (float)(inv_mat_vp->i.x * v78)) + v88;
  v86.min.y = (float)((float)((float)(v23 * v91) + (float)(inv_mat_vp->i.y * v78)) + v89) + inv_mat_vp->c.y;
  v86.max.x = (float)((float)((float)(z * v91) + (float)(inv_mat_vp->i.z * v78)) + v84) + inv_mat_vp->c.z;
  v33 = s_bm_current_air_resistance
      / (float)((float)((float)((float)(w * v91) + (float)(inv_mat_vp->i.w * v78)) + v83) + inv_mat_vp->c.w);
  v69.x = v33 * v86.min.x;
  v69.y = v33 * v86.min.y;
  v69.z = v33 * v86.max.x;
  v34 = inv_mat_vp->i.x;
  v82 = v17 * v81;
  v80 = v34;
  v86.min.x = (float)((float)(v17 * v81) + (float)(v78 * v34)) + v88;
  v35 = inv_mat_vp->i.y;
  v88 = v23 * v81;
  v86.min.y = (float)((float)((float)(v23 * v81) + (float)(v78 * v35)) + v89) + inv_mat_vp->c.y;
  v36 = inv_mat_vp->i.z;
  v89 = z * v81;
  v37 = (float)((float)((float)(z * v81) + (float)(v78 * v36)) + v84) + inv_mat_vp->c.z;
  v38 = s_bm_current_air_resistance
      / (float)((float)((float)((float)(w * v81) + (float)(v78 * inv_mat_vp->i.w)) + v83) + inv_mat_vp->c.w);
  v70.x = v38 * v86.min.x;
  *(float *)&v39 = v38 * v86.min.y;
  *(float *)&v40 = v38 * v37;
  v41 = inv_mat_vp->k.z;
  *(_QWORD *)&v70.elements[1] = __PAIR64__(v40, v39);
  v42 = inv_mat_vp->i.y;
  v43 = inv_mat_vp->c.z;
  v86.min.x = (float)((float)((float)(v17 * v81) + (float)(v87 * v80)) + inv_mat_vp->c.x) + inv_mat_vp->k.x;
  v86.min.y = (float)((float)((float)(v23 * v81) + (float)(v87 * v42)) + inv_mat_vp->c.y) + inv_mat_vp->k.y;
  v77 = v43;
  v82 = v41;
  v44 = inv_mat_vp->c.w;
  v45 = inv_mat_vp->k.w;
  v46 = (float)((float)(z * v81) + (float)(v87 * inv_mat_vp->i.z)) + v41;
  v74 = inv_mat_vp->i.w;
  v47 = v46 + v43;
  v48 = inv_mat_vp->j.w;
  v76 = v44;
  v75 = v45;
  v49 = s_bm_current_air_resistance / (float)((float)((float)((float)(v74 * v87) + (float)(v48 * v81)) + v45) + v44);
  v63.x = v49 * v86.min.x;
  *(float *)&v50 = v49 * v86.min.y;
  *(float *)&v51 = v49 * v47;
  v52 = inv_mat_vp->j.x;
  *(_QWORD *)&v63.elements[1] = __PAIR64__(v51, v50);
  v53 = v87;
  v54 = inv_mat_vp->c.x + inv_mat_vp->k.x;
  v55 = inv_mat_vp->i.y;
  v56 = (float)(v87 * v80) + (float)(v52 * v91);
  v89 = inv_mat_vp->c.y;
  v84 = inv_mat_vp->k.y;
  v83 = inv_mat_vp->j.y;
  *(float *)&v79 = v55;
  v87 = v87 * v55;
  v57 = inv_mat_vp->j.z;
  v86.min.y = (float)((float)(v87 + (float)(v83 * v91)) + v84) + v89;
  v58 = inv_mat_vp->i.z;
  v88 = v57;
  v85 = v58;
  v87 = v53 * v58;
  v86.max.x = (float)((float)((float)(v53 * v58) + (float)(v57 * v91)) + v82) + v77;
  v59 = s_bm_current_air_resistance / (float)((float)((float)((float)(v53 * v74) + (float)(v48 * v91)) + v75) + v76);
  v64.x = (float)(v56 + v54) * v59;
  v60 = v59 * v86.min.y;
  v86.min.y = v91;
  v64.z = v59 * v86.max.x;
  v64.y = v60;
  v72 = (float)((float)((float)(v78 * *(float *)&v79) + (float)(v83 * v91)) + v84) + v89;
  v73 = (float)((float)((float)(v78 * v58) + (float)(v57 * v91)) + v82) + v77;
  v61 = s_bm_current_air_resistance / (float)((float)((float)((float)(v78 * v74) + (float)(v48 * v91)) + v75) + v76);
  v65.x = (float)((float)((float)(v78 * v80) + (float)(v52 * v91)) + v54) * v61;
  v65.y = v61 * v72;
  v65.z = v61 * v73;
  v62 = s_bm_current_air_resistance / (float)((float)((float)((float)(v78 * v74) + (float)(v48 * v81)) + v75) + v76);
  v66.x = v62 * (float)((float)((float)(v78 * v80) + (float)(v52 * v81)) + v54);
  v66.y = v62 * (float)((float)((float)((float)(v78 * *(float *)&v79) + (float)(v83 * v81)) + v84) + v89);
  v66.z = v62 * (float)((float)((float)((float)(v78 * v58) + (float)(v57 * v81)) + v82) + v77);
  if ( !vostok::math::plane::intersect_segment(&v67, &v63, portal_plane, (vostok::math::float3 *)io_points)
    || !vostok::math::plane::intersect_segment(&v68, &v64, portal_plane, &(*io_points)[1])
    || !vostok::math::plane::intersect_segment(&v69, &v65, portal_plane, &(*io_points)[2])
    || !vostok::math::plane::intersect_segment(&v70, &v66, portal_plane, &(*io_points)[3]) )
  {
    stlp_std::priv::__copy_trivial((unsigned __int8 *)&v67, (unsigned __int8 *)&v71, (unsigned __int8 *)io_points);
  }
  return 1;
}
