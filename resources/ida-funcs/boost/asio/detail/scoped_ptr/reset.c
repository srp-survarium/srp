void __userpurge boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread>::reset(
        boost::asio::detail::scoped_ptr<boost::asio::detail::win_thread> *this@<ecx>,
        HANDLE **a2@<edi>,
        HANDLE *p)
{
  HANDLE *v3; // esi

  v3 = *a2;
  if ( *a2 )
  {
    CloseHandle(v3[1]);
    operator delete(v3);
  }
  *a2 = p;
}
