void __thiscall Scaleform::Render::MaskPrimitive::Remove(
        Scaleform::Render::MaskPrimitive *this,
        unsigned int index,
        unsigned int count)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    &this->MaskAreas,
    index,
    count);
}
