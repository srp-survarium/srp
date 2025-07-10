void __thiscall Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float x,
        float y)
{
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  int v7; // [esp-14h] [ebp-14h]

  v4 = (int)(x * this->Multiplier) - pos->LastX;
  v5 = (int)(y * this->Multiplier);
  v6 = v5 - pos->LastY;
  if ( v5 == pos->LastY )
  {
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
      &this->Encoder,
      v4);
    pos->LastX += v4;
    pos->LastY += v6;
  }
  else
  {
    v7 = v5 - pos->LastY;
    if ( v4 )
    {
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
        &this->Encoder,
        v4,
        v7);
      pos->LastX += v4;
    }
    else
    {
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
        &this->Encoder,
        v7);
      pos->LastX = pos->LastX;
    }
    pos->LastY += v6;
  }
}
