void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::SortKeyType vm3DKeyType,
        Scaleform::Render::Matrix3x4Ref<float> *viewMat)
{
  if ( vm3DKeyType == SortKey_ViewMatrix3DStart )
  {
    this->pImpl = &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance;
    this->Data = viewMat;
    Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.AddRef(
      &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
      viewMat);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_ViewMatrix3D::End_Instance;
    this->Data = 0;
    Scaleform::Render::SKI_ViewMatrix3D::End_Instance.AddRef(&Scaleform::Render::SKI_ViewMatrix3D::End_Instance, 0);
  }
}
