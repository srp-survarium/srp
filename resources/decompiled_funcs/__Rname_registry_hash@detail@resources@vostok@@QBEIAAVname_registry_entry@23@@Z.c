unsigned int __usercall vostok::resources::detail::name_registry_hash::operator()@<eax>(
        vostok::resources::name_registry_entry *entry@<eax>,
        vostok::resources::detail::name_registry_hash *this)
{
  return vostok::fs_new::crc32((char *)entry->name, strlen(entry->name), 0);
}
