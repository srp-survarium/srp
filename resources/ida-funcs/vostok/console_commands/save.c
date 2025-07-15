void __cdecl vostok::console_commands::save(char *name, char *path)
{
  vostok::strings::detail::tuples *v2; // ecx
  vostok::strings::detail::tuples *v3; // ecx
  void *v4; // esp
  vostok::strings::detail::tuples *v5; // ecx
  char v6[12]; // [esp+0h] [ebp-40h] BYREF
  unsigned int v7[13]; // [esp+Ch] [ebp-34h] BYREF

  vostok::strings::detail::tuples::tuples(v2, (vostok::strings::detail::tuples *)v7, path, "/", name);
  v4 = alloca(vostok::strings::detail::tuples::size(v3, v7));
  vostok::strings::detail::tuples::concat(v5, (int)v7, v6);
  vostok::console_commands::save_impl(v6);
}


void __usercall vostok::console_commands::save(
        const vostok::console_commands::command_type command_type@<eax>,
        int a2@<ecx>)
{
  char *v2; // eax

  if ( command_type == command_type_user_specific )
  {
    v2 = (char *)((int (__thiscall *)(vostok::core::engine *, int))s_engine_0->get_user_data_directory)(s_engine_0, a2);
    vostok::console_commands::save("user.cfg", v2);
  }
}
