int __cdecl atexit(int (__cdecl *func)())
{
  return (_onexit(func) != 0) - 1;
}
