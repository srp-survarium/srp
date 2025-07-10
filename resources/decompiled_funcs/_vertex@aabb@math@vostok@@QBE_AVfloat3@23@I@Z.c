vostok::math::float3 *__userpurge vostok::math::aabb::vertex@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::float3 *a2@<eax>,
        vostok::math::float3 *result,
        unsigned int index)
{
  switch ( (unsigned int)result )
  {
    case 0u:
      a2->x = this->min.x;
      a2->y = this->min.y;
      a2->z = this->min.z;
      break;
    case 1u:
      a2->x = this->min.x;
      a2->y = this->min.y;
      a2->z = this->max.z;
      break;
    case 2u:
      a2->x = this->min.x;
      a2->y = this->max.y;
      a2->z = this->min.z;
      break;
    case 3u:
      a2->x = this->min.x;
      a2->y = this->max.y;
      a2->z = this->max.z;
      break;
    case 4u:
      a2->x = this->max.x;
      a2->y = this->min.y;
      a2->z = this->min.z;
      break;
    case 5u:
      a2->x = this->max.x;
      a2->y = this->min.y;
      a2->z = this->max.z;
      break;
    case 6u:
      a2->x = this->max.x;
      a2->y = this->max.y;
      a2->z = this->min.z;
      break;
    case 7u:
      *a2 = this->max;
      break;
  }
  return a2;
}
