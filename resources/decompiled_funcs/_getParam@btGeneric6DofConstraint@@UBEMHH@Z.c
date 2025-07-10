double __thiscall btGeneric6DofConstraint::getParam(btGeneric6DofConstraint *this, int num, int axis)
{
  float retVal; // [esp+0h] [ebp-4h]

  retVal = 0.0;
  if ( axis >= 0 )
  {
    if ( axis >= 3 )
    {
      if ( axis < 6 )
      {
        switch ( num )
        {
          case 2:
            return *(&this->m_linearLimits.m_limitSoftness + 16 * axis);
          case 3:
            return this->m_linearLimits.m_accumulatedImpulse.mVec128.m128_f32[16 * axis + 3];
          case 4:
            return *(&this->m_linearLimits.m_damping + 16 * axis);
        }
      }
    }
    else
    {
      switch ( num )
      {
        case 2:
          return this->m_linearLimits.m_stopERP.mVec128.m128_f32[axis];
        case 3:
          return this->m_linearLimits.m_normalCFM.mVec128.m128_f32[axis];
        case 4:
          return this->m_linearLimits.m_stopCFM.mVec128.m128_f32[axis];
      }
    }
  }
  return retVal;
}
