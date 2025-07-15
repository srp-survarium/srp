Scaleform::Render::ShapePathType __thiscall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord,
        unsigned int *styles)
{
  return Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadPathInfo(
           &this->Decoder,
           pos,
           coord,
           styles);
}
