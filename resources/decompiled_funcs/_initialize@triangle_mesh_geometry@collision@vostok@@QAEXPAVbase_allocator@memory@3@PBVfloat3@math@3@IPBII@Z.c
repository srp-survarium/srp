void __userpurge vostok::collision::triangle_mesh_geometry::initialize(
        vostok::collision::triangle_mesh_geometry *this@<eax>,
        vostok::memory::base_allocator *allocator@<esi>,
        const IceMaths::Point *vertices,
        unsigned int vertex_count,
        const IceMaths::IndexedTriangle *indices,
        unsigned int index_count)
{
  Opcode::MeshInterface *v7; // eax
  Opcode::MeshInterface *v8; // ecx
  Opcode::MeshInterface *m_mesh; // eax
  Opcode::MeshInterface *v10; // edx
  vostok::memory::base_allocator_vtbl *v11; // eax
  void *(__thiscall *call_malloc)(vostok::memory::base_allocator *, unsigned int); // edx
  Opcode::Model *v13; // eax
  Opcode::OPCODECREATE options; // [esp+10h] [ebp-14h] BYREF

  v7 = (Opcode::MeshInterface *)allocator->call_malloc(allocator, 20);
  if ( v7 )
  {
    v7->mNbTris = 0;
    v7->mNbVerts = 0;
    v7->m_allocator = allocator;
    v7->mTris = 0;
    v7->mVerts = 0;
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  this->m_mesh = v8;
  v8->mNbTris = index_count / 3;
  this->m_mesh->mNbVerts = vertex_count;
  m_mesh = this->m_mesh;
  if ( indices && vertices )
  {
    m_mesh->mTris = indices;
    m_mesh->mVerts = vertices;
  }
  v10 = this->m_mesh;
  options.mSettings.mLimit = 1;
  options.mNoLeaf = 1;
  v11 = allocator->__vftable;
  options.mIMesh = v10;
  call_malloc = v11->call_malloc;
  options.mSettings.mRules = 34;
  options.mKeepOriginal = 0;
  options.mQuantized = 0;
  options.mCanRemap = 0;
  v13 = (Opcode::Model *)call_malloc(allocator, 24u);
  if ( v13 )
  {
    v13->mIMesh = 0;
    v13->mModelCode = 0;
    v13->mSource = 0;
    v13->mTree = 0;
    v13->m_allocator = allocator;
    v13->__vftable = (Opcode::Model_vtbl *)&Opcode::Model::`vftable';
  }
  else
  {
    v13 = 0;
  }
  this->m_model = v13;
  v13->Build(v13, &options);
  this->m_root = (const Opcode::AABBNoLeafNode *)this->m_model->mTree[1].__vftable;
  vostok::collision::triangle_mesh_geometry::calculate_aabb(
    this,
    (const vostok::math::float3 *const)vertices,
    vertex_count);
}
