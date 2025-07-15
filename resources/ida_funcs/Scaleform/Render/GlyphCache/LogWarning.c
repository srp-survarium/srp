void Scaleform::Render::GlyphCache::LogWarning(Scaleform::Render::GlyphCache *this, const char *fmt, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, fmt);
  if ( this->pLog )
    ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))this->pLog->LogMessageVarg)(
      this->pLog,
      143360,
      fmt,
      va);
}
