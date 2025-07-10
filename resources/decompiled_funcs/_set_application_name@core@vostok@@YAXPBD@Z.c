void __cdecl vostok::core::set_application_name()
{
  strcpy_s((char *)&s_crt_allocator_creation.m_arena, 0x200u, "survarium");
}
