void __thiscall vostok::particle::particle_world_cooker::particle_world_cooker(
        vostok::particle::particle_world_cooker *this)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v1; // [esp-4h] [ebp-14h] BYREF
  vostok::particle::particle_world_cooker *thisa; // [esp+8h] [ebp-8h]

  thisa = this;
  v1.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v1);
  vostok::resources::unmanaged_cook::unmanaged_cook(
    thisa,
    particle_world_class,
    reuse_false,
    0xFFFFFFFC,
    0xFFFFFFFC,
    v1);
  thisa->__vftable = (vostok::particle::particle_world_cooker_vtbl *)&vostok::particle::particle_world_cooker::`vftable';
}
