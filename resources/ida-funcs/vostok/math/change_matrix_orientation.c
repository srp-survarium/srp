void __fastcall vostok::math::change_matrix_orientation(
        const vostok::math::float4x4 *rotation_matrix,
        vostok::math::float4x4 *matrix_to_rotate)
{
  vostok::math::float4_pod *p_c; // ebx
  vostok::math::float4x4 *v3; // edx
  vostok::math::float4x4 v4; // [esp+4h] [ebp-58h] BYREF
  __int64 v5; // [esp+44h] [ebp-18h]
  float z; // [esp+4Ch] [ebp-10h]
  int v7; // [esp+50h] [ebp-Ch]
  __int64 v8; // [esp+54h] [ebp-8h]

  p_c = &matrix_to_rotate->c;
  v5 = *(_QWORD *)&matrix_to_rotate->lines[3].x;
  z = matrix_to_rotate->c.z;
  v7 = 0;
  v8 = 0;
  matrix_to_rotate->c.x = 0.0;
  *(_QWORD *)&matrix_to_rotate->lines[3].elements[1] = v8;
  vostok::math::mul4x3(rotation_matrix, matrix_to_rotate, &v4);
  qmemcpy(v3, &v4, sizeof(vostok::math::float4x4));
  *(_QWORD *)&p_c->x = v5;
  p_c->z = z;
}
