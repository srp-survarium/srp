void __thiscall vostok::collision::loose_oct_tree::move(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::object *object,
        const vostok::math::float4x4 *new_local_to_world)
{
  vostok::math::float3 aabb_extents; // [esp+10h] [ebp-30h] BYREF
  vostok::math::float3 aabb_center; // [esp+1Ch] [ebp-24h] BYREF
  float v6; // [esp+28h] [ebp-18h] BYREF
  float v7; // [esp+2Ch] [ebp-14h]
  float v8; // [esp+30h] [ebp-10h]
  float v9; // [esp+34h] [ebp-Ch]
  float v10; // [esp+38h] [ebp-8h]
  float v11; // [esp+3Ch] [ebp-4h]

  object->update_aabb(object, (vostok::math::aabb *)&v6, new_local_to_world);
  aabb_extents.x = (float)(v9 - v6) * 0.5;
  aabb_extents.y = (float)(v10 - v7) * 0.5;
  aabb_extents.z = (float)(v11 - v8) * 0.5;
  aabb_center.x = (float)(v6 + v9) * 0.5;
  aabb_center.y = (float)(v7 + v10) * 0.5;
  aabb_center.z = (float)(v8 + v11) * 0.5;
  if ( vostok::collision::loose_oct_tree::out_of_bounds(&aabb_extents, &aabb_center, this) )
  {
    this->erase(this, object);
    this->insert(this, object, new_local_to_world);
  }
  else
  {
    LODWORD(aabb_center.x) = this;
    *(_QWORD *)&aabb_center.elements[1] = __PAIR64__((unsigned int)new_local_to_world, (unsigned int)object);
    vostok::collision::loose_oct_tree::remove_impl<vostok::collision::move_helper>(
      this,
      object,
      (const vostok::collision::move_helper *)&aabb_center);
  }
}
