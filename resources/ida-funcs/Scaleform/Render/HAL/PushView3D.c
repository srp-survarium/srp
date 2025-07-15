void __thiscall Scaleform::Render::HAL::PushView3D(Scaleform::Render::HAL *this, const __m128i *m)
{
  memcpy((int)&this->Matrices.pObject->View3D, m, sizeof(this->Matrices.pObject->View3D));
  this->Matrices.pObject->UVPOChanged = 1;
  Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
    &this->ViewMatrix3DStack.Data,
    m);
}
