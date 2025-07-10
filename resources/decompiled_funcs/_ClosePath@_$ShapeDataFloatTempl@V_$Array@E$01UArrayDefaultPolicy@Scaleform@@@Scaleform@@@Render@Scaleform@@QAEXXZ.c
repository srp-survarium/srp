void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  if ( this->StartX != this->LastX || this->StartY != this->LastY )
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
      this,
      this->StartX,
      this->StartY);
}
