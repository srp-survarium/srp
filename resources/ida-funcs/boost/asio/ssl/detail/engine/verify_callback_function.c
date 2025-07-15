BOOL __usercall boost::asio::ssl::detail::engine::verify_callback_function@<eax>(int a1@<edi>, int a2, ssl_ctx_st *s)
{
  const ssl_ctx_st *v3; // esi
  int v4; // eax
  const ssl_st *v5; // eax
  const ssl_st *v6; // edi
  void *v7; // eax

  v3 = s;
  if ( !s )
    return 0;
  v4 = SSL_get_ex_data_X509_STORE_CTX_idx(a1);
  v5 = (const ssl_st *)X509_STORE_CTX_get_ex_data(v3, v4);
  v6 = v5;
  if ( !v5 || !SSL_get_ex_data(v5, 0) )
    return 0;
  v7 = SSL_get_ex_data(v6, 0);
  s = (ssl_ctx_st *)v3;
  return (*(unsigned __int8 (__thiscall **)(void *, bool, ssl_ctx_st **))(*(_DWORD *)v7 + 4))(v7, a2 != 0, &s) != 0;
}
