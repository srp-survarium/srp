unsigned int __cdecl _getdrive()
{
  unsigned __int8 *v0; // ebx
  signed int CurrentDirectoryA; // esi
  char *v2; // eax
  unsigned int v3; // edi
  int memfree; // [esp+10h] [ebp-110h]
  char curdirstr[264]; // [esp+14h] [ebp-10Ch] BYREF

  memfree = 0;
  v0 = (unsigned __int8 *)curdirstr;
  CurrentDirectoryA = GetCurrentDirectoryA(0x105u, curdirstr);
  if ( CurrentDirectoryA > 260 )
  {
    v2 = (char *)_calloc_crt(CurrentDirectoryA + 1, 1u);
    v0 = (unsigned __int8 *)v2;
    if ( v2 )
    {
      memfree = 1;
      CurrentDirectoryA = GetCurrentDirectoryA(CurrentDirectoryA + 1, v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryA = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryA )
  {
    if ( v0[1] == 58 )
      v3 = toupper(*v0) - 64;
  }
  else
  {
    *_errno() = 12;
  }
  if ( memfree )
    free(v0);
  return v3;
}
