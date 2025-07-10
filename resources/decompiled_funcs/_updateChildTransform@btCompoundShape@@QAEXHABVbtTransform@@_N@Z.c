void __userpurge btCompoundShape::updateChildTransform(
        int childIndex@<eax>,
        const btTransform *newChildTransform@<edx>,
        btCompoundShape *this,
        bool shouldRecalculateLocalAabb)
{
  int v4; // esi
  btCollisionShape *m_childShape; // ecx
  btDbvt *m_dynamicAabbTree; // edx
  btDbvtNode *m_node; // edi
  __m128i v8; // [esp+50h] [ebp-40h] BYREF
  __m128i v9; // [esp+60h] [ebp-30h] BYREF
  btDbvtAabbMm bounds; // [esp+70h] [ebp-20h] BYREF

  v4 = childIndex;
  this->m_children.m_data[childIndex].m_transform = *newChildTransform;
  if ( this->m_dynamicAabbTree )
  {
    m_childShape = this->m_children.m_data[v4].m_childShape;
    m_childShape->getAabb(m_childShape, newChildTransform, (btVector3 *)&v8, (btVector3 *)&v9);
    m_dynamicAabbTree = this->m_dynamicAabbTree;
    m_node = this->m_children.m_data[v4].m_node;
    bounds.mi = (btVector3)_mm_load_si128(&v8);
    bounds.mx = (btVector3)_mm_load_si128(&v9);
    btDbvt::update(m_node, m_dynamicAabbTree, &bounds);
  }
  if ( shouldRecalculateLocalAabb )
    this->recalculateLocalAabb(this);
}
