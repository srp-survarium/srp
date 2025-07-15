char __userpurge Opcode::AABBTreeOfAABBsBuilder::ComputeGlobalBox@<al>(
        Opcode::AABBTreeOfAABBsBuilder *this@<ecx>,
        const IceMaths::AABB *a2@<esi>,
        const unsigned int *primitives,
        unsigned int nb_prims,
        IceMaths::AABB *global_box)
{
  const IceMaths::AABB *mAABBArray; // ecx
  float x; // edx
  IceMaths::Point *p_mCenter; // ecx
  unsigned int i; // esi
  const IceMaths::AABB *v11; // [esp-4h] [ebp-10h]

  if ( !primitives || !nb_prims )
    return 0;
  mAABBArray = this->mAABBArray;
  x = mAABBArray[*primitives].mCenter.x;
  p_mCenter = &mAABBArray[*primitives].mCenter;
  global_box->mCenter.x = x;
  global_box->mCenter.y = p_mCenter->y;
  global_box->mCenter.z = p_mCenter->z;
  global_box->mExtents = p_mCenter[1];
  v11 = a2;
  for ( i = 1; i < nb_prims; ++i )
    IceMaths::AABB::Add((IceMaths::AABB *)&this->mAABBArray[primitives[i]], v11);
  return 1;
}
