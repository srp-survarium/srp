void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStrokeStyle(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int idx,
        Scaleform::Render::StrokeStyleType *p)
{
  Scaleform::Render::StrokeStyleType::operator=(p, &this->Strokes.Data.Data[idx - 1]);
}
