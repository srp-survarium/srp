char *__cdecl vostok::ai::clone_string_from_config(const vostok::configs::binary_config_value *prototype)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v1; // ecx
  const char *object_name; // [esp+2Ch] [ebp-Ch]
  char *clone; // [esp+30h] [ebp-8h]
  unsigned int length; // [esp+34h] [ebp-4h]

  object_name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                v1,
                                (int)prototype);
  length = vostok::strings::length(object_name) + 1;
  clone = vostok::memory::new_array_helper<char>::call<vostok::memory::doug_lea_allocator>(
            vostok::ai::g_allocator,
            length);
  vostok::strings::copy(clone, length, object_name);
  return clone;
}
