boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *__cdecl boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp>::create(
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *result,
        addrinfo *address_info,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *host_name,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *service_name)
{
  unsigned int v5; // eax
  char *__s; // [esp+50h] [ebp-B0h]
  boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> __x; // [esp+6Ch] [ebp-94h] BYREF
  vostok::ai::std_allocator<vostok::ai::planning::specified_action> __a; // [esp+BBh] [ebp-45h] BYREF
  stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *v9; // [esp+BCh] [ebp-44h]
  boost::asio::ip::basic_endpoint<boost::asio::ip::tcp> endpoint; // [esp+C0h] [ebp-40h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > actual_host_name; // [esp+DCh] [ebp-24h] BYREF
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> iter; // [esp+F4h] [ebp-Ch] BYREF

  memset(&iter, 0, sizeof(iter));
  if ( address_info )
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      &actual_host_name,
      host_name);
    if ( address_info->ai_canonname )
    {
      __s = address_info->ai_canonname;
      v5 = stlp_std::char_traits<char>::length(__s);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
        &actual_host_name,
        __s,
        &__s[v5]);
    }
    v9 = (stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *)operator new(0xCu);
    if ( v9 )
    {
      stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
        v9,
        &__a);
      boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::reset<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>(
        &iter.values_,
        (stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp> > > *)v9);
    }
    else
    {
      boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::reset<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>(
        &iter.values_,
        0);
    }
    while ( address_info )
    {
      if ( address_info->ai_family == 2 || address_info->ai_family == 23 )
      {
        boost::asio::ip::detail::endpoint::endpoint(&endpoint.impl_);
        boost::asio::ip::basic_endpoint<boost::asio::ip::tcp>::resize(
          (boost::asio::ip::basic_endpoint<boost::asio::ip::udp> *)&endpoint,
          address_info->ai_addrlen);
        memcpy((unsigned __int8 *)&endpoint, (unsigned __int8 *)address_info->ai_addr, address_info->ai_addrlen);
        qmemcpy(&__x, &endpoint, 0x1Cu);
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
          &__x.host_name_,
          &actual_host_name);
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
          &__x.service_name_,
          service_name);
        stlp_std::priv::_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>>::push_back(
          (stlp_std::priv::_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > *)iter.values_.px,
          &__x);
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__x.service_name_);
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__x.host_name_);
      }
      address_info = address_info->ai_next;
    }
    result->values_.px = iter.values_.px;
    result->values_.pn.pi_ = iter.values_.pn.pi_;
    if ( result->values_.pn.pi_ )
      _InterlockedExchangeAdd(&result->values_.pn.pi_->use_count_, 1u);
    result->index_ = iter.index_;
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&actual_host_name);
    if ( iter.values_.pn.pi_ )
      boost::detail::sp_counted_base::release(iter.values_.pn.pi_);
    return result;
  }
  else
  {
    boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>(
      (boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > > *)result,
      (const boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > > *)&iter);
    result->index_ = iter.index_;
    if ( iter.values_.pn.pi_ )
      boost::detail::sp_counted_base::release(iter.values_.pn.pi_);
    return result;
  }
}


boost::asio::ip::basic_resolver_iterator<boost::asio::ip::udp> *__cdecl boost::asio::ip::basic_resolver_iterator<boost::asio::ip::udp>::create(
        boost::asio::ip::basic_resolver_iterator<boost::asio::ip::udp> *result,
        addrinfo *address_info,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *host_name,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *service_name)
{
  unsigned int v5; // eax
  char *__s; // [esp+50h] [ebp-B0h]
  boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> __x; // [esp+6Ch] [ebp-94h] BYREF
  vostok::ai::std_allocator<vostok::ai::planning::specified_action> __a; // [esp+BBh] [ebp-45h] BYREF
  stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *v9; // [esp+BCh] [ebp-44h]
  boost::asio::ip::basic_endpoint<boost::asio::ip::udp> endpoint; // [esp+C0h] [ebp-40h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > actual_host_name; // [esp+DCh] [ebp-24h] BYREF
  boost::asio::ip::basic_resolver_iterator<boost::asio::ip::udp> iter; // [esp+F4h] [ebp-Ch] BYREF

  memset(&iter, 0, sizeof(iter));
  if ( address_info )
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      &actual_host_name,
      host_name);
    if ( address_info->ai_canonname )
    {
      __s = address_info->ai_canonname;
      v5 = stlp_std::char_traits<char>::length(__s);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_assign(
        &actual_host_name,
        __s,
        &__s[v5]);
    }
    v9 = (stlp_std::priv::_Vector_base<vostok::ai::planning::specified_action,vostok::ai::std_allocator<vostok::ai::planning::specified_action> > *)operator new(0xCu);
    if ( v9 )
    {
      stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>(
        v9,
        &__a);
      boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>>>::reset<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>>>(
        &iter.values_,
        (stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp> > > *)v9);
    }
    else
    {
      boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>>>::reset<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>>>(
        &iter.values_,
        0);
    }
    while ( address_info )
    {
      if ( address_info->ai_family == 2 || address_info->ai_family == 23 )
      {
        boost::asio::ip::detail::endpoint::endpoint(&endpoint.impl_);
        boost::asio::ip::basic_endpoint<boost::asio::ip::tcp>::resize(&endpoint, address_info->ai_addrlen);
        memcpy((unsigned __int8 *)&endpoint, (unsigned __int8 *)address_info->ai_addr, address_info->ai_addrlen);
        qmemcpy(&__x, &endpoint, 0x1Cu);
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
          &__x.host_name_,
          &actual_host_name);
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
          &__x.service_name_,
          service_name);
        stlp_std::priv::_Impl_vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::udp>>>::push_back(
          &iter.values_.px->_M_impl,
          &__x);
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__x.service_name_);
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&__x.host_name_);
      }
      address_info = address_info->ai_next;
    }
    result->values_.px = iter.values_.px;
    result->values_.pn.pi_ = iter.values_.pn.pi_;
    if ( result->values_.pn.pi_ )
      _InterlockedExchangeAdd(&result->values_.pn.pi_->use_count_, 1u);
    result->index_ = iter.index_;
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&actual_host_name);
    if ( iter.values_.pn.pi_ )
      boost::detail::sp_counted_base::release(iter.values_.pn.pi_);
    return result;
  }
  else
  {
    boost::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>::shared_ptr<stlp_std::vector<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>,stlp_std::allocator<boost::asio::ip::basic_resolver_entry<boost::asio::ip::tcp>>>>(
      &result->values_,
      &iter.values_);
    result->index_ = iter.index_;
    if ( iter.values_.pn.pi_ )
      boost::detail::sp_counted_base::release(iter.values_.pn.pi_);
    return result;
  }
}
