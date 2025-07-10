void __cdecl stlp_std::_Param_Construct<boost::shared_ptr<boost::asio::detail::win_mutex>,boost::shared_ptr<boost::asio::detail::win_mutex>>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *__p,
        const boost::shared_ptr<boost::asio::detail::win_mutex> *__val)
{
  stlp_std::__false_type __formal; // [esp+Eh] [ebp-2h] BYREF
  char v3; // [esp+Fh] [ebp-1h]

  v3 = 0;
  __formal = 0;
  stlp_std::_Copy_Construct_aux<boost::shared_ptr<boost::asio::detail::win_mutex>>(__p, __val, &__formal);
}
