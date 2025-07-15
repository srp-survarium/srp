void __thiscall survarium::key_binder::set_default_controls(survarium::key_binder *this, survarium::key_binder *thisa)
{
  unsigned int i; // ebx
  vostok::strings::detail::tuples *v3; // ecx
  void *v4; // esp
  vostok::strings::detail::tuples *v5; // ecx
  char v6[16]; // [esp+0h] [ebp-44h] BYREF
  vostok::strings::detail::tuples STR_JOINA_tuples_unique_identifier; // [esp+10h] [ebp-34h] BYREF

  for ( i = 0; i < 250; i += 5 )
  {
    if ( off_9C3E48[i] )
    {
      vostok::strings::detail::tuples::tuples(
        &STR_JOINA_tuples_unique_identifier,
        actions_[i / 5].action_name,
        (const char *)&stru_95AF78,
        off_9C3E48[i]);
      v4 = alloca(vostok::strings::detail::tuples::size(v3, (unsigned int *)&STR_JOINA_tuples_unique_identifier));
      vostok::strings::detail::tuples::size(v5, (unsigned int *)&STR_JOINA_tuples_unique_identifier);
      vostok::strings::detail::tuples::concat(v6, &STR_JOINA_tuples_unique_identifier);
      survarium::key_binder::bind_key(thisa, v6, 0);
    }
  }
}
