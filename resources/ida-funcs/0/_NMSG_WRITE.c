void __cdecl _NMSG_WRITE(int rterrnum)
{
  unsigned int v1; // edi
  int v2; // eax
  int v3; // eax
  HANDLE StdHandle; // eax
  void *v5; // ebx
  unsigned __int8 **p_rterrtxt; // esi
  DWORD v7; // eax
  unsigned int NumberOfBytesWritten; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v9; // [esp+10h] [ebp-4h]

  v1 = 0;
  v9 = 0;
  do
  {
    if ( rterrnum == rterrs[v1].rterrno )
      break;
    v9 = ++v1;
  }
  while ( v1 < 0x17 );
  if ( v1 < 0x17 )
  {
    if ( _set_error_mode(rterrnum, v1, 3) == 1 || !_set_error_mode(rterrnum, v1, 3) && __app_type == 1 )
    {
      StdHandle = GetStdHandle(0xFFFFFFF4);
      v5 = StdHandle;
      if ( StdHandle && StdHandle != (HANDLE)-1 )
      {
        p_rterrtxt = (unsigned __int8 **)&rterrs[v1].rterrtxt;
        strlen(*p_rterrtxt);
        WriteFile(v5, *p_rterrtxt, v7, &NumberOfBytesWritten, 0);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( strcpy_s((int)outmsg, outmsg, 788, "Runtime Error!\n\nProgram: ") )
        _invoke_watson(788, (int)outmsg, 0);
      outmsg[285] = 0;
      if ( !GetModuleFileNameA(0, &outmsg[25], 0x104u)
        && strcpy_s((int)outmsg, &outmsg[25], 763, "<program name unknown>") )
      {
        _invoke_watson(788, (int)outmsg, (int)&outmsg[25]);
      }
      strlen((unsigned __int8 *)&outmsg[25]);
      if ( (unsigned int)(v2 + 1) > 0x3C )
      {
        strlen((unsigned __int8 *)&outmsg[25]);
        if ( strncpy_s((int)outmsg, &outmsg[v3 - 34], (char *)&gpFlsAlloc - &outmsg[v3 - 34], "...", 3u) )
          _invoke_watson(788, (int)outmsg, 0);
      }
      if ( strcat_s((int)outmsg, outmsg, 788, "\n\n") )
        _invoke_watson(788, (int)outmsg, 0);
      if ( strcat_s((int)outmsg, outmsg, 788, rterrs[v9].rterrtxt) )
        _invoke_watson(788, (int)outmsg, 0);
      __crtMessageBoxA(outmsg, "Microsoft Visual C++ Runtime Library", 0x12010u);
    }
  }
}
