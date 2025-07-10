void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::booby_trap_core,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::booby_trap_core *>,boost::arg<1>,boost::arg<2>>>::operator()<unsigned int,unsigned int>(
        boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::damage_zone_core,unsigned int,unsigned int>,boost::_bi::list3<boost::_bi::value<survarium::damage_zone_core *>,boost::arg<1>,boost::arg<2> > > *this,
        unsigned __int8 *a1,
        unsigned int *a2)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  const vostok::variant<32> **v5; // eax
  const void *pointer; // [esp+Ch] [ebp-18h]
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v8[2]; // [esp+1Bh] [ebp-9h] BYREF

  boost::_bi::list2<unsigned int &,unsigned int &>::list2<unsigned int &,unsigned int &>(
    (boost::_bi::list2<unsigned int &,unsigned int &> *)((char *)v8 + 1),
    a1,
    a2);
  LOBYTE(v3) = 0;
  pointer = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
              v3,
              (int)v8 + 1)->config.data.pointer;
  v5 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v4, (int)v8 + 1);
  ((void (__thiscall *)(char *, const vostok::variant<32> *, const void *))LODWORD(this->f_.f_))(
    (char *)this->l_.a1_.t_ + HIDWORD(this->f_.f_),
    *v5,
    pointer);
}
