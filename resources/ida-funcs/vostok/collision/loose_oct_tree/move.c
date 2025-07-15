void __thiscall vostok::collision::loose_oct_tree::move(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::object *object,
        const vostok::math::float4x4 *new_local_to_world)
{
  float v4; // [esp+Ch] [ebp-30h] BYREF
  float v5; // [esp+10h] [ebp-2Ch]
  float v6; // [esp+14h] [ebp-28h]
  float v7; // [esp+18h] [ebp-24h]
  float v8; // [esp+1Ch] [ebp-20h]
  float v9; // [esp+20h] [ebp-1Ch]
  vostok::collision::move_helper predicate; // [esp+24h] [ebp-18h] BYREF
  vostok::math::float3 v11; // [esp+30h] [ebp-Ch] BYREF

  object->update_aabb(object, (vostok::math::aabb *)&v4, new_local_to_world);
  v11.x = (float)(v7 - v4) * 0.5;
  v11.y = (float)(v8 - v5) * 0.5;
  v11.z = (float)(v9 - v6) * 0.5;
  *(float *)&predicate.m_tree = (float)(v4 + v7) * 0.5;
  *(float *)&predicate.m_object = (float)(v5 + v8) * 0.5;
  *(float *)&predicate.m_local_to_world = (float)(v6 + v9) * 0.5;
  if ( vostok::collision::loose_oct_tree::out_of_bounds(this, (const vostok::math::float3 *)&predicate, &v11) )
  {
    this->erase(this, object);
    this->insert(this, object, new_local_to_world);
  }
  else
  {
    predicate.m_local_to_world = new_local_to_world;
    predicate.m_tree = this;
    predicate.m_object = object;
    vostok::collision::loose_oct_tree::remove_impl<vostok::collision::move_helper>(this, object, &predicate);
  }
}
