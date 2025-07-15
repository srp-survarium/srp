void __thiscall vostok::console_commands::console_command::save_to(
        vostok::console_commands::console_command *this,
        vostok::console_commands::save_storage *f,
        vostok::memory::base_allocator *a)
{
  vostok::console_commands::console_command_vtbl *v4; // eax
  vostok::strings::detail::tuples *v5; // ecx
  vostok::strings::detail::tuples *v6; // ecx
  void *v7; // esp
  vostok::strings::detail::tuples *v8; // ecx
  vostok::console_commands::save_storage *v9; // ecx
  stlp_std::vector<char const *,vostok::vectora_allocator<void *> > v10; // [esp-8h] [ebp-244h] BYREF
  char v11[512]; // [esp+8h] [ebp-234h] BYREF
  vostok::strings::detail::tuples v12; // [esp+208h] [ebp-34h] BYREF

  v4 = this->__vftable;
  v10._M_impl._M_finish = (const void **)v11;
  ((void (__thiscall *)(vostok::console_commands::console_command *))v4->status)(this);
  vostok::strings::detail::tuples::tuples(v5, &v12, this->m_name, " ", v11);
  v7 = alloca(vostok::strings::detail::tuples::size(v6, (unsigned int *)&v12));
  vostok::strings::detail::tuples::concat(v8, (int)&v12, (char *)&v10._M_impl._M_finish);
  v10._M_impl._M_start = (const void **)&v10._M_impl._M_finish;
  vostok::console_commands::save_storage::add_line(v9, v10);
}
