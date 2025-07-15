vostok::animation::bone_transform *__thiscall vostok::animation::bone_matrices_computer::computed_local_bone_transform(
        vostok::animation::bone_matrices_computer *this,
        vostok::animation::bone_transform *result,
        vostok::animation::bone_transform *bone,
        unsigned int bone_mask,
        unsigned int animation_layer_id,
        int a7)
{
  float x; // esi
  void *v8; // esp
  void *v9; // esp
  float z; // ebx
  int v11; // esi
  _DWORD *v12; // ecx
  int v13; // xmm0_4
  int v14; // xmm0_4
  vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *v15; // ecx
  float v16; // xmm0_4
  __int64 v17; // kr00_8
  float v18; // xmm2_4
  float i; // eax
  float v20; // xmm1_4
  float v21; // xmm1_4
  float *v22; // eax
  float v23; // xmm1_4
  int j; // eax
  float v25; // xmm2_4
  vostok::math::quaternion *v26; // ebx
  vostok::math::float3 *v27; // esi
  vostok::animation::bone_transform *v28; // eax
  vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *v29; // [esp-4h] [ebp-A8h]
  _BYTE v30[16]; // [esp+0h] [ebp-A4h] BYREF
  vostok::animation::current_frame_position frame_pos; // [esp+10h] [ebp-94h] BYREF
  vostok::math::quaternion v32; // [esp+34h] [ebp-70h] BYREF
  vostok::animation::frame f; // [esp+44h] [ebp-60h] BYREF
  __int64 v34; // [esp+68h] [ebp-3Ch] BYREF
  float v35; // [esp+70h] [ebp-34h]
  int v36; // [esp+74h] [ebp-30h]
  vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > v37; // [esp+78h] [ebp-2Ch] BYREF
  __int128 v38; // [esp+84h] [ebp-20h] BYREF
  stlp_std::pair<vostok::math::float3,float> value; // [esp+94h] [ebp-10h] BYREF

  x = result->rotation.x;
  v8 = alloca(16 * LODWORD(x));
  LODWORD(value.first.x) = v30;
  LODWORD(value.first.y) = v30;
  LODWORD(value.first.z) = &v30[16 * LODWORD(x)];
  v9 = alloca(16 * LODWORD(x));
  z = result->translation.z;
  v37.m_begin = (stlp_std::pair<vostok::math::float3,float> *)v30;
  v37.m_end = (stlp_std::pair<vostok::math::float3,float> *)v30;
  v37.m_max_end = (stlp_std::pair<vostok::math::float3,float> *)LODWORD(value.first.z);
  v11 = LODWORD(z) + 176 * LODWORD(x);
  while ( LODWORD(z) != v11 )
  {
    v12 = *(_DWORD **)(LODWORD(z) + 168);
    if ( v12[9] == LODWORD(result->translation.x)
      && *(float *)(LODWORD(z) + 104) != 0.0
      && v12[18] == a7
      && (animation_layer_id & v12[19]) != 0 )
    {
      memset(&frame_pos, 0, sizeof(frame_pos));
      vostok::animation::evaluate_frame(
        (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)(*(_DWORD *)(LODWORD(z) + 84) + *(_DWORD *)(*(_DWORD *)(LODWORD(z) + 84) + 20) + 72 * *(_DWORD *)(**(_DWORD **)(LODWORD(z) + 84) + 72 * *(_DWORD *)(bone_mask + 20) + *(_DWORD *)(LODWORD(z) + 84) + 68)),
        channel_scale_x,
        *(float *)(LODWORD(z) + 108) * 30.0,
        &f,
        &frame_pos);
      v13 = *(_DWORD *)(LODWORD(z) + 104);
      v34 = *(_QWORD *)&f.translation.x;
      v35 = f.translation.z;
      v36 = v13;
      vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float>>::push_back(v29, &value, (float *)&v34);
      v14 = *(_DWORD *)(LODWORD(z) + 104);
      *(vostok::math::float3_pod *)&v38 = f.rotation;
      HIDWORD(v38) = v14;
      vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float>>::push_back(
        v15,
        (const stlp_std::pair<vostok::math::float3,float> *)&v37,
        (float *)&v38);
    }
    LODWORD(z) += 176;
  }
  v16 = s_bm_current_air_resistance;
  if ( !a7 )
  {
    v17 = *(_QWORD *)&value.first.x;
    v18 = 0.0;
    for ( i = value.first.x; LODWORD(i) != LODWORD(value.first.y); v18 = v20 + v18 )
    {
      v20 = *(float *)(LODWORD(i) + 12);
      LODWORD(i) += 16;
    }
    if ( fabs(v18 - s_bm_current_air_resistance) >= 0.0000099999997 )
    {
      if ( LODWORD(value.first.x) != LODWORD(value.first.y) )
      {
        v21 = s_bm_current_air_resistance / v18;
        v22 = (float *)(LODWORD(value.first.x) + 12);
        do
        {
          *v22 = *v22 * v21;
          v22 += 4;
        }
        while ( v22 - 3 != (float *)HIDWORD(v17) );
      }
      v23 = 0.0;
      for ( j = v17; j != HIDWORD(v17); v23 = v25 + v23 )
      {
        v25 = *(float *)(j + 12);
        j += 16;
      }
      if ( !LOBYTE(result->rotation.vector.elements[2]) && fabs(v16 - v23) >= 0.5 )
        LOBYTE(result->rotation.vector.elements[2]) = 1;
    }
  }
  *((float *)&v38 + 1) = v16;
  *((float *)&v38 + 2) = v16;
  *((float *)&v38 + 3) = v16;
  v26 = mix_rotations(&v37, &v32, a7 == 0);
  v27 = mix_translations(
          (const vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *)&value,
          (vostok::math::float3 *)((char *)&v34 + 4));
  v28 = bone;
  bone->translation = *v27;
  bone->rotation = *v26;
  bone->scale = *(vostok::math::float3 *)((char *)&v38 + 4);
  bone->visibility = 1;
  return v28;
}
