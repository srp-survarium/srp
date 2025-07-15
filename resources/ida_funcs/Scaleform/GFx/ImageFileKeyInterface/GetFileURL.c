const char *__thiscall Scaleform::GFx::ImageFileKeyInterface::GetFileURL(
        Scaleform::GFx::ImageFileKeyInterface *this,
        _DWORD *hdata)
{
  return (const char *)((*(_DWORD *)(hdata[5] + 16) & 0xFFFFFFFC) + 8);
}
