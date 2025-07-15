vostok::math::aabb *__userpurge vostok::math::aabb::modify@<eax>(
        vostok::math::aabb *other@<esi>,
        vostok::math::aabb *this)
{
  vostok::math::aabb::modify(other, this);
  vostok::math::aabb::modify((vostok::math::aabb *)&other->max, this);
  return this;
}


vostok::math::aabb *__usercall vostok::math::aabb::modify@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::aabb *result@<eax>)
{
  __int64 v2; // [esp+0h] [ebp-Ch]
  _BYTE v3[12]; // [esp+0h] [ebp-Ch]
  float z; // [esp+8h] [ebp-4h]

  if ( this->min.x <= result->min.x )
    *(float *)&v2 = this->min.x;
  else
    *(float *)&v2 = result->min.x;
  if ( this->min.y <= result->min.y )
    HIDWORD(v2) = LODWORD(this->min.y);
  else
    HIDWORD(v2) = LODWORD(result->min.y);
  if ( this->min.z <= result->min.z )
    z = this->min.z;
  else
    z = result->min.z;
  *(_QWORD *)&result->min.x = v2;
  result->min.z = z;
  if ( result->max.x <= this->min.x )
    *(float *)v3 = this->min.x;
  else
    *(float *)v3 = result->max.x;
  if ( result->max.y <= this->min.y )
    *(float *)&v3[4] = this->min.y;
  else
    *(float *)&v3[4] = result->max.y;
  if ( result->max.z <= this->min.z )
    *(float *)&v3[8] = this->min.z;
  else
    *(float *)&v3[8] = result->max.z;
  result->max = *(vostok::math::float3 *)v3;
  return result;
}


vostok::math::aabb *__usercall vostok::math::aabb::modify@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::aabb *result@<eax>)
{
  vostok::math::float3 *p_max; // edx
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm6_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float y; // xmm3_4
  float v10; // [esp+Ch] [ebp-34h]
  float v11; // [esp+14h] [ebp-2Ch]
  float v12; // [esp+18h] [ebp-28h]
  float v13; // [esp+20h] [ebp-20h]
  float v14; // [esp+28h] [ebp-18h]
  float v15; // [esp+2Ch] [ebp-14h]
  _BYTE v16[12]; // [esp+30h] [ebp-10h]

  p_max = &result->max;
  v3 = result->max.x - result->min.x;
  v4 = result->max.y - result->min.y;
  v5 = result->max.z - result->min.z;
  v14 = this->min.y * v3;
  v6 = this->min.x * v3;
  v15 = this->min.z * v3;
  v13 = this[1].min.x * v4;
  v12 = this->max.y * v4;
  v7 = this->max.z * v4;
  v11 = this[1].max.y * v5;
  v10 = v5 * this[1].min.z;
  v8 = this[1].max.x * v5;
  y = result->min.y;
  *(float *)v16 = (float)((float)((float)(this->min.x * result->min.x) + (float)(result->min.z * this[1].min.z))
                        + (float)(y * this->max.y))
                + this[2].min.x;
  *(float *)&v16[4] = (float)((float)((float)(this[1].max.x * result->min.z) + (float)(this->max.z * y))
                            + (float)(this->min.y * result->min.x))
                    + this[2].min.y;
  *(float *)&v16[8] = (float)((float)((float)(this[1].max.y * result->min.z) + (float)(this[1].min.x * y))
                            + (float)(this->min.z * result->min.x))
                    + this[2].min.z;
  *(_QWORD *)&result->min.x = *(_QWORD *)v16;
  result->min.z = *(float *)&v16[8];
  result->max = *(vostok::math::float3 *)v16;
  if ( v6 >= 0.0 )
    p_max->x = v6 + p_max->x;
  else
    result->min.x = result->min.x + v6;
  if ( v14 >= 0.0 )
    result->max.y = result->max.y + v14;
  else
    result->min.y = result->min.y + v14;
  if ( v15 >= 0.0 )
    result->max.z = result->max.z + v15;
  else
    result->min.z = result->min.z + v15;
  if ( v12 >= 0.0 )
    p_max->x = p_max->x + v12;
  else
    result->min.x = result->min.x + v12;
  if ( v7 >= 0.0 )
    result->max.y = v7 + result->max.y;
  else
    result->min.y = result->min.y + v7;
  if ( v13 >= 0.0 )
    result->max.z = result->max.z + v13;
  else
    result->min.z = result->min.z + v13;
  if ( v10 >= 0.0 )
    p_max->x = p_max->x + v10;
  else
    result->min.x = result->min.x + v10;
  if ( v8 >= 0.0 )
    result->max.y = result->max.y + v8;
  else
    result->min.y = v8 + result->min.y;
  if ( v11 >= 0.0 )
    result->max.z = result->max.z + v11;
  else
    result->min.z = result->min.z + v11;
  return result;
}
