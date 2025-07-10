void __thiscall vostok::collision::intersection_double_dispatcher::dispatch(
        vostok::collision::intersection_double_dispatcher *this,
        const vostok::collision::capsule_geometry_instance *bounding_volume,
        const vostok::collision::capsule_geometry_instance *testee)
{
  const vostok::math::float4x4 *v4; // eax
  float x; // xmm1_4
  const vostok::math::float4x4 *v6; // eax
  float v7; // xmm0_4
  const vostok::collision::geometry_instance *m_testee; // ecx
  const vostok::math::float4x4 *(__thiscall *get_matrix)(vostok::collision::geometry_instance *); // edx
  float *p_x; // eax
  const vostok::math::float4x4 *v11; // eax
  float v12; // xmm0_4
  const vostok::collision::geometry_instance *m_bounding_volume; // ecx
  const vostok::math::float4x4 *(__thiscall *v14)(vostok::collision::geometry_instance *); // edx
  float *v15; // eax
  float v16; // xmm1_4
  const vostok::math::float4x4 *v17; // eax
  float v18; // xmm0_4
  const vostok::collision::geometry_instance *v19; // ecx
  const vostok::math::float4x4 *(__thiscall *v20)(vostok::collision::geometry_instance *); // edx
  float *v21; // eax
  float v22; // xmm1_4
  const vostok::math::float4x4 *v23; // eax
  float v24; // xmm0_4
  float m_half_length; // [esp+0h] [ebp-4Ch]
  float v26; // [esp+4h] [ebp-48h]
  float v27; // [esp+8h] [ebp-44h]
  float m_radius; // [esp+Ch] [ebp-40h]
  float v29; // [esp+10h] [ebp-3Ch]
  float v30; // [esp+14h] [ebp-38h]
  float v31; // [esp+14h] [ebp-38h]
  float v32; // [esp+14h] [ebp-38h]
  float v33; // [esp+14h] [ebp-38h]
  float v34; // [esp+18h] [ebp-34h]
  float v35; // [esp+18h] [ebp-34h]
  float v36; // [esp+18h] [ebp-34h]
  float v37; // [esp+18h] [ebp-34h]
  vostok::math::float3 p4; // [esp+1Ch] [ebp-30h] BYREF
  vostok::math::float3 p1; // [esp+28h] [ebp-24h] BYREF
  vostok::math::float3 v40; // [esp+34h] [ebp-18h] BYREF
  float v41[3]; // [esp+40h] [ebp-Ch] BYREF

  m_half_length = testee->m_half_length;
  v26 = bounding_volume->m_half_length;
  m_radius = testee->m_radius;
  v27 = bounding_volume->m_radius;
  v4 = this->m_testee->get_matrix(this->m_testee);
  x = v4->j.x;
  v4 = (const vostok::math::float4x4 *)((char *)v4 + 16);
  v30 = v4->i.y * m_half_length;
  v34 = v4->i.z * m_half_length;
  v6 = this->m_testee->get_matrix(this->m_testee);
  v7 = v6->c.x - (float)(x * m_half_length);
  m_testee = this->m_testee;
  v6 = (const vostok::math::float4x4 *)((char *)v6 + 48);
  p4.x = v7;
  p4.y = v6->i.y - v30;
  get_matrix = m_testee->get_matrix;
  p4.z = v6->i.z - v34;
  p_x = &get_matrix((vostok::collision::geometry_instance *)m_testee)->j.x;
  v29 = m_half_length * *p_x;
  v31 = p_x[1] * m_half_length;
  v35 = p_x[2] * m_half_length;
  v11 = this->m_testee->get_matrix(this->m_testee);
  v12 = v29 + v11->c.x;
  m_bounding_volume = this->m_bounding_volume;
  v11 = (const vostok::math::float4x4 *)((char *)v11 + 48);
  v40.x = v12;
  v40.y = v11->i.y + v31;
  v14 = m_bounding_volume->get_matrix;
  v40.z = v11->i.z + v35;
  v15 = (float *)v14((vostok::collision::geometry_instance *)m_bounding_volume);
  v16 = v15[4];
  v15 += 4;
  v32 = v15[1] * v26;
  v36 = v15[2] * v26;
  v17 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v18 = v17->c.x - (float)(v16 * v26);
  v19 = this->m_bounding_volume;
  v17 = (const vostok::math::float4x4 *)((char *)v17 + 48);
  v41[0] = v18;
  v41[1] = v17->i.y - v32;
  v20 = v19->get_matrix;
  v41[2] = v17->i.z - v36;
  v21 = (float *)v20((vostok::collision::geometry_instance *)v19);
  v22 = v21[4];
  v21 += 4;
  v33 = v21[1] * v26;
  v37 = v21[2] * v26;
  v23 = this->m_bounding_volume->get_matrix(this->m_bounding_volume);
  v24 = (float)(v22 * v26) + v23->c.x;
  v23 = (const vostok::math::float4x4 *)((char *)v23 + 48);
  p1.x = v24;
  p1.y = v23->i.y + v33;
  p1.z = v23->i.z + v37;
  this->m_result = vostok::collision::segment_segment_intersect(v41, &v40, v27 + m_radius, &p1, &p4);
}
