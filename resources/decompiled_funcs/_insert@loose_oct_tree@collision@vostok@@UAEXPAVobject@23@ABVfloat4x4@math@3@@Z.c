void __thiscall vostok::collision::loose_oct_tree::insert(
        vostok::collision::loose_oct_tree *this,
        vostok::collision::object *object,
        const vostok::math::float4x4 *local_to_world)
{
  _BYTE v4[24]; // [esp+8h] [ebp-18h] BYREF

  object->m_aabb = *object->update_aabb(object, v4, local_to_world);
  vostok::collision::loose_oct_tree::insert_impl(this, object);
}
