char __usercall vostok::resources::queries_result::calculate_result_from_children@<al>(
        vostok::resources::queries_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::query_result_for_user *v2; // ecx
  char v3; // bl
  int v4; // esi
  int v5; // edi

  v2 = *(vostok::resources::query_result_for_user **)(a2 + 56);
  v3 = 1;
  if ( v2 )
  {
    v4 = a2 + 80;
    v5 = *(_DWORD *)(a2 + 56);
    do
    {
      v3 &= vostok::resources::query_result_for_user::is_successful(v2, v4);
      v4 += 736;
      --v5;
    }
    while ( v5 );
  }
  return v3;
}
