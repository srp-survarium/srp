vostok::math::aabb *__usercall vostok::math::create_zero_aabb@<eax>(vostok::math::aabb *a1@<eax>)
{
  *(_QWORD *)&a1->min.x = 0;
  *(_QWORD *)&a1->max.x = 0;
  a1->min.z = 0.0;
  a1->max.z = 0.0;
  return a1;
}
