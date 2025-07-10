void __thiscall Scaleform::Render::Text::TextFormat::SetUrl(
        Scaleform::Render::Text::TextFormat *this,
        const Scaleform::String *url)
{
  Scaleform::String::operator=(&this->Url, url);
  this->PresentMask |= 0x100u;
}
