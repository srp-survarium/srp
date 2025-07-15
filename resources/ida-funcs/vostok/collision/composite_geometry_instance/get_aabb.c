vostok::math::aabb *__userpurge vostok::collision::composite_geometry_instance::get_aabb@<eax>(
        vostok::collision::composite_geometry_instance *this@<ecx>,
        const vostok::math::float4x4 *a2@<edi>,
        vostok::math::aabb *result)
{
  const vostok::collision::composite_geometry *m_geometry; // eax
  vostok::collision::geometry_instance **m_begin; // esi
  vostok::collision::geometry_instance **m_end; // edi
  int v7; // eax
  float v8; // xmm7_4
  float v9; // xmm6_4
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  __int64 v17; // [esp+48h] [ebp-6Ch]
  float v18; // [esp+50h] [ebp-64h]
  __int64 v19; // [esp+54h] [ebp-60h]
  float v20; // [esp+5Ch] [ebp-58h]
  __int64 v21; // [esp+74h] [ebp-40h]
  float v22; // [esp+7Ch] [ebp-38h]
  __int64 v23; // [esp+80h] [ebp-34h]
  float i; // [esp+88h] [ebp-2Ch]
  vostok::math::aabb v25; // [esp+9Ch] [ebp-18h] BYREF

  v22 = 0.0;
  m_geometry = this->m_geometry;
  m_begin = m_geometry->m_geometry_instances.m_begin;
  m_end = m_geometry->m_geometry_instances.m_end;
  v21 = 0;
  v23 = 0;
  for ( i = 0.0; m_begin != m_end; i = v20 )
  {
    v7 = (int)(*m_begin)->get_aabb(*m_begin, &v25);
    if ( *(float *)v7 <= *(float *)&v21 )
      v8 = *(float *)v7;
    else
      v8 = *(float *)&v21;
    if ( *(float *)(v7 + 4) <= *((float *)&v21 + 1) )
      v9 = *(float *)(v7 + 4);
    else
      v9 = *((float *)&v21 + 1);
    if ( *(float *)(v7 + 8) <= v22 )
      v10 = *(float *)(v7 + 8);
    else
      v10 = v22;
    if ( *(float *)&v23 <= *(float *)v7 )
      v11 = *(float *)v7;
    else
      v11 = *(float *)&v23;
    if ( *((float *)&v23 + 1) <= *(float *)(v7 + 4) )
      v12 = *(float *)(v7 + 4);
    else
      v12 = *((float *)&v23 + 1);
    v13 = *(float *)(v7 + 8);
    if ( i > v13 )
      v13 = i;
    v14 = *(float *)(v7 + 12);
    if ( v14 <= v8 )
      LODWORD(v17) = *(_DWORD *)(v7 + 12);
    else
      *(float *)&v17 = v8;
    if ( *(float *)(v7 + 16) <= v9 )
      HIDWORD(v17) = *(_DWORD *)(v7 + 16);
    else
      *((float *)&v17 + 1) = v9;
    if ( *(float *)(v7 + 20) <= v10 )
      v18 = *(float *)(v7 + 20);
    else
      v18 = v10;
    v21 = v17;
    v22 = v18;
    if ( v11 <= v14 )
      LODWORD(v19) = *(_DWORD *)(v7 + 12);
    else
      *(float *)&v19 = v11;
    if ( v12 <= *(float *)(v7 + 16) )
      HIDWORD(v19) = *(_DWORD *)(v7 + 16);
    else
      *((float *)&v19 + 1) = v12;
    if ( v13 <= *(float *)(v7 + 20) )
      v20 = *(float *)(v7 + 20);
    else
      v20 = v13;
    ++m_begin;
    v23 = v19;
  }
  *result = *vostok::math::aabb::modify((vostok::math::aabb *)&this->m_matrix, a2);
  return result;
}
