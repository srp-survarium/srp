void __thiscall Scaleform::Render::TreeText::ClearFilters(Scaleform::Render::TreeText *this)
{
  Scaleform::Render::TreeText::Filter filters; // [esp+4h] [ebp-20h] BYREF

  filters.Type = 0;
  Scaleform::Render::TreeText::Filter::InitByDefaultValues(&filters);
  Scaleform::Render::TreeText::SetFilters(this, &filters, 1u);
}
