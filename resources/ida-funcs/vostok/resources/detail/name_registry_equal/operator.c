BOOL __usercall vostok::resources::detail::name_registry_equal::operator()@<eax>(
        const vostok::resources::name_registry_entry *left@<edi>,
        const vostok::resources::name_registry_entry *right@<esi>,
        vostok::resources::detail::name_registry_equal *this)
{
  return !strcmp(left->name, right->name) && left->class_id == right->class_id;
}
