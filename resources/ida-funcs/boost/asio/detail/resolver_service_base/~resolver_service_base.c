void __usercall boost::asio::detail::resolver_service_base::~resolver_service_base(
        boost::asio::detail::resolver_service_base *this@<ecx>,
        unsigned int a2@<eax>)
{
  boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *v3; // ecx
  boost::asio::io_service::work *v4; // ecx
  void *v5; // edi

  boost::asio::detail::resolver_service_base::shutdown_service(this, (HANDLE **)a2);
  boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::~scoped_ptr<boost::asio::detail::win_thread>(
    v3,
    (HANDLE **)(a2 + 40));
  v5 = *(void **)(a2 + 36);
  if ( v5 )
    boost::asio::io_service::work::`scalar deleting destructor'(v4, v5);
  boost::asio::detail::scoped_ptr<boost::asio::io_service>::~scoped_ptr<boost::asio::io_service>(
    (boost::asio::detail::scoped_ptr<boost::asio::io_service> *)v4,
    (_DWORD **)(a2 + 28));
  DeleteCriticalSection((LPCRITICAL_SECTION)(a2 + 4));
}
