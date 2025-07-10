char __thiscall Opcode::Model::Build(Opcode::Model *this, const Opcode::OPCODECREATE *create)
{
  Opcode::MeshInterface *mIMesh; // eax
  unsigned int mNbTris; // edi
  _DWORD *v6; // eax
  Opcode::AABBTree *v7; // eax
  Opcode::AABBTree **p_mSource; // ebx
  vostok::memory::base_allocator *m_allocator; // edx
  Opcode::MeshInterface *v10; // ecx
  unsigned int mLimit; // edx
  Opcode::AABBTree *mRules; // ecx
  Opcode::BaseModel *v13; // ecx
  Opcode::AABBTree *v14; // ecx
  Opcode::AABBTreeOfTrianglesBuilder TB; // [esp+8h] [ebp-24h] BYREF

  mIMesh = create->mIMesh;
  if ( !create->mIMesh
    || !mIMesh->mNbTris
    || !mIMesh->mNbVerts
    || !mIMesh->mTris
    || !mIMesh->mVerts
    || create->mSettings.mLimit != 1 )
  {
    return 0;
  }
  Opcode::BaseModel::ReleaseBase(this);
  this->mIMesh = create->mIMesh;
  mNbTris = create->mIMesh->mNbTris;
  if ( mNbTris == 1 )
  {
    this->mModelCode |= 4u;
    return 1;
  }
  else
  {
    v6 = this->m_allocator->call_malloc(this->m_allocator, 56);
    if ( v6 )
      Opcode::AABBTree::AABBTree((Opcode::AABBTree *)this->m_allocator, v6, this->m_allocator);
    else
      v7 = 0;
    p_mSource = &this->mSource;
    this->mSource = v7;
    if ( !v7 )
      return 0;
    m_allocator = this->m_allocator;
    TB.mNodeBase = 0;
    TB.mCount = 0;
    TB.mNbInvalidSplits = 0;
    v10 = create->mIMesh;
    TB.m_allocator = m_allocator;
    mLimit = create->mSettings.mLimit;
    TB.mIMesh = v10;
    mRules = (Opcode::AABBTree *)create->mSettings.mRules;
    TB.mNbPrimitives = mNbTris;
    TB.__vftable = (Opcode::AABBTreeOfTrianglesBuilder_vtbl *)&Opcode::AABBTreeOfTrianglesBuilder::`vftable';
    TB.mSettings.mLimit = mLimit;
    TB.mSettings.mRules = (unsigned int)mRules;
    if ( !Opcode::AABBTree::Build(&TB, mRules, v7) )
      return 0;
    if ( Opcode::BaseModel::CreateTree(v13, create->mNoLeaf, create->mQuantized)
      && this->mTree->Build(this->mTree, *p_mSource) )
    {
      if ( !create->mKeepOriginal )
      {
        if ( *p_mSource )
        {
          vostok::memory::delete_helper<vostok::memory::base_allocator,Opcode::AABBTree>(
            &this->mSource,
            v14,
            this->m_allocator);
          *p_mSource = 0;
        }
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
}
