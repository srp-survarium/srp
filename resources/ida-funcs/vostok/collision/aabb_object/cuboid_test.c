BOOL __thiscall vostok::collision::aabb_object::cuboid_test(
        vostok::collision::aabb_object *this,
        const vostok::math::cuboid *cuboid)
{
  int v2; // eax

  v2 = vostok::math::cuboid::test_inexact(
         (vostok::math::cuboid *)&this->m_aabb,
         (int)cuboid,
         (vostok::math::aabb_plane *)&this->m_aabb);
  return v2 == 1 || v2 == 3;
}
