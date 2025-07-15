Scaleform::GFx::AS2::TextFormatObject *__thiscall Scaleform::GFx::AS2::TextFormatObject::`vector deleting destructor'(
        Scaleform::GFx::AS2::TextFormatObject *this,
        char a2)
{
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&this->mParagraphFormat);
  Scaleform::Render::Text::TextFormat::~TextFormat(&this->mTextFormat);
  Scaleform::GFx::AS2::Object::~Object(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


Scaleform::GFx::AS2::TextFormatObject *__thiscall Scaleform::GFx::AS2::TextFormatObject::`vector deleting destructor'(
        char *this,
        char a2)
{
  return Scaleform::GFx::AS2::TextFormatObject::`vector deleting destructor'(
           (Scaleform::GFx::AS2::TextFormatObject *)(this - 16),
           a2);
}
