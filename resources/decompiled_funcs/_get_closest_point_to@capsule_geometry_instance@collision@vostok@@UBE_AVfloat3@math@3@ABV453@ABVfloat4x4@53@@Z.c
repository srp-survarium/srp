vostok::math::float3 *__thiscall vostok::collision::capsule_geometry_instance::get_closest_point_to(
        vostok::collision::capsule_geometry_instance *this,
        vostok::math::float3 *result,
        const vostok::math::float3 *point,
        const vostok::math::float4x4 *origin)
{
  float m_half_length; // xmm3_4
  float v6; // xmm7_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float m_radius; // xmm3_4
  vostok::math::float3 *v21; // eax
  float z; // ecx
  vostok::math::float3 *v23; // eax
  float v24; // xmm3_4
  float y; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  unsigned __int64 v28; // xmm0_8
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  long double v32; // st7
  float v33; // xmm2_4
  float v34; // xmm0_4
  vostok::math::float3 v35; // [esp+Ch] [ebp-70h]
  float height_vector_proj_point; // [esp+18h] [ebp-64h]
  unsigned __int64 height_vector_proj_pointa; // [esp+18h] [ebp-64h]
  float height_vector_proj_point_4; // [esp+1Ch] [ebp-60h]
  float height_vector_proj_point_8; // [esp+20h] [ebp-5Ch]
  float top_surface_center_8; // [esp+2Ch] [ebp-50h]
  vostok::math::float3 dir; // [esp+30h] [ebp-4Ch] BYREF
  vostok::math::float4x4 transform; // [esp+3Ch] [ebp-40h] BYREF

  vostok::math::mul4x3(&transform, origin, &this->m_matrix);
  m_half_length = this->m_half_length;
  v6 = transform.c.z + (float)(m_half_length * transform.j.z);
  v7 = transform.c.x + (float)(m_half_length * transform.j.x);
  v8 = transform.c.y + (float)(m_half_length * transform.j.y);
  v9 = m_half_length * transform.j.x;
  v10 = this->m_half_length * transform.j.z;
  dir.y = transform.c.y - (float)(this->m_half_length * transform.j.y);
  dir.x = v9;
  v11 = dir.y - v8;
  v35 = *point;
  dir.x = transform.c.x - v9;
  v12 = (float)(transform.c.x - v9) - v7;
  dir.z = transform.c.z - v10;
  v13 = (float)(transform.c.z - v10) - v6;
  v14 = (float)((float)((float)((float)(v35.x - v7) * v12) + (float)((float)(v35.z - v6) * v13))
              + (float)((float)(v35.y - v8) * (float)(dir.y - v8)))
      / (float)((float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v11 * v11));
  if ( v14 <= 0.0 || *(float *)&clear_value <= v14 )
  {
    if ( v14 >= 0.0 )
    {
      v28 = *(_QWORD *)&dir.x;
      height_vector_proj_point_8 = dir.z;
    }
    else
    {
      v28 = __PAIR64__(LODWORD(v8), LODWORD(v7));
      height_vector_proj_point_8 = v6;
    }
    v29 = v35.z - height_vector_proj_point_8;
    height_vector_proj_pointa = v28;
    v30 = v35.x - *(float *)&v28;
    v31 = v35.y - *((float *)&height_vector_proj_pointa + 1);
    if ( (float)(this->m_radius * this->m_radius) > (float)((float)((float)(v30 * v30) + (float)(v29 * v29))
                                                          + (float)(v31 * v31)) )
      goto LABEL_4;
    top_surface_center_8 = v35.z - height_vector_proj_point_8;
    v32 = sqrtf((float)((float)(v29 * v29) + (float)(v31 * v31)) + (float)(v30 * v30));
    v21 = result;
    v35.z = 1.0 / v32;
    v33 = (float)(this->m_radius * (float)((float)(v35.y - *((float *)&height_vector_proj_pointa + 1)) * v35.z))
        + *((float *)&height_vector_proj_pointa + 1);
    v34 = (float)(this->m_radius * (float)(top_surface_center_8 * v35.z)) + height_vector_proj_point_8;
    result->x = (float)(this->m_radius * (float)(v35.z * (float)(v35.x - *(float *)&height_vector_proj_pointa)))
              + *(float *)&height_vector_proj_pointa;
    result->y = v33;
    result->z = v34;
  }
  else
  {
    v15 = (float)(v11 * v14) + v8;
    v16 = v35.y - v15;
    v17 = (float)(v12 * v14) + v7;
    height_vector_proj_point_4 = v15;
    dir.x = v35.x - v17;
    v18 = (float)(v13 * v14) + v6;
    v19 = (float)((float)((float)(v35.x - v17) * (float)(v35.x - v17))
                + (float)((float)(v35.z - v18) * (float)(v35.z - v18)))
        + (float)(v16 * v16);
    height_vector_proj_point = v17;
    m_radius = this->m_radius;
    dir.y = v16;
    dir.z = v35.z - v18;
    if ( (float)(m_radius * m_radius) > v19 )
    {
LABEL_4:
      v21 = result;
      z = point->z;
      *(_QWORD *)&result->x = *(_QWORD *)&point->x;
      result->z = z;
      return v21;
    }
    v23 = vostok::math::float3_pod::normalize(&dir);
    v24 = this->m_radius;
    y = v23->y;
    v26 = v23->z;
    v27 = v24 * v23->x;
    v21 = result;
    result->x = v27 + height_vector_proj_point;
    result->y = (float)(y * v24) + height_vector_proj_point_4;
    result->z = (float)(v26 * v24) + v18;
  }
  return v21;
}
