BOOL __thiscall Scaleform::Render::Text::TextFormat::IsUrlSet(Scaleform::Render::Text::TextFormat *this)
{
  return (this->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&this->Url);
}
