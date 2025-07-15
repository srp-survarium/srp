vostok::math::float4x4 *__thiscall vostok::animation::bone_matrices_computer::computed_local_bone_matrix(
        vostok::animation::bone_matrices_computer *this,
        vostok::animation::bone_transform *result,
        vostok::math::float4x4 *bone,
        vostok::animation::bone_matrices_computer *bone_mask,
        unsigned int animation_layer_id)
{
  void *v5; // esp
  unsigned int v6; // edi
  float *i; // esi
  const vostok::animation::skeleton_bone *v8; // eax
  char v9; // dl
  float *p_w; // ecx
  float *v11; // eax
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm5_4
  float v16; // xmm7_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  const vostok::math::float4x4 *v21; // eax
  _QWORD v23[2]; // [esp+0h] [ebp-110h] BYREF
  vostok::math::float4x4 left; // [esp+10h] [ebp-100h] BYREF
  vostok::math::float4x4 dst; // [esp+50h] [ebp-C0h] BYREF
  vostok::math::float4x4 right; // [esp+90h] [ebp-80h] BYREF
  __int64 v27; // [esp+D0h] [ebp-40h]
  __int64 v28; // [esp+D8h] [ebp-38h]
  float v29; // [esp+E0h] [ebp-30h]
  __int64 bonea; // [esp+E4h] [ebp-2Ch] BYREF
  _BYTE bone_8[24]; // [esp+ECh] [ebp-24h]
  __int64 v32; // [esp+104h] [ebp-Ch]
  float z; // [esp+10Ch] [ebp-4h]

  v5 = alloca(44 * LODWORD(result->rotation.y));
  v6 = 0;
  for ( i = (float *)v23; v6 < LODWORD(result->rotation.y); i += 11 )
  {
    v8 = vostok::animation::bone_matrices_computer::computed_local_bone_transform(
           bone_mask,
           result,
           (const vostok::animation::skeleton_bone *)&bonea,
           (char **)bone_mask,
           animation_layer_id,
           v6);
    if ( i )
    {
      *(_QWORD *)i = *(_QWORD *)&v8->m_id;
      *((_QWORD *)i + 1) = *(_QWORD *)&v8->m_children_begin;
      *((_QWORD *)i + 2) = *(_QWORD *)&v8->m_mask;
      *((_QWORD *)i + 3) = *(_QWORD *)&v8[1].m_parent;
      *((_QWORD *)i + 4) = *(_QWORD *)&v8[1].m_children_end;
      i[10] = *(float *)&v8[2].m_id;
    }
    ++v6;
  }
  v9 = LOBYTE(left.lines[1].elements[2]);
  bonea = v23[0];
  *(_QWORD *)bone_8 = v23[1];
  *(_QWORD *)&bone_8[8] = *(_QWORD *)&left.i.x;
  *(_QWORD *)&bone_8[16] = *(_QWORD *)&left.lines[0].elements[2];
  p_w = &left.j.w;
  v32 = *(_QWORD *)&left.lines[1].x;
  z = left.j.z;
  if ( &left.lines[1].elements[3] != i )
  {
    v11 = &left.k.w;
    do
    {
      v12 = v11[2];
      v13 = *(v11 - 1);
      v14 = *v11;
      v15 = v11[1];
      *(float *)&bonea = *p_w + *(float *)&bonea;
      *((float *)&bonea + 1) = *(v11 - 3) + *((float *)&bonea + 1);
      *(float *)bone_8 = *(v11 - 2) + *(float *)bone_8;
      *((float *)&v28 + 1) = (float)((float)((float)(*(float *)&bone_8[16] * v12) - (float)(*(float *)&bone_8[4] * v13))
                                   - (float)(*(float *)&bone_8[8] * v14))
                           - (float)(*(float *)&bone_8[12] * v15);
      v16 = (float)((float)(*(float *)&bone_8[16] * *(v11 - 1)) + (float)(*(float *)&bone_8[8] * v15))
          + (float)(*(float *)&bone_8[4] * v12);
      v17 = *v11;
      *(float *)&v27 = v16 - (float)(*(float *)&bone_8[12] * *v11);
      v18 = *(float *)&bone_8[16] * v17;
      v9 &= *((_BYTE *)v11 + 24);
      v19 = *(v11 - 1);
      *((float *)&v27 + 1) = (float)((float)(v18 - (float)(*(float *)&bone_8[4] * v11[1]))
                                   + (float)(*(float *)&bone_8[12] * v19))
                           + (float)(*(float *)&bone_8[8] * v12);
      *(float *)&v28 = (float)((float)((float)(*(float *)&bone_8[16] * v11[1]) + (float)(*(float *)&bone_8[4] * *v11))
                             - (float)(*(float *)&bone_8[8] * v19))
                     + (float)(*(float *)&bone_8[12] * v12);
      *(_QWORD *)&bone_8[4] = v27;
      *(_QWORD *)&bone_8[12] = v28;
      *(float *)&bone_8[20] = v11[3] * *(float *)&bone_8[20];
      *(float *)&v32 = v11[4] * *(float *)&v32;
      *((float *)&v32 + 1) = v11[5] * *((float *)&v32 + 1);
      p_w += 11;
      v11 += 11;
    }
    while ( p_w != i );
    LOBYTE(z) = v9;
  }
  v20 = *(float *)&bone_8[12];
  v29 = *(float *)&bone_8[12] * *(float *)&bone_8[8];
  right.i.x = *(float *)&clear_value
            - (float)((float)((float)(v20 * v20) + (float)(*(float *)&bone_8[8] * *(float *)&bone_8[8])) * 2.0);
  right.j.x = (float)((float)(*(float *)&bone_8[16] * *(float *)&bone_8[12])
                    + (float)(*(float *)&bone_8[8] * *(float *)&bone_8[4]))
            * 2.0;
  right.i.y = (float)((float)(*(float *)&bone_8[8] * *(float *)&bone_8[4])
                    - (float)(*(float *)&bone_8[16] * *(float *)&bone_8[12]))
            * 2.0;
  right.j.y = *(float *)&clear_value
            - (float)((float)((float)(v20 * v20) + (float)(*(float *)&bone_8[4] * *(float *)&bone_8[4])) * 2.0);
  right.i.z = (float)((float)(*(float *)&bone_8[16] * *(float *)&bone_8[8])
                    + (float)(*(float *)&bone_8[12] * *(float *)&bone_8[4]))
            * 2.0;
  right.i.w = 0.0;
  *(_QWORD *)&right.lines[1].elements[2] = COERCE_UNSIGNED_INT(
                                             (float)((float)(*(float *)&bone_8[12] * *(float *)&bone_8[8])
                                                   - (float)(*(float *)&bone_8[16] * *(float *)&bone_8[4]))
                                           * 2.0);
  right.k.x = (float)((float)(*(float *)&bone_8[12] * *(float *)&bone_8[4])
                    - (float)(*(float *)&bone_8[16] * *(float *)&bone_8[8]))
            * 2.0;
  right.k.y = (float)((float)(*(float *)&bone_8[16] * *(float *)&bone_8[4])
                    + (float)(*(float *)&bone_8[12] * *(float *)&bone_8[8]))
            * 2.0;
  right.k.z = *(float *)&clear_value
            - (float)((float)((float)(*(float *)&bone_8[8] * *(float *)&bone_8[8])
                            + (float)(*(float *)&bone_8[4] * *(float *)&bone_8[4]))
                    * 2.0);
  memset(&right.lines[2].elements[3], 0, 16);
  LODWORD(right.c.w) = clear_value;
  memset((int)&dst, 0, sizeof(dst));
  dst.i.x = *(float *)&bone_8[20];
  dst.k.z = *((float *)&v32 + 1);
  LODWORD(dst.j.y) = v32;
  LODWORD(dst.c.w) = clear_value;
  vostok::math::mul4x3(&left, &dst, &right);
  v21 = vostok::math::create_translation(&dst, (const vostok::math::float3 *)&bonea);
  vostok::math::mul4x3(bone, &left, v21);
  return bone;
}
