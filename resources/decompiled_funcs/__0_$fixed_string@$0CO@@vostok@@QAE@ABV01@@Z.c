void __thiscall vostok::fixed_string<46>::fixed_string<46>(
        vostok::fixed_string<46> *this,
        const vostok::fixed_string<46> *src)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  unsigned int max_count; // [esp+10h] [ebp-Ch] BYREF
  char *begin_src; // [esp+14h] [ebp-8h] BYREF
  char *end_src; // [esp+18h] [ebp-4h] BYREF

  end_src = (char *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                      (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this,
                      (int)src);
  begin_src = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                        v2,
                        (int)src);
  max_count = 46;
  vostok::buffer_string::buffer_string(
    this,
    this->m_buffer,
    &max_count,
    (const char *const *)&begin_src,
    (const char *const *)&end_src);
}
