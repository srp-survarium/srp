void __thiscall boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::oxygen_tank,unsigned int>,boost::_bi::list2<boost::_bi::value<survarium::oxygen_tank *>,boost::arg<1>>>::operator()<unsigned int,unsigned int>(
        boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::oxygen_tank,unsigned int>,boost::_bi::list2<boost::_bi::value<survarium::oxygen_tank *>,boost::arg<1> > > *this,
        unsigned __int8 *a1,
        unsigned int *a2)
{
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::variant<32> **v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6[2]; // [esp+17h] [ebp-9h] BYREF

  boost::_bi::list2<unsigned int &,unsigned int &>::list2<unsigned int &,unsigned int &>(
    (boost::_bi::list2<unsigned int &,unsigned int &> *)((char *)v6 + 1),
    a1,
    a2);
  LOBYTE(v3) = 0;
  v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v6 + 1);
  ((void (__thiscall *)(char *, const vostok::variant<32> *))LODWORD(this->f_.f_))(
    (char *)this->l_.a1_.t_ + HIDWORD(this->f_.f_),
    *v4);
}
