void __thiscall survarium::key_binder::set_default_controls(survarium::key_binder *this, survarium::key_binder *a2)
{
  unsigned int i; // edi
  vostok::strings::detail::tuples *v3; // ecx
  void *v4; // esp
  vostok::strings::detail::tuples *v5; // ecx
  char v6[16]; // [esp+0h] [ebp-44h] BYREF
  vostok::strings::detail::tuples v7; // [esp+10h] [ebp-34h] BYREF

  for ( i = 0; i < 54; ++i )
  {
    if ( actions_[i].default_key )
    {
      vostok::strings::detail::tuples::tuples(
        (vostok::strings::detail::tuples *)this,
        &v7,
        actions_[i].action_name,
        " ",
        (char *)actions_[i].default_key);
      v4 = alloca(vostok::strings::detail::tuples::size(v3, (unsigned int *)&v7));
      vostok::strings::detail::tuples::concat(v5, (int)&v7, v6);
      survarium::key_binder::bind_key(a2, v6, 0);
    }
  }
}
