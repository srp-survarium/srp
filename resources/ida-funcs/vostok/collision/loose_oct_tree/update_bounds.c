void __userpurge vostok::collision::loose_oct_tree::update_bounds(
        vostok::collision::loose_oct_tree *this@<esi>,
        const vostok::math::float3 *aabb_center@<edi>,
        int a3@<ebx>,
        const vostok::math::float3 *aabb_extents)
{
  vostok::math::float3 *v4; // eax
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float m_aabb_extents; // xmm2_4
  float v10; // xmm0_4
  unsigned int v11; // eax
  float v12; // xmm5_4
  float v13; // xmm3_4
  char v14; // al
  char v15; // cl
  float v16; // xmm4_4
  char v17; // dl
  float v18; // xmm7_4
  vostok::collision::loose_oct_tree *v19; // ecx
  float v20; // xmm0_4
  char v21; // bl
  vostok::collision::oct_node *v22; // eax
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm0_4
  long double v26; // [esp+4h] [ebp-24h] BYREF
  vostok::math::float3 object; // [esp+14h] [ebp-14h] BYREF
  float v28; // [esp+20h] [ebp-8h]
  float v29; // [esp+24h] [ebp-4h]

  object.x = aabb_center->x - this->m_aabb_center.x;
  object.y = aabb_center->y - this->m_aabb_center.y;
  LODWORD(v26) = a3;
  object.z = aabb_center->z - this->m_aabb_center.z;
  v4 = vostok::math::abs(&object, (vostok::math::float3 *)((char *)&v26 + 4));
  v5 = v4->y + aabb_extents->y;
  v6 = v4->z + aabb_extents->z;
  v7 = v4->x + aabb_extents->x;
  if ( v5 <= v6 )
    v8 = v4->z + aabb_extents->z;
  else
    v8 = v4->y + aabb_extents->y;
  if ( v7 < v8 )
  {
    if ( v7 <= v6 )
      v7 = v4->z + aabb_extents->z;
    m_aabb_extents = this->m_aabb_extents;
    if ( v5 < v7 )
      v10 = m_aabb_extents + v6;
    else
      v10 = m_aabb_extents + v5;
  }
  else
  {
    m_aabb_extents = this->m_aabb_extents;
    v10 = m_aabb_extents + v7;
  }
  v28 = v10 * 0.5;
  __libm_sse2_log(v26);
  v29 = (float)(v10 * 0.5) / m_aabb_extents;
  __libm_sse2_log(v26);
  v11 = vostok::math::floor(v29 / (float)2.0);
  v29 = pow(2.0, (double)v11) * m_aabb_extents;
  if ( v28 > (double)v29 )
  {
    LODWORD(v28) = v11 + 1;
    v29 = pow(2.0, (double)(v11 + 1)) * m_aabb_extents;
  }
  v12 = m_aabb_extents * 2.0;
  if ( v29 >= (float)(m_aabb_extents * 2.0) )
  {
    do
    {
      v13 = this->m_aabb_center.x - aabb_center->x;
      if ( v13 <= 0.0 )
      {
        if ( v13 >= 0.0 )
          v14 = 0;
        else
          v14 = -1;
      }
      else
      {
        v14 = 1;
      }
      v16 = COERCE_FLOAT(make_non_zero(COERCE_INT((float)v14)));
      v18 = COERCE_FLOAT(make_non_zero(COERCE_INT((float)v15)));
      v20 = COERCE_FLOAT(make_non_zero(COERCE_INT((float)v17)));
      if ( v16 >= 0.0 )
      {
        v21 = 1;
        LODWORD(v28) = 1;
      }
      else
      {
        v28 = 0.0;
        v21 = 1;
      }
      if ( v20 < 0.0 )
        v21 = 0;
      v22 = vostok::collision::loose_oct_tree::new_node(v19, (int)this);
      v22->octants[LOBYTE(v28) | (unsigned __int8)(2 * ((v18 >= 0.0) | (2 * v21)))] = this->m_root;
      this->m_root->parent = v22;
      this->m_root = v22;
      v23 = this->m_aabb_extents * v16;
      v24 = this->m_aabb_extents;
      this->m_aabb_center.x = this->m_aabb_center.x - v23;
      this->m_aabb_center.y = this->m_aabb_center.y - (float)(v24 * v18);
      this->m_aabb_center.z = this->m_aabb_center.z - (float)(v24 * v20);
      v25 = v29;
      this->m_aabb_extents = v12;
      v12 = v12 * 2.0;
    }
    while ( v25 >= v12 );
  }
}
