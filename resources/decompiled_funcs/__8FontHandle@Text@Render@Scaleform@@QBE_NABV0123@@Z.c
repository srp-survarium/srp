BOOL __thiscall Scaleform::Render::Text::FontHandle::operator==(
        Scaleform::Render::Text::FontHandle *this,
        const Scaleform::Render::Text::FontHandle *f)
{
  return this->pFontManager == f->pFontManager
      && this->pFont.pObject == f->pFont.pObject
      && this->OverridenFontFlags == f->OverridenFontFlags
      && Scaleform::String::operator==(&this->FontName, &f->FontName)
      && f->FontScaleFactor == this->FontScaleFactor;
}
