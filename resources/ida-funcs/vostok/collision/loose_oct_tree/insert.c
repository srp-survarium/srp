void __thiscall vostok::collision::loose_oct_tree::insert(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::oct_node *node,
        vostok::collision::object *object,
        const vostok::math::float3 *aabb_center,
        float aabb_extents)
{
  float m_min_aabb_extents; // xmm0_4
  unsigned int v6; // xmm1_4
  unsigned int v7; // xmm2_4
  char v8; // al
  char v9; // dl
  char v10; // cl
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm4_4
  vostok::collision::oct_node **v14; // esi
  vostok::collision::oct_node *v15; // eax
  vostok::collision::oct_node *v16; // [esp-Ch] [ebp-38h]
  vostok::math::float3 aabb_centera; // [esp+10h] [ebp-1Ch] BYREF
  vostok::math::float3 objecta; // [esp+1Ch] [ebp-10h] BYREF
  vostok::collision::loose_oct_tree *v19; // [esp+28h] [ebp-4h]

  m_min_aabb_extents = this->m_min_aabb_extents;
  v19 = this;
  if ( m_min_aabb_extents < aabb_extents )
  {
    *(float *)&v6 = (float)((float)(object->m_aabb.max.y + object->m_aabb.min.y) * 0.5) - aabb_center->y;
    *(float *)&v7 = (float)((float)(object->m_aabb.max.z + object->m_aabb.min.z) * 0.5) - aabb_center->z;
    objecta.x = (float)((float)(object->m_aabb.max.x + object->m_aabb.min.x) * 0.5) - aabb_center->x;
    *(_QWORD *)&objecta.elements[1] = __PAIR64__(v7, v6);
    vostok::math::abs(&objecta, &aabb_centera);
    if ( aabb_centera.x >= (float)((float)(object->m_aabb.max.x - object->m_aabb.min.x) * 0.5)
      && aabb_centera.y >= (float)((float)(object->m_aabb.max.y - object->m_aabb.min.y) * 0.5)
      && aabb_centera.z >= (float)((float)(object->m_aabb.max.z - object->m_aabb.min.z) * 0.5) )
    {
      v8 = -1;
      if ( objecta.z <= 0.0 )
      {
        if ( objecta.z >= 0.0 )
          v9 = 0;
        else
          v9 = -1;
      }
      else
      {
        v9 = 1;
      }
      if ( objecta.y <= 0.0 )
      {
        if ( objecta.y >= 0.0 )
          v10 = 0;
        else
          v10 = -1;
      }
      else
      {
        v10 = 1;
      }
      if ( objecta.x <= 0.0 )
      {
        if ( objecta.x >= 0.0 )
          v8 = 0;
      }
      else
      {
        v8 = 1;
      }
      v11 = (float)v8;
      v12 = (float)v10;
      v13 = (float)v9;
      v14 = &node->octants[(v11 >= 0.0) | (unsigned __int8)(2 * ((v12 >= 0.0) | (2 * (v13 >= 0.0))))];
      if ( !*v14 )
      {
        v15 = vostok::collision::loose_oct_tree::new_node((vostok::collision::loose_oct_tree *)(v11 >= 0.0), (int)v19);
        *v14 = v15;
        v15->parent = node;
      }
      aabb_centera.x = aabb_center->x + (float)(v11 * (float)(aabb_extents * 0.5));
      aabb_centera.y = aabb_center->y + (float)(v12 * (float)(aabb_extents * 0.5));
      v16 = *v14;
      aabb_centera.z = aabb_center->z + (float)(v13 * (float)(aabb_extents * 0.5));
      vostok::collision::loose_oct_tree::insert(v19, v16, object, &aabb_centera, aabb_extents * 0.5);
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
  vostok::collision::object_vtbl *v3; // eax
  vostok::math::aabb *v4; // esi
  vostok::collision::loose_oct_tree *v5; // eax
  vostok::math::aabb v6; // [esp+Ch] [ebp-1Ch] BYREF
  vostok::collision::loose_oct_tree *v7; // [esp+24h] [ebp-4h]

  v3 = object->__vftable;
  v7 = this;
  v4 = v3->update_aabb(object, &v6, local_to_world);
  v5 = v7;
  qmemcpy(&object->m_aabb, v4, sizeof(object->m_aabb));
  vostok::collision::loose_oct_tree::insert_impl(0, v5, object);
}
