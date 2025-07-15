void __usercall boost::asio::ssl::detail::engine::~engine(
        boost::asio::ssl::detail::engine *this@<ecx>,
        int a2@<esi>,
        int a3@<edi>)
{
  void (__thiscall ***v3)(void *, int); // eax

  if ( SSL_get_ex_data(*(const ssl_st **)a2, 0) )
  {
    v3 = (void (__thiscall ***)(void *, int))SSL_get_ex_data(*(const ssl_st **)a2, 0);
    if ( v3 )
      (**v3)(v3, 1);
    SSL_set_ex_data(*(ssl_st **)a2, 0, 0);
  }
  BIO_free(a3, *(bio_st **)(a2 + 4));
  SSL_free(a3, *(ssl_st **)a2);
}
