vostok::math::aabb *__thiscall vostok::collision::composite_geometry_instance::get_geometry_aabb(
        vostok::collision::composite_geometry_instance *this,
        vostok::math::aabb *result)
{
  const vostok::collision::composite_geometry *m_geometry; // eax
  vostok::collision::geometry_instance **m_end; // ebx
  vostok::collision::geometry_instance **i; // edi
  float *v5; // eax
  float x; // xmm0_4
  __int64 v8; // [esp+4h] [ebp-48h]
  float z; // [esp+Ch] [ebp-40h]
  __int64 v10; // [esp+10h] [ebp-3Ch]
  float v11; // [esp+18h] [ebp-34h]
  __int64 v12; // [esp+1Ch] [ebp-30h]
  float v13; // [esp+24h] [ebp-28h]
  _BYTE v14[12]; // [esp+28h] [ebp-24h]
  vostok::math::aabb v15; // [esp+34h] [ebp-18h] BYREF

  *(_QWORD *)&result->min.x = 0;
  *(_QWORD *)&result->max.x = 0;
  result->min.z = 0.0;
  result->max.z = 0.0;
  m_geometry = this->m_geometry;
  m_end = m_geometry->m_geometry_instances.m_end;
  for ( i = m_geometry->m_geometry_instances.m_begin; i != m_end; result->max = *(vostok::math::float3 *)v14 )
  {
    v5 = (float *)(*i)->get_aabb(*i, &v15);
    if ( *v5 <= result->min.x )
      *(float *)&v8 = *v5;
    else
      *(float *)&v8 = result->min.x;
    if ( v5[1] <= result->min.y )
      *((float *)&v8 + 1) = v5[1];
    else
      HIDWORD(v8) = LODWORD(result->min.y);
    if ( v5[2] <= result->min.z )
      z = v5[2];
    else
      z = result->min.z;
    *(_QWORD *)&result->min.x = v8;
    result->min.z = z;
    if ( result->max.x <= *v5 )
      *(float *)&v10 = *v5;
    else
      *(float *)&v10 = result->max.x;
    if ( result->max.y <= v5[1] )
      *((float *)&v10 + 1) = v5[1];
    else
      HIDWORD(v10) = LODWORD(result->max.y);
    if ( result->max.z <= v5[2] )
      v11 = v5[2];
    else
      v11 = result->max.z;
    *(_QWORD *)&result->max.x = v10;
    x = result->min.x;
    result->max.z = v11;
    if ( v5[3] <= x )
      *(float *)&v12 = v5[3];
    else
      *(float *)&v12 = x;
    if ( v5[4] <= result->min.y )
      *((float *)&v12 + 1) = v5[4];
    else
      HIDWORD(v12) = LODWORD(result->min.y);
    if ( v5[5] <= result->min.z )
      v13 = v5[5];
    else
      v13 = result->min.z;
    *(_QWORD *)&result->min.x = v12;
    result->min.z = v13;
    if ( result->max.x <= v5[3] )
      *(float *)v14 = v5[3];
    else
      *(float *)v14 = result->max.x;
    if ( result->max.y <= v5[4] )
      *(float *)&v14[4] = v5[4];
    else
      *(float *)&v14[4] = result->max.y;
    if ( result->max.z <= v5[5] )
      *(float *)&v14[8] = v5[5];
    else
      *(float *)&v14[8] = result->max.z;
    ++i;
  }
  return result;
}
