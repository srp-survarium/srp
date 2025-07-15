double __thiscall SpeedTree::CCore::ComputeLodByDistanceSquared(SpeedTree::CCore *this, float a2)
{
  float v3; // [esp+4h] [ebp-4h]

  v3 = -1.0;
  if ( this->m_sLodProfileSquared.m_fHighDetail3dDistance <= (double)a2 )
  {
    if ( this->m_sLodProfileSquared.m_fLowDetail3dDistance <= (double)a2 )
    {
      if ( this->m_sLodProfileSquared.m_fBillboardStartDistance <= (double)a2 )
      {
        if ( this->m_sLodProfileSquared.m_fBillboardFinalDistance > (double)a2 )
          return (float)(-(a2 - this->m_sLodProfileSquared.m_fBillboardStartDistance)
                       / this->m_sLodProfileSquared.m_fBillboardRange);
      }
      else
      {
        return (float)0.0;
      }
    }
    else
    {
      return (float)(1.0
                   - (a2 - this->m_sLodProfileSquared.m_fHighDetail3dDistance) / this->m_sLodProfileSquared.m_f3dRange);
    }
  }
  else
  {
    return (float)1.0;
  }
  return v3;
}
