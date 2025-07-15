void __thiscall vostok::vfs::base_node<1>::set_name(vostok::vfs::base_node<1> *this, char *name, char *a3)
{
  vostok::strings::copy(name + 51, strlen(a3) + 1, a3);
}
