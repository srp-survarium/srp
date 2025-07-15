int __userpurge boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp>>::`scalar deleting destructor'@<eax>(
        boost::asio::ip::basic_resolver<boost::asio::ip::tcp,boost::asio::ip::resolver_service<boost::asio::ip::tcp> > *this@<ecx>,
        int a2@<esi>,
        char a3)
{
  boost::detail::shared_count *v3; // ecx

  boost::shared_ptr<void>::reset((boost::shared_ptr<void> *)this, (_DWORD *)(a2 + 4));
  boost::detail::shared_count::~shared_count(v3, (volatile signed __int32 **)(a2 + 8));
  if ( (a3 & 1) != 0 )
    operator delete((void *)a2);
  return a2;
}
