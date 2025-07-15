void __thiscall btCompoundShape::removeChildShape(btCompoundShape *this, btCollisionShape *shape)
{
  int v3; // edi
  int v4; // ebx

  ++this->m_updateRevision;
  v3 = this->m_children.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = v3;
    do
    {
      if ( this->m_children.m_data[v4].m_childShape == shape )
        btCompoundShape::removeChildShapeByIndex(this, this, v3);
      --v3;
      --v4;
    }
    while ( v3 >= 0 );
  }
  this->recalculateLocalAabb(this);
}
