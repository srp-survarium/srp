void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::SortKeyType pm3DKeyType,
        Scaleform::Render::Matrix4x4Ref<float> *projMat)
{
  if ( pm3DKeyType == SortKey_ProjectionMatrix3DStart )
  {
    this->pImpl = &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance;
    this->Data = projMat;
    Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.AddRef(
      &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
      projMat);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance;
    this->Data = 0;
    Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance.AddRef(
      &Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance,
      0);
  }
}
