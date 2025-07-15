boost::asio::error::detail::ssl_category *__cdecl boost::asio::error::get_ssl_category()
{
  if ( (`boost::asio::error::get_ssl_category'::`2'::`local static guard' & 1) == 0 )
  {
    `boost::asio::error::get_ssl_category'::`2'::`local static guard' |= 1u;
    survarium::weapon_core::cast_weapon_core(&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always);
    `boost::asio::error::get_ssl_category'::`2'::instance.__vftable = (boost::asio::error::detail::ssl_category_vtbl *)&boost::asio::error::detail::ssl_category::`vftable';
    atexit(`boost::asio::error::get_ssl_category'::`2'::`dynamic atexit destructor for 'instance'');
  }
  return &`boost::asio::error::get_ssl_category'::`2'::instance;
}
