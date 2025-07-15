vostok::math::float4x4 *__thiscall vostok::animation::bone_matrices_computer::get_object_transform(
        vostok::animation::bone_matrices_computer *this,
        vostok::math::float4x4 *result,
        vostok::math::float4x4 *a4)
{
  int v4; // edi
  void *v5; // esp
  float z; // ebx
  int v7; // esi
  int v8; // eax
  vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *v9; // ecx
  int v10; // xmm0_4
  vostok::math::float3 *v11; // eax
  float v12; // xmm0_4
  int v13; // xmm0_4
  vostok::math::float3 *v14; // eax
  vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *v16; // [esp-4h] [ebp-94h]
  _BYTE v17[12]; // [esp+0h] [ebp-90h] BYREF
  vostok::animation::current_frame_position frame_pos; // [esp+Ch] [ebp-84h] BYREF
  vostok::animation::frame f; // [esp+30h] [ebp-60h] BYREF
  vostok::math::float3 v20; // [esp+54h] [ebp-3Ch] BYREF
  int v21; // [esp+60h] [ebp-30h]
  _DWORD v22[4]; // [esp+64h] [ebp-2Ch] BYREF
  vostok::math::float3 v23; // [esp+74h] [ebp-1Ch] BYREF
  int i; // [esp+80h] [ebp-10h]
  stlp_std::pair<vostok::math::float3,float> value; // [esp+84h] [ebp-Ch] BYREF

  v4 = 16 * LODWORD(result->i.w);
  v5 = alloca(v4);
  z = result->i.z;
  v7 = LODWORD(z) + 176 * LODWORD(result->i.w);
  LODWORD(value.first.x) = v17;
  LODWORD(value.first.y) = v17;
  LODWORD(value.first.z) = &v17[v4];
  for ( i = v7; LODWORD(z) != i; LODWORD(z) += 176 )
  {
    v8 = *(_DWORD *)(LODWORD(z) + 168);
    if ( *(_DWORD *)(v8 + 36) == LODWORD(result->i.x) )
    {
      v9 = *(vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > **)(LODWORD(z) + 84);
      if ( !v9[2].m_begin && (*(_BYTE *)(v8 + 76) & 1) != 0 )
      {
        if ( *(_BYTE *)(LODWORD(z) + 116) )
        {
          v10 = *(_DWORD *)(LODWORD(z) + 104);
          v22[0] = *(_DWORD *)(LODWORD(z) + 56);
          v22[1] = *(_DWORD *)(LODWORD(z) + 60);
          v22[2] = *(_DWORD *)(LODWORD(z) + 64);
          v22[3] = v10;
          v11 = (vostok::math::float3 *)v22;
        }
        else
        {
          v12 = *(float *)(LODWORD(z) + 108) * 30.0;
          memset(&frame_pos, 0, sizeof(frame_pos));
          vostok::animation::evaluate_frame(
            (const vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1> > *)(*(_DWORD *)(LODWORD(z) + 84) + *(_DWORD *)(*(_DWORD *)(LODWORD(z) + 84) + 20)),
            channel_rotation_x,
            v12,
            &f,
            &frame_pos);
          v23.x = f.translation.x - *(float *)(LODWORD(z) + 56);
          v23.y = f.translation.y - *(float *)(LODWORD(z) + 60);
          v23.z = f.translation.z - *(float *)(LODWORD(z) + 64);
          v13 = *(_DWORD *)(LODWORD(z) + 104);
          v20 = v23;
          v9 = v16;
          v21 = v13;
          v11 = &v20;
        }
        vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float>>::push_back(v9, &value, &v11->x);
      }
    }
  }
  v14 = mix_translations((const vostok::buffer_vector<stlp_std::pair<vostok::math::float3,float> > *)&value, &v23);
  vostok::math::create_translation(v14, a4);
  return a4;
}
