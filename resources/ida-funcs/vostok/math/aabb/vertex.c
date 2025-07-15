vostok::math::float3 *__userpurge vostok::math::aabb::vertex@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::float3 *a2@<eax>,
        vostok::math::float3 *result,
        unsigned int index)
{
  double x; // st7
  double y; // st7
  double z; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7

  switch ( (unsigned int)result )
  {
    case 0u:
      x = this->min.x;
      goto LABEL_3;
    case 1u:
      v7 = this->min.x;
      goto LABEL_6;
    case 2u:
      v9 = this->min.x;
      goto LABEL_8;
    case 3u:
      v10 = this->min.x;
      goto LABEL_14;
    case 4u:
      x = this->max.x;
LABEL_3:
      a2->x = x;
      y = this->min.y;
      goto LABEL_4;
    case 5u:
      v7 = this->max.x;
LABEL_6:
      a2->x = v7;
      v8 = this->min.y;
      goto LABEL_15;
    case 6u:
      v9 = this->max.x;
LABEL_8:
      a2->x = v9;
      y = this->max.y;
LABEL_4:
      a2->y = y;
      z = this->min.z;
      goto LABEL_16;
    case 7u:
      v10 = this->max.x;
LABEL_14:
      a2->x = v10;
      v8 = this->max.y;
LABEL_15:
      a2->y = v8;
      z = this->max.z;
LABEL_16:
      a2->z = z;
      return a2;
  }
}
