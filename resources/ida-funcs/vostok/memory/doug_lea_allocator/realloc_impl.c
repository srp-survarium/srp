unsigned __int8 *__userpurge vostok::memory::doug_lea_allocator::realloc_impl@<eax>(
        vostok::memory::doug_lea_allocator *this@<ecx>,
        int a2@<eax>,
        vostok::memory::doug_lea_allocator *pointer,
        unsigned int new_size,
        char *description,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  vostok::memory::doug_lea_allocator *v8; // ecx
  bool v10; // al
  unsigned __int8 *result; // eax
  unsigned int v12; // eax
  vostok::memory::base_allocator *v13; // [esp-4h] [ebp-18h]
  const char *v14; // [esp+0h] [ebp-14h]
  const char *v15; // [esp+4h] [ebp-10h]
  unsigned int v16; // [esp+8h] [ebp-Ch]
  unsigned int previous_size; // [esp+10h] [ebp-4h]

  v8 = pointer;
  v10 = *(_BYTE *)(a2 + 42) && new_size;
  *(_BYTE *)(a2 + 42) = v10;
  if ( !new_size )
  {
    vostok::memory::doug_lea_allocator::free_impl(v8, a2, v8, v14, v15, v16);
    return 0;
  }
  if ( v8 )
  {
    if ( *(_BYTE *)(a2 + 43) )
      v12 = (*(int (__thiscall **)(int, vostok::memory::doug_lea_allocator *))(*(_DWORD *)a2 + 28))(a2, v8);
    else
      v12 = vostok_mspace_usable_size(v8);
    previous_size = v12;
  }
  else
  {
    previous_size = 0;
  }
  if ( pointer && *(_BYTE *)(a2 + 43) )
  {
    if ( *(_BYTE *)(a2 + 16) )
      vostok::memory::monitor::on_free((void **)&pointer, (vostok::command_line::key *)v8);
  }
  result = vostok_mspace_realloc(*(malloc_state **)(a2 + 20), (unsigned __int8 *)pointer, new_size);
  if ( *(_BYTE *)(a2 + 43) )
  {
    if ( !result )
      return 0;
    return (unsigned __int8 *)vostok::memory::base_allocator::on_malloc(
                                v13,
                                result,
                                new_size,
                                previous_size,
                                description);
  }
  return result;
}
