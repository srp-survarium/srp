void __thiscall btTriangleShape::getPreferredPenetrationDirection(
        btTriangleShape *this,
        int index,
        btTriangleShape *penetrationVector)
{
  btTriangleShape::calcNormal(penetrationVector, (float *)this);
  if ( index )
  {
    *(float *)&penetrationVector->__vftable = *(float *)&penetrationVector->__vftable * -1.0;
    *(float *)&penetrationVector->m_shapeType = *(float *)&penetrationVector->m_shapeType * -1.0;
    *(float *)&penetrationVector->m_userPointer = *(float *)&penetrationVector->m_userPointer * -1.0;
  }
}
