vostok::math::aabb *__usercall vostok::math::aabb::move@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::aabb *result@<eax>)
{
  result->min.x = this->min.x + result->min.x;
  result->min.y = result->min.y + this->min.y;
  result->min.z = result->min.z + this->min.z;
  result->max.x = result->max.x + this->min.x;
  result->max.y = result->max.y + this->min.y;
  result->max.z = result->max.z + this->min.z;
  return result;
}
