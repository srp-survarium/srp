vostok::math::aabb *__thiscall vostok::render::skeleton_render_model_instance::get_aabb(
        vostok::render::skeleton_render_model_instance *this,
        vostok::math::aabb *result)
{
  vostok::math::aabb *v2; // eax
  __int64 v3; // [esp+0h] [ebp-Ch]

  v2 = result;
  *(_QWORD *)&result->min.x = 0xC0000000C0000000uLL;
  *(float *)&v3 = retry_to_increase_quality_period_sec;
  *((float *)&v3 + 1) = retry_to_increase_quality_period_sec;
  *(_QWORD *)&result->max.x = v3;
  result->min.z = -2.0;
  result->max.z = retry_to_increase_quality_period_sec;
  return v2;
}
