void __thiscall btConeTwistConstraint::setParam(btConeTwistConstraint *this, int num, float value, unsigned int axis)
{
  switch ( num )
  {
    case 1:
    case 2:
      if ( axis > 2 )
      {
        this->m_biasFactor = value;
      }
      else
      {
        this->m_linERP = value;
        this->m_flags |= 2u;
      }
      break;
    case 3:
    case 4:
      if ( axis > 2 )
      {
        this->m_flags |= 4u;
        this->m_angCFM = value;
      }
      else
      {
        this->m_linCFM = value;
        this->m_flags |= 1u;
      }
      break;
    default:
      return;
  }
}
