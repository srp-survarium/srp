BOOL __cdecl boost::asio::ip::operator!=(
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *a,
        const boost::asio::ip::basic_resolver_iterator<boost::asio::ip::tcp> *b)
{
  bool v3; // [esp+3h] [ebp-9h]

  v3 = !a->values_.px && !b->values_.px || a->values_.px == b->values_.px && a->index_ == b->index_;
  return !v3;
}
