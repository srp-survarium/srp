vostok::math::sphere *__usercall vostok::math::aabb::sphere@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::sphere *a2@<eax>)
{
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v5; // xmm2_4
  __int64 v6; // [esp+4h] [ebp-8h]

  x = this->min.x;
  y = this->min.y;
  z = this->min.z;
  *(float *)&v6 = (float)(this->max.y + y) * 0.5;
  *((float *)&v6 + 1) = (float)(this->max.z + z) * 0.5;
  v5 = (float)(this->min.x + this->max.x) * 0.5;
  a2->vector.x = v5;
  *(_QWORD *)&a2->center.elements[1] = v6;
  a2->vector.w = fsqrt(
                   (float)((float)((float)(*((float *)&v6 + 1) - z) * (float)(*((float *)&v6 + 1) - z))
                         + (float)((float)(*(float *)&v6 - y) * (float)(*(float *)&v6 - y)))
                 + (float)((float)(v5 - x) * (float)(v5 - x)));
  return a2;
}
