void __userpurge IceMaths::AABB::SetMinMax(
        const IceMaths::Point *min@<ecx>,
        const IceMaths::Point *max@<eax>,
        IceMaths::AABB *this)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm2_4
  float v6; // xmm1_4

  v3 = min->y + max->y;
  v4 = max->z + min->z;
  this->mCenter.x = (float)(min->x + max->x) * 0.5;
  this->mCenter.y = v3 * 0.5;
  this->mCenter.z = v4 * 0.5;
  v5 = max->z - min->z;
  v6 = (float)(max->y - min->y) * 0.5;
  this->mExtents.x = (float)(max->x - min->x) * 0.5;
  this->mExtents.y = v6;
  this->mExtents.z = v5 * 0.5;
}
