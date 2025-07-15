void __thiscall Scaleform::Render::HAL::PopProj3D(Scaleform::Render::HAL *this)
{
  Scaleform::ArrayLH<Scaleform::Render::Matrix4x4<float>,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_ProjectionMatrix3DStack; // edi
  const __m128i *v3; // eax

  p_ProjectionMatrix3DStack = &this->ProjectionMatrix3DStack;
  Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->ProjectionMatrix3DStack.Data,
    this->ProjectionMatrix3DStack.Data.Size - 1);
  if ( this->ProjectionMatrix3DStack.Data.Size )
    v3 = (const __m128i *)&p_ProjectionMatrix3DStack->Data.Data[p_ProjectionMatrix3DStack->Data.Size - 1];
  else
    v3 = (const __m128i *)&Scaleform::Render::Matrix4x4<float>::Identity;
  memcpy((int)&this->Matrices.pObject->Proj3D, v3, sizeof(this->Matrices.pObject->Proj3D));
  this->Matrices.pObject->UVPOChanged = 1;
}
