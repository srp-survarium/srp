void __thiscall boost::asio::detail::win_iocp_io_service::win_iocp_io_service(
        boost::asio::detail::win_iocp_io_service *this,
        boost::asio::io_service *io_service,
        unsigned int concurrency_hint)
{
  DWORD *v3; // eax
  const boost::system::error_category *v4; // eax
  unsigned int __b; // [esp+2BCh] [ebp-10h] BYREF
  boost::system::error_code ec; // [esp+2C0h] [ebp-Ch] BYREF
  unsigned int last_error; // [esp+2C8h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->key_);
  this->__vftable = (boost::asio::detail::win_iocp_io_service_vtbl *)&boost::asio::io_service::service::`vftable';
  this->key_.type_info_ = 0;
  this->key_.id_ = 0;
  this->owner_ = io_service;
  this->next_ = 0;
  this->__vftable = (boost::asio::detail::win_iocp_io_service_vtbl *)&boost::asio::detail::service_base<boost::asio::detail::win_iocp_io_service>::`vftable';
  this->__vftable = (boost::asio::detail::win_iocp_io_service_vtbl *)&boost::asio::detail::win_iocp_io_service::`vftable';
  this->iocp_.handle = 0;
  this->outstanding_work_ = 0;
  this->stopped_ = 0;
  this->shutdown_ = 0;
  this->timer_thread_.p_ = 0;
  this->waitable_timer_.handle = 0;
  this->dispatch_required_ = 0;
  boost::asio::detail::win_mutex::win_mutex(&this->dispatch_mutex_);
  this->timer_queues_.first_ = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->completed_ops_);
  this->completed_ops_.front_ = 0;
  this->completed_ops_.back_ = 0;
  __b = -1;
  v3 = (DWORD *)stlp_std::min<unsigned int>(&concurrency_hint, &__b);
  this->iocp_.handle = CreateIoCompletionPort((HANDLE)0xFFFFFFFF, 0, 0, *v3);
  if ( !this->iocp_.handle )
  {
    last_error = GetLastError();
    v4 = boost::system::system_category();
    ec.m_val = last_error;
    ec.m_cat = v4;
    if ( (last_error != 0
        ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
        : 0) != 0 )
      boost::asio::detail::do_throw_error(&ec, "iocp");
  }
}
