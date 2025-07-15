char __userpurge btPrimitiveTriangle::find_triangle_collision_clip_method@<al>(
        btPrimitiveTriangle *this@<ecx>,
        btVector3 *a2@<edi>,
        btPrimitiveTriangle *other,
        btPrimitiveTriangle *contacts,
        int *a5)
{
  float v5; // xmm0_4
  const btVector3 *v6; // eax
  const btVector3 *v8; // eax
  int v9; // eax
  int v10; // xmm0_4
  int v11; // xmm1_4
  float *v12; // edi
  int v13; // edx
  btVector3 *v14; // ecx
  int *v15; // eax
  int v16; // eax
  int v17; // edx
  btVector3 *v18; // ecx
  int *v19; // eax
  int v20; // [esp+Ch] [ebp-350h]
  btVector3 *v21; // [esp+Ch] [ebp-350h]
  int v22; // [esp+Ch] [ebp-350h]
  float v23; // [esp+1Ch] [ebp-340h] BYREF
  int v24; // [esp+20h] [ebp-33Ch]
  GIM_TRIANGLE_CONTACT v25; // [esp+2Ch] [ebp-330h] BYREF
  GIM_TRIANGLE_CONTACT v26; // [esp+14Ch] [ebp-210h] BYREF

  v5 = contacts->m_margin + other->m_margin;
  *(_QWORD *)&v25.m_penetration_depth = other->m_plane.mVec128.m128_u64[0];
  *(_QWORD *)(&v25.m_point_count + 1) = other->m_plane.mVec128.m128_u64[1];
  v6 = (const btVector3 *)btPrimitiveTriangle::clip_triangle(
                            contacts,
                            (float *)other,
                            (btPrimitiveTriangle *)&v26.m_points[15],
                            a2);
  if ( !v6 )
    return 0;
  GIM_TRIANGLE_CONTACT::merge_points(
    &v25,
    (int)&v23,
    (const btVector4 *)LODWORD(v5),
    COERCE_FLOAT((GIM_TRIANGLE_CONTACT *)&v26.m_points[15]),
    v6,
    v20);
  if ( !v24 )
    return 0;
  *(_QWORD *)&v26.m_penetration_depth = contacts->m_plane.mVec128.m128_u64[0];
  v25.m_penetration_depth = v25.m_penetration_depth * -1.0;
  *(&v26.m_point_count + 1) = contacts->m_plane.mVec128.m128_i32[2];
  *(float *)&v25.m_point_count = *(float *)&v25.m_point_count * -1.0;
  *((float *)&v25.m_point_count + 1) = *((float *)&v25.m_point_count + 1) * -1.0;
  *(&v26.m_point_count + 2) = contacts->m_plane.mVec128.m128_i32[3];
  v8 = (const btVector3 *)btPrimitiveTriangle::clip_triangle(
                            other,
                            (float *)contacts,
                            (btPrimitiveTriangle *)&v26.m_points[15],
                            v21);
  if ( !v8 )
    return 0;
  GIM_TRIANGLE_CONTACT::merge_points(
    &v26,
    (int)&v25.m_points[15],
    (const btVector4 *)LODWORD(v5),
    COERCE_FLOAT((GIM_TRIANGLE_CONTACT *)&v26.m_points[15]),
    v8,
    v22);
  v9 = v25.m_points[15].mVec128.m128_i32[1];
  if ( !v25.m_points[15].mVec128.m128_i32[1] )
    return 0;
  v10 = LODWORD(v23);
  v11 = v25.m_points[15].mVec128.m128_i32[0];
  v12 = (float *)(a5 + 4);
  if ( v23 <= v25.m_points[15].mVec128.m128_f32[0] )
  {
    v16 = v24;
    *v12 = v25.m_penetration_depth;
    a5[5] = v25.m_point_count;
    a5[1] = v16;
    v17 = v16;
    a5[6] = *(&v25.m_point_count + 1);
    *a5 = v10;
    a5[7] = *(&v25.m_point_count + 2);
    v18 = &v25.m_points[v16 - 1];
    v19 = &a5[4 * v16 + 8];
    do
    {
      --v18;
      v19 -= 4;
      *v19 = v18->mVec128.m128_i32[0];
      v19[1] = v18->mVec128.m128_i32[1];
      v19[2] = v18->mVec128.m128_i32[2];
      --v17;
      v19[3] = v18->mVec128.m128_i32[3];
    }
    while ( v17 );
  }
  else
  {
    *v12 = v26.m_penetration_depth;
    a5[5] = v26.m_point_count;
    a5[1] = v9;
    v13 = v9;
    a5[6] = *(&v26.m_point_count + 1);
    *a5 = v11;
    a5[7] = *(&v26.m_point_count + 2);
    v14 = &v26.m_points[v9 - 1];
    v15 = &a5[4 * v9 + 8];
    do
    {
      --v14;
      v15 -= 4;
      *v15 = v14->mVec128.m128_i32[0];
      v15[1] = v14->mVec128.m128_i32[1];
      v15[2] = v14->mVec128.m128_i32[2];
      --v13;
      v15[3] = v14->mVec128.m128_i32[3];
    }
    while ( v13 );
  }
  return 1;
}
