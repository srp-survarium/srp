BOOL __cdecl Scaleform::String::HasExtension(const char *path)
{
  const char *ext; // [esp+0h] [ebp-4h] BYREF

  ext = 0;
  Scaleform::ScanFilePath(path, 0, &ext);
  return ext != 0;
}
