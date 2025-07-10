bool __thiscall vostok::collision::triangle_mesh_geometry::ray_test(
        vostok::collision::triangle_mesh_geometry *this,
        const vostok::math::float3 *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  char v6; // [esp+ADh] [ebp-51h] BYREF
  _DWORD v7[2]; // [esp+AEh] [ebp-50h] BYREF
  fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> predicate; // [esp+B6h] [ebp-48h] BYREF
  vostok::collision::colliders::ray_test_geometry v9; // [esp+BEh] [ebp-40h] BYREF

  *distance = max_distance;
  v7[0] = distance;
  v7[1] = &v6;
  predicate.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v7;
  v6 = 0;
  predicate.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))vostok::collision::helper::predicate;
  vostok::collision::colliders::ray_test_geometry::ray_test_geometry(
    &v9,
    this,
    origin,
    direction,
    max_distance,
    &predicate);
  return v6;
}
