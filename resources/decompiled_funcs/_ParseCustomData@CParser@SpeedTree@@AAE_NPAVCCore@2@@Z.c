char __thiscall SpeedTree::CParser::ParseCustomData(SpeedTree::CParser *this, struct SpeedTree::CCore *a2)
{
  int j; // [esp+24h] [ebp-24h]
  int i; // [esp+28h] [ebp-20h]
  unsigned int v6[5]; // [esp+2Ch] [ebp-1Ch] BYREF
  unsigned int siNumElements; // [esp+40h] [ebp-8h]
  char v8; // [esp+47h] [ebp-1h]

  v8 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 20) )
  {
    siNumElements = 0;
    memset(v6, 0, sizeof(v6));
    for ( i = 0; i < 5; ++i )
    {
      v6[i] = SpeedTree::CParser::ParseInt(this);
      siNumElements += v6[i];
    }
    if ( *((_DWORD *)this + 1) >= siNumElements + *((_DWORD *)this + 2) )
    {
      a2->m_pUserStrings[0] = SpeedTree::st_new_array<char>(siNumElements);
      memcpy(
        (unsigned __int8 *)a2->m_pUserStrings[0],
        (unsigned __int8 *)(*((_DWORD *)this + 2) + *(_DWORD *)this),
        siNumElements);
      *((_DWORD *)this + 2) += siNumElements;
      for ( j = 1; j < 5; ++j )
        a2->m_pUserStrings[j] = (char *)(v6[j - 1] + *((_DWORD *)&a2->m_strUserString.m_bExternalMemory + j));
      return 1;
    }
  }
  return v8;
}
