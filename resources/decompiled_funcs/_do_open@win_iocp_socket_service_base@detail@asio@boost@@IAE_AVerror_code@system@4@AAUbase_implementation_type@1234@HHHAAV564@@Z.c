boost::system::error_code *__thiscall boost::asio::detail::win_iocp_socket_service_base::do_open(
        boost::asio::detail::win_iocp_socket_service_base *this,
        boost::system::error_code *result,
        boost::asio::detail::win_iocp_socket_service_base::base_implementation_type *impl,
        int family,
        int type,
        int protocol,
        boost::system::error_code *ec)
{
  const boost::system::error_category *v7; // eax
  const boost::system::error_category *m_cat; // eax
  const boost::system::error_category *v10; // edx
  const boost::system::error_category *v11; // eax
  unsigned int socket; // [esp+9Ch] [ebp-88h]
  unsigned int v14; // [esp+D4h] [ebp-50h]
  boost::asio::error::detail::misc_category *misc_category; // [esp+104h] [ebp-20h]
  const boost::system::error_category *v16; // [esp+10Ch] [ebp-18h]
  boost::system::error_code v17; // [esp+114h] [ebp-10h] BYREF
  boost::asio::detail::socket_holder sock; // [esp+11Ch] [ebp-8h] BYREF
  void *sock_as_handle; // [esp+120h] [ebp-4h]

  if ( impl->socket_ == -1 )
  {
    v14 = boost::asio::detail::socket_ops::socket(family, type, protocol, ec);
    survarium::weapon_core::cast_weapon_core((survarium::game_options *)&sock);
    sock.socket_ = v14;
    if ( v14 == -1 )
    {
      m_cat = ec->m_cat;
      result->m_val = ec->m_val;
      result->m_cat = m_cat;
      boost::asio::detail::socket_holder::~socket_holder(&sock);
      return result;
    }
    else
    {
      sock_as_handle = (void *)sock.socket_;
      if ( (boost::asio::detail::win_iocp_io_service::register_handle(
              this->iocp_service_,
              &v17,
              (void *)sock.socket_,
              ec)->m_val != 0
          ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
          : 0) != 0 )
      {
        v10 = ec->m_cat;
        result->m_val = ec->m_val;
        result->m_cat = v10;
        boost::asio::detail::socket_holder::~socket_holder(&sock);
        return result;
      }
      else
      {
        socket = sock.socket_;
        sock.socket_ = -1;
        impl->socket_ = socket;
        if ( type == 1 )
        {
          impl->state_ = 16;
        }
        else if ( type == 2 )
        {
          impl->state_ = 32;
        }
        else
        {
          impl->state_ = 0;
        }
        boost::shared_ptr<void>::reset<void,boost::asio::detail::socket_ops::noop_deleter>(&impl->cancel_token_, 0, 0);
        v16 = boost::system::system_category();
        ec->m_val = 0;
        ec->m_cat = v16;
        v11 = ec->m_cat;
        result->m_val = ec->m_val;
        result->m_cat = v11;
        boost::asio::detail::socket_holder::~socket_holder(&sock);
        return result;
      }
    }
  }
  else
  {
    misc_category = boost::asio::error::get_misc_category();
    ec->m_val = 1;
    ec->m_cat = misc_category;
    v7 = ec->m_cat;
    result->m_val = ec->m_val;
    result->m_cat = v7;
    return result;
  }
}
