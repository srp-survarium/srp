void __userpurge vostok::collision::loose_oct_tree::insert_impl(
        vostok::collision::loose_oct_tree *this@<ecx>,
        vostok::collision::loose_oct_tree *a2@<eax>,
        vostok::collision::object *const object)
{
  unsigned int v3; // xmm2_4
  unsigned int v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  bool v8; // zf
  float v9; // xmm3_4
  vostok::math::float3 v10; // [esp+10h] [ebp-18h] BYREF
  vostok::math::float3 v11; // [esp+1Ch] [ebp-Ch] BYREF

  *(float *)&v3 = (float)(object->m_aabb.max.y + object->m_aabb.min.y) * 0.5;
  *(float *)&v4 = (float)(object->m_aabb.max.z + object->m_aabb.min.z) * 0.5;
  v10.x = (float)(object->m_aabb.min.x + object->m_aabb.max.x) * 0.5;
  v5 = object->m_aabb.max.x - object->m_aabb.min.x;
  *(_QWORD *)&v10.elements[1] = __PAIR64__(v4, v3);
  v6 = object->m_aabb.max.y - object->m_aabb.min.y;
  v8 = !a2->m_initialized;
  v9 = (float)(object->m_aabb.max.z - object->m_aabb.min.z) * 0.5;
  v11.x = v5 * 0.5;
  v11.y = v6 * 0.5;
  v11.z = v9;
  if ( v8 )
  {
    vostok::collision::loose_oct_tree::initialize(object, this, a2, &v10, &v11);
  }
  else
  {
    ++a2->m_objects_count;
    if ( vostok::collision::loose_oct_tree::out_of_bounds(a2, &v10, &v11) )
      vostok::collision::loose_oct_tree::update_bounds(a2, &v10, (int)object, &v11);
    vostok::collision::loose_oct_tree::insert(a2, a2->m_root, object, &a2->m_aabb_center, a2->m_aabb_extents);
  }
}
