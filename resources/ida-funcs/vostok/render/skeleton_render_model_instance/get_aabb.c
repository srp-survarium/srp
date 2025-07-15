vostok::math::aabb *__thiscall vostok::render::skeleton_render_model_instance::get_aabb(
        vostok::render::skeleton_render_model_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v2; // eax
  vostok::math::aabb v4; // [esp+0h] [ebp-18h] BYREF

  v2 = vostok::math::create_identity_aabb(&v4);
  vostok::math::operator*(&result->min.x, &v2->min.x, 2.0);
  return result;
}
