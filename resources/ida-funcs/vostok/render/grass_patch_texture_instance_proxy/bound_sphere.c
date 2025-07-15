vostok::math::sphere *__thiscall vostok::render::grass_patch_texture_instance_proxy::bound_sphere(
        vostok::render::grass_patch_texture_instance_proxy *this,
        vostok::math::sphere *result)
{
  vostok::math::sphere *v2; // eax

  v2 = result;
  *(_QWORD *)&result->vector.x = 0;
  result->vector.z = 0.0;
  result->vector.w = FLOAT_3000_0;
  return v2;
}
