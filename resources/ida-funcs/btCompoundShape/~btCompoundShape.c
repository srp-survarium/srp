void __thiscall btCompoundShape::~btCompoundShape(btCompoundShape *this)
{
  btDbvt *m_dynamicAabbTree; // ecx
  btDbvt *v3; // [esp-4h] [ebp-Ch]

  m_dynamicAabbTree = this->m_dynamicAabbTree;
  this->__vftable = (btCompoundShape_vtbl *)&btCompoundShape::`vftable';
  if ( m_dynamicAabbTree )
  {
    btDbvt::~btDbvt(m_dynamicAabbTree);
    btAlignedFreeInternal(this->m_dynamicAabbTree);
    m_dynamicAabbTree = v3;
  }
  btAlignedObjectArray<btInternalEdge>::~btAlignedObjectArray<btInternalEdge>(
    (btAlignedObjectArray<GrahamVector2> *)m_dynamicAabbTree,
    (int)&this->m_children);
  this->__vftable = (btCompoundShape_vtbl *)&btCollisionShape::`vftable';
}
