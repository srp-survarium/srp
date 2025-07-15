void __thiscall survarium::console_command_bind::save_to(
        survarium::console_command_bind *this,
        vostok::console_commands::save_storage *f,
        vostok::memory::base_allocator *a)
{
  const char ***v4; // eax
  vostok::strings::detail::tuples **v5; // ecx
  vostok::strings::detail::tuples *v6; // ecx
  vostok::strings::detail::tuples *v7; // ecx
  void *v8; // esp
  vostok::strings::detail::tuples *v9; // ecx
  vostok::console_commands::save_storage *v10; // ecx
  stlp_std::vector<char const *,vostok::vectora_allocator<void *> > v11; // [esp-4h] [ebp-4Ch] BYREF
  vostok::strings::detail::tuples v12; // [esp+Ch] [ebp-3Ch] BYREF
  const void ***p_M_finish; // [esp+40h] [ebp-8h]
  int i; // [esp+44h] [ebp-4h]

  for ( i = 0; i < 864; i += 12 )
  {
    v4 = (const char ***)((char *)this->m_binder + i);
    v5 = (vostok::strings::detail::tuples **)&v4[this->m_type + 1];
    if ( *v5 )
    {
      v6 = *v5;
      if ( v6->m_strings[0].first )
      {
        vostok::strings::detail::tuples::tuples(v6, &v12, this->m_name, " ", **v4, " ", v6->m_strings[0].first);
        v8 = alloca(vostok::strings::detail::tuples::size(v7, (unsigned int *)&v12));
        p_M_finish = &v11._M_impl._M_finish;
        vostok::strings::detail::tuples::concat(v9, (int)&v12, (char *)&v11._M_impl._M_finish);
        v11._M_impl._M_start = (const void **)p_M_finish;
        vostok::console_commands::save_storage::add_line(v10, v11);
      }
    }
  }
}
