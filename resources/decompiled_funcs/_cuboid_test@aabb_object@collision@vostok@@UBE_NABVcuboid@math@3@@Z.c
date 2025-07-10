BOOL __thiscall vostok::collision::aabb_object::cuboid_test(
        vostok::collision::aabb_object *this,
        const vostok::math::cuboid *cuboid)
{
  vostok::math::intersection v2; // eax

  v2 = vostok::math::cuboid::test_inexact((vostok::math::cuboid *)&this->m_aabb, &this->m_aabb);
  return v2 == intersection_inside || v2 == intersection_intersect;
}
