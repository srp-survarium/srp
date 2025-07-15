void __thiscall survarium::victory_item_core::set_transform(
        survarium::victory_item_core *this,
        const vostok::math::float4x4 *transform)
{
  qmemcpy((void *)&this->m_transform, transform, sizeof(this->m_transform));
  (*(void (__thiscall **)(survarium::collision_geometry *, const vostok::math::float4x4 *))(**(_DWORD **)this->m_collision_geometries
                                                                                          + 16))(
    *this->m_collision_geometries,
    transform);
}
