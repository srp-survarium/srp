void __userpurge IceMaths::AABB::SetMinMax(
        const IceMaths::Point *min@<ecx>,
        const IceMaths::Point *max@<eax>,
        IceMaths::AABB *this)
{
  float v3; // [esp+4h] [ebp-8h]
  float v4; // [esp+4h] [ebp-8h]
  float v5; // [esp+8h] [ebp-4h]
  float v6; // [esp+8h] [ebp-4h]

  v3 = (float)(min->y + max->y) * 0.5;
  v5 = (float)(max->z + min->z) * 0.5;
  this->mCenter.x = (float)(min->x + max->x) * 0.5;
  this->mCenter.y = v3;
  this->mCenter.z = v5;
  v4 = (float)(max->y - min->y) * 0.5;
  v6 = (float)(max->z - min->z) * 0.5;
  this->mExtents.x = (float)(max->x - min->x) * 0.5;
  this->mExtents.y = v4;
  this->mExtents.z = v6;
}
