void __thiscall vostok::console_commands::console_command::save_to(
        vostok::console_commands::console_command *this,
        vostok::console_commands::save_storage *f,
        vostok::memory::base_allocator *a)
{
  vostok::strings::detail::tuples *v4; // ecx
  void *v5; // esp
  vostok::strings::detail::tuples *v6; // ecx
  vostok::console_commands::save_storage *v7; // ecx
  char v8[12]; // [esp-4h] [ebp-240h] BYREF
  char buff[512]; // [esp+8h] [ebp-234h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+208h] [ebp-34h] BYREF

  this->status(this, (char (*)[512])buff);
  vostok::strings::detail::tuples::tuples(
    &STR_JOINA_tuples_unique_identifier,
    this->m_name,
    (const char *)&stru_95AF78,
    buff);
  v5 = alloca(vostok::strings::detail::tuples::size(v4, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
  vostok::strings::detail::tuples::size(v6, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
  vostok::strings::detail::tuples::concat(v8, &STR_JOINA_tuples_unique_identifier);
  vostok::console_commands::save_storage::add_line(v7, (int)f, v8);
}
