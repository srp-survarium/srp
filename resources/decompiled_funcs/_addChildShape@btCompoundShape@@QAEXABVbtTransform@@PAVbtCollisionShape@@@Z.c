void __userpurge btCompoundShape::addChildShape(
        btCompoundShape *this@<esi>,
        const btTransform *localTransform@<eax>,
        btCollisionShape *shape)
{
  btCollisionShape_vtbl *v3; // edx
  unsigned __int64 v6; // xmm0_8
  int m_shapeType; // eax
  float (__thiscall *getMargin)(btCollisionShape *); // eax
  btDbvt *v9; // ecx
  btDbvt *m_dynamicAabbTree; // edi
  int m_capacity; // ecx
  int v12; // eax
  int v13; // edi
  btCompoundShapeChild *v14; // edi
  int v15; // ebx
  btCompoundShapeChild *m_data; // eax
  btCompoundShapeChild *v17; // eax
  void *m_size; // [esp+19Ch] [ebp-B4h]
  btCompoundShapeChild *v19; // [esp+1B4h] [ebp-9Ch]
  int v20; // [esp+1B8h] [ebp-98h]
  int v21; // [esp+1BCh] [ebp-94h]
  __m128i v22; // [esp+1C0h] [ebp-90h] BYREF
  __m128i v23; // [esp+1D0h] [ebp-80h] BYREF
  btCompoundShapeChild v24; // [esp+1E0h] [ebp-70h] BYREF
  btDbvtAabbMm v25; // [esp+230h] [ebp-20h] BYREF

  ++this->m_updateRevision;
  v3 = shape->__vftable;
  v6 = localTransform->m_basis.m_el[0].mVec128.m128_u64[0];
  m_shapeType = shape->m_shapeType;
  v24.m_transform.m_basis.m_el[0].mVec128.m128_u64[0] = v6;
  v24.m_transform.m_basis.m_el[0].mVec128.m128_u64[1] = localTransform->m_basis.m_el[0].mVec128.m128_u64[1];
  v24.m_transform.m_basis.m_el[1] = localTransform->m_basis.m_el[1];
  v24.m_transform.m_basis.m_el[2] = localTransform->m_basis.m_el[2];
  v24.m_transform.m_origin.mVec128.m128_u64[0] = localTransform->m_origin.mVec128.m128_u64[0];
  v24.m_childShapeType = m_shapeType;
  getMargin = v3->getMargin;
  v24.m_node = 0;
  v24.m_transform.m_origin.mVec128.m128_u64[1] = localTransform->m_origin.mVec128.m128_u64[1];
  v24.m_childShape = shape;
  v24.m_childMargin = getMargin(shape);
  shape->getAabb(shape, localTransform, (btVector3 *)&v22, (btVector3 *)&v23);
  if ( this->m_localAabbMin.mVec128.m128_f32[0] > *(float *)v22.m128i_i32 )
    this->m_localAabbMin.mVec128.m128_i32[0] = v22.m128i_i32[0];
  if ( *(float *)v23.m128i_i32 > this->m_localAabbMax.mVec128.m128_f32[0] )
    this->m_localAabbMax.mVec128.m128_i32[0] = v23.m128i_i32[0];
  if ( this->m_localAabbMin.mVec128.m128_f32[1] > *(float *)&v22.m128i_i32[1] )
    this->m_localAabbMin.mVec128.m128_i32[1] = v22.m128i_i32[1];
  if ( *(float *)&v23.m128i_i32[1] > this->m_localAabbMax.mVec128.m128_f32[1] )
    this->m_localAabbMax.mVec128.m128_i32[1] = v23.m128i_i32[1];
  if ( this->m_localAabbMin.mVec128.m128_f32[2] > *(float *)&v22.m128i_i32[2] )
    this->m_localAabbMin.mVec128.m128_i32[2] = v22.m128i_i32[2];
  if ( *(float *)&v23.m128i_i32[2] > this->m_localAabbMax.mVec128.m128_f32[2] )
    this->m_localAabbMax.mVec128.m128_i32[2] = v23.m128i_i32[2];
  m_dynamicAabbTree = this->m_dynamicAabbTree;
  if ( m_dynamicAabbTree )
  {
    m_size = (void *)this->m_children.m_size;
    v25.mi = (btVector3)_mm_load_si128(&v22);
    v25.mx = (btVector3)_mm_load_si128(&v23);
    v24.m_node = btDbvt::insert(v9, m_dynamicAabbTree, &v25, m_size);
  }
  m_capacity = this->m_children.m_capacity;
  v12 = this->m_children.m_size;
  if ( v12 == m_capacity )
  {
    if ( v12 )
    {
      v13 = 2 * v12;
      v20 = 2 * v12;
    }
    else
    {
      v20 = 1;
      v13 = 1;
    }
    if ( m_capacity < v13 )
    {
      if ( v13 )
      {
        ++gNumAlignedAllocs;
        v19 = (btCompoundShapeChild *)sAlignedAllocFunc(80 * v13, 16);
      }
      else
      {
        v19 = 0;
      }
      if ( this->m_children.m_size > 0 )
      {
        v14 = v19;
        v15 = 0;
        v21 = this->m_children.m_size;
        do
        {
          if ( v14 )
            btCompoundShapeChild::btCompoundShapeChild(&this->m_children.m_data[v15], v14);
          ++v15;
          ++v14;
          --v21;
        }
        while ( v21 );
        v13 = v20;
      }
      m_data = this->m_children.m_data;
      if ( m_data )
      {
        if ( this->m_children.m_ownsMemory )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(m_data);
        }
        this->m_children.m_data = 0;
      }
      this->m_children.m_ownsMemory = 1;
      this->m_children.m_data = v19;
      this->m_children.m_capacity = v13;
    }
  }
  v17 = &this->m_children.m_data[this->m_children.m_size];
  if ( v17 )
    btCompoundShapeChild::btCompoundShapeChild(&v24, v17);
  ++this->m_children.m_size;
}
