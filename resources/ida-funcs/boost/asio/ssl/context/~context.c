void __usercall boost::asio::ssl::context::~context(boost::asio::ssl::context *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(void *, int); // eax
  boost::asio::ssl::context *v5; // [esp-4h] [ebp-8h]

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 )
  {
    v3 = *(void (__thiscall ****)(_DWORD, int))(v2 + 112);
    if ( v3 )
    {
      (**v3)(v3, 1);
      *(_DWORD *)(*(_DWORD *)(a2 + 4) + 112) = 0;
    }
    if ( X509_STORE_CTX_get_ex_data(*(const ssl_ctx_st **)(a2 + 4), 0) )
    {
      v4 = (void (__thiscall ***)(void *, int))X509_STORE_CTX_get_ex_data(*(const ssl_ctx_st **)(a2 + 4), 0);
      if ( v4 )
        (**v4)(v4, 1);
      X509_STORE_CTX_set_ex_data(*(ssl_ctx_st **)(a2 + 4), 0, 0);
    }
    SSL_CTX_free(0, *(ssl_ctx_st **)(a2 + 4));
    this = v5;
  }
  boost::detail::shared_count::~shared_count((boost::detail::shared_count *)this, (volatile signed __int32 **)(a2 + 12));
}
