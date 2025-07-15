void __usercall boost::_bi::value<float>::value<float>(boost::_bi::value<float> *this@<ecx>, float *a2@<eax>)
{
  *a2 = this->t_;
}


stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> *__usercall boost::_bi::value<survarium::weapon_state_creation_params const *>::value<survarium::weapon_state_creation_params const *>@<eax>(
        stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *this@<ecx>,
        stlp_std::reverse_iterator<survarium::base_project::resolve_link_object *> *a2@<eax>)
{
  a2->current = this->_M_start;
  return a2;
}


void __usercall boost::_bi::value<vostok::configs::binary_config_value>::value<vostok::configs::binary_config_value>(
        boost::_bi::value<vostok::configs::binary_config_value> *this@<ecx>,
        boost::_bi::value<vostok::configs::binary_config_value> *a2@<eax>)
{
  *a2 = *this;
}


void __usercall boost::_bi::value<vostok::mutable_buffer>::value<vostok::mutable_buffer>(
        boost::_bi::value<vostok::mutable_buffer> *this@<ecx>,
        boost::_bi::value<vostok::mutable_buffer> *a2@<eax>)
{
  *a2 = *this;
}


void __thiscall boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *other)
{
  this->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    this,
    other);
}


void __thiscall boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *other)
{
  this->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)other);
}


void __usercall boost::_bi::value<bool>::value<bool>(
        boost::_bi::value<unsigned char> *this@<ecx>,
        boost::_bi::value<unsigned char> *a2@<eax>)
{
  a2->t_ = this->t_;
}
