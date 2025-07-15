boost::asio::detail::socket_ops::noop_deleter *__thiscall boost::detail::sp_counted_impl_pd<void *,boost::asio::detail::socket_ops::noop_deleter>::get_deleter(
        boost::detail::sp_counted_impl_pd<void *,boost::asio::detail::socket_ops::noop_deleter> *this,
        const type_info *ti)
{
  return type_info::operator==(ti, &boost::asio::detail::socket_ops::noop_deleter `RTTI Type Descriptor')
       ? &this->del
       : 0;
}
