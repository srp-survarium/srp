char __thiscall vostok::collision::aabb_object::cuboid_query(
        vostok::collision::aabb_object *this,
        const vostok::math::cuboid *cuboid,
        vostok::buffer_vector<vostok::collision::triangle_result> *triangles)
{
  vostok::collision::triangle_result value; // [esp+4h] [ebp-8h] BYREF

  if ( vostok::math::cuboid::test_inexact(
         (vostok::math::cuboid *)this,
         (int)cuboid,
         (vostok::math::aabb_plane *)&this->m_aabb) == 2 )
    return 0;
  value.triangle_id = -1;
  value.object = this;
  vostok::buffer_vector<vostok::collision::triangle_result>::push_back(triangles, &value);
  return 1;
}
