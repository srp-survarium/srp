boost::asio::error::detail::ssl_category *__cdecl boost::asio::error::get_ssl_category()
{
  if ( (`boost::asio::error::get_ssl_category'::`2'::`local static guard' & 1) == 0 )
  {
    `boost::asio::error::get_ssl_category'::`2'::`local static guard' |= 1u;
    `boost::asio::error::get_ssl_category'::`2'::instance.__vftable = (boost::asio::error::detail::ssl_category_vtbl *)&boost::asio::error::detail::ssl_category::`vftable';
    atexit((int (__cdecl *)())`boost::asio::error::get_ssl_category'::`2'::`dynamic atexit destructor for 'instance'');
  }
  return &`boost::asio::error::get_ssl_category'::`2'::instance;
}
