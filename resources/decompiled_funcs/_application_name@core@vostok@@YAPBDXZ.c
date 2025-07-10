void **__cdecl vostok::core::application_name()
{
  int v0; // eax
  char path[512]; // [esp+0h] [ebp-200h] BYREF

  if ( !LOBYTE(s_crt_allocator_creation.m_arena) && GetModuleFileNameA(0, path, 0x200u) )
  {
    strrchr(path, 0x5Cu);
    if ( v0 )
      strcpy_s((char *)&s_crt_allocator_creation.m_arena, 0x200u, (const char *)(v0 + 1));
    else
      strcpy_s((char *)&s_crt_allocator_creation.m_arena, 0x200u, path);
  }
  return &s_crt_allocator_creation.m_arena;
}
