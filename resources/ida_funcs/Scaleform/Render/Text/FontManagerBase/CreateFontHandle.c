Scaleform::Render::Text::FontHandle *__thiscall Scaleform::Render::Text::FontManagerBase::CreateFontHandle(
        Scaleform::Render::Text::FontManagerBase *this,
        const char *pfontName,
        bool bold,
        bool italic,
        bool device,
        BOOL allowListOfFonts,
        Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo *searchInfo)
{
  return this->CreateFontHandle(
           this,
           pfontName,
           (device ? 0x10 : 0) | italic | (bold ? 2 : 0),
           allowListOfFonts,
           searchInfo);
}
