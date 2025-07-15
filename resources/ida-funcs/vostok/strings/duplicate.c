char *__cdecl vostok::strings::duplicate<vostok::memory::base_allocator>(char *string)
{
  int v1; // ecx
  unsigned int v2; // kr00_4
  unsigned __int8 *v3; // edi

  v2 = strlen(string);
  v3 = (unsigned __int8 *)(*(int (__thiscall **)(int, unsigned int, const char *, const char *, const char *, int))(*(_DWORD *)v1 + 16))(
                            v1,
                            v2 + 1,
                            "strings::duplicate",
                            "vostok::strings::duplicate",
                            "c:\\survarium.deploy\\sources\\vostok/strings_functions_inline.h",
                            100);
  memcpy(v3, (unsigned __int8 *)string, v2 + 1);
  return (char *)v3;
}


char *__usercall vostok::strings::duplicate<vostok::memory::stack_allocator>@<eax>(
        vostok::memory::stack_allocator *allocator@<edx>,
        char *string)
{
  unsigned int v2; // eax
  unsigned __int8 *m_arena_current_position; // esi

  v2 = strlen(string);
  m_arena_current_position = (unsigned __int8 *)allocator->m_arena_current_position;
  allocator->m_arena_current_position = &m_arena_current_position[v2 + 1];
  memcpy(m_arena_current_position, (unsigned __int8 *)string, v2 + 1);
  return (char *)m_arena_current_position;
}
