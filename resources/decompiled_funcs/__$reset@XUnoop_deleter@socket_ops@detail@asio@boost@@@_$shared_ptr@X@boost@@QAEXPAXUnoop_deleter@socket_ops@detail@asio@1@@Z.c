void __thiscall boost::shared_ptr<void>::reset<void,boost::asio::detail::socket_ops::noop_deleter>(
        boost::shared_ptr<void> *this,
        boost::detail::sp_counted_base_vtbl *p,
        boost::asio::detail::socket_ops::noop_deleter d)
{
  boost::detail::sp_counted_base *pi; // [esp+10h] [ebp-20h]
  vostok::size_policy __a; // [esp+28h] [ebp-8h] BYREF
  boost::detail::shared_count v6; // [esp+2Ch] [ebp-4h] BYREF

  __a.m_size = (unsigned int)p;
  boost::detail::shared_count::shared_count(&v6, p, d);
  boost::intrusive::detail::destructor_impl<boost::intrusive::detail::generic_hook<boost::intrusive::get_set_node_algo<void *,0>,boost::intrusive::member_tag,1,0>>();
  stlp_std::swap<vostok::size_policy>(&__a, (vostok::size_policy *)this);
  pi = this->pn.pi_;
  this->pn = v6;
  v6.pi_ = pi;
  if ( pi )
    boost::detail::sp_counted_base::release(v6.pi_);
}
