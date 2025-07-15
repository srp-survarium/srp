void __cdecl stlp_std::_Copy_Construct_aux<boost::shared_ptr<boost::asio::detail::win_mutex>>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *__p,
        const boost::shared_ptr<boost::asio::detail::win_mutex> *__val)
{
  boost::shared_ptr<boost::asio::detail::win_mutex> *v2; // [esp+Ch] [ebp-4h]

  v2 = (boost::shared_ptr<boost::asio::detail::win_mutex> *)operator new(8u, __p);
  if ( v2 )
  {
    *v2 = *__val;
    if ( v2->pn.pi_ )
      _InterlockedExchangeAdd(&v2->pn.pi_->use_count_, 1u);
  }
}
