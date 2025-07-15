BOOL __fastcall FLoadedAtPreferredAddress(HINSTANCE__ *hmod, _IMAGE_NT_HEADERS *pinh)
{
  return hmod == (HINSTANCE__ *)pinh->OptionalHeader.ImageBase;
}
