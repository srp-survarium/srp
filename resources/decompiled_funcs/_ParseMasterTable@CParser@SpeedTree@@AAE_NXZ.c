char __thiscall SpeedTree::CParser::ParseMasterTable(SpeedTree::CParser *this)
{
  __int16 v3; // [esp+Ah] [ebp-52h]
  int i; // [esp+50h] [ebp-Ch]
  int j; // [esp+50h] [ebp-Ch]
  int k; // [esp+50h] [ebp-Ch]
  int m; // [esp+50h] [ebp-Ch]
  int v8; // [esp+54h] [ebp-8h]
  int v9; // [esp+54h] [ebp-8h]
  int v10; // [esp+54h] [ebp-8h]
  int v11; // [esp+54h] [ebp-8h]
  int v12; // [esp+54h] [ebp-8h]
  char v13; // [esp+5Bh] [ebp-1h]

  v13 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 8) )
  {
    *((_DWORD *)this + 7) = SpeedTree::CParser::ParseInt(this);
    *((_DWORD *)this + 10) = SpeedTree::CParser::ParseInt(this);
    *((_DWORD *)this + 13) = SpeedTree::CParser::ParseInt(this);
    *((_DWORD *)this + 16) = SpeedTree::CParser::ParseInt(this);
    *((_DWORD *)this + 19) = SpeedTree::CParser::ParseInt(this);
    *((_DWORD *)this + 20) = *((_DWORD *)this + 13)
                           + 4 * *((_DWORD *)this + 10)
                           + 4 * *((_DWORD *)this + 7)
                           + 2 * *((_DWORD *)this + 16)
                           + 4 * *((_DWORD *)this + 19);
    if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 20) + *((_DWORD *)this + 2)) )
    {
      *((_DWORD *)this + 4) = *((_DWORD *)this + 2) + *(_DWORD *)this;
      *((_DWORD *)this + 2) += *((_DWORD *)this + 20);
      v8 = *((_DWORD *)this + 4);
      *((_DWORD *)this + 5) = v8;
      *((_DWORD *)this + 6) = v8;
      v9 = v8 + 4 * *((_DWORD *)this + 7);
      *((_DWORD *)this + 8) = v9;
      *((_DWORD *)this + 9) = v9;
      v10 = v9 + 4 * *((_DWORD *)this + 10);
      *((_DWORD *)this + 11) = v10;
      *((_DWORD *)this + 12) = v10;
      v11 = *((_DWORD *)this + 13) + v10;
      *((_DWORD *)this + 14) = v11;
      *((_DWORD *)this + 15) = v11;
      v12 = v11 + 2 * *((_DWORD *)this + 16);
      *((_DWORD *)this + 17) = v12;
      *((_DWORD *)this + 18) = v12;
      if ( *((_BYTE *)this + 92) )
      {
        for ( i = 0; i < *((_DWORD *)this + 7); ++i )
          *(float *)(*((_DWORD *)this + 5) + 4 * i) = COERCE_FLOAT(SpeedTree::EndianSwap(COERCE_SPEEDTREE_(*(float *)(*((_DWORD *)this + 5) + 4 * i))));
        for ( j = 0; j < *((_DWORD *)this + 10); ++j )
          *(_DWORD *)(*((_DWORD *)this + 8) + 4 * j) = SpeedTree::EndianSwap(*(SpeedTree **)(*((_DWORD *)this + 8)
                                                                                           + 4 * j));
        for ( k = 0; k < *((_DWORD *)this + 16); ++k )
        {
          v3 = *(_WORD *)(*((_DWORD *)this + 14) + 2 * k);
          *(_WORD *)(*((_DWORD *)this + 14) + 2 * k) = ((unsigned __int8)v3 << 8) | ((v3 & 0xFF00) >> 8);
        }
        for ( m = 0; m < *((_DWORD *)this + 19); ++m )
          *(_DWORD *)(*((_DWORD *)this + 18) + 4 * m) = SpeedTree::EndianSwap(*(SpeedTree **)(*((_DWORD *)this + 18)
                                                                                            + 4 * m));
      }
      return 1;
    }
  }
  return v13;
}
