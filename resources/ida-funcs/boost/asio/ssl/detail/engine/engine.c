void __userpurge boost::asio::ssl::detail::engine::engine(
        boost::asio::ssl::detail::engine *this@<ecx>,
        int a2@<esi>,
        int *a3@<edi>,
        ssl_ctx_st *context)
{
  boost::asio::detail::win_static_mutex *v4; // ecx
  boost::system::error_code v5; // [esp+Ch] [ebp-Ch] BYREF

  *(_DWORD *)a2 = SSL_new(a3, a2, context);
  v5.m_val = boost::asio::detail::win_static_mutex::do_init(v4);
  v5.m_cat = boost::system::system_category();
  if ( (v5.m_val != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    boost::asio::detail::do_throw_error(&v5, "static_mutex");
  SSL_ctrl(*(ssl_st **)a2, 33, 1, 0);
  SSL_ctrl(*(ssl_st **)a2, 33, 2, 0);
  SSL_ctrl(*(ssl_st **)a2, 33, 16, 0);
  context = 0;
  BIO_new_bio_pair((bio_st **)&context, 0, (bio_st **)(a2 + 4), 0);
  SSL_set_bio(*(ssl_st **)a2, (bio_st *)context, (bio_st *)context);
}
