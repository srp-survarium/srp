int __thiscall vostok::collision::collision_object::ray_test(
        vostok::collision::collision_object *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  return ((int (__stdcall *)(const vostok::math::float3 *, const vostok::math::float3 *, _DWORD, float *))this->m_geometry_instance->ray_test)(
           origin,
           direction,
           LODWORD(max_distance),
           distance);
}
