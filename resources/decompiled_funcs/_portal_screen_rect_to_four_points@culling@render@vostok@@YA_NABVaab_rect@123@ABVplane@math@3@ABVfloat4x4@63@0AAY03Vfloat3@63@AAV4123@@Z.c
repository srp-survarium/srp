char __usercall vostok::render::culling::portal_screen_rect_to_four_points@<al>(
        const vostok::render::culling::aab_rect *portal_rect@<edx>,
        const vostok::render::culling::aab_rect *limiting_rect@<ecx>,
        vostok::render::culling::aab_rect *limited_rect@<edi>,
        vostok::math::plane *portal_plane,
        const vostok::math::float4x4 *inv_mat_vp,
        vostok::math::float3 (*io_points)[4])
{
  float y; // xmm7_4
  float x; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm5_4
  float v11; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm6_4
  float v28; // xmm2_4
  float v29; // xmm7_4
  float v30; // xmm7_4
  float v31; // xmm4_4
  float v32; // [esp+0h] [ebp-BCh]
  float v33; // [esp+4h] [ebp-B8h]
  float v34; // [esp+8h] [ebp-B4h]
  float v35; // [esp+8h] [ebp-B4h]
  float v36; // [esp+8h] [ebp-B4h]
  float v37; // [esp+Ch] [ebp-B0h]
  float v38; // [esp+Ch] [ebp-B0h]
  float v39; // [esp+10h] [ebp-ACh]
  float v40; // [esp+10h] [ebp-ACh]
  float v41; // [esp+18h] [ebp-A4h]
  float v42; // [esp+18h] [ebp-A4h]
  float v43; // [esp+1Ch] [ebp-A0h]
  float v44; // [esp+1Ch] [ebp-A0h]
  float v45; // [esp+1Ch] [ebp-A0h]
  float v46; // [esp+20h] [ebp-9Ch]
  float v47; // [esp+20h] [ebp-9Ch]
  float v48; // [esp+20h] [ebp-9Ch]
  float v49; // [esp+20h] [ebp-9Ch]
  float v50; // [esp+20h] [ebp-9Ch]
  float v51; // [esp+28h] [ebp-94h]
  float v52; // [esp+28h] [ebp-94h]
  float v53; // [esp+2Ch] [ebp-90h]
  float v54; // [esp+30h] [ebp-8Ch]
  float v55; // [esp+30h] [ebp-8Ch]
  float v56; // [esp+34h] [ebp-88h]
  float v57; // [esp+38h] [ebp-84h] BYREF
  float v58; // [esp+3Ch] [ebp-80h]
  float v59; // [esp+40h] [ebp-7Ch]
  float v60; // [esp+48h] [ebp-74h]
  float v61; // [esp+4Ch] [ebp-70h]
  float v62; // [esp+50h] [ebp-6Ch]
  float v63; // [esp+54h] [ebp-68h]
  float v64; // [esp+58h] [ebp-64h]
  vostok::math::float3 ws_near_rect[4]; // [esp+5Ch] [ebp-60h] BYREF
  vostok::math::float3 ws_far_rect[4]; // [esp+8Ch] [ebp-30h] BYREF

  if ( limiting_rect->max.x <= portal_rect->min.x )
    return 0;
  if ( portal_rect->max.x <= limiting_rect->min.x )
    return 0;
  if ( limiting_rect->max.y <= portal_rect->min.y )
    return 0;
  if ( portal_rect->max.y <= limiting_rect->min.y )
    return 0;
  *limited_rect = *vostok::render::culling::get_intersection_rect(limiting_rect, portal_rect, (int)&v57);
  y = limited_rect->min.y;
  x = limited_rect->min.x;
  v33 = limited_rect->max.y;
  v61 = limited_rect->max.x;
  v56 = y;
  v39 = x;
  if ( fabs((float)(v61 - x) * (float)(v33 - y)) < 0.0000099999997 )
    return 0;
  v9 = inv_mat_vp->j.x;
  v10 = inv_mat_vp->i.x;
  v60 = inv_mat_vp->k.x * 0.0;
  v57 = x;
  v11 = inv_mat_vp->j.y;
  v51 = inv_mat_vp->k.y * 0.0;
  v43 = (float)((float)((float)(inv_mat_vp->i.y * x) + (float)(v11 * y)) + v51) + inv_mat_vp->c.y;
  z = inv_mat_vp->j.z;
  v54 = inv_mat_vp->k.z * 0.0;
  v37 = inv_mat_vp->k.w * 0.0;
  v46 = (float)((float)((float)(inv_mat_vp->i.z * x) + (float)(z * y)) + v54) + inv_mat_vp->c.z;
  w = inv_mat_vp->j.w;
  v32 = *(float *)&clear_value
      / (float)((float)((float)((float)(inv_mat_vp->i.w * x) + (float)(w * y)) + v37) + inv_mat_vp->c.w);
  ws_near_rect[0].x = v32 * (float)((float)((float)((float)(v10 * x) + (float)(v9 * y)) + v60) + inv_mat_vp->c.x);
  ws_near_rect[0].y = v43 * v32;
  v14 = inv_mat_vp->c.x;
  ws_near_rect[0].z = v46 * v32;
  v58 = v33;
  v47 = (float)((float)((float)(inv_mat_vp->i.z * x) + (float)(v33 * z)) + v54) + inv_mat_vp->c.z;
  v34 = *(float *)&clear_value
      / (float)((float)((float)((float)(inv_mat_vp->i.w * x) + (float)(v33 * w)) + v37) + inv_mat_vp->c.w);
  ws_near_rect[1].y = v34
                    * (float)((float)((float)((float)(inv_mat_vp->i.y * x) + (float)(v33 * v11)) + v51) + inv_mat_vp->c.y);
  ws_near_rect[1].z = v34 * v47;
  v57 = v61;
  ws_near_rect[1].x = v34 * (float)((float)((float)(v10 * x) + (float)(v33 * v9)) + (float)(v60 + v14));
  v48 = (float)((float)((float)(z * v33) + (float)(v61 * inv_mat_vp->i.z)) + v54) + inv_mat_vp->c.z;
  v35 = *(float *)&clear_value
      / (float)((float)((float)((float)(w * v33) + (float)(v61 * inv_mat_vp->i.w)) + v37) + inv_mat_vp->c.w);
  ws_near_rect[2].y = v35
                    * (float)((float)((float)((float)(v11 * v33) + (float)(v61 * inv_mat_vp->i.y)) + v51)
                            + inv_mat_vp->c.y);
  ws_near_rect[2].z = v35 * v48;
  v57 = v61;
  ws_near_rect[2].x = v35 * (float)((float)((float)(v9 * v33) + (float)(v61 * v10)) + (float)(v60 + v14));
  v44 = (float)((float)((float)(v11 * v56) + (float)(v61 * inv_mat_vp->i.y)) + v51) + inv_mat_vp->c.y;
  v49 = (float)((float)((float)(z * v56) + (float)(v61 * inv_mat_vp->i.z)) + v54) + inv_mat_vp->c.z;
  v15 = *(float *)&clear_value
      / (float)((float)((float)((float)(w * v56) + (float)(v61 * inv_mat_vp->i.w)) + v37) + inv_mat_vp->c.w);
  ws_near_rect[3].x = v15 * (float)((float)((float)(v9 * v56) + (float)(v61 * v10)) + (float)(v60 + v14));
  ws_near_rect[3].z = v15 * v49;
  ws_near_rect[3].y = v15 * v44;
  v41 = (float)((float)((float)(v9 * v56) + (float)(v39 * v10)) + inv_mat_vp->c.x) + inv_mat_vp->k.x;
  v45 = (float)((float)((float)(v11 * v56) + (float)(v39 * inv_mat_vp->i.y)) + inv_mat_vp->c.y) + inv_mat_vp->k.y;
  v38 = inv_mat_vp->k.z;
  v16 = inv_mat_vp->c.w;
  v53 = inv_mat_vp->c.z;
  v17 = inv_mat_vp->i.w;
  v50 = (float)((float)((float)(z * v56) + (float)(v39 * inv_mat_vp->i.z)) + v38) + v53;
  v18 = inv_mat_vp->k.w;
  v62 = inv_mat_vp->j.w;
  v64 = v17;
  v19 = *(float *)&clear_value / (float)((float)((float)((float)(v62 * v56) + (float)(v39 * v17)) + v18) + v16);
  ws_far_rect[0].x = v41 * v19;
  v63 = v18;
  v20 = v39;
  v36 = v16;
  v21 = inv_mat_vp->k.x + inv_mat_vp->c.x;
  ws_far_rect[0].y = v19 * v45;
  ws_far_rect[0].z = v19 * v50;
  v22 = inv_mat_vp->j.x;
  v23 = (float)(v22 * v33) + (float)(v39 * v10);
  v40 = v21;
  v24 = v23 + v21;
  v42 = v20;
  v52 = inv_mat_vp->c.y;
  v25 = inv_mat_vp->k.y;
  v60 = inv_mat_vp->i.y;
  v55 = v25;
  v26 = inv_mat_vp->j.y;
  v27 = inv_mat_vp->i.z;
  v58 = (float)((float)((float)(v20 * v60) + (float)(v26 * v33)) + v55) + v52;
  v28 = inv_mat_vp->j.z;
  v59 = (float)((float)((float)(v42 * v27) + (float)(v28 * v33)) + v38) + v53;
  v29 = *(float *)&clear_value / (float)((float)((float)((float)(v62 * v33) + (float)(v42 * v64)) + v63) + v36);
  ws_far_rect[1].x = v24 * v29;
  ws_far_rect[1].y = v29 * v58;
  ws_far_rect[1].z = v29 * v59;
  v57 = v61;
  v30 = *(float *)&clear_value / (float)((float)((float)((float)(v62 * v33) + (float)(v61 * v64)) + v63) + v36);
  ws_far_rect[2].y = v30 * (float)((float)((float)((float)(v26 * v33) + (float)(v61 * v60)) + v55) + v52);
  ws_far_rect[2].z = v30 * (float)((float)((float)((float)(v61 * v27) + (float)(v28 * v33)) + v38) + v53);
  ws_far_rect[2].x = (float)((float)((float)(v22 * v33) + (float)(v61 * v10)) + v40) * v30;
  v31 = *(float *)&clear_value / (float)((float)((float)((float)(v61 * v64) + (float)(v62 * v56)) + v63) + v36);
  ws_far_rect[3].x = (float)((float)((float)(v22 * v56) + (float)(v61 * v10)) + v40) * v31;
  ws_far_rect[3].y = v31 * (float)((float)((float)((float)(v26 * v56) + (float)(v61 * v60)) + v55) + v52);
  ws_far_rect[3].z = v31 * (float)((float)((float)((float)(v28 * v56) + (float)(v61 * v27)) + v38) + v53);
  if ( !vostok::math::plane::intersect_segment(
          ws_near_rect,
          ws_far_rect,
          (vostok::math::float3 *)io_points,
          portal_plane)
    || !vostok::math::plane::intersect_segment(&ws_near_rect[1], &ws_far_rect[1], &(*io_points)[1], portal_plane)
    || !vostok::math::plane::intersect_segment(&ws_near_rect[2], &ws_far_rect[2], &(*io_points)[2], portal_plane)
    || !vostok::math::plane::intersect_segment(&ws_near_rect[3], &ws_far_rect[3], &(*io_points)[3], portal_plane) )
  {
    memmove((unsigned __int8 *)io_points, (unsigned __int8 *)ws_near_rect, 0x30u);
  }
  return 1;
}
