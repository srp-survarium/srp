void __thiscall btGeneric6DofConstraint::setParam(btGeneric6DofConstraint *this, int num, float value, int axis)
{
  if ( axis >= 0 )
  {
    if ( axis >= 3 )
    {
      if ( axis < 6 )
      {
        switch ( num )
        {
          case 2:
            *(&this->m_linearLimits.m_limitSoftness + 16 * axis) = value;
            this->m_flags |= 4 << (3 * axis);
            break;
          case 3:
            this->m_linearLimits.m_accumulatedImpulse.mVec128.m128_f32[16 * axis + 3] = value;
            this->m_flags |= 1 << (3 * axis);
            break;
          case 4:
            *(&this->m_linearLimits.m_damping + 16 * axis) = value;
            this->m_flags |= 2 << (3 * axis);
            break;
        }
      }
    }
    else
    {
      switch ( num )
      {
        case 2:
          this->m_linearLimits.m_stopERP.mVec128.m128_f32[axis] = value;
          this->m_flags |= 4 << (3 * axis);
          break;
        case 3:
          this->m_linearLimits.m_normalCFM.mVec128.m128_f32[axis] = value;
          this->m_flags |= 1 << (3 * axis);
          break;
        case 4:
          this->m_linearLimits.m_stopCFM.mVec128.m128_f32[axis] = value;
          this->m_flags |= 2 << (3 * axis);
          break;
      }
    }
  }
}
