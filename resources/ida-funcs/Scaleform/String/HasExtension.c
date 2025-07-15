BOOL __cdecl Scaleform::String::HasExtension(char *path)
{
  const char *v2; // [esp+0h] [ebp-4h] BYREF

  v2 = 0;
  Scaleform::ScanFilePath(path, 0, &v2);
  return v2 != 0;
}
