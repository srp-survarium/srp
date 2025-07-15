vostok::math::float3 *__thiscall vostok::collision::cylinder_geometry_instance::get_closest_point_to(
        vostok::collision::cylinder_geometry_instance *this,
        vostok::math::float3 *result,
        const vostok::math::float3 *point,
        const vostok::math::float4x4 *origin)
{
  vostok::math::float4x4 *p_m_matrix; // esi
  float y; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float x; // xmm6_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  vostok::math::float3 *v19; // eax
  float v20; // edx
  vostok::math::float3 *v21; // eax
  float v22; // xmm0_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  __int64 v26; // xmm0_8
  float v27; // xmm6_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  float v30; // [esp+Ch] [ebp-78h]
  float v31; // [esp+Ch] [ebp-78h]
  float v32; // [esp+Ch] [ebp-78h]
  float v33; // [esp+10h] [ebp-74h]
  float v34; // [esp+10h] [ebp-74h]
  float z; // [esp+10h] [ebp-74h]
  float _X; // [esp+10h] [ebp-74h]
  float v37; // [esp+14h] [ebp-70h]
  float v38; // [esp+18h] [ebp-6Ch]
  float v39; // [esp+18h] [ebp-6Ch]
  float v40; // [esp+18h] [ebp-6Ch]
  float v41; // [esp+1Ch] [ebp-68h]
  float v42; // [esp+1Ch] [ebp-68h]
  float v43; // [esp+1Ch] [ebp-68h]
  float v44; // [esp+1Ch] [ebp-68h]
  __int64 height_vector_proj_point; // [esp+20h] [ebp-64h]
  float height_vector_proj_point_8; // [esp+28h] [ebp-5Ch]
  vostok::math::float3 dir; // [esp+2Ch] [ebp-58h] BYREF
  vostok::math::float3 bottom_surface_center; // [esp+38h] [ebp-4Ch]
  vostok::math::float4x4 transform; // [esp+44h] [ebp-40h] BYREF

  p_m_matrix = &this->m_matrix;
  vostok::math::mul4x3(&transform, origin, &this->m_matrix);
  v33 = sqrtf(
          (float)((float)(this->m_matrix.j.z * this->m_matrix.j.z) + (float)(this->m_matrix.j.x * this->m_matrix.j.x))
        + (float)(this->m_matrix.j.y * this->m_matrix.j.y));
  dir.z = (float)(transform.j.z * v33) + transform.c.z;
  y = this->m_matrix.j.y;
  dir.y = (float)(transform.j.y * v33) + transform.c.y;
  v7 = y * y;
  v8 = this->m_matrix.j.z * this->m_matrix.j.z;
  dir.x = (float)(transform.j.x * v33) + transform.c.x;
  v34 = sqrtf((float)(v7 + v8) + (float)(this->m_matrix.j.x * this->m_matrix.j.x));
  x = point->x;
  bottom_surface_center.x = transform.c.x - (float)(transform.j.x * v34);
  v10 = bottom_surface_center.x - dir.x;
  v11 = point->y;
  bottom_surface_center.y = transform.c.y - (float)(transform.j.y * v34);
  bottom_surface_center.z = transform.c.z - (float)(transform.j.z * v34);
  v12 = bottom_surface_center.y - dir.y;
  v13 = bottom_surface_center.z - dir.z;
  v30 = v11;
  z = point->z;
  v14 = (float)((float)((float)((float)(z - dir.z) * (float)(bottom_surface_center.z - dir.z))
                      + (float)((float)(v11 - dir.y) * (float)(bottom_surface_center.y - dir.y)))
              + (float)((float)(x - dir.x) * (float)(bottom_surface_center.x - dir.x)))
      / (float)((float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(v10 * v10));
  if ( v14 > 0.0 && *(float *)&clear_value > v14 )
  {
    v15 = p_m_matrix->i.y;
    v16 = (float)(v10 * v14) + dir.x;
    *((float *)&height_vector_proj_point + 1) = dir.y + (float)(v12 * v14);
    v17 = (float)(v13 * v14) + dir.z;
    dir.x = x - v16;
    dir.z = z - v17;
    v18 = p_m_matrix->i.x;
    *(float *)&height_vector_proj_point = v16;
    dir.y = v30 - *((float *)&height_vector_proj_point + 1);
    v31 = p_m_matrix->i.z;
    v41 = dir.x * dir.x + (float)(z - v17) * (float)(z - v17) + dir.y * dir.y;
    height_vector_proj_point_8 = v17;
    v38 = sqrtf((float)((float)(v15 * v15) + (float)(v31 * v31)) + (float)(v18 * v18));
    if ( sqrtf((float)((float)(v15 * v15) + (float)(v31 * v31)) + (float)(v18 * v18)) * v38 > v41 )
    {
      v19 = result;
      v20 = point->z;
      *(_QWORD *)&result->x = *(_QWORD *)&point->x;
      result->z = v20;
      return v19;
    }
    v42 = sqrtf(
            (float)((float)(p_m_matrix->i.z * p_m_matrix->i.z) + (float)(p_m_matrix->i.x * p_m_matrix->i.x))
          + (float)(p_m_matrix->i.y * p_m_matrix->i.y));
    v21 = vostok::math::float3_pod::normalize(&dir);
    v22 = v21->x;
    v23 = v42;
    v24 = v21->y;
    v25 = v21->z;
    goto LABEL_6;
  }
  if ( v14 >= 0.0 )
  {
    v26 = *(_QWORD *)&bottom_surface_center.x;
    height_vector_proj_point_8 = bottom_surface_center.z;
  }
  else
  {
    v26 = *(_QWORD *)&dir.x;
    height_vector_proj_point_8 = dir.z;
  }
  height_vector_proj_point = v26;
  v27 = x - *(float *)&v26;
  *(float *)&v26 = (float)((float)(v27 * transform.j.x)
                         + (float)(transform.j.z * (float)(z - height_vector_proj_point_8)))
                 + (float)(transform.j.y * (float)(v11 - *((float *)&v26 + 1)));
  v28 = v27 - (float)(transform.j.x * *(float *)&v26);
  dir.z = (float)(z - height_vector_proj_point_8) - (float)(transform.j.z * *(float *)&v26);
  dir.y = (float)(v11 - *((float *)&v26 + 1)) - (float)(transform.j.y * *(float *)&v26);
  v37 = p_m_matrix->i.y;
  _X = (float)((float)(dir.z * dir.z) + (float)(dir.y * dir.y)) + (float)(v28 * v28);
  v39 = p_m_matrix->i.x;
  v29 = p_m_matrix->i.x;
  v43 = p_m_matrix->i.z;
  dir.x = v28;
  v32 = sqrtf((float)((float)(v37 * v37) + (float)(v43 * v43)) + (float)(v29 * v29));
  if ( _X > sqrtf((float)((float)(v43 * v43) + (float)(v39 * v39)) + (float)(v37 * v37)) * v32 )
  {
    v40 = sqrtf(
            (float)((float)(p_m_matrix->i.y * p_m_matrix->i.y) + (float)(p_m_matrix->i.z * p_m_matrix->i.z))
          + (float)(p_m_matrix->i.x * p_m_matrix->i.x));
    v23 = v40;
    v44 = 1.0 / sqrtf(_X);
    v22 = v44 * dir.x;
    v24 = v44 * dir.y;
    v25 = v44 * dir.z;
LABEL_6:
    v19 = result;
    result->x = (float)(v22 * v23) + *(float *)&height_vector_proj_point;
    result->y = (float)(v24 * v23) + *((float *)&height_vector_proj_point + 1);
    result->z = (float)(v25 * v23) + height_vector_proj_point_8;
    return v19;
  }
  v19 = result;
  result->x = dir.x + *(float *)&height_vector_proj_point;
  result->y = dir.y + *((float *)&height_vector_proj_point + 1);
  result->z = dir.z + height_vector_proj_point_8;
  return v19;
}
