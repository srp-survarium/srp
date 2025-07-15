void __userpurge vostok::console_commands::save_storage::add_line(
        vostok::console_commands::save_storage *this@<ecx>,
        stlp_std::vector<char const *,vostok::vectora_allocator<void *> > str)
{
  const char *const *savedregs; // [esp+0h] [ebp+0h]

  str._M_impl._M_start = (const void **)vostok::strings::duplicate<vostok::memory::base_allocator>((char *)str._M_impl._M_start);
  stlp_std::vector<char const *,vostok::vectora_allocator<void *>>::push_back(&str, savedregs);
}
