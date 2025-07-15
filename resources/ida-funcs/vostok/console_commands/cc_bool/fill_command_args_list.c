void __thiscall vostok::console_commands::cc_bool::fill_command_args_list(
        vostok::console_commands::cc_bool *this,
        vostok::vectora<char const *> *dest)
{
  const char *const *v2; // [esp+0h] [ebp-4h]
  const char *const *v3; // [esp+0h] [ebp-4h]

  stlp_std::vector<char const *,vostok::vectora_allocator<void *>>::clear(
    (stlp_std::vector<char const *,vostok::vectora_allocator<void *> > *)this,
    (unsigned __int8 **)dest);
  stlp_std::vector<char const *,vostok::vectora_allocator<void *>>::push_back(
    &vostok::console_commands::bool_values_str,
    v2);
  stlp_std::vector<char const *,vostok::vectora_allocator<void *>>::push_back(
    (stlp_std::vector<char const *,vostok::vectora_allocator<void *> > *)&vostok::console_commands::bool_values_str._M_impl._M_finish,
    v3);
}
