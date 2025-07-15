int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != 0) - 1;
}
