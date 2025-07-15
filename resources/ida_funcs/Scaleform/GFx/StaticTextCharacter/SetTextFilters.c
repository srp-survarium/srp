void __thiscall Scaleform::GFx::StaticTextCharacter::SetTextFilters(
        Scaleform::GFx::StaticTextCharacter *this,
        const Scaleform::Render::Text::TextFilter *f)
{
  Scaleform::Render::Text::TextFilter::operator=(&this->Filter, f);
  Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(this);
}
