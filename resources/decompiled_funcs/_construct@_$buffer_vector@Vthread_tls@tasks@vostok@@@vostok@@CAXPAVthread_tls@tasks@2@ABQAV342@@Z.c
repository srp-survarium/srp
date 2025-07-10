void __cdecl vostok::buffer_vector<vostok::tasks::thread_tls>::construct(
        vostok::tasks::thread_tls *begin,
        vostok::tasks::thread_tls **end)
{
  vostok::tasks::thread_tls *v2; // ecx
  vostok::tasks::thread_tls *v3; // ebx
  vostok::tasks::thread_tls *v4; // edi
  int i; // esi

  v3 = begin;
  if ( begin != *end )
  {
    v4 = begin + 1;
    do
    {
      for ( i = (int)v3; (vostok::tasks::thread_tls *)i != v4; i += 360 )
      {
        if ( i )
          vostok::tasks::thread_tls::thread_tls(v2, i);
      }
      ++v3;
      ++v4;
    }
    while ( v3 != *end );
  }
}
