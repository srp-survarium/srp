vostok::math::aabb *__usercall vostok::math::aabb::modify@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::aabb *result@<eax>)
{
  float v2; // edx
  float v3; // ecx
  __int64 v4; // [esp+0h] [ebp-Ch]
  float z; // [esp+8h] [ebp-4h]

  if ( this->min.x <= result->min.x )
    *(float *)&v4 = this->min.x;
  else
    *(float *)&v4 = result->min.x;
  if ( this->min.y <= result->min.y )
    HIDWORD(v4) = LODWORD(this->min.y);
  else
    HIDWORD(v4) = LODWORD(result->min.y);
  if ( this->min.z <= result->min.z )
    z = this->min.z;
  else
    z = result->min.z;
  v2 = z;
  *(_QWORD *)&result->min.x = v4;
  result->min.z = v2;
  if ( result->max.x <= this->min.x )
    *(float *)&v4 = this->min.x;
  else
    *(float *)&v4 = result->max.x;
  if ( result->max.y <= this->min.y )
    HIDWORD(v4) = LODWORD(this->min.y);
  else
    HIDWORD(v4) = LODWORD(result->max.y);
  if ( result->max.z <= this->min.z )
    z = this->min.z;
  else
    z = result->max.z;
  v3 = z;
  *(_QWORD *)&result->max.x = v4;
  result->max.z = v3;
  return result;
}
