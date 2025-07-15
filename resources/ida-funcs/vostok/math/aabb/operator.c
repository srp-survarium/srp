vostok::math::aabb *__usercall vostok::math::aabb::operator*=@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::aabb *result@<eax>)
{
  float y; // xmm4_4
  float z; // xmm5_4
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // edx
  float v9; // xmm5_4
  float v10; // xmm2_4
  __int64 v11; // xmm6_8
  float v12; // [esp+0h] [ebp-18h]
  __int64 v13; // [esp+0h] [ebp-18h]
  float v14; // [esp+4h] [ebp-14h]

  y = result->min.y;
  z = result->min.z;
  v12 = (float)(result->max.x - result->min.x) * 0.5;
  v14 = (float)(result->max.y - y) * 0.5;
  v4 = result->min.x + v12;
  v5 = y + v14;
  v6 = this->min.x * v12;
  v7 = this->min.y * v14;
  *(float *)&v13 = v4 - v6;
  v8 = (float)(result->max.z - z) * 0.5;
  v9 = z + v8;
  *((float *)&v13 + 1) = v5 - v7;
  v10 = this->min.z * v8;
  v11 = v13;
  *(float *)&v13 = v4 + v6;
  *((float *)&v13 + 1) = v5 + v7;
  *(_QWORD *)&result->min.x = v11;
  *(_QWORD *)&result->max.x = v13;
  result->min.z = v9 - v10;
  result->max.z = v9 + v10;
  return result;
}


vostok::math::aabb *__usercall vostok::math::aabb::operator*=@<eax>(
        vostok::math::aabb *this@<ecx>,
        vostok::math::aabb *result@<eax>)
{
  float z; // xmm5_4
  float y; // xmm4_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  __int64 v11; // xmm6_8
  __int64 v12; // [esp+0h] [ebp-18h]
  float extents_4; // [esp+10h] [ebp-8h]

  z = result->min.z;
  y = result->min.y;
  v4 = (float)(result->max.z - z) * 0.5;
  v5 = (float)(result->max.x - result->min.x) * 0.5;
  extents_4 = (float)(result->max.y - y) * 0.5;
  v6 = y + extents_4;
  v7 = z + v4;
  v8 = result->min.x + v5;
  v9 = v5 * 2.0;
  v10 = v4 * 2.0;
  *(float *)&v12 = v8 - v9;
  *((float *)&v12 + 1) = v6 - (float)(extents_4 * 2.0);
  v11 = v12;
  *(float *)&v12 = v8 + v9;
  *((float *)&v12 + 1) = v6 + (float)(extents_4 * 2.0);
  *(_QWORD *)&result->min.x = v11;
  *(_QWORD *)&result->max.x = v12;
  result->min.z = v7 - v10;
  result->max.z = v7 + v10;
  return result;
}
