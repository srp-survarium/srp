char __thiscall SpeedTree::CParser::ParseLeafCards(
        SpeedTree::CParser *this,
        struct SpeedTree::CParser::SLeafCardsTmp *a2)
{
  int i; // [esp+20h] [ebp-8h]
  char v5; // [esp+27h] [ebp-1h]

  v5 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 4) )
  {
    *(_DWORD *)a2 = SpeedTree::CParser::ParseInt(this);
    for ( i = 0; i < *(_DWORD *)a2; ++i )
    {
      if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 4) )
      {
        *((_DWORD *)a2 + 42 * i + 1) = SpeedTree::CParser::ParseInt(this);
        *((float *)a2 + 42 * i + 2) = SpeedTree::CParser::ParseFloat(this);
        v5 = 1;
      }
    }
    if ( !*(_DWORD *)a2 )
      return 1;
  }
  return v5;
}
