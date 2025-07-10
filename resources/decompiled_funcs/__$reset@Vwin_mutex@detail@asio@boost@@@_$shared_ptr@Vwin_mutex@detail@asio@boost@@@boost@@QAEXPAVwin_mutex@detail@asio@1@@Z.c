void __thiscall boost::shared_ptr<boost::asio::detail::win_mutex>::reset<boost::asio::detail::win_mutex>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *this,
        boost::asio::detail::win_mutex *p)
{
  boost::detail::sp_counted_base *pi; // [esp+10h] [ebp-28h]
  boost::detail::shared_count v4; // [esp+34h] [ebp-4h] BYREF

  boost::detail::shared_count::shared_count(&v4, p);
  boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>();
  this->px = p;
  pi = this->pn.pi_;
  this->pn = v4;
  v4.pi_ = pi;
  if ( pi )
    boost::detail::sp_counted_base::release(v4.pi_);
}
