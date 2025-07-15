int __usercall vostok::resources::queries_result::calculate_fs_iterator_requests_count@<eax>(
        vostok::resources::queries_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::query_result *v2; // ecx
  int v3; // esi
  int v4; // edx
  int v5; // edx
  int v6; // ecx

  v2 = *(vostok::resources::query_result **)(a2 + 56);
  v3 = 0;
  if ( v2 )
  {
    v4 = a2 + 80;
    do
    {
      if ( vostok::resources::query_result::is_fs_iterator_query(v2, v4) )
        ++v3;
      v4 = v5 + 736;
      v2 = (vostok::resources::query_result *)(v6 - 1);
    }
    while ( v2 );
  }
  return v3;
}
