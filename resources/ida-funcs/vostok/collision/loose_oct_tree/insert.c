void __thiscall vostok::collision::loose_oct_tree::insert(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::oct_node *node,
        vostok::collision::object *object,
        const vostok::math::float3 *aabb_center,
        float aabb_extents)
{
  float v5; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm1_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  char v13; // dl
  char v14; // cl
  char v15; // al
  vostok::collision::oct_node **v16; // edi
  vostok::collision::oct_node *v17; // eax
  vostok::collision::oct_node *v18; // eax
  vostok::math::float3 difference; // [esp+1Ch] [ebp-Ch] BYREF

  if ( this->m_min_aabb_extents < aabb_extents )
  {
    v5 = (float)((float)(object->m_aabb.max.z + object->m_aabb.min.z) * 0.5) - aabb_center->z;
    v6 = object->m_aabb.max.z - object->m_aabb.min.z;
    v7 = (float)((float)(object->m_aabb.max.y + object->m_aabb.min.y) * 0.5) - aabb_center->y;
    v8 = object->m_aabb.max.y - object->m_aabb.min.y;
    v9 = (float)((float)(object->m_aabb.max.x + object->m_aabb.min.x) * 0.5) - aabb_center->x;
    v10 = object->m_aabb.max.x - object->m_aabb.min.x;
    LODWORD(difference.x) = LODWORD(v9) & 0x7FFFFFFF;
    v11 = v8 * 0.5;
    v12 = v6 * 0.5;
    if ( COERCE_FLOAT(LODWORD(v9) & 0x7FFFFFFF) >= (float)(v10 * 0.5)
      && COERCE_FLOAT(LODWORD(v7) & 0x7FFFFFFF) >= v11
      && COERCE_FLOAT(LODWORD(v5) & 0x7FFFFFFF) >= v12 )
    {
      if ( v5 <= 0.0 )
      {
        if ( v5 >= 0.0 )
          v13 = 0;
        else
          v13 = -1;
      }
      else
      {
        v13 = 1;
      }
      if ( v7 <= 0.0 )
      {
        if ( v7 >= 0.0 )
          v14 = 0;
        else
          v14 = -1;
      }
      else
      {
        v14 = 1;
      }
      if ( v9 <= 0.0 )
      {
        if ( v9 >= 0.0 )
          v15 = 0;
        else
          v15 = -1;
      }
      else
      {
        v15 = 1;
      }
      difference.x = (float)v15;
      difference.y = (float)v14;
      difference.z = (float)v13;
      v16 = &node->octants[(unsigned __int8)vostok::collision::octant_index(&difference)];
      if ( !*v16 )
      {
        v17 = vostok::collision::vertex_allocator::allocate(this->m_allocator);
        *v16 = v17;
        v17->parent = node;
      }
      v18 = *v16;
      difference.x = aabb_center->x + (float)(difference.x * (float)(aabb_extents * 0.5));
      difference.y = aabb_center->y + (float)(difference.y * (float)(aabb_extents * 0.5));
      difference.z = aabb_center->z + (float)(difference.z * (float)(aabb_extents * 0.5));
      vostok::collision::loose_oct_tree::insert(this, v18, object, &difference, aabb_extents * 0.5);
    }
    else
    {
      object->m_node = node;
      object->m_next = node->objects;
      node->objects = object;
    }
  }
  else
  {
    object->m_node = node;
    object->m_next = node->objects;
    node->objects = object;
  }
}


void __thiscall vostok::collision::loose_oct_tree::insert(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::object *object,
        const vostok::math::float4x4 *local_to_world)
{
  _BYTE v4[24]; // [esp+8h] [ebp-18h] BYREF

  object->m_aabb = *object->update_aabb(object, v4, local_to_world);
  vostok::collision::loose_oct_tree::insert_impl(this, object);
}
