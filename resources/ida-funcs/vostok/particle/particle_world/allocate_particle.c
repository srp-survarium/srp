vostok::particle::base_particle *__usercall vostok::particle::particle_world::allocate_particle@<eax>(
        vostok::particle::particle_world *this@<ecx>,
        _DWORD *a2@<edi>)
{
  char *v3; // eax
  int v4; // eax
  vostok::particle::base_particle *v5; // ecx
  int v6; // esi
  unsigned int v7; // eax
  bool v8; // [esp+Fh] [ebp-1h] BYREF

  if ( (unsigned int)(a2[105] + 1) > a2[106] )
    return 0;
  v3 = type_info::raw_name(&vostok::particle::base_particle `RTTI Type Descriptor');
  v4 = (*(int (__thiscall **)(_DWORD *, int, char *, const char *, const char *, int))(a2[66] + 16))(
         a2 + 66,
         292,
         v3,
         "vostok::particle::particle_world::allocate_particle",
         ".\\particle_world.cpp",
         93);
  v6 = v4;
  if ( !debug_macro_helper_ignore_always_54 && !v4 )
  {
    v7 = occurances_left_27;
    if ( occurances_left_27 == -1 )
      v7 = 10;
    occurances_left_27 = v7 - 1;
    if ( v7 )
    {
      v8 = 0;
      vostok::debug::on_error(
        &v8,
        process_error_false,
        (bool *)"particle",
        ".\\particle_world.cpp",
        "vostok::particle::particle_world::allocate_particle",
        (const char *)0x5E);
      if ( vostok::debug::is_debugger_present() || v8 )
        __debugbreak();
    }
    return 0;
  }
  vostok::particle::base_particle::set_defaults(v5, v4);
  ++a2[105];
  return (vostok::particle::base_particle *)v6;
}
