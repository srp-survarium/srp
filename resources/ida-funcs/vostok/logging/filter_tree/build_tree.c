void __usercall vostok::logging::filter_tree::build_tree(vostok::logging::filter_tree *this@<ecx>, int a2@<edi>)
{
  const char *i; // esi
  const char *v3; // ebx

  vostok::logging::node::clean(*(vostok::logging::node **)(a2 + 8), *(vostok::logging::base_allocator **)(a2 + 12));
  for ( i = *(const char **)(a2 + 20); i; i = *(const char **)i )
  {
    v3 = *(const char **)i;
    if ( *(_DWORD *)i )
    {
      while ( !vostok::strings::starts_with(i + 16, v3 + 16) )
      {
        v3 = *(const char **)v3;
        if ( !v3 )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      vostok::logging::node::set(
        *(vostok::logging::node **)(a2 + 8),
        (char *)i + 16,
        *((_DWORD *)i + 2),
        *((_DWORD *)i + 3),
        *(vostok::logging::base_allocator **)(a2 + 12),
        0);
    }
  }
}
