void __thiscall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        unsigned int type,
        unsigned int leftStyle,
        unsigned int rightStyle,
        unsigned int strokeStyle,
        float startX,
        float startY)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // eax
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v9; // [esp+8h] [ebp-8h] BYREF

  pContainer = this->pContainer;
  v9.Multiplier = this->Multiplier;
  v9.Encoder.Data = pContainer;
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
    &v9,
    pos,
    type,
    leftStyle,
    rightStyle,
    strokeStyle,
    startX,
    startY);
}
