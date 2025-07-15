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


vostok::math::aabb *__usercall vostok::math::aabb::modify@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::aabb *result@<eax>)
{
  float y; // xmm5_4
  float z; // xmm6_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm7_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // [esp+0h] [ebp-38h]
  float v12; // [esp+4h] [ebp-34h]
  __int64 v13; // [esp+8h] [ebp-30h]
  float vx; // [esp+14h] [ebp-24h]
  float vx_4; // [esp+18h] [ebp-20h]
  float vy; // [esp+20h] [ebp-18h]
  float vy_4; // [esp+24h] [ebp-14h]
  float vz; // [esp+2Ch] [ebp-Ch]
  float vz_4; // [esp+30h] [ebp-8h]

  y = result->min.y;
  z = result->min.z;
  v4 = result->max.x - result->min.x;
  vx = this->min.x * v4;
  v5 = result->max.z - z;
  v11 = this->min.y;
  v6 = result->max.y - y;
  vx_4 = v11 * v4;
  v12 = this->min.z;
  v7 = v12 * v4;
  vy = this->max.y * v6;
  vy_4 = this->max.z * v6;
  v8 = this[1].min.x * v6;
  vz = v5 * this[1].min.z;
  vz_4 = this[1].max.x * v5;
  v9 = this[1].max.y * v5;
  *(float *)&v13 = (float)((float)((float)(this->min.x * result->min.x) + (float)(z * this[1].min.z))
                         + (float)(y * this->max.y))
                 + this[2].min.x;
  *((float *)&v13 + 1) = (float)((float)((float)(this[1].max.x * z) + (float)(this->max.z * y))
                               + (float)(v11 * result->min.x))
                       + this[2].min.y;
  v10 = (float)((float)((float)(this[1].max.y * z) + (float)(this[1].min.x * y)) + (float)(v12 * result->min.x))
      + this[2].min.z;
  *(_QWORD *)&result->min.x = v13;
  *(_QWORD *)&result->max.x = v13;
  result->min.z = v10;
  result->max.z = v10;
  if ( vx >= 0.0 )
    result->max.x = vx + result->max.x;
  else
    result->min.x = result->min.x + vx;
  if ( vx_4 >= 0.0 )
    result->max.y = result->max.y + vx_4;
  else
    result->min.y = result->min.y + vx_4;
  if ( v7 >= 0.0 )
    result->max.z = result->max.z + v7;
  else
    result->min.z = result->min.z + v7;
  if ( vy >= 0.0 )
    result->max.x = result->max.x + vy;
  else
    result->min.x = result->min.x + vy;
  if ( vy_4 >= 0.0 )
    result->max.y = vy_4 + result->max.y;
  else
    result->min.y = result->min.y + vy_4;
  if ( v8 >= 0.0 )
    result->max.z = result->max.z + v8;
  else
    result->min.z = result->min.z + v8;
  if ( vz >= 0.0 )
    result->max.x = result->max.x + vz;
  else
    result->min.x = result->min.x + vz;
  if ( vz_4 >= 0.0 )
    result->max.y = result->max.y + vz_4;
  else
    result->min.y = vz_4 + result->min.y;
  if ( v9 >= 0.0 )
    result->max.z = result->max.z + v9;
  else
    result->min.z = result->min.z + v9;
  return result;
}
