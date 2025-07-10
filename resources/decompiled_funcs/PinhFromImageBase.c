_IMAGE_NT_HEADERS *__thiscall PinhFromImageBase(HINSTANCE__ *hmod)
{
  return (_IMAGE_NT_HEADERS *)((char *)hmod + *((_DWORD *)hmod + 15));
}
