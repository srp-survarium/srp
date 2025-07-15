void __thiscall vostok::resources::unmanaged_resource::set_no_delete(vostok::resources::unmanaged_resource *this)
{
  vostok::enum_flags<enum vostok::resources::unmanaged_resource::flag_enum> v1; // [esp-4h] [ebp-10h] BYREF
  vostok::resources::unmanaged_resource *thisa; // [esp+0h] [ebp-Ch]

  thisa = this;
  v1.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)2,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v1);
  vostok::flags_type<enum vostok::resources::unmanaged_resource::flag_enum,vostok::threading::single_threading_policy>::set(
    &thisa->m_flags,
    v1);
}
