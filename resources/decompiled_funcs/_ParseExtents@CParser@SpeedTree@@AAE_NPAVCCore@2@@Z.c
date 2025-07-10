char __thiscall SpeedTree::CParser::ParseExtents(SpeedTree::CParser *this, struct SpeedTree::CCore *a2)
{
  float y; // [esp+50h] [ebp-30h]
  float z; // [esp+54h] [ebp-2Ch]
  struct SpeedTree::Vec3 v6; // [esp+58h] [ebp-28h]
  struct SpeedTree::Vec3 v7; // [esp+64h] [ebp-1Ch] BYREF
  struct SpeedTree::Vec3 v8; // [esp+70h] [ebp-10h] BYREF
  char v9; // [esp+7Fh] [ebp-1h]

  v9 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 24) )
  {
    a2->m_cExtents.m_cMin.x = SpeedTree::CParser::ParseFloat(this);
    a2->m_cExtents.m_cMin.y = SpeedTree::CParser::ParseFloat(this);
    a2->m_cExtents.m_cMin.z = SpeedTree::CParser::ParseFloat(this);
    a2->m_cExtents.m_cMax.x = SpeedTree::CParser::ParseFloat(this);
    a2->m_cExtents.m_cMax.y = SpeedTree::CParser::ParseFloat(this);
    a2->m_cExtents.m_cMax.z = SpeedTree::CParser::ParseFloat(this);
    if ( *((_DWORD *)this + 22) )
    {
      SpeedTree::CParser::ConvertCoord(
        this,
        &v8,
        a2->m_cExtents.m_cMin.x,
        a2->m_cExtents.m_cMin.y,
        a2->m_cExtents.m_cMin.z);
      SpeedTree::CParser::ConvertCoord(
        this,
        &v7,
        a2->m_cExtents.m_cMax.x,
        a2->m_cExtents.m_cMax.y,
        a2->m_cExtents.m_cMax.z);
      y = v8.y;
      z = v8.z;
      v6 = v7;
      a2->m_cExtents.m_cMin.x = v8.x;
      a2->m_cExtents.m_cMin.y = y;
      a2->m_cExtents.m_cMin.z = z;
      a2->m_cExtents.m_cMax = v6;
    }
    SpeedTree::CExtents::Order(&a2->m_cExtents);
    return 1;
  }
  return v9;
}
