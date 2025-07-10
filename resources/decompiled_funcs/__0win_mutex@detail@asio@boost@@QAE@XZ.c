void __thiscall boost::asio::detail::win_mutex::win_mutex(boost::asio::detail::win_mutex *this)
{
  boost::system::error_code ec; // [esp+160h] [ebp-Ch] BYREF
  int error; // [esp+168h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  error = boost::asio::detail::win_mutex::do_init(this);
  ec.m_val = error;
  ec.m_cat = boost::system::system_category();
  if ( (error != 0
      ? (unsigned int)boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>
      : 0) != 0 )
    boost::asio::detail::do_throw_error(&ec, "mutex");
}
