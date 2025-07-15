IceMaths::AABB *__usercall IceMaths::AABB::Add@<eax>(IceMaths::AABB *this@<ecx>, IceMaths::AABB *result@<eax>)
{
  float y; // xmm5_4
  float z; // xmm6_4
  float v4; // xmm6_4
  float v5; // xmm5_4
  float v6; // xmm4_4
  float Min; // [esp+0h] [ebp-24h]
  float Min_4; // [esp+4h] [ebp-20h]
  float Min_8; // [esp+8h] [ebp-1Ch]
  float v10; // [esp+14h] [ebp-10h]
  float Max_4; // [esp+1Ch] [ebp-8h]

  y = result->mCenter.y;
  z = result->mCenter.z;
  Min = result->mCenter.x - result->mExtents.x;
  Min_4 = y - result->mExtents.y;
  Min_8 = z - result->mExtents.z;
  if ( (float)(this->mCenter.x - this->mExtents.x) <= Min )
    Min = this->mCenter.x - this->mExtents.x;
  if ( (float)(this->mCenter.y - this->mExtents.y) <= Min_4 )
    Min_4 = this->mCenter.y - this->mExtents.y;
  if ( (float)(this->mCenter.z - this->mExtents.z) <= Min_8 )
    Min_8 = this->mCenter.z - this->mExtents.z;
  v10 = result->mExtents.z + z;
  Max_4 = result->mExtents.y + y;
  v4 = this->mExtents.x + this->mCenter.x;
  if ( (float)(result->mCenter.x + result->mExtents.x) > v4 )
    v4 = result->mCenter.x + result->mExtents.x;
  v5 = result->mExtents.y + y;
  if ( Max_4 <= (float)(this->mExtents.y + this->mCenter.y) )
    v5 = this->mExtents.y + this->mCenter.y;
  v6 = v10;
  if ( v10 <= (float)(this->mExtents.z + this->mCenter.z) )
    v6 = this->mExtents.z + this->mCenter.z;
  result->mCenter.x = (float)(v4 + Min) * 0.5;
  result->mCenter.y = (float)(v5 + Min_4) * 0.5;
  result->mExtents.x = (float)(v4 - Min) * 0.5;
  result->mCenter.z = (float)(v6 + Min_8) * 0.5;
  result->mExtents.y = (float)(v5 - Min_4) * 0.5;
  result->mExtents.z = (float)(v6 - Min_8) * 0.5;
  return result;
}
