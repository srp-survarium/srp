vostok::math::uint2 *__usercall vostok::render::parse_resolution@<eax>(char *in_str@<edx>, int *a2)
{
  const char *token; // esi
  int v3; // edi
  int v4; // eax
  char xy_str[16]; // [esp+10h] [ebp-10h] BYREF

  if ( in_str
    && *in_str
    && (token = vostok::strings::get_token(in_str, xy_str, strlen(in_str), 120)) != 0
    && (v3 = atoi(xy_str), v4 = atoi(token), v3)
    && v4 )
  {
    a2[1] = v4;
    *a2 = v3;
    return (vostok::math::uint2 *)a2;
  }
  else
  {
    *a2 = 1280;
    a2[1] = 720;
    return (vostok::math::uint2 *)a2;
  }
}
