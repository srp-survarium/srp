void __thiscall Scaleform::Render::ProfileViews::SetProfileViews(
        Scaleform::Render::ProfileViews *this,
        unsigned __int64 modes)
{
  int v2; // edi
  float *v3; // eax
  int v4; // esi
  double v5; // st6
  double v6; // st6
  double v7; // st6

  this->OverrideBlend = Blend_None;
  this->OverrideMasks = 0;
  this->FillMode = 0;
  this->BatchMode = 0;
  this->DrawMode = 0;
  this->NoFilterCaching = 0;
  this->NoFilterCaching = ((unsigned int)&_sbh_sizeHeaderList & HIDWORD(modes)) != 0;
  v2 = WORD2(modes);
  HIDWORD(modes) = v2;
  if ( v2 | (unsigned int)modes )
  {
    v3 = &this->FillCxforms[0].M[1][3];
    v4 = 4;
    do
    {
      *(v3 - 7) = 0.0;
      *(v3 - 6) = 0.0;
      *(v3 - 5) = 0.0;
      *(v3 - 4) = 0.0;
      *(v3 - 3) = 0.0;
      *(v3 - 2) = 0.0;
      *(v3 - 1) = 0.0;
      *v3 = 255.0;
      v3 += 8;
      --v4;
    }
    while ( v4 );
    this->OverrideMasks = 1;
    if ( (modes & 0x100) != 0 )
    {
      v5 = ((double)(unsigned __int8)modes - (double)0LL) * 0.003921568859368563;
      this->FillCxforms[0].M[1][0] = this->FillCxforms[0].M[1][0] + v5;
      this->FillCxforms[3].M[1][0] = v5 + this->FillCxforms[3].M[1][0];
      this->FillMode = 1;
    }
    if ( (modes & 0x200) != 0 )
    {
      this->FillCxforms[1].M[1][0] = ((double)(unsigned __int8)modes - (double)0LL) * 0.003921568859368563
                                   + this->FillCxforms[1].M[1][0];
      this->FillMode = 1;
    }
    if ( (modes & 0x400) != 0 )
    {
      this->FillCxforms[2].M[1][0] = ((double)(unsigned __int8)modes - (double)0LL) * 0.003921568859368563
                                   + this->FillCxforms[2].M[1][0];
      this->FillMode = 1;
    }
    if ( (modes & 0x1000) != 0 )
    {
      this->FillCxforms[3].M[1][0] = ((double)(unsigned __int8)modes - (double)0LL) * 0.003921568859368563
                                   + this->FillCxforms[3].M[1][0];
      this->FillMode = 1;
    }
    if ( (modes & 0x800) != 0 )
      this->BatchMode |= 9u;
    if ( (modes & 0x1000000) != 0 )
    {
      v6 = ((double)BYTE2(modes) - (double)0LL) * 0.003921568859368563;
      this->FillCxforms[0].M[1][1] = this->FillCxforms[0].M[1][1] + v6;
      this->FillCxforms[3].M[1][1] = v6 + this->FillCxforms[3].M[1][1];
      this->FillMode = 1;
    }
    if ( (modes & 0x2000000) != 0 )
    {
      this->FillCxforms[1].M[1][1] = ((double)BYTE2(modes) - (double)0LL) * 0.003921568859368563
                                   + this->FillCxforms[1].M[1][1];
      this->FillMode = 1;
    }
    if ( (modes & 0x4000000) != 0 )
    {
      this->FillCxforms[2].M[1][1] = ((double)BYTE2(modes) - (double)0LL) * 0.003921568859368563
                                   + this->FillCxforms[2].M[1][1];
      this->FillMode = 1;
    }
    if ( (modes & 0x10000000) != 0 )
    {
      this->FillCxforms[3].M[1][1] = ((double)BYTE2(modes) - (double)0LL) * 0.003921568859368563
                                   + this->FillCxforms[3].M[1][1];
      this->FillMode = 1;
    }
    if ( ((modes >> 16) & 0x800) != 0 )
      this->BatchMode |= 0xAu;
    if ( (v2 & 0x100) != 0 )
    {
      v7 = ((double)(unsigned __int8)v2 - (double)0LL) * 0.003921568859368563;
      this->FillCxforms[0].M[1][2] = this->FillCxforms[0].M[1][2] + v7;
      this->FillCxforms[3].M[1][2] = v7 + this->FillCxforms[3].M[1][2];
      this->FillMode = 1;
    }
    if ( (v2 & 0x200) != 0 )
    {
      this->FillCxforms[1].M[1][2] = ((double)(unsigned __int8)v2 - (double)0LL) * 0.003921568859368563
                                   + this->FillCxforms[1].M[1][2];
      this->FillMode = 1;
    }
    if ( (v2 & 0x400) != 0 )
    {
      this->FillCxforms[2].M[1][2] = ((double)(unsigned __int8)v2 - (double)0LL) * 0.003921568859368563
                                   + this->FillCxforms[2].M[1][2];
      this->FillMode = 1;
    }
    if ( (v2 & 0x1000) != 0 )
    {
      this->FillCxforms[3].M[1][2] = 0.003921568859368563 * ((double)(unsigned __int8)v2 - (double)0LL)
                                   + this->FillCxforms[3].M[1][2];
      this->FillMode = 1;
    }
    if ( (v2 & 0x800) != 0 )
      this->BatchMode |= 0xCu;
    if ( this->FillMode )
      this->OverrideBlend = Blend_Add;
  }
}
