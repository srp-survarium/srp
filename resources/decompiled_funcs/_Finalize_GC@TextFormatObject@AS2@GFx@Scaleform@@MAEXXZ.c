void __thiscall Scaleform::GFx::AS2::TextFormatObject::Finalize_GC(Scaleform::GFx::AS2::TextFormatObject *this)
{
  Scaleform::Render::Text::TextFormat::~TextFormat(&this->mTextFormat);
  Scaleform::Render::Text::ParagraphFormat::FreeTabStops(&this->mParagraphFormat);
  Scaleform::GFx::AS2::Object::Finalize_GC(this);
}
