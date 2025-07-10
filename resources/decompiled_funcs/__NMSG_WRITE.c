void __cdecl _NMSG_WRITE(int rterrnum)
{
  unsigned int v1; // edi
  int v2; // eax
  int v3; // eax
  HANDLE StdHandle; // eax
  void *v5; // ebx
  unsigned __int8 **p_rterrtxt; // esi
  DWORD v7; // eax
  unsigned int bytes_written; // [esp+Ch] [ebp-8h] BYREF
  int tblindx; // [esp+10h] [ebp-4h]

  v1 = 0;
  tblindx = 0;
  do
  {
    if ( rterrnum == rterrs[v1].rterrno )
      break;
    tblindx = ++v1;
  }
  while ( v1 < 0x17 );
  if ( v1 < 0x17 )
  {
    if ( _set_error_mode(3) == 1 || !_set_error_mode(3) && __app_type == 1 )
    {
      StdHandle = GetStdHandle(0xFFFFFFF4);
      v5 = StdHandle;
      if ( StdHandle && StdHandle != (HANDLE)-1 )
      {
        p_rterrtxt = (unsigned __int8 **)&rterrs[v1].rterrtxt;
        strlen(*p_rterrtxt);
        WriteFile(v5, *p_rterrtxt, v7, &bytes_written, 0);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( strcpy_s(outmsg, 0x314u, "Runtime Error!\n\nProgram: ") )
        _invoke_watson(0x314u, (unsigned int)outmsg, 0);
      outmsg[285] = 0;
      if ( !GetModuleFileNameA(0, &outmsg[25], 0x104u) && strcpy_s(&outmsg[25], 0x2FBu, "<program name unknown>") )
        _invoke_watson(0x314u, (unsigned int)outmsg, (unsigned int)&outmsg[25]);
      strlen((unsigned __int8 *)&outmsg[25]);
      if ( (unsigned int)(v2 + 1) > 0x3C )
      {
        strlen((unsigned __int8 *)&outmsg[25]);
        if ( strncpy_s(&outmsg[v3 - 34], &unk_A9A94C - (_UNKNOWN *)&outmsg[v3 - 34], "...", 3u) )
          _invoke_watson(0x314u, (unsigned int)outmsg, 0);
      }
      if ( strcat_s(outmsg, 0x314u, "\n\n") )
        _invoke_watson(0x314u, (unsigned int)outmsg, 0);
      if ( strcat_s(outmsg, 0x314u, rterrs[tblindx].rterrtxt) )
        _invoke_watson(0x314u, (unsigned int)outmsg, 0);
      __crtMessageBoxA(
        outmsg,
        "Microsoft Visual C++ Runtime Library",
        (unsigned int)vostok::threading::multi_threading_policy::intrusive_ptr_decrement<vostok::resources::unmanaged_intrusive_base>);
    }
  }
}
