vostok::math::float4x4 *__thiscall vostok::animation::bone_matrices_computer::computed_local_bone_matrix(
        vostok::animation::bone_matrices_computer *this,
        vostok::animation::bone_transform *result,
        vostok::math::float4x4 *bone,
        unsigned int bone_mask,
        unsigned int a6)
{
  float y; // edi
  void *v7; // esp
  unsigned int v8; // esi
  vostok::animation::bone_transform *v9; // eax
  vostok::buffer_vector<vostok::animation::bone_transform> *v10; // ecx
  float *v11; // eax
  int v12; // ebx
  vostok::math::quaternion *v13; // eax
  float v14; // xmm0_4
  vostok::math::quaternion *v15; // esi
  float v16; // xmm0_4
  vostok::math::float4x4 *v17; // eax
  _DWORD v19[4]; // [esp+0h] [ebp-D8h] BYREF
  vostok::math::float4x4 v20; // [esp+10h] [ebp-C8h] BYREF
  vostok::math::float4x4 v21; // [esp+50h] [ebp-88h] BYREF
  vostok::math::quaternion v22; // [esp+90h] [ebp-48h] BYREF
  vostok::animation::bone_transform v23; // [esp+A0h] [ebp-38h] BYREF
  vostok::math::float3 v24; // [esp+CCh] [ebp-Ch] BYREF
  int v25; // [esp+E0h] [ebp+8h]

  y = result->rotation.y;
  v7 = alloca(44 * LODWORD(y));
  LODWORD(v24.z) = &v19[11 * LODWORD(y)];
  v8 = 0;
  LODWORD(v24.x) = v19;
  LODWORD(v24.y) = v19;
  if ( y != 0.0 )
  {
    do
    {
      v9 = vostok::animation::bone_matrices_computer::computed_local_bone_transform(
             this,
             result,
             &v23,
             bone_mask,
             a6,
             v8);
      vostok::buffer_vector<vostok::animation::bone_transform>::push_back(
        v10,
        (const vostok::animation::bone_transform *)&v24,
        v9);
      ++v8;
    }
    while ( v8 < LODWORD(result->rotation.y) );
  }
  v11 = (float *)(LODWORD(v24.x) + 44);
  qmemcpy(&v23, (const void *)LODWORD(v24.x), sizeof(v23));
  v25 = LODWORD(v24.x) + 44;
  if ( LODWORD(v24.x) + 44 != LODWORD(v24.y) )
  {
    v12 = LODWORD(v24.x) + 80;
    while ( 1 )
    {
      v23.translation.x = *v11 + v23.translation.x;
      v23.translation.y = *(float *)(v12 - 32) + v23.translation.y;
      v23.translation.z = *(float *)(v12 - 28) + v23.translation.z;
      v13 = vostok::math::operator*((const vostok::math::quaternion *)(v12 - 24), &v23.rotation, &v22);
      v14 = *(float *)(v12 - 8);
      v25 += 44;
      v15 = v13;
      LOBYTE(v13) = *(_BYTE *)(v12 + 4);
      v23.rotation.x = v15->x;
      v15 = (vostok::math::quaternion *)((char *)v15 + 4);
      v23.rotation.y = v15->x;
      *(_QWORD *)&v23.rotation.vector.elements[2] = *(_QWORD *)&v15->vector.elements[1];
      v23.visibility &= (unsigned __int8)v13;
      v23.scale.x = v14 * v23.scale.x;
      v23.scale.y = *(float *)(v12 - 4) * v23.scale.y;
      v16 = *(float *)v12 * v23.scale.z;
      v12 += 44;
      v23.scale.z = v16;
      if ( v25 == LODWORD(v24.y) )
        break;
      v11 = (float *)v25;
    }
  }
  memset(&v24, 0, sizeof(v24));
  vostok::math::create_matrix(&v23.rotation, &v24, &v21);
  v17 = vostok::math::create_translation(&v23.translation, &v20);
  vostok::math::mul4x3(v17, &v21, bone);
  return bone;
}
