int __usercall wcsncnt@<eax>(const wchar_t *string@<eax>, int cnt)
{
  int v2; // ecx

  v2 = cnt;
  while ( v2 )
  {
    --v2;
    if ( !*string )
      return cnt - v2 - 1;
    ++string;
  }
  v2 = -1;
  return cnt - v2 - 1;
}
