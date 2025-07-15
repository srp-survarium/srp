char __thiscall Opcode::Model::Build(Opcode::Model *this, const Opcode::OPCODECREATE *create)
{
  Opcode::MeshInterface *mIMesh; // eax
  char *v6; // eax
  Opcode::AABBTree *v7; // eax
  vostok::memory::base_allocator *v8; // ecx
  Opcode::BaseModel *v9; // ecx
  Opcode::AABBTree *v10; // ecx
  Opcode::AABBTree *mSource; // edi
  Opcode::AABBTreeBuilder builder; // [esp+Ch] [ebp-28h] BYREF
  Opcode::MeshInterface *v13; // [esp+2Ch] [ebp-8h]
  unsigned int mNbTris; // [esp+30h] [ebp-4h]
  vostok::memory::base_allocator *m_allocator; // [esp+3Ch] [ebp+8h]
  vostok::memory::base_allocator *v16; // [esp+3Ch] [ebp+8h]

  mIMesh = create->mIMesh;
  if ( create->mIMesh
    && mIMesh->mNbTris
    && mIMesh->mNbVerts
    && mIMesh->mTris
    && mIMesh->mVerts
    && create->mSettings.mLimit == 1 )
  {
    Opcode::BaseModel::ReleaseBase(this, (int)this);
    this->mIMesh = create->mIMesh;
    mNbTris = create->mIMesh->mNbTris;
    if ( mNbTris == 1 )
    {
      this->mModelCode |= 4u;
      return 1;
    }
    m_allocator = this->m_allocator;
    v6 = type_info::raw_name(&Opcode::AABBTree `RTTI Type Descriptor');
    v7 = (Opcode::AABBTree *)m_allocator->call_malloc(
                               m_allocator,
                               56u,
                               v6,
                               "Opcode::Model::Build",
                               ".\\OPC_Model.cpp",
                               169u);
    if ( v7 )
    {
      v8 = this->m_allocator;
      v7->mPos = 0;
      v7->mNodePrimitives = 0;
      v7->mNbPrimitives = 0;
      v7->mIndices = 0;
      v7->mPool = 0;
      v7->mTotalNbNodes = 0;
      v7->m_allocator = v8;
    }
    else
    {
      v7 = 0;
    }
    this->mSource = v7;
    if ( v7 )
    {
      builder.m_allocator = this->m_allocator;
      v13 = create->mIMesh;
      builder.mSettings = create->mSettings;
      builder.mNbPrimitives = mNbTris;
      builder.mNodeBase = 0;
      builder.mCount = 0;
      builder.mNbInvalidSplits = 0;
      builder.__vftable = (Opcode::AABBTreeBuilder_vtbl *)&Opcode::AABBTreeOfTrianglesBuilder::`vftable';
      if ( Opcode::AABBTree::Build((Opcode::AABBTree *)&builder, (int)v7, (const char *)this, &builder) )
      {
        if ( Opcode::BaseModel::CreateTree(v9, (int)this, create->mNoLeaf, create->mQuantized)
          && this->mTree->Build(this->mTree, this->mSource) )
        {
          if ( !create->mKeepOriginal && this->mSource )
          {
            mSource = this->mSource;
            v16 = this->m_allocator;
            if ( mSource )
            {
              Opcode::AABBTree::Release(v10, (int)mSource);
              v16->call_free(v16, mSource, "Opcode::Model::Build", ".\\OPC_Model.cpp", 189u);
              this->mSource = 0;
            }
            this->mSource = 0;
          }
          return 1;
        }
      }
    }
  }
  return 0;
}
