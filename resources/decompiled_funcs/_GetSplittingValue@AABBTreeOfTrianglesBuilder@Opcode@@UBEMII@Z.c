double __thiscall Opcode::AABBTreeOfTrianglesBuilder::GetSplittingValue(
        Opcode::AABBTreeOfTrianglesBuilder *this,
        unsigned int index,
        unsigned int axis)
{
  const Opcode::MeshInterface *mIMesh; // ecx
  const IceMaths::IndexedTriangle *mTris; // edx

  mIMesh = this->mIMesh;
  mTris = mIMesh->mTris;
  return (*(&mIMesh->mVerts[mTris[index].mVRef[2]].x + axis)
        + *(&mIMesh->mVerts[mTris[index].mVRef[1]].x + axis)
        + *(&mIMesh->mVerts[mTris[index].mVRef[0]].x + axis))
       * 0.33333334;
}
