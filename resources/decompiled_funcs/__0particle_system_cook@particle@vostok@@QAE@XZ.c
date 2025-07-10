void __thiscall vostok::particle::particle_system_cook::particle_system_cook(
        vostok::particle::particle_system_cook *this)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v1; // [esp-4h] [ebp-10h] BYREF
  vostok::particle::particle_system_cook *thisa; // [esp+4h] [ebp-8h]

  thisa = this;
  v1.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v1);
  vostok::resources::inplace_unmanaged_cook::inplace_unmanaged_cook(
    thisa,
    particle_system_binary_class,
    reuse_true,
    0xFFFFFFFC,
    0xFFFFFFFC,
    v1);
  thisa->__vftable = (vostok::particle::particle_system_cook_vtbl *)&vostok::particle::particle_system_cook::`vftable';
}
