char __userpurge btPrimitiveTriangle::find_triangle_collision_clip_method@<al>(
        GIM_TRIANGLE_CONTACT *contacts@<esi>,
        btPrimitiveTriangle *this,
        btPrimitiveTriangle *other)
{
  int v3; // eax
  unsigned __int64 v5; // xmm0_8
  int v6; // eax
  int m_point_count; // edx
  float m_penetration_depth; // xmm0_4
  float v9; // xmm1_4
  btVector3 *v10; // ecx
  unsigned __int64 v11; // xmm0_8
  btVector3 *v12; // eax
  unsigned __int64 v13; // xmm0_8
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  btVector3 *v17; // ecx
  unsigned __int64 *v18; // eax
  unsigned __int64 v19; // xmm0_8
  float v20; // [esp+9A8h] [ebp-344h]
  GIM_TRIANGLE_CONTACT v21; // [esp+9ACh] [ebp-340h] BYREF
  GIM_TRIANGLE_CONTACT v22; // [esp+ACCh] [ebp-220h] BYREF
  btVector3 points; // [esp+BECh] [ebp-100h] BYREF

  v20 = other->m_margin + this->m_margin;
  v21.m_separating_normal = this->m_plane;
  v3 = btPrimitiveTriangle::clip_triangle(other, this, &points);
  if ( !v3 )
    return 0;
  GIM_TRIANGLE_CONTACT::merge_points(&v21, &v21.m_separating_normal, v20, &points, v3);
  if ( !v21.m_point_count )
    return 0;
  v21.m_separating_normal.mVec128.m128_f32[0] = v21.m_separating_normal.mVec128.m128_f32[0] * -1.0;
  v21.m_separating_normal.mVec128.m128_f32[1] = v21.m_separating_normal.mVec128.m128_f32[1] * -1.0;
  v22.m_separating_normal.mVec128.m128_u64[0] = other->m_plane.mVec128.m128_u64[0];
  v5 = other->m_plane.mVec128.m128_u64[1];
  v21.m_separating_normal.mVec128.m128_f32[2] = v21.m_separating_normal.mVec128.m128_f32[2] * -1.0;
  v22.m_separating_normal.mVec128.m128_u64[1] = v5;
  v6 = btPrimitiveTriangle::clip_triangle(this, other, &points);
  if ( !v6 )
    return 0;
  GIM_TRIANGLE_CONTACT::merge_points(&v22, &v22.m_separating_normal, v20, &points, v6);
  m_point_count = v22.m_point_count;
  if ( !v22.m_point_count )
    return 0;
  m_penetration_depth = v21.m_penetration_depth;
  v9 = v22.m_penetration_depth;
  if ( v21.m_penetration_depth <= v22.m_penetration_depth )
  {
    v14 = v21.m_point_count;
    contacts->m_point_count = v21.m_point_count;
    v15 = v14;
    contacts->m_penetration_depth = m_penetration_depth;
    contacts->m_separating_normal = v21.m_separating_normal;
    v16 = 16 * (v14 + 2);
    v17 = &v21.m_points[v14];
    v18 = (unsigned __int64 *)((char *)contacts + v16);
    do
    {
      v19 = v17[-1].mVec128.m128_u64[0];
      --v17;
      v18 -= 2;
      --v15;
      *v18 = v19;
      v18[1] = v17->mVec128.m128_u64[1];
    }
    while ( v15 );
    return 1;
  }
  else
  {
    v10 = &v22.m_points[v22.m_point_count];
    contacts->m_separating_normal.mVec128.m128_u64[0] = v22.m_separating_normal.mVec128.m128_u64[0];
    v11 = v22.m_separating_normal.mVec128.m128_u64[1];
    contacts->m_penetration_depth = v9;
    contacts->m_separating_normal.mVec128.m128_u64[1] = v11;
    contacts->m_point_count = m_point_count;
    v12 = &contacts->m_points[m_point_count];
    do
    {
      v13 = v10[-1].mVec128.m128_u64[0];
      --v10;
      --v12;
      --m_point_count;
      v12->mVec128.m128_u64[0] = v13;
      v12->mVec128.m128_u64[1] = v10->mVec128.m128_u64[1];
    }
    while ( m_point_count );
    return 1;
  }
}
