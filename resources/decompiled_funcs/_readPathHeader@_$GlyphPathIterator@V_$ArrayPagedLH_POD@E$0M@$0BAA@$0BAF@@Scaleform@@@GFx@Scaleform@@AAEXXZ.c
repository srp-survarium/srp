void __thiscall Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::readPathHeader(
        Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this)
{
  unsigned int NumEdges; // eax

  if ( this->NumContours )
  {
    this->Pos += Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
                   &this->Data,
                   this->Pos,
                   &this->MoveX);
    this->Pos += Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
                   &this->Data,
                   this->Pos,
                   &this->MoveY);
    this->Pos += Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
                   &this->Data,
                   this->Pos,
                   &this->NumEdges);
    this->EdgePos = this->Pos;
    NumEdges = this->NumEdges;
    this->JumpToPos = 1;
    if ( (NumEdges & 1) != 0 )
    {
      this->EdgePos = NumEdges >> 1;
      this->EdgePos += Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
                         &this->Data,
                         NumEdges >> 1,
                         &this->NumEdges);
      this->JumpToPos = 0;
    }
    this->NumEdges >>= 1;
  }
}
