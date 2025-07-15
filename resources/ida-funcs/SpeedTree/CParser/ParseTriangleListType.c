char __thiscall SpeedTree::CParser::ParseTriangleListType(
        SpeedTree::CParser *this,
        struct SpeedTree::CParser::STriListTmp *a2)
{
  int *v4; // [esp+2Ch] [ebp-Ch]
  int i; // [esp+30h] [ebp-8h]
  char v6; // [esp+37h] [ebp-1h]

  v6 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 4) )
  {
    *(_DWORD *)a2 = SpeedTree::CParser::ParseInt(this);
    for ( i = 0; i < *(_DWORD *)a2; ++i )
    {
      v4 = (int *)((char *)a2 + 176 * i + 4);
      if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 8) )
      {
        *v4 = SpeedTree::CParser::ParseInt(this);
        if ( *v4 > 0 )
        {
          *((_BYTE *)a2 + 176 * i + 12) = SpeedTree::CParser::ParseInt(this) != 0;
          *((float *)a2 + 44 * i + 4) = SpeedTree::CParser::ParseFloat(this);
          *((_DWORD *)a2 + 44 * i + 2) = SpeedTree::CParser::ParseInt(this);
          v6 = 1;
        }
      }
    }
    if ( !*(_DWORD *)a2 )
      return 1;
  }
  return v6;
}
