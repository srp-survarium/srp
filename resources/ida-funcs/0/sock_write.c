int __cdecl sock_write(bio_st *b, const char *in, int inl)
{
  int v3; // esi
  int Error; // eax
  int v6; // [esp+0h] [ebp-8h]

  WSASetLastError(0);
  v3 = ((int (__stdcall *)(int, const char *, int, _DWORD, int))(&off_8E3A98 + 1))(b->num, in, inl, 0, v6);
  BIO_clear_flags(b, 15);
  if ( v3 <= 0 && (!v3 || v3 == -1) )
  {
    Error = WSAGetLastError();
    if ( Error == 4 || Error == 11 || Error == 10035 )
      BIO_set_flags(b, 10);
  }
  return v3;
}
