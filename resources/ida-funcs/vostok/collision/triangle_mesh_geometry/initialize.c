void __userpurge vostok::collision::triangle_mesh_geometry::initialize(
        vostok::collision::triangle_mesh_geometry *this@<esi>,
        vostok::memory::base_allocator *allocator@<eax>,
        const vostok::math::float3 *vertices,
        unsigned int vertex_count,
        const IceMaths::IndexedTriangle *indices,
        unsigned int index_count)
{
  char *v7; // eax
  Opcode::MeshInterface *v8; // eax
  Opcode::MeshInterface *m_mesh; // eax
  char *v10; // eax
  Opcode::Model *v11; // eax
  const unsigned int *v12; // [esp+0h] [ebp-1Ch]
  unsigned int v13; // [esp+4h] [ebp-18h]
  _DWORD v14[3]; // [esp+8h] [ebp-14h] BYREF
  char v15; // [esp+14h] [ebp-8h]
  char v16; // [esp+15h] [ebp-7h]
  char v17; // [esp+16h] [ebp-6h]
  char v18; // [esp+17h] [ebp-5h]
  Opcode::MeshInterface *v19; // [esp+18h] [ebp-4h]

  v7 = type_info::raw_name(&Opcode::MeshInterface `RTTI Type Descriptor');
  v8 = (Opcode::MeshInterface *)allocator->call_malloc(
                                  allocator,
                                  20,
                                  v7,
                                  "vostok::collision::triangle_mesh_geometry::initialize",
                                  ".\\triangle_mesh_geometry.cpp",
                                  50);
  if ( v8 )
  {
    v8->mNbTris = 0;
    v8->mNbVerts = 0;
    v8->m_allocator = allocator;
    v8->mTris = 0;
    v8->mVerts = 0;
  }
  else
  {
    v8 = 0;
  }
  this->m_mesh = v8;
  v19 = v8;
  v8->mNbTris = index_count / 3;
  this->m_mesh->mNbVerts = vertex_count;
  m_mesh = this->m_mesh;
  if ( indices && vertices )
  {
    m_mesh->mTris = indices;
    m_mesh->mVerts = (const IceMaths::Point *)vertices;
  }
  v14[0] = this->m_mesh;
  v14[1] = 1;
  v14[2] = 34;
  v17 = 0;
  v15 = 1;
  v16 = 0;
  v18 = 0;
  v10 = type_info::raw_name(&Opcode::Model `RTTI Type Descriptor');
  v11 = (Opcode::Model *)allocator->call_malloc(
                           allocator,
                           24,
                           v10,
                           "vostok::collision::triangle_mesh_geometry::initialize",
                           ".\\triangle_mesh_geometry.cpp",
                           64);
  if ( v11 )
  {
    v11->mIMesh = 0;
    v11->mModelCode = 0;
    v11->mSource = 0;
    v11->mTree = 0;
    v11->m_allocator = allocator;
    v11->__vftable = (Opcode::Model_vtbl *)&Opcode::Model::`vftable';
  }
  else
  {
    v11 = 0;
  }
  this->m_model = v11;
  v11->Build(v11, (const Opcode::OPCODECREATE *)v14);
  this->m_root = (const Opcode::AABBNoLeafNode *)this->m_model->mTree[1].__vftable;
  vostok::collision::triangle_mesh_geometry::calculate_aabb(vertices, vertex_count, this, v12, v13);
}
