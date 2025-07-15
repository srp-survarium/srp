vostok::math::quaternion *__usercall vostok::math::conjugate@<eax>(
        const vostok::math::quaternion *value@<ecx>,
        vostok::math::quaternion *result@<eax>)
{
  float w; // [esp+14h] [ebp-10h]
  __int64 v3; // [esp+1Ch] [ebp-8h]

  w = value->w;
  LODWORD(v3) = LODWORD(value->y) ^ _mask__NegFloat_;
  HIDWORD(v3) = LODWORD(value->z) ^ _mask__NegFloat_;
  LODWORD(result->x) = LODWORD(value->x) ^ _mask__NegFloat_;
  *(_QWORD *)&result->vector.elements[1] = v3;
  result->w = w;
  return result;
}
