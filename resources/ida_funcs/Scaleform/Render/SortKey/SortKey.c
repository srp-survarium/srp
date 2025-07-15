void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::MeshProvider *fill,
        bool is3D)
{
  this->Data = fill;
  if ( is3D )
  {
    this->pImpl = &Scaleform::Render::SKI_ComplexPrimitive::Instance3D;
    Scaleform::Render::SKI_ComplexPrimitive::Instance3D.AddRef(
      &Scaleform::Render::SKI_ComplexPrimitive::Instance3D,
      fill);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_ComplexPrimitive::Instance;
    Scaleform::Render::SKI_ComplexPrimitive::Instance.AddRef(&Scaleform::Render::SKI_ComplexPrimitive::Instance, fill);
  }
}


void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::PrimitiveFill *fill,
        bool is3D)
{
  this->Data = fill;
  if ( is3D )
  {
    this->pImpl = &Scaleform::Render::SKI_Primitive::Instance3D;
    Scaleform::Render::SKI_Primitive::Instance3D.AddRef(&Scaleform::Render::SKI_Primitive::Instance3D, fill);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_Primitive::Instance;
    Scaleform::Render::SKI_Primitive::Instance.AddRef(&Scaleform::Render::SKI_Primitive::Instance, fill);
  }
}


void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::SortKeyMaskType maskType)
{
  Scaleform::Render::SortKeyInterface *v3; // ecx

  v3 = SortKeyMaskInterfaces[maskType];
  this->Data = (void *)maskType;
  this->pImpl = v3;
  v3->AddRef(v3, (void *)maskType);
}


void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::SortKeyTextType __formal,
        bool is3D)
{
  this->Data = 0;
  if ( is3D )
  {
    this->pImpl = &Scaleform::Render::SKI_TextPrimitive::Instance3D;
    Scaleform::Render::SKI_TextPrimitive::Instance3D.AddRef(&Scaleform::Render::SKI_TextPrimitive::Instance3D, 0);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_TextPrimitive::Instance;
    Scaleform::Render::SKI_TextPrimitive::Instance.AddRef(&Scaleform::Render::SKI_TextPrimitive::Instance, 0);
  }
}


void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::SortKeyType keyType,
        Scaleform::Render::UserDataState::Data *data)
{
  if ( keyType == SortKey_UserDataStart )
  {
    this->pImpl = &Scaleform::Render::SKI_UserData::Start_Instance;
    this->Data = (void *)data;
    Scaleform::Render::SKI_UserData::Start_Instance.AddRef(
      &Scaleform::Render::SKI_UserData::Start_Instance,
      (void *)data);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_UserData::End_Instance;
    this->Data = 0;
    Scaleform::Render::SKI_UserData::End_Instance.AddRef(&Scaleform::Render::SKI_UserData::End_Instance, 0);
  }
}


void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::SortKeyType filterKeyType,
        Scaleform::Render::FilterSet *filters)
{
  if ( filterKeyType == SortKey_FilterStart )
  {
    this->pImpl = &Scaleform::Render::SKI_Filter::Start_Instance;
    this->Data = filters;
    Scaleform::Render::SKI_Filter::Start_Instance.AddRef(&Scaleform::Render::SKI_Filter::Start_Instance, filters);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_Filter::End_Instance;
    this->Data = 0;
    Scaleform::Render::SKI_Filter::End_Instance.AddRef(&Scaleform::Render::SKI_Filter::End_Instance, 0);
  }
}


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


void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::SortKeyType blendKeyType,
        Scaleform::Render::BlendMode mode)
{
  if ( blendKeyType == SortKey_BlendModeStart )
  {
    this->pImpl = &Scaleform::Render::SKI_BlendMode::Start_Instance;
    this->Data = (void *)mode;
    Scaleform::Render::SKI_BlendMode::Start_Instance.AddRef(
      &Scaleform::Render::SKI_BlendMode::Start_Instance,
      (void *)mode);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_BlendMode::End_Instance;
    this->Data = (void *)-1;
    Scaleform::Render::SKI_BlendMode::End_Instance.AddRef(&Scaleform::Render::SKI_BlendMode::End_Instance, (void *)-1);
  }
}
