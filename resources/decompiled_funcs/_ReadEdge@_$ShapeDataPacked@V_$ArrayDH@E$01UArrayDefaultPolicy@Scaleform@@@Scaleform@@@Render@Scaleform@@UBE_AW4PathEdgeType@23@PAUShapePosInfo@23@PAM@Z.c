Scaleform::Render::PathEdgeType __thiscall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Render::ShapePosInfo *pos,
        float *coord)
{
  return Scaleform::Render::ShapeDataPackedDecoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ReadEdge(
           &this->Decoder,
           pos,
           coord);
}
