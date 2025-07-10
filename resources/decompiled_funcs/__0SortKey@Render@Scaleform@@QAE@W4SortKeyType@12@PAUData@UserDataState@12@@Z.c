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
