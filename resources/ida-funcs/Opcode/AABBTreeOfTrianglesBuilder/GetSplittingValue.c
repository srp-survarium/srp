double __thiscall Opcode::AABBTreeOfTrianglesBuilder::GetSplittingValue(
        Opcode::AABBTreeOfTrianglesBuilder *this,
        unsigned int index,
        unsigned int axis)
{
  const Opcode::MeshInterface *mIMesh; // ecx
  const IceMaths::IndexedTriangle *v4; // eax

  mIMesh = this->mIMesh;
  v4 = &mIMesh->mTris[index];
  return (*(&mIMesh->mVerts[v4->mVRef[2]].x + axis)
        + *(&mIMesh->mVerts[v4->mVRef[1]].x + axis)
        + *(&mIMesh->mVerts[v4->mVRef[0]].x + axis))
       * 0.33333334;
}


double __thiscall Opcode::AABBTreeOfTrianglesBuilder::GetSplittingValue(
        Opcode::AABBTreeOfTrianglesBuilder *this,
        const unsigned int *primitives,
        unsigned int nb_prims,
        const IceMaths::AABB *global_box,
        unsigned int axis)
{
  unsigned int v5; // eax
  unsigned int v6; // ebx
  const Opcode::MeshInterface *mIMesh; // eax
  const IceMaths::Point *mVerts; // edi
  const IceMaths::IndexedTriangle *v9; // eax
  const IceMaths::IndexedTriangle *mTris; // [esp+0h] [ebp-4h]
  float v12; // [esp+14h] [ebp+10h]

  if ( (this->mSettings.mRules & 0x20) == 0 )
    return *(&global_box->mCenter.x + axis);
  v5 = nb_prims;
  v6 = 0;
  v12 = 0.0;
  if ( nb_prims )
  {
    mIMesh = this->mIMesh;
    mVerts = mIMesh->mVerts;
    mTris = mIMesh->mTris;
    do
    {
      v9 = &mTris[primitives[v6++]];
      v12 = (float)((float)(*(&mVerts[v9->mVRef[0]].x + axis) + v12) + *(&mVerts[v9->mVRef[1]].x + axis))
          + *(&mVerts[v9->mVRef[2]].x + axis);
    }
    while ( v6 < nb_prims );
    v5 = nb_prims;
  }
  return v12 / (double)(3 * v5);
}
