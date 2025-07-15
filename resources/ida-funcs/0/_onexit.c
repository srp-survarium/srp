int (__cdecl *__cdecl _onexit(int (__cdecl *func)()))()
{
  int (__cdecl *retval)(); // [esp+10h] [ebp-1Ch]

  _lockexit();
  retval = onexit_nolock(func);
  _unlockexit();
  return retval;
}
