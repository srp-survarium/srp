void __thiscall Scaleform::Render::Text::TextFormat::ClearUrl(Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::String::Clear(&this->Url);
  this->PresentMask &= ~0x100u;
}
