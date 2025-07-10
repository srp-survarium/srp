void __usercall vostok::collision::loose_oct_tree::insert_impl(
        vostok::collision::loose_oct_tree *this@<eax>,
        vostok::collision::object *const object@<edi>)
{
  unsigned int v2; // xmm1_4
  unsigned int v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  bool v7; // zf
  float v8; // xmm2_4
  vostok::math::float3 aabb_extents; // [esp+8h] [ebp-18h] BYREF
  vostok::math::float3 aabb_center; // [esp+14h] [ebp-Ch] BYREF

  *(float *)&v2 = (float)(object->m_aabb.max.y + object->m_aabb.min.y) * 0.5;
  *(float *)&v3 = (float)(object->m_aabb.max.z + object->m_aabb.min.z) * 0.5;
  aabb_center.x = (float)(object->m_aabb.min.x + object->m_aabb.max.x) * 0.5;
  v4 = object->m_aabb.max.x - object->m_aabb.min.x;
  *(_QWORD *)&aabb_center.elements[1] = __PAIR64__(v3, v2);
  v5 = object->m_aabb.max.y - object->m_aabb.min.y;
  v7 = !this->m_initialized;
  v8 = (float)(object->m_aabb.max.z - object->m_aabb.min.z) * 0.5;
  aabb_extents.x = v4 * 0.5;
  aabb_extents.y = v5 * 0.5;
  aabb_extents.z = v8;
  if ( v7 )
  {
    vostok::collision::loose_oct_tree::initialize(this, object, &aabb_center, &aabb_extents);
  }
  else
  {
    ++this->m_object_count;
    if ( vostok::collision::loose_oct_tree::out_of_bounds(&aabb_extents, &aabb_center, this) )
      vostok::collision::loose_oct_tree::update_bounds(this, &aabb_extents, &aabb_center);
    vostok::collision::loose_oct_tree::insert(this, this->m_root, object, &this->m_aabb_center, this->m_aabb_extents);
  }
}
