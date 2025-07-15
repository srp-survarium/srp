void __usercall IceMaths::AABB::Extend(IceMaths::AABB *this@<ecx>, float *a2@<eax>)
{
  float v2; // xmm3_4
  float v3; // xmm2_4
  float v4; // xmm5_4
  float x; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm7_4
  float v8; // xmm6_4
  float v9; // xmm2_4
  float y; // xmm3_4
  float z; // xmm3_4
  float Min; // [esp+0h] [ebp-18h]
  float Min_4; // [esp+4h] [ebp-14h]

  v2 = a2[2];
  v3 = a2[1];
  v4 = a2[5] + v2;
  x = *a2 + a2[3];
  v6 = *a2 - a2[3];
  v7 = v2 - a2[5];
  v8 = a2[4] + v3;
  v9 = v3 - a2[4];
  Min = v6;
  Min_4 = v9;
  if ( this->mCenter.x > x )
    x = this->mCenter.x;
  if ( v6 > this->mCenter.x )
  {
    Min = this->mCenter.x;
    v6 = this->mCenter.x;
  }
  y = this->mCenter.y;
  if ( y > v8 )
    v8 = this->mCenter.y;
  if ( v9 > y )
  {
    Min_4 = this->mCenter.y;
    v9 = Min_4;
  }
  z = this->mCenter.z;
  if ( z > v4 )
    v4 = this->mCenter.z;
  if ( v7 > z )
    v7 = this->mCenter.z;
  *a2 = (float)(v6 + x) * 0.5;
  a2[1] = (float)(v9 + v8) * 0.5;
  a2[3] = (float)(x - Min) * 0.5;
  a2[2] = (float)(v7 + v4) * 0.5;
  a2[4] = (float)(v8 - Min_4) * 0.5;
  a2[5] = (float)(v4 - v7) * 0.5;
}
