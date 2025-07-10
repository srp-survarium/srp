void __thiscall Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        Scaleform::Render::ShapePathType type,
        unsigned int leftStyle,
        unsigned int rightStyle,
        unsigned int strokeStyle,
        float startX,
        float startY)
{
  int v9; // eax
  int v10; // eax

  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
    &this->Encoder,
    type);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &this->Encoder,
    leftStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &this->Encoder,
    rightStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &this->Encoder,
    strokeStyle);
  v9 = (int)(startX * this->Multiplier);
  pos->LastX = v9;
  pos->StartX = v9;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
    &this->Encoder,
    v9);
  v10 = (int)(startY * this->Multiplier);
  pos->LastY = v10;
  pos->StartY = v10;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
    &this->Encoder,
    v10);
}
