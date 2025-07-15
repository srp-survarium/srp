vostok::math::aabb *__usercall vostok::math::aabb::zero@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::aabb *result@<eax>)
{
  *(_QWORD *)&result->max.x = 0;
  result->max.z = 0.0;
  *(_QWORD *)&result->min.x = 0;
  result->min.z = 0.0;
  return result;
}
