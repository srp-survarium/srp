char __thiscall SpeedTree::CParser::ParseLOD(SpeedTree::CParser *this, struct SpeedTree::CCore *a2)
{
  SpeedTree::SLodProfile sLodProfile; // [esp+30h] [ebp-20h] BYREF
  char v5; // [esp+4Fh] [ebp-1h]

  v5 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 20) )
  {
    sLodProfile.m_fHighDetail3dDistance = 300.0;
    sLodProfile.m_fLowDetail3dDistance = 1200.0;
    sLodProfile.m_fBillboardStartDistance = 1300.0;
    sLodProfile.m_fBillboardFinalDistance = 1500.0;
    sLodProfile.m_bLodIsPresent = 1;
    SpeedTree::SLodProfile::ComputeDerived(&sLodProfile);
    sLodProfile.m_bLodIsPresent = SpeedTree::CParser::ParseInt(this) != 0;
    sLodProfile.m_fHighDetail3dDistance = SpeedTree::CParser::ParseFloat(this);
    sLodProfile.m_fLowDetail3dDistance = SpeedTree::CParser::ParseFloat(this);
    sLodProfile.m_fBillboardStartDistance = SpeedTree::CParser::ParseFloat(this);
    sLodProfile.m_fBillboardFinalDistance = SpeedTree::CParser::ParseFloat(this);
    SpeedTree::CCore::SetLodProfile(a2, &sLodProfile);
    return 1;
  }
  return v5;
}
