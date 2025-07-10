void __thiscall Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
        Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float cx,
        float cy,
        float ax,
        float ay)
{
  int v6; // ebx
  int v7; // ebp

  v6 = (int)(ax * this->Multiplier) - pos->LastX;
  v7 = (int)(ay * this->Multiplier) - pos->LastY;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
    &this->Encoder,
    (int)(cx * this->Multiplier) - pos->LastX,
    (int)(cy * this->Multiplier) - pos->LastY,
    v6,
    v7);
  pos->LastX += v6;
  pos->LastY += v7;
}
