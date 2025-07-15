double __thiscall btConvexShape::getMarginNonVirtual(btConvexShape *this)
{
  double result; // st7

  switch ( this->m_shapeType )
  {
    case 0:
    case 1:
    case 4:
    case 5:
    case 0xA:
    case 0xD:
      result = *(float *)&this[3].__vftable;
      break;
    case 8:
      result = *(float *)&this[2].__vftable * *(float *)&this[1].__vftable;
      break;
    default:
      this->getMargin(this);
      break;
  }
  return result;
}
