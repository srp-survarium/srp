int __usercall sock_read@<eax>(int a1@<edi>, bio_st *b, char *out, int outl)
{
  int result; // eax
  int v5; // esi
  int Error; // eax

  result = 0;
  if ( out )
  {
    WSASetLastError(0);
    v5 = ((int (__stdcall *)(int, char *, int, _DWORD, int))(&off_8E3A98 + 2))(b->num, out, outl, 0, a1);
    BIO_clear_flags(b, 15);
    if ( v5 <= 0 && (!v5 || v5 == -1) )
    {
      Error = WSAGetLastError();
      if ( Error == 4 || Error == 11 || Error == 10035 )
        BIO_set_flags(b, 9);
    }
    return v5;
  }
  return result;
}
