void __thiscall Scaleform::Render::HAL::PushProj3D(Scaleform::Render::HAL *this, const __m128i *m)
{
  memcpy((int)&this->Matrices.pObject->Proj3D, m, sizeof(this->Matrices.pObject->Proj3D));
  this->Matrices.pObject->UVPOChanged = 1;
  Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
    &this->ProjectionMatrix3DStack.Data,
    m);
}
