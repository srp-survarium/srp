void __thiscall Scaleform::Render::MaskPrimitive::Insert(
        Scaleform::Render::MaskPrimitive *this,
        unsigned int index,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->MaskAreas,
    index,
    m);
}
