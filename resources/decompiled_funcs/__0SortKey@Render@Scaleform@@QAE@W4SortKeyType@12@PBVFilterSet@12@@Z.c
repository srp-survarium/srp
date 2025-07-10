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
