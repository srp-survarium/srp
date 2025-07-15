void __thiscall Scaleform::Render::HAL::PopView3D(Scaleform::Render::HAL *this)
{
  Scaleform::ArrayLH<Scaleform::Render::Matrix3x4<float>,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_ViewMatrix3DStack; // edi
  const __m128i *v3; // eax

  p_ViewMatrix3DStack = &this->ViewMatrix3DStack;
  Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->ViewMatrix3DStack.Data,
    this->ViewMatrix3DStack.Data.Size - 1);
  if ( this->ViewMatrix3DStack.Data.Size )
    v3 = (const __m128i *)&p_ViewMatrix3DStack->Data.Data[p_ViewMatrix3DStack->Data.Size - 1];
  else
    v3 = (const __m128i *)&Scaleform::Render::Matrix3x4<float>::Identity;
  memcpy((int)&this->Matrices.pObject->View3D, v3, sizeof(this->Matrices.pObject->View3D));
  this->Matrices.pObject->UVPOChanged = 1;
}
