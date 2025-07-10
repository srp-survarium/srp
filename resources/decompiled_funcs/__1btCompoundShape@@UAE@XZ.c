void __thiscall btCompoundShape::~btCompoundShape(btCompoundShape *this)
{
  btDbvt *m_dynamicAabbTree; // eax
  btDbvt *v3; // eax
  btCompoundShapeChild *m_data; // eax

  m_dynamicAabbTree = this->m_dynamicAabbTree;
  this->__vftable = (btCompoundShape_vtbl *)&btCompoundShape::`vftable';
  if ( m_dynamicAabbTree )
  {
    btDbvt::`scalar deleting destructor'((btDbvt *)this, (int)m_dynamicAabbTree);
    v3 = this->m_dynamicAabbTree;
    if ( v3 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v3);
    }
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
  this->m_children.m_data = 0;
  this->m_children.m_size = 0;
  this->m_children.m_capacity = 0;
  this->m_children.m_ownsMemory = 1;
  this->__vftable = (btCompoundShape_vtbl *)&btCollisionShape::`vftable';
}
