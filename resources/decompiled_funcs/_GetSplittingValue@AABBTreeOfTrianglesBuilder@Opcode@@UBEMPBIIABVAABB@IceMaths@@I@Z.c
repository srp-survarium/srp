double __thiscall Opcode::AABBTreeOfTrianglesBuilder::GetSplittingValue(
        Opcode::AABBTreeOfTrianglesBuilder *this,
        const unsigned int *primitives,
        signed int nb_prims,
        const IceMaths::AABB *global_box,
        unsigned int axis)
{
  float v6; // xmm1_4
  unsigned int v7; // ebp
  unsigned int v8; // edi
  const Opcode::MeshInterface *mIMesh; // ecx
  const IceMaths::IndexedTriangle *mTris; // edi
  const IceMaths::Point *mVerts; // edx
  const unsigned int *v12; // esi
  const IceMaths::IndexedTriangle *v13; // ebx
  const Opcode::MeshInterface *v14; // ecx
  const IceMaths::Point *v15; // edx
  _DWORD *v16; // ecx
  float v17; // xmm0_4
  Opcode::AABBTreeOfTrianglesBuilder *v19; // [esp+0h] [ebp-8h]
  unsigned int i; // [esp+4h] [ebp-4h]
  unsigned int nb_primsa; // [esp+10h] [ebp+8h]
  float SplitValue; // [esp+14h] [ebp+Ch]
  unsigned int axisa; // [esp+18h] [ebp+10h]

  v19 = this;
  if ( (this->mSettings.mRules & 0x20) == 0 )
    return *(&global_box->mCenter.x + axis);
  v6 = 0.0;
  v7 = nb_prims;
  v8 = 0;
  SplitValue = 0.0;
  if ( nb_prims >= 4 )
  {
    mIMesh = this->mIMesh;
    mTris = mIMesh->mTris;
    axisa = ((unsigned int)(nb_prims - 4) >> 2) + 1;
    v12 = primitives + 2;
    i = 4 * axisa;
    do
    {
      v13 = &mTris[*(v12 - 1)];
      mVerts = mIMesh->mVerts;
      v6 = (float)((float)(*(&mVerts[mTris[v12[1]].mVRef[0]].x + axis)
                         + (float)((float)((float)(*(&mVerts[mTris[*v12].mVRef[0]].x + axis)
                                                 + (float)((float)((float)(*(&mVerts[v13->mVRef[0]].x + axis)
                                                                         + (float)((float)((float)(*(&mVerts[mTris[*(v12 - 2)].mVRef[0]].x + axis)
                                                                                                 + v6)
                                                                                         + *(&mVerts[mTris[*(v12 - 2)].mVRef[1]].x
                                                                                           + axis))
                                                                                 + *(&mVerts[mTris[*(v12 - 2)].mVRef[2]].x
                                                                                   + axis)))
                                                                 + *(&mVerts[v13->mVRef[1]].x + axis))
                                                         + *(&mVerts[v13->mVRef[2]].x + axis)))
                                         + *(&mVerts[mTris[*v12].mVRef[1]].x + axis))
                                 + *(&mVerts[mTris[*v12].mVRef[2]].x + axis)))
                 + *(&mVerts[mTris[v12[1]].mVRef[1]].x + axis))
         + *(&mVerts[mTris[v12[1]].mVRef[2]].x + axis);
      v12 += 4;
      --axisa;
    }
    while ( axisa );
    this = v19;
    v8 = i;
    v7 = nb_prims;
    SplitValue = v6;
  }
  if ( v8 < v7 )
  {
    v14 = this->mIMesh;
    nb_primsa = (unsigned int)v14->mTris->mVRef;
    v15 = v14->mVerts;
    do
    {
      v16 = (_DWORD *)(nb_primsa + 12 * primitives[v8]);
      v17 = (float)((float)(*(&v15[*v16].x + axis) + v6) + *(&v15[v16[1]].x + axis)) + *(&v15[v16[2]].x + axis);
      ++v8;
      v6 = v17;
    }
    while ( v8 < v7 );
    SplitValue = v17;
  }
  return SplitValue / (double)(3 * v7);
}
