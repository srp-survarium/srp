void __thiscall Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::readPathHeader(
        Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this)
{
  unsigned __int8 *v2; // ecx
  int v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // ecx
  int v6; // eax
  int v7; // eax
  unsigned int NumEdges; // eax

  if ( this->NumContours )
  {
    v2 = &this->Data.Data->Data[this->Pos];
    v3 = (char)*v2;
    if ( (v3 & 1) != 0 )
    {
      this->MoveX = (v3 >> 1) & 0x7F | ((char)v2[1] << 7);
      v4 = 2;
    }
    else
    {
      this->MoveX = v3 >> 1;
      v4 = 1;
    }
    this->Pos += v4;
    v5 = &this->Data.Data->Data[this->Pos];
    v6 = (char)*v5;
    if ( (v6 & 1) != 0 )
    {
      this->MoveY = (v6 >> 1) & 0x7F | ((char)v5[1] << 7);
      v7 = 2;
    }
    else
    {
      this->MoveY = v6 >> 1;
      v7 = 1;
    }
    this->Pos += v7;
    this->Pos += Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadUInt30(
                   (Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)this,
                   this->Pos,
                   &this->NumEdges);
    this->EdgePos = this->Pos;
    NumEdges = this->NumEdges;
    this->JumpToPos = 1;
    if ( (NumEdges & 1) != 0 )
    {
      this->EdgePos = NumEdges >> 1;
      this->EdgePos += Scaleform::Render::PathDataDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadUInt30(
                         (Scaleform::Render::PathDataDecoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)this,
                         NumEdges >> 1,
                         &this->NumEdges);
      this->JumpToPos = 0;
    }
    this->NumEdges >>= 1;
  }
}
