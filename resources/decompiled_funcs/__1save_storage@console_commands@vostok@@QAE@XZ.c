void __usercall vostok::console_commands::save_storage::~save_storage(
        vostok::console_commands::save_storage *this@<ecx>,
        const char ***a2@<edi>)
{
  const char **v2; // ebx
  const char **i; // esi

  v2 = a2[1];
  for ( i = *a2; i != v2; ++i )
    vostok::memory::free_helper<vostok::memory::base_allocator,char const>((vostok::memory::base_allocator *)a2[4], i);
  if ( *a2 )
    (*((void (__thiscall **)(const char **, const char **))*a2[2] + 6))(a2[2], *a2);
}
