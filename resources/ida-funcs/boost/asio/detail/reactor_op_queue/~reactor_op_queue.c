void __thiscall boost::asio::detail::reactor_op_queue<unsigned int>::~reactor_op_queue<unsigned int>(
        boost::asio::detail::reactor_op_queue<unsigned int> *this)
{
  boost::asio::detail::hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>::~hash_map<unsigned int,boost::asio::detail::reactor_op_queue<unsigned int>::operations>(
    &this->operations_,
    (int)this);
}
