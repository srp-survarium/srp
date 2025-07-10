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
