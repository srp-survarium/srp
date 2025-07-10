const vostok::animation::skeleton_bone *__thiscall vostok::animation::bone_matrices_computer::computed_local_bone_transform(
        vostok::animation::bone_matrices_computer *this,
        vostok::animation::bone_transform *result,
        const vostok::animation::skeleton_bone *bone,
        char **bone_mask,
        unsigned int animation_layer_id,
        unsigned int a6)
{
  float x; // esi
  void *v7; // esp
  float *v8; // ebx
  void *v9; // esp
  void *v10; // esp
  vostok::animation::bone_transform *v11; // edx
  float z; // edi
  float v13; // xmm4_4
  int v14; // esi
  _DWORD *v15; // ecx
  char *v16; // eax
  vostok::animation::bone_names *v17; // esi
  vostok::animation::bone_names *v18; // esi
  unsigned int v19; // eax
  vostok::animation::frame *p_f; // eax
  vostok::animation::frame *v21; // eax
  float v22; // ecx
  float v23; // edx
  __int64 v24; // xmm0_8
  int v25; // xmm0_4
  int v26; // eax
  stlp_std::pair<vostok::math::float3,float> *m_end; // eax
  float v28; // xmm0_4
  float v29; // ecx
  float v30; // xmm0_4
  stlp_std::pair<vostok::math::float3,float> *v31; // eax
  float v32; // edx
  float *v33; // eax
  float v34; // xmm1_4
  float *j; // ecx
  float v36; // xmm0_4
  const vostok::math::float4x4 *v37; // xmm2_4
  float v38; // xmm0_4
  float *v39; // ecx
  float v40; // xmm0_4
  float *k; // ecx
  float v42; // xmm1_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  float *v45; // eax
  float v46; // xmm3_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  vostok::math::float3 *v53; // esi
  vostok::math::quaternion *v54; // eax
  const vostok::animation::skeleton_bone *v55; // edx
  __int64 v56; // xmm0_8
  unsigned int z_low; // eax
  _BYTE v59[16]; // [esp+8h] [ebp-114h] BYREF
  vostok::animation::frame v60; // [esp+18h] [ebp-104h] BYREF
  vostok::animation::frame f; // [esp+40h] [ebp-DCh] BYREF
  vostok::animation::current_frame_position frame_pos; // [esp+64h] [ebp-B8h] BYREF
  _QWORD v63[4]; // [esp+88h] [ebp-94h] BYREF
  float v64; // [esp+A8h] [ebp-74h]
  vostok::math::quaternion do_normalization; // [esp+ACh] [ebp-70h] BYREF
  __int64 v66; // [esp+BCh] [ebp-60h] BYREF
  int v67; // [esp+C4h] [ebp-58h]
  __int64 v68; // [esp+CCh] [ebp-50h]
  __int64 v69; // [esp+D4h] [ebp-48h]
  __int64 v70; // [esp+DCh] [ebp-40h]
  __int64 v71; // [esp+E4h] [ebp-38h]
  float v72; // [esp+ECh] [ebp-30h]
  int i; // [esp+F0h] [ebp-2Ch]
  vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > v74; // [esp+F4h] [ebp-28h] BYREF
  vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > transforms; // [esp+FCh] [ebp-20h] BYREF
  float *v76; // [esp+104h] [ebp-18h]
  _BYTE v77[12]; // [esp+108h] [ebp-14h]
  float v78; // [esp+114h] [ebp-8h]

  x = result->rotation.x;
  v7 = alloca(16 * LODWORD(x));
  v8 = (float *)v59;
  v76 = (float *)v59;
  v9 = alloca(16 * LODWORD(x));
  v74.m_begin = (stlp_std::pair<vostok::math::float3,float> *)v59;
  v74.m_end = (stlp_std::pair<vostok::math::float3,float> *)v59;
  v10 = alloca(16 * LODWORD(x));
  v11 = result;
  z = result->translation.z;
  v13 = 0.0;
  v14 = LODWORD(z) + 180 * LODWORD(x);
  transforms.m_begin = (stlp_std::pair<vostok::math::float3,float> *)v59;
  transforms.m_end = (stlp_std::pair<vostok::math::float3,float> *)v59;
  for ( i = v14; LODWORD(z) != v14; LODWORD(z) += 180 )
  {
    v15 = *(_DWORD **)(LODWORD(z) + 172);
    if ( v15[9] == LODWORD(v11->translation.x)
      && *(float *)(LODWORD(z) + 104) != 0.0
      && v15[18] == a6
      && (animation_layer_id & v15[19]) != 0 )
    {
      v16 = *bone_mask;
      v17 = *(vostok::animation::bone_names **)(LODWORD(z) + 84);
      memset(&frame_pos, 0, sizeof(frame_pos));
      if ( vostok::animation::bone_names::bone_index(v17, v16) == -1 )
      {
        v21 = identity_frame(&v60);
        v22 = v21->scale.z;
        v63[0] = *(_QWORD *)&v21->translation.x;
        v63[1] = *(_QWORD *)&v21->channels[2];
        v63[2] = *(_QWORD *)&v21->channels[4];
        v63[3] = *(_QWORD *)&v21->channels[6];
        v64 = v22;
        p_f = (vostok::animation::frame *)v63;
      }
      else
      {
        v18 = *(vostok::animation::bone_names **)(LODWORD(z) + 84);
        v19 = vostok::animation::bone_names::bone_index(v18, *bone_mask);
        vostok::animation::evaluate_frame(
          (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)((char *)&v18[9 * v19] + v18[2].m_bone_count),
          &f,
          0.0,
          *(float *)(LODWORD(z) + 108) * 30.0,
          &frame_pos);
        p_f = &f;
      }
      v23 = p_f->scale.z;
      v68 = *(_QWORD *)&p_f->translation.x;
      v69 = *(_QWORD *)&p_f->channels[2];
      v24 = *(_QWORD *)&p_f->channels[4];
      v66 = v68;
      v70 = v24;
      v71 = *(_QWORD *)&p_f->channels[6];
      v25 = *(_DWORD *)(LODWORD(z) + 104);
      v72 = v23;
      v67 = v69;
      if ( v8 )
      {
        v26 = v67;
        *(_QWORD *)v8 = v66;
        *((_DWORD *)v8 + 2) = v26;
        *((_DWORD *)v8 + 3) = v25;
      }
      m_end = v74.m_end;
      v28 = *(float *)(LODWORD(z) + 104);
      *(_QWORD *)v77 = __PAIR64__(v70, HIDWORD(v69));
      v8 += 4;
      *(_DWORD *)&v77[8] = HIDWORD(v70);
      if ( v74.m_end )
      {
        v29 = *(float *)&v77[8];
        *(_QWORD *)&v74.m_end->first.x = *(_QWORD *)v77;
        m_end->first.z = v29;
        m_end->second = v28;
      }
      v30 = *(float *)(LODWORD(z) + 104);
      *(_QWORD *)&do_normalization.x = v71;
      v74.m_end = m_end + 1;
      v31 = transforms.m_end;
      do_normalization.z = v72;
      if ( transforms.m_end )
      {
        v32 = do_normalization.z;
        *(_QWORD *)&transforms.m_end->first.x = *(_QWORD *)&do_normalization.x;
        v31->first.z = v32;
        v31->second = v30;
      }
      v13 = 0.0;
      v11 = result;
      v14 = i;
      transforms.m_end = v31 + 1;
    }
  }
  v33 = v76;
  if ( !a6 )
  {
    v34 = 0.0;
    for ( j = v76; j != v8; v34 = v36 + v34 )
    {
      v36 = j[3];
      j += 4;
    }
    v37 = clear_value;
    if ( fabs(v34 - *(float *)&clear_value) >= 0.0000099999997 )
    {
      if ( v76 != v8 )
      {
        v38 = *(float *)&clear_value / v34;
        v39 = v76 + 3;
        do
        {
          *v39 = v38 * *v39;
          v39 += 4;
        }
        while ( v39 - 3 != v8 );
      }
      v40 = 0.0;
      for ( k = v33; k != v8; v40 = v42 + v40 )
      {
        v42 = k[3];
        k += 4;
      }
      if ( !LOBYTE(v11->rotation.vector.elements[2]) && fabs(*(float *)&v37 - v40) >= 0.5 )
        LOBYTE(v11->rotation.vector.elements[2]) = 1;
    }
  }
  v43 = 0.0;
  v44 = 0.0;
  *(_DWORD *)&v77[4] = 0;
  *(_DWORD *)&v77[8] = 0;
  v78 = 0.0;
  if ( v33 != v8 )
  {
    v45 = v33 + 3;
    do
    {
      v46 = *v45;
      v47 = *(v45 - 3);
      v48 = *(v45 - 2);
      v49 = *(v45 - 1);
      v45 += 4;
      v50 = (float)(v47 * v46) + v13;
      v51 = (float)(v48 * v46) + v43;
      v52 = (float)(v49 * v46) + v44;
      v13 = v50;
      v43 = v51;
      v44 = v52;
    }
    while ( v45 - 3 != v8 );
    v78 = v52;
    *(float *)&v77[8] = v51;
    *(float *)&v77[4] = v50;
  }
  v53 = mix_scales(&transforms, (float *)&v66 + 1);
  v54 = mix_rotations(&v74, &do_normalization, a6 < 2);
  v55 = (const vostok::animation::skeleton_bone *)LODWORD(v78);
  *(_QWORD *)&bone->m_id = *(_QWORD *)&v77[4];
  *(_QWORD *)&bone->m_children_end = *(_QWORD *)&v54->x;
  v56 = *(_QWORD *)&v54->vector.elements[2];
  z_low = LODWORD(v53->z);
  *(_QWORD *)&bone[1].m_id = v56;
  *(_QWORD *)&bone[1].m_children_begin = *(_QWORD *)&v53->x;
  bone[1].m_mask = z_low;
  bone->m_children_begin = v55;
  LOBYTE(bone[2].m_id) = 1;
  return bone;
}
