void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::archive_mounter,bool>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1>>>::operator()<bool>(
        boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::archive_mounter,bool>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1> > > *this,
        bool *a1)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v3; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::archive_mounter,bool>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1> > > *thisa; // [esp+0h] [ebp-14h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // [esp+Fh] [ebp-5h] BYREF

  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)a1,
    (vostok::network_core::packet_reader *)this);
  LOBYTE(v2) = 0;
  v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, (int)&v5 + 1);
  ((void (__thiscall *)(int, _DWORD))LODWORD(thisa->f_.f_))(
    (int)thisa->l_.a1_.t_ + HIDWORD(thisa->f_.f_),
    *(unsigned __int8 *)v3);
}
