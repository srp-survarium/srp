vostok::math::sphere *__thiscall vostok::render::render_surface_instance::get_bound_sphere(
        vostok::render::render_surface_instance *this,
        vostok::math::sphere *result,
        vostok::math::sphere *a3)
{
  vostok::math::aabb *aabb; // eax
  vostok::math::aabb v5; // [esp+0h] [ebp-18h] BYREF

  aabb = vostok::render::render_surface_instance::get_aabb(this, (int)result, &v5);
  vostok::math::aabb::sphere(aabb, a3);
  return a3;
}
