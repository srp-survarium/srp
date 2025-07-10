void __usercall vostok::console_commands::save(char *name@<eax>, const char *path@<edi>)
{
  vostok::strings::detail::tuples *v2; // ecx
  void *v3; // esp
  vostok::strings::detail::tuples *v4; // ecx
  char v5; // [esp+0h] [ebp-38h] BYREF
  vostok::strings::detail::tuples v6; // [esp+4h] [ebp-34h] BYREF

  vostok::strings::detail::tuples::tuples(&v6, path, "/", name);
  v3 = alloca(vostok::strings::detail::tuples::size(v2, (unsigned int *)&v6));
  vostok::strings::detail::tuples::size(v4, (unsigned int *)&v6);
  vostok::strings::detail::tuples::concat(&v5, &v6);
  vostok::console_commands::save_impl((vostok::memory::writer *)&v5);
}
