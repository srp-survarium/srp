void __thiscall Scaleform::Render::TreeText::ClearFilters(Scaleform::Render::TreeText *this)
{
  Scaleform::Render::TreeText::Filter filter; // [esp+4h] [ebp-20h] BYREF

  filter.Type = 0;
  Scaleform::Render::TreeText::Filter::InitByDefaultValues(&filter);
  Scaleform::Render::TreeText::SetFilters(this, &filter, 1u);
}
