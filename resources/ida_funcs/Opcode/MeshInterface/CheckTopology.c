unsigned int __thiscall Opcode::MeshInterface::CheckTopology(Opcode::MeshInterface *this)
{
  unsigned int mNbTris; // edx
  unsigned int result; // eax
  const IceMaths::Point *mVerts; // esi
  const IceMaths::IndexedTriangle *mTris; // ecx
  unsigned int v5; // ebp
  const IceMaths::Point *v6; // ebx
  const IceMaths::Point *v7; // edi
  const IceMaths::Point *v8; // edx

  mNbTris = this->mNbTris;
  result = 0;
  if ( this->mNbTris )
  {
    mVerts = this->mVerts;
    mTris = this->mTris;
    v5 = mNbTris;
    do
    {
      v6 = &mVerts[mTris->mVRef[0]];
      v7 = &mVerts[mTris->mVRef[1]];
      v8 = &mVerts[mTris->mVRef[2]];
      if ( v6 == v7 || v7 == v8 || v8 == v6 )
        ++result;
      ++mTris;
      --v5;
    }
    while ( v5 );
  }
  return result;
}
