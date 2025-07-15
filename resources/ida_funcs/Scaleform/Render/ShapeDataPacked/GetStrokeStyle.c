void __thiscall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int idx,
        Scaleform::Render::StrokeStyleType *p)
{
  Scaleform::Render::StrokeStyleType::operator=(p, &this->StrokeStyles.Data.Data[idx - 1]);
}
