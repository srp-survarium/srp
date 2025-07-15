vostok::math::float4x4 *__thiscall survarium::usable_object::get_transform(
        survarium::usable_object *this,
        vostok::math::float4x4 *result)
{
  (*(void (__thiscall **)(survarium::collision_geometry *, vostok::math::float4x4 *))(**(_DWORD **)this->m_collision_geometries
                                                                                    + 20))(
    *this->m_collision_geometries,
    result);
  return result;
}
