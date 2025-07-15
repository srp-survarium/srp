vostok::math::aabb *__thiscall vostok::collision::composite_geometry::get_aabb(
        vostok::collision::composite_geometry *this,
        vostok::math::aabb *result)
{
  vostok::collision::geometry_instance **m_end; // ebx
  vostok::collision::geometry_instance **i; // edi
  vostok::math::aabb *v4; // eax
  float x; // xmm0_4
  __int64 v7; // [esp+4h] [ebp-48h]
  float z; // [esp+Ch] [ebp-40h]
  __int64 v9; // [esp+10h] [ebp-3Ch]
  float v10; // [esp+18h] [ebp-34h]
  __int64 v11; // [esp+1Ch] [ebp-30h]
  float v12; // [esp+24h] [ebp-28h]
  _BYTE v13[12]; // [esp+28h] [ebp-24h]
  vostok::math::aabb v14; // [esp+34h] [ebp-18h] BYREF

  *(_QWORD *)&result->min.x = 0;
  *(_QWORD *)&result->max.x = 0;
  result->min.z = 0.0;
  result->max.z = 0.0;
  m_end = this->m_geometry_instances.m_end;
  for ( i = this->m_geometry_instances.m_begin; i != m_end; result->max = *(vostok::math::float3 *)v13 )
  {
    v4 = (*i)->get_aabb(*i, &v14);
    if ( v4->min.x <= result->min.x )
      *(float *)&v7 = v4->min.x;
    else
      *(float *)&v7 = result->min.x;
    if ( v4->min.y <= result->min.y )
      HIDWORD(v7) = LODWORD(v4->min.y);
    else
      HIDWORD(v7) = LODWORD(result->min.y);
    if ( v4->min.z <= result->min.z )
      z = v4->min.z;
    else
      z = result->min.z;
    *(_QWORD *)&result->min.x = v7;
    result->min.z = z;
    if ( result->max.x <= v4->min.x )
      *(float *)&v9 = v4->min.x;
    else
      *(float *)&v9 = result->max.x;
    if ( result->max.y <= v4->min.y )
      HIDWORD(v9) = LODWORD(v4->min.y);
    else
      HIDWORD(v9) = LODWORD(result->max.y);
    if ( result->max.z <= v4->min.z )
      v10 = v4->min.z;
    else
      v10 = result->max.z;
    *(_QWORD *)&result->max.x = v9;
    x = result->min.x;
    result->max.z = v10;
    if ( v4->max.x <= x )
      *(float *)&v11 = v4->max.x;
    else
      *(float *)&v11 = x;
    if ( v4->max.y <= result->min.y )
      HIDWORD(v11) = LODWORD(v4->max.y);
    else
      HIDWORD(v11) = LODWORD(result->min.y);
    if ( v4->max.z <= result->min.z )
      v12 = v4->max.z;
    else
      v12 = result->min.z;
    *(_QWORD *)&result->min.x = v11;
    result->min.z = v12;
    if ( result->max.x <= v4->max.x )
      *(float *)v13 = v4->max.x;
    else
      *(float *)v13 = result->max.x;
    if ( result->max.y <= v4->max.y )
      *(float *)&v13[4] = v4->max.y;
    else
      *(float *)&v13[4] = result->max.y;
    if ( result->max.z <= v4->max.z )
      *(float *)&v13[8] = v4->max.z;
    else
      *(float *)&v13[8] = result->max.z;
    ++i;
  }
  return result;
}
