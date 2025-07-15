vostok::math::uint2 *__usercall survarium::parse_resolution@<eax>(char *in_str@<ecx>, int *a2@<esi>)
{
  char *token; // edi
  int v3; // ebx
  int v4; // eax
  char nptr[16]; // [esp+8h] [ebp-10h] BYREF

  if ( in_str
    && *in_str
    && (token = (char *)vostok::strings::get_token(0x78u, in_str, nptr, strlen(in_str))) != 0
    && (v3 = atoi(nptr), v4 = atoi(token), v3)
    && v4 )
  {
    *a2 = v3;
    a2[1] = v4;
  }
  else
  {
    *a2 = 1280;
    a2[1] = 720;
  }
  return (vostok::math::uint2 *)a2;
}
