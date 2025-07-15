int __cdecl _unlink(const char *path)
{
  return remove(path);
}
