vostok::math::aabb *__usercall vostok::math::create_invalid_aabb@<eax>(vostok::math::aabb *a1@<eax>)
{
  float v1; // xmm0_4
  __int64 v2; // [esp+4h] [ebp-8h]

  *(float *)&v2 = infinity_11;
  *((float *)&v2 + 1) = infinity_11;
  LODWORD(v1) = LODWORD(infinity_11) ^ _mask__NegFloat_;
  a1->min.x = infinity_11;
  *(_QWORD *)&a1->min.elements[1] = v2;
  a1->max.x = v1;
  a1->max.y = v1;
  a1->max.z = v1;
  return a1;
}
