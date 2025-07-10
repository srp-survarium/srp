char __thiscall SpeedTree::CParser::ParseBillboards(SpeedTree::CParser *this)
{
  float *v3; // [esp+14h] [ebp-54h]
  struct SpeedTree::Vec3 v4; // [esp+48h] [ebp-20h] BYREF
  int j; // [esp+54h] [ebp-14h]
  int i; // [esp+58h] [ebp-10h]
  int v7; // [esp+5Ch] [ebp-Ch]
  int v8; // [esp+60h] [ebp-8h]
  char v9; // [esp+67h] [ebp-1h]

  v9 = 0;
  if ( *((_DWORD *)this + 1) >= (unsigned int)(*((_DWORD *)this + 2) + 20) )
  {
    v8 = *((_DWORD *)this + 3) + 40;
    *(_DWORD *)v8 = SpeedTree::CParser::ParseInt(this);
    *(float *)(v8 + 8) = SpeedTree::CParser::ParseFloat(this);
    *(float *)(v8 + 12) = SpeedTree::CParser::ParseFloat(this);
    *(float *)(v8 + 16) = SpeedTree::CParser::ParseFloat(this);
    *(_DWORD *)(v8 + 4) = SpeedTree::CParser::ParseInt(this);
    v9 = 1;
  }
  if ( v9 )
  {
    if ( *((_DWORD *)this + 1) < (unsigned int)(*((_DWORD *)this + 2) + 84) )
    {
      return 0;
    }
    else
    {
      v7 = *((_DWORD *)this + 3) + 64;
      *(_BYTE *)v7 = SpeedTree::CParser::ParseInt(this) != 0;
      *(_DWORD *)(v7 + 4) = SpeedTree::CParser::ParseInt(this);
      for ( i = 0; i < 8; ++i )
        *(float *)(v7 + 4 * i + 56) = SpeedTree::CParser::ParseFloat(this);
      if ( SpeedTree::CParser::TexturesNeedFlipping(this) )
      {
        *(float *)(v7 + 60) = 1.0 - *(float *)(v7 + 60);
        *(float *)(v7 + 68) = 1.0 - *(float *)(v7 + 68);
        *(float *)(v7 + 76) = 1.0 - *(float *)(v7 + 76);
        *(float *)(v7 + 84) = 1.0 - *(float *)(v7 + 84);
      }
      *(float *)(v7 + 88) = *(float *)(v7 + 64);
      *(float *)(v7 + 92) = *(float *)(v7 + 76);
      *(float *)(v7 + 96) = *(float *)(v7 + 64) - *(float *)(v7 + 56);
      *(float *)(v7 + 100) = *(float *)(v7 + 76) - *(float *)(v7 + 68);
      for ( j = 0; j < 4; ++j )
      {
        v3 = (float *)(v7 + 12 * j + 8);
        *v3 = SpeedTree::CParser::ParseFloat(this);
        v3[1] = SpeedTree::CParser::ParseFloat(this);
        v3[2] = SpeedTree::CParser::ParseFloat(this);
        SpeedTree::CParser::ConvertCoord(
          this,
          &v4,
          *(float *)(v7 + 12 * j + 8),
          *(float *)(v7 + 12 * j + 12),
          *(float *)(v7 + 12 * j + 16));
        *(struct SpeedTree::Vec3 *)(v7 + 12 * j + 8) = v4;
      }
    }
  }
  return v9;
}
