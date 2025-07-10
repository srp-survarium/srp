double __thiscall btConeTwistConstraint::getParam(btConeTwistConstraint *this, int num, int axis)
{
  double result; // st7
  float retVal; // [esp+0h] [ebp-4h]

  retVal = 0.0;
  switch ( num )
  {
    case 1:
    case 2:
      if ( axis < 0 )
        goto LABEL_14;
      if ( axis >= 3 )
      {
        if ( axis >= 6 )
          goto LABEL_14;
        result = this->m_biasFactor;
      }
      else
      {
        result = this->m_linERP;
      }
      break;
    case 3:
    case 4:
      if ( axis < 0 )
        goto LABEL_14;
      if ( axis >= 3 )
      {
        if ( axis < 6 )
          retVal = this->m_angCFM;
        goto LABEL_14;
      }
      result = this->m_linCFM;
      break;
    default:
LABEL_14:
      result = retVal;
      break;
  }
  return result;
}
