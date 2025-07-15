void __thiscall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        Scaleform::Render::ShapePathType type,
        unsigned int leftStyle,
        unsigned int rightStyle,
        unsigned int strokeStyle,
        float startX,
        float startY)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // eax
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > encoder; // [esp+8h] [ebp-8h] BYREF

  pContainer = this->pContainer;
  encoder.Multiplier = this->Multiplier;
  encoder.Encoder.Data = pContainer;
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
    &encoder,
    pos,
    type,
    leftStyle,
    rightStyle,
    strokeStyle,
    startX,
    startY);
}
