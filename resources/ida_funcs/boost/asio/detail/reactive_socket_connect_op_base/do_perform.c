char __cdecl boost::asio::detail::reactive_socket_connect_op_base::do_perform(boost::asio::detail::reactor_op *base)
{
  return boost::asio::detail::socket_ops::non_blocking_connect(base[1].Internal, &base->ec_);
}
