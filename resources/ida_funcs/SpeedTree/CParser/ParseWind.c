char __thiscall SpeedTree::CParser::ParseWind(SpeedTree::CParser *this, struct SpeedTree::CCore *a2)
{
  SpeedTree::CWind *Wind; // eax
  SpeedTree::CParser *v4; // [esp+0h] [ebp-F8h]
  int i; // [esp+10h] [ebp-E8h]
  SpeedTree::CWind::SParams *p_dst; // [esp+14h] [ebp-E4h]
  SpeedTree::CWind::SParams dst; // [esp+18h] [ebp-E0h] BYREF
  int v8; // [esp+F0h] [ebp-8h]
  char v9; // [esp+F7h] [ebp-1h]

  v4 = this;
  v9 = 0;
  if ( !*((_BYTE *)this + 95) )
    return 1;
  SpeedTree::CWind::SParams::SParams(&dst);
  v8 = 54;
  if ( *((_DWORD *)v4 + 1) >= (unsigned int)(*((_DWORD *)v4 + 2) + 216) )
  {
    memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)(*((_DWORD *)v4 + 2) + *(_DWORD *)v4), sizeof(dst));
    *((_DWORD *)v4 + 2) += 216;
    if ( *((_BYTE *)v4 + 92) )
    {
      p_dst = &dst;
      for ( i = 0; i < 54; ++i )
      {
        p_dst->m_fStrengthResponse = COERCE_FLOAT(
                                       SpeedTree::EndianSwap(
                                         COERCE_SPEEDTREE_(p_dst->m_fStrengthResponse),
                                         (unsigned int)v4));
        p_dst = (SpeedTree::CWind::SParams *)((char *)p_dst + 4);
      }
    }
    Wind = SpeedTree::CCore::GetWind(a2);
    SpeedTree::CWind::SetParams(Wind, &dst);
    return 1;
  }
  return v9;
}
