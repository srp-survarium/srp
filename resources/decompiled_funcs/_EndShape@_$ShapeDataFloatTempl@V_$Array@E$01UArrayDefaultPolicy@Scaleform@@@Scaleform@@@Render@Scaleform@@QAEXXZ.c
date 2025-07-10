void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus Status; // eax
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > encoder; // [esp+4h] [ebp-4h] BYREF

  Status = this->Status;
  if ( Status != Status_EndShape && Status )
  {
    if ( Status != Status_EndPath )
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(this);
    encoder.Data = this->Data;
    Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteChar(
      &encoder,
      7);
    this->Status = Status_EndShape;
  }
}
