double __thiscall btConvexShape::getMarginNonVirtual(btConvexShape *this)
{
  int m_shapeType; // eax
  double result; // st7

  m_shapeType = this->m_shapeType;
  if ( (unsigned int)m_shapeType < 2 )
    return *(float *)&this[3].__vftable;
  if ( m_shapeType > 3 )
  {
    if ( m_shapeType <= 5 )
      return *(float *)&this[3].__vftable;
    if ( m_shapeType == 8 )
      return *(float *)&this[2].__vftable * *(float *)&this[1].__vftable;
    if ( m_shapeType == 10 || m_shapeType == 13 )
      return *(float *)&this[3].__vftable;
  }
  this->getMargin(this);
  return result;
}
