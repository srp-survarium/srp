boost::shared_ptr<boost::asio::detail::win_mutex> *__cdecl stlp_std::priv::__ucopy<boost::shared_ptr<boost::asio::detail::win_mutex> *,boost::shared_ptr<boost::asio::detail::win_mutex> *,int>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *__first,
        boost::shared_ptr<boost::asio::detail::win_mutex> *__last,
        boost::shared_ptr<boost::asio::detail::win_mutex> *__result)
{
  stlp_std::__false_type v4; // [esp+Eh] [ebp-Ah] BYREF
  char v5; // [esp+Fh] [ebp-9h]
  int __n; // [esp+10h] [ebp-8h]
  boost::shared_ptr<boost::asio::detail::win_mutex> *__cur; // [esp+14h] [ebp-4h]

  __cur = __result;
  for ( __n = __last - __first; __n > 0; --__n )
  {
    v5 = 0;
    v4 = 0;
    stlp_std::_Copy_Construct_aux<boost::shared_ptr<boost::asio::detail::win_mutex>>(__cur++, __first++, &v4);
  }
  return __cur;
}
