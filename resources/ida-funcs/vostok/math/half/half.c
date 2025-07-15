void __thiscall vostok::math::half::half(vostok::math::half *this, float x)
{
  int v2; // esi
  int v3; // edi
  signed int v4; // edx
  unsigned __int16 v5; // di
  int v6; // edx

  v2 = (unsigned __int8)(LODWORD(x) >> 23) - 112;
  v3 = HIWORD(LODWORD(x)) & 0x8000;
  v4 = (unsigned int)&unk_7FFFFF & LODWORD(x);
  this->data = v3;
  if ( v2 > 0 )
  {
    if ( (unsigned __int8)(LODWORD(x) >> 23) == 255 )
    {
      v5 = v3 | 0x7C00;
      this->data = v5;
      if ( v4 )
        this->data = (v4 >> 13) | v5 | (v4 >> 13 == 0);
    }
    else
    {
      v6 = v4 + 4096;
      if ( ((unsigned int)&unk_800000 & v6) != 0 )
      {
        v6 = 0;
        ++v2;
      }
      if ( v2 < 31 )
        this->data = v3 | ((_WORD)v2 << 10) | (v6 >> 13);
      else
        this->data = v3 | 0x7C00;
    }
  }
  else
  {
    this->data = v3 | ((((int)((unsigned int)&unk_800000 | v4) >> (1 - v2)) + 4096) >> 13);
  }
}
