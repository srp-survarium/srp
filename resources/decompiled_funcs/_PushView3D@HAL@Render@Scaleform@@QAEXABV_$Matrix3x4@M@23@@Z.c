void __thiscall Scaleform::Render::HAL::PushView3D(
        Scaleform::Render::HAL *this,
        Scaleform::Render::Matrix3x4<float> *m)
{
  memcpy(
    (unsigned __int8 *)&this->Matrices.pObject->View3D,
    (unsigned __int8 *)m,
    sizeof(this->Matrices.pObject->View3D));
  this->Matrices.pObject->UVPOChanged = 1;
  Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
    &this->ViewMatrix3DStack.Data,
    m);
}
