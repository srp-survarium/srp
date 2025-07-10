void __thiscall Scaleform::Render::Text::TextFormat::SetLetterSpacing(
        Scaleform::Render::Text::TextFormat *this,
        float letterSpacing)
{
  this->PresentMask |= 2u;
  this->LetterSpacing = (int)(letterSpacing * 20.0);
}
