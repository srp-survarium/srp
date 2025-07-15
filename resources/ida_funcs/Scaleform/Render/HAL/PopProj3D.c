void __thiscall Scaleform::Render::HAL::PopProj3D(Scaleform::Render::HAL *this)
{
  Scaleform::ArrayLH<Scaleform::Render::Matrix4x4<float>,2,Scaleform::ArrayConstPolicy<0,8,1> > *p_ProjectionMatrix3DStack; // edi
  unsigned __int8 *v3; // eax

  p_ProjectionMatrix3DStack = &this->ProjectionMatrix3DStack;
  Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Resize(
    &this->ProjectionMatrix3DStack.Data,
    this->ProjectionMatrix3DStack.Data.Size - 1);
  if ( this->ProjectionMatrix3DStack.Data.Size )
    v3 = (unsigned __int8 *)&p_ProjectionMatrix3DStack->Data.Data[p_ProjectionMatrix3DStack->Data.Size - 1];
  else
    v3 = (unsigned __int8 *)&Scaleform::Render::Matrix4x4<float>::Identity;
  memcpy((unsigned __int8 *)&this->Matrices.pObject->Proj3D, v3, sizeof(this->Matrices.pObject->Proj3D));
  this->Matrices.pObject->UVPOChanged = 1;
}
