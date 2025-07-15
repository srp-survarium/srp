int __cdecl _getch()
{
  int v1; // [esp+10h] [ebp-1Ch]

  _lock(3);
  v1 = _getch_nolock();
  _unlock(3);
  return v1;
}
