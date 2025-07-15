void __thiscall boost::asio::ssl::detail::engine::engine(boost::asio::ssl::detail::engine *this, ssl_ctx_st *context)
{
  bio_st *int_bio; // [esp+16Ch] [ebp-4h] BYREF

  this->ssl_ = SSL_new(context);
  boost::asio::detail::win_static_mutex::init((boost::asio::detail::win_static_mutex *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.survarium::flash_external_handler);
  SSL_ctrl(this->ssl_, 33, 1, 0);
  SSL_ctrl(this->ssl_, 33, 2, 0);
  SSL_ctrl(this->ssl_, 33, 16, 0);
  int_bio = 0;
  BIO_new_bio_pair(&int_bio, 0, &this->ext_bio_, 0);
  SSL_set_bio(this->ssl_, int_bio, int_bio);
}
