int __cdecl _getdrive()
{
  char *v0; // ebx
  signed int CurrentDirectoryA; // esi
  unsigned __int8 *v2; // eax
  int v3; // edi
  int v5; // [esp+10h] [ebp-110h]
  char Buffer[264]; // [esp+14h] [ebp-10Ch] BYREF

  v5 = 0;
  v0 = Buffer;
  CurrentDirectoryA = GetCurrentDirectoryA(0x105u, Buffer);
  if ( CurrentDirectoryA > 260 )
  {
    v2 = _calloc_crt(CurrentDirectoryA + 1, 1u);
    v0 = (char *)v2;
    if ( v2 )
    {
      v5 = 1;
      CurrentDirectoryA = GetCurrentDirectoryA(CurrentDirectoryA + 1, (LPSTR)v2);
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
      v3 = toupper((unsigned __int8)*v0) - 64;
  }
  else
  {
    *_errno() = 12;
  }
  if ( v5 )
    free(v0);
  return v3;
}
