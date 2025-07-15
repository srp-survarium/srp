const char *__thiscall Scaleform::GFx::GFxMovieDataDefFileKeyInterface::GetFileURL(
        Scaleform::GFx::GFxMovieDataDefFileKeyInterface *this,
        _DWORD *hdata)
{
  return (const char *)((hdata[2] & 0xFFFFFFFC) + 8);
}
