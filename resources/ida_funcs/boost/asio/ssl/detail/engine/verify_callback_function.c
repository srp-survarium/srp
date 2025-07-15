BOOL __cdecl boost::asio::ssl::detail::engine::verify_callback_function(int preverified, x509_store_ctx_st *ctx)
{
  int v2; // eax
  BOOL v4; // [esp+0h] [ebp-10h]
  boost::asio::ssl::detail::verify_callback_base *callback; // [esp+4h] [ebp-Ch]
  boost::asio::ssl::verify_context verify_ctx; // [esp+8h] [ebp-8h] BYREF
  ssl_st *ssl; // [esp+Ch] [ebp-4h]

  if ( !ctx )
    return 0;
  v2 = SSL_get_ex_data_X509_STORE_CTX_idx();
  ssl = (ssl_st *)X509_STORE_CTX_get_ex_data((const ssl_ctx_st *)ctx, v2);
  if ( !ssl || !SSL_get_ex_data(ssl, 0) )
    return 0;
  callback = (boost::asio::ssl::detail::verify_callback_base *)SSL_get_ex_data(ssl, 0);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&verify_ctx);
  verify_ctx.handle_ = ctx;
  v4 = callback->call(callback, preverified != 0, &verify_ctx);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&verify_ctx);
  return v4;
}
