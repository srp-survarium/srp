char __fastcall vostok::resources::queries_result::calculate_result_from_children(
        vostok::resources::queries_result *this,
        int a2)
{
  int v2; // ecx
  char result; // al
  _DWORD *v4; // edx
  int v5; // esi
  bool v6; // cl

  v2 = *(_DWORD *)(a2 + 56);
  result = 1;
  if ( v2 )
  {
    v4 = (_DWORD *)(a2 + 340);
    v5 = v2;
    do
    {
      v6 = !*(v4 - 1) && *v4 != 1;
      result &= v6;
      v4 += 180;
      --v5;
    }
    while ( v5 );
  }
  return result;
}
