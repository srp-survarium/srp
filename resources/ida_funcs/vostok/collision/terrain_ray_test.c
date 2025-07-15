bool __usercall vostok::collision::terrain_ray_test<vostok::collision::terrain_data>@<al>(
        const vostok::math::float3 *p_os@<ecx>,
        const vostok::math::float3 *d_ir@<eax>,
        bool a3@<dil>,
        const vostok::collision::terrain_data *terrain_data,
        float max_distance,
        float *distance)
{
  float z; // edx
  float m_physical_size; // xmm3_4
  __int64 v8; // xmm0_8
  float v9; // ecx
  float x; // xmm1_4
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  unsigned int m_vertex_row_size; // edi
  float v23; // xmm2_4
  float v24; // xmm1_4
  int v25; // edx
  float v26; // xmm6_4
  int v27; // eax
  int v28; // ecx
  float v29; // xmm5_4
  int v30; // esi
  int v31; // edx
  int v32; // edi
  float terrain_size; // [esp+14h] [ebp-24h]
  float v36; // [esp+1Ch] [ebp-1Ch]
  float v37; // [esp+1Ch] [ebp-1Ch]
  vostok::math::float3 ray_direction; // [esp+20h] [ebp-18h] BYREF
  vostok::math::float3 ray_start; // [esp+2Ch] [ebp-Ch] BYREF

  z = d_ir->z;
  m_physical_size = terrain_data->m_physical_size;
  v36 = m_physical_size;
  v8 = *(_QWORD *)&p_os->x;
  v9 = p_os->z;
  *(_QWORD *)&ray_start.x = v8;
  *(_QWORD *)&ray_direction.x = *(_QWORD *)&d_ir->x;
  x = ray_direction.x;
  terrain_size = m_physical_size;
  ray_start.z = v9;
  ray_direction.z = z;
  if ( COERCE_FLOAT(LODWORD(ray_direction.x) & 0x7FFFFFFF) < 0.0000099999997 )
  {
    x = FLOAT_0_000099999997;
    ray_direction.x = FLOAT_0_000099999997;
  }
  if ( COERCE_FLOAT(LODWORD(ray_direction.y) & 0x7FFFFFFF) < 0.0000099999997 )
    ray_direction.y = FLOAT_0_000099999997;
  v11 = ray_direction.z;
  if ( COERCE_FLOAT(LODWORD(ray_direction.z) & 0x7FFFFFFF) < 0.0000099999997 )
  {
    v11 = FLOAT_0_000099999997;
    ray_direction.z = FLOAT_0_000099999997;
  }
  v12 = (float)-ray_start.x * (float)(*(float *)&clear_value / x);
  v13 = (float)(m_physical_size - ray_start.x) * (float)(*(float *)&clear_value / x);
  if ( v12 > v13 )
  {
    v12 = v13;
    v13 = (float)-ray_start.x * (float)(*(float *)&clear_value / x);
  }
  v14 = terrain_size;
  v15 = -(float)((float)(ray_start.z + terrain_size) * (float)(*(float *)&clear_value / v11));
  v16 = (float)-ray_start.z * (float)(*(float *)&clear_value / v11);
  if ( v16 > v15 )
  {
    v16 = -(float)((float)(ray_start.z + terrain_size) * (float)(*(float *)&clear_value / v11));
    v15 = (float)-ray_start.z * (float)(*(float *)&clear_value / v11);
  }
  if ( v12 <= v16 )
    v12 = v16;
  v17 = 0.0;
  if ( v12 <= 0.0 )
    v12 = 0.0;
  v18 = v13;
  if ( v13 <= 0.0 )
    v18 = 0.0;
  if ( v15 >= 0.0 && v15 <= v18 )
    v18 = v15;
  v19 = (float)(v12 * ray_direction.x) + ray_start.x;
  v20 = (float)(v12 * ray_direction.z) + ray_start.z;
  if ( v19 > 0.0 )
  {
    if ( terrain_size >= v19 )
      v14 = v19;
  }
  else
  {
    v14 = 0.0;
  }
  if ( (float)-terrain_size < v20 )
  {
    if ( v20 <= 0.0 )
      v17 = v20;
  }
  else
  {
    v17 = -terrain_size;
  }
  v21 = v18 - 0.0000099999997;
  m_vertex_row_size = terrain_data->m_vertex_row_size;
  v23 = (float)(v21 * ray_direction.x) + ray_start.x;
  v24 = (float)(v21 * ray_direction.z) + ray_start.z;
  v25 = m_vertex_row_size - 1;
  v37 = v36 / (double)(m_vertex_row_size - 1);
  v26 = *(float *)&clear_value / (float)(int)v37;
  v27 = (int)(float)(v26 * v14);
  v28 = -(int)(float)(v26 * v17);
  if ( v27 > 0 )
  {
    if ( v27 > v25 )
      v27 = m_vertex_row_size - 1;
  }
  else
  {
    v27 = 0;
  }
  if ( (int)(float)(v26 * v17) < 0 )
  {
    if ( v28 > v25 )
      v28 = m_vertex_row_size - 1;
  }
  else
  {
    v28 = 0;
  }
  v29 = *(float *)&clear_value / (float)(int)v37;
  v30 = (int)(float)(v29 * v23);
  v31 = -(int)(float)(v29 * v24);
  v32 = m_vertex_row_size - 1;
  if ( v30 > 0 )
  {
    if ( v30 > v32 )
      v30 = v32;
  }
  else
  {
    v30 = 0;
  }
  if ( (int)(float)(v29 * v24) < 0 )
  {
    if ( v31 > v32 )
      v31 = v32;
  }
  else
  {
    v31 = 0;
  }
  return vostok::collision::bresenham<vostok::collision::terrain_data>(
           terrain_data,
           v28,
           v27,
           v31,
           v30,
           &ray_start,
           &ray_direction,
           max_distance,
           distance,
           a3);
}
