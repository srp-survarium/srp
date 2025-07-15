vostok::math::float4x4 *__thiscall vostok::animation::bone_matrices_computer::get_object_transform(
        vostok::animation::bone_matrices_computer *this,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *a3)
{
  float w; // edi
  void *v4; // esp
  vostok::math::float3 **v5; // ebx
  void *v6; // esp
  void *v7; // esp
  float z; // eax
  float v9; // xmm4_4
  stlp_std::pair<vostok::math::float3,float> *v10; // esi
  int v11; // ebx
  float v12; // eax
  float v13; // xmm1_4
  vostok::math::float4x4 *v14; // ecx
  vostok::math::float3 *angles_xyz; // eax
  stlp_std::pair<vostok::math::float3,float> *m_end; // ecx
  __int64 v17; // xmm0_8
  float v18; // eax
  float v19; // xmm1_4
  vostok::math::float3 **v20; // eax
  __int64 v21; // xmm0_8
  vostok::math::float3 *v22; // xmm1_4
  vostok::math::float3 *v23; // ecx
  const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *v24; // ecx
  vostok::math::quaternion *v25; // ecx
  float v26; // xmm0_4
  float v27; // eax
  vostok::math::float4x4 *v28; // ecx
  vostok::math::float3 *v29; // eax
  stlp_std::pair<vostok::math::float3,float> *v30; // ecx
  __int64 v31; // xmm0_8
  float v32; // eax
  float v33; // xmm1_4
  float v34; // xmm6_4
  float v35; // xmm1_4
  float v36; // xmm5_4
  float v37; // xmm0_4
  float v38; // xmm4_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // xmm5_4
  float v42; // xmm0_4
  float v43; // xmm6_4
  float v44; // xmm2_4
  vostok::math::float3 *v45; // xmm0_4
  float v46; // edx
  float v47; // xmm5_4
  float v48; // xmm6_4
  float *v49; // eax
  float v50; // xmm3_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  vostok::math::quaternion *v57; // eax
  vostok::math::float3 *v58; // esi
  const vostok::math::float4x4 *v59; // eax
  vostok::math::float3 *v61[3]; // [esp+8h] [ebp-1A0h] BYREF
  vostok::math::float4x4 v62; // [esp+14h] [ebp-194h] BYREF
  vostok::math::float4x4 right; // [esp+60h] [ebp-148h] BYREF
  vostok::math::float4x4 resulta; // [esp+A0h] [ebp-108h] BYREF
  float v65[3]; // [esp+E0h] [ebp-C8h] BYREF
  vostok::math::float4x4 dst; // [esp+ECh] [ebp-BCh] BYREF
  vostok::math::quaternion q; // [esp+12Ch] [ebp-7Ch] BYREF
  vostok::math::float3 position; // [esp+13Ch] [ebp-6Ch] BYREF
  vostok::math::quaternion do_normalization; // [esp+148h] [ebp-60h] BYREF
  vostok::math::float3 **v70; // [esp+158h] [ebp-50h]
  int v71; // [esp+15Ch] [ebp-4Ch]
  vostok::math::float3 v72; // [esp+160h] [ebp-48h] BYREF
  float v73; // [esp+16Ch] [ebp-3Ch]
  vostok::math::float3 **v74; // [esp+174h] [ebp-34h]
  vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > transforms; // [esp+178h] [ebp-30h] BYREF
  vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > v76; // [esp+180h] [ebp-28h] BYREF
  vostok::math::float3 v77; // [esp+188h] [ebp-20h] BYREF
  vostok::math::quaternion v78; // [esp+194h] [ebp-14h] BYREF
  float v79; // [esp+1A4h] [ebp-4h]

  w = result->i.w;
  v4 = alloca(16 * LODWORD(w));
  v5 = v61;
  v70 = v61;
  v74 = v61;
  v6 = alloca(16 * LODWORD(w));
  transforms.m_begin = (stlp_std::pair<vostok::math::float3,float> *)v61;
  transforms.m_end = (stlp_std::pair<vostok::math::float3,float> *)v61;
  v7 = alloca(16 * LODWORD(w));
  z = result->i.z;
  v9 = 0.0;
  v10 = (stlp_std::pair<vostok::math::float3,float> *)v61;
  v76.m_begin = (stlp_std::pair<vostok::math::float3,float> *)v61;
  v76.m_end = (stlp_std::pair<vostok::math::float3,float> *)v61;
  v73 = z;
  v71 = LODWORD(z) + 180 * LODWORD(w);
  if ( LODWORD(z) != v71 )
  {
    v11 = LODWORD(z) + 52;
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)(v11 + 120) + 36) == LODWORD(result->i.x)
        && vostok::animation::cubic_spline_skeleton_animation::animation_type(*(vostok::animation::cubic_spline_skeleton_animation **)(v11 + 32)) == animation_type_full
        && (*(_BYTE *)(*(_DWORD *)(v11 + 120) + 76) & 1) != 0 )
      {
        if ( *(_BYTE *)(v11 + 64) )
        {
          v12 = *(float *)(v11 + 24);
          v13 = *(float *)(v11 + 52);
          if ( v10 )
          {
            *(_QWORD *)&v10->first.x = *(_QWORD *)(v11 + 16);
            v10->first.z = v12;
            v10->second = v13;
          }
          v76.m_end = v10 + 1;
          memset(&position, 0, sizeof(position));
          vostok::math::create_matrix((const vostok::math::quaternion *)(v11 - 12), &position);
          angles_xyz = vostok::math::float4x4::get_angles_xyz(v14, v61[0]);
          m_end = transforms.m_end;
          v17 = *(_QWORD *)&angles_xyz->x;
          v18 = angles_xyz->z;
          v19 = *(float *)(v11 + 52);
          if ( transforms.m_end )
          {
            *(_QWORD *)&transforms.m_end->first.x = v17;
            m_end->first.z = v18;
            m_end->second = v19;
          }
          v20 = v74;
          v21 = *(_QWORD *)(v11 + 4);
          v22 = *(vostok::math::float3 **)(v11 + 52);
          transforms.m_end = m_end + 1;
          v23 = *(vostok::math::float3 **)(v11 + 12);
          if ( v74 )
          {
            *(_QWORD *)v74 = v21;
            v20[2] = v23;
            v20[3] = v22;
          }
        }
        else
        {
          v24 = (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)(*(_DWORD *)(v11 + 32) + *(_DWORD *)(*(_DWORD *)(v11 + 32) + 20));
          memset(&resulta.lines[1].elements[3], 0, 36);
          vostok::animation::evaluate_frame(
            v24,
            (vostok::animation::frame *)&right.lines[1].elements[3],
            v9,
            *(float *)(v11 + 56) * 30.0,
            (vostok::animation::current_frame_position *)&resulta.lines[1].elements[3]);
          vostok::animation::bone_transform::bone_transform(
            (const vostok::animation::frame *)&right.lines[1].elements[3],
            v25,
            (vostok::animation::bone_transform *)&dst.lines[1].elements[1],
            (bool)v61[0]);
          vostok::math::conjugate((const vostok::math::quaternion *)(v11 - 12), &v78);
          v77.x = dst.c.x / *(float *)(v11 + 16);
          v77.y = dst.c.y / *(float *)(v11 + 20);
          v77.z = dst.c.z / *(float *)(v11 + 24);
          v26 = *(float *)(v11 + 52);
          if ( v10 )
          {
            v27 = v77.z;
            *(_QWORD *)&v10->first.x = *(_QWORD *)&v77.x;
            v10->first.z = v27;
            v10->second = v26;
          }
          q.w = (float)((float)((float)(v78.w * dst.k.w) - (float)(v78.x * dst.k.x)) - (float)(v78.y * dst.k.y))
              - (float)(v78.z * dst.k.z);
          q.x = (float)((float)((float)(dst.k.z * v78.y) + (float)(dst.k.x * v78.w)) + (float)(v78.x * dst.k.w))
              - (float)(v78.z * dst.k.y);
          q.z = (float)((float)((float)(dst.k.z * v78.w) + (float)(dst.k.y * v78.x)) - (float)(v78.y * dst.k.x))
              + (float)(v78.z * dst.k.w);
          v76.m_end = v10 + 1;
          q.y = (float)((float)((float)(dst.k.y * v78.w) - (float)(dst.k.z * v78.x)) + (float)(v78.z * dst.k.x))
              + (float)(v78.y * dst.k.w);
          memset(&v72, 0, sizeof(v72));
          vostok::math::create_matrix(&q, &v72);
          v29 = vostok::math::float4x4::get_angles_xyz(v28, v61[0]);
          v30 = transforms.m_end;
          v31 = *(_QWORD *)&v29->x;
          v32 = v29->z;
          v33 = *(float *)(v11 + 52);
          if ( transforms.m_end )
          {
            *(_QWORD *)&transforms.m_end->first.x = v31;
            v30->first.z = v32;
            v30->second = v33;
          }
          v34 = *(float *)v11;
          v35 = dst.j.y - *(float *)(v11 + 4);
          v36 = *(float *)(v11 - 12);
          v37 = dst.j.z - *(float *)(v11 + 8);
          v38 = *(float *)(v11 - 8);
          v39 = dst.j.w - *(float *)(v11 + 12);
          v79 = *(float *)(v11 - 4);
          v40 = (float)((float)((float)(v34 * 0.0) - (float)(v35 * v36)) - (float)(v37 * v38)) - (float)(v39 * v79);
          v9 = (float)((float)((float)(v39 * *(float *)(v11 - 8)) + (float)(v35 * v34)) + (float)(v36 * 0.0))
             - (float)(v37 * v79);
          v41 = (float)((float)((float)(v37 * v34) - (float)(v39 * *(float *)(v11 - 12))) + (float)(v35 * v79))
              + (float)(*(float *)(v11 - 8) * 0.0);
          v42 = (float)((float)((float)(v37 * *(float *)(v11 - 12)) + (float)(v39 * *(float *)v11))
                      - (float)(v35 * *(float *)(v11 - 8)))
              + (float)(v79 * 0.0);
          do_normalization.x = (float)((float)((float)(v78.z * v41) + (float)(v78.x * v40)) + (float)(v78.w * v9))
                             - (float)(v78.y * v42);
          transforms.m_end = v30 + 1;
          v20 = v74;
          v43 = (float)((float)(v78.y * v40) - (float)(v78.z * v9)) + (float)(v78.x * v42);
          v44 = v78.w * v42;
          v45 = *(vostok::math::float3 **)(v11 + 52);
          do_normalization.y = v43 + (float)(v78.w * v41);
          do_normalization.z = (float)((float)((float)(v78.z * v40) + (float)(v78.y * v9)) - (float)(v78.x * v41)) + v44;
          if ( v74 )
          {
            v46 = do_normalization.z;
            *(_QWORD *)v74 = *(_QWORD *)&do_normalization.x;
            *((float *)v20 + 2) = v46;
            v20[3] = v45;
          }
        }
        v10 = v76.m_end;
        v74 = v20 + 4;
      }
      v11 += 180;
      LODWORD(v73) += 180;
    }
    while ( LODWORD(v73) != v71 );
    v9 = 0.0;
    v5 = v70;
  }
  v47 = 0.0;
  v48 = 0.0;
  memset(&v77, 0, sizeof(v77));
  if ( v5 != v74 )
  {
    v49 = (float *)(v5 + 3);
    do
    {
      v50 = *v49;
      v51 = *(v49 - 3);
      v52 = *(v49 - 2);
      v53 = *(v49 - 1);
      v49 += 4;
      v54 = (float)(v51 * v50) + v9;
      v55 = (float)(v52 * v50) + v47;
      v56 = (float)(v53 * v50) + v48;
      v9 = v54;
      v47 = v55;
      v48 = v56;
    }
    while ( v49 - 3 != (float *)v74 );
    *(_QWORD *)&v77.elements[1] = __PAIR64__(LODWORD(v56), LODWORD(v55));
    v77.x = v54;
  }
  v57 = mix_rotations(&transforms, &do_normalization, 1);
  memset(&v72, 0, sizeof(v72));
  vostok::math::create_matrix(v57, &v72);
  v58 = mix_scales(&v76, v65);
  memset((int)&dst, 0, sizeof(dst));
  dst.i.x = v58->x;
  dst.j.y = v58->y;
  dst.k.z = v58->z;
  LODWORD(dst.c.w) = clear_value;
  vostok::math::mul4x3(&resulta, &dst, &right);
  v59 = vostok::math::create_translation(&v62, &v77);
  vostok::math::mul4x3(a3, &resulta, v59);
  return a3;
}
