void __thiscall survarium::console_command_bind::save_to(
        survarium::console_command_bind *this,
        vostok::console_commands::save_storage *f,
        vostok::memory::base_allocator *a)
{
  int i; // ebx
  int m_type; // ecx
  const char ***v6; // eax
  bool v7; // zf
  const char ***v8; // ecx
  vostok::strings::detail::tuples *v9; // ecx
  void *v10; // esp
  vostok::strings::detail::tuples *v11; // ecx
  vostok::console_commands::save_storage *v12; // ecx
  char v13[12]; // [esp+0h] [ebp-40h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+Ch] [ebp-34h] BYREF

  for ( i = 0; i < 768; i += 12 )
  {
    m_type = this->m_type;
    v6 = (const char ***)((char *)this->m_binder + i);
    v7 = v6[m_type + 1] == 0;
    v8 = &v6[m_type + 1];
    if ( !v7 )
    {
      if ( **v8 )
      {
        vostok::strings::detail::tuples::tuples(
          &STR_JOINA_tuples_unique_identifier,
          this->m_name,
          (const char *)&stru_95AF78,
          **v6,
          (const char *)&stru_95AF78,
          **v8);
        v10 = alloca(vostok::strings::detail::tuples::size(v9, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
        vostok::strings::detail::tuples::size(v11, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
        vostok::strings::detail::tuples::concat(v13, &STR_JOINA_tuples_unique_identifier);
        vostok::console_commands::save_storage::add_line(v12, v13);
      }
    }
  }
}
