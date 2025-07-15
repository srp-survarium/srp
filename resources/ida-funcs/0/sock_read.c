int __cdecl sock_read(bio_st *b, char *out, int outl)
{
  int result; // eax
  int v4; // esi
  int Error; // eax

  result = 0;
  if ( out )
  {
    WSASetLastError(0);
    v4 = recv(b->num, out, outl, 0);
    BIO_clear_flags(b, 15);
    if ( v4 <= 0 && (!v4 || v4 == -1) )
    {
      Error = WSAGetLastError();
      if ( Error == 4 || Error == 11 || Error == 10035 )
        BIO_set_flags(b, 9);
    }
    return v4;
  }
  return result;
}
