void __thiscall boost::shared_ptr<void>::reset(boost::shared_ptr<void> *this)
{
  boost::detail::sp_counted_base *pi; // [esp+10h] [ebp-14h]
  vostok::size_policy __a; // [esp+1Ch] [ebp-8h] BYREF
  boost::detail::sp_counted_base *v4; // [esp+20h] [ebp-4h]

  __a.m_size = 0;
  v4 = 0;
  stlp_std::swap<vostok::size_policy>(&__a, (vostok::size_policy *)this);
  pi = this->pn.pi_;
  this->pn.pi_ = v4;
  v4 = pi;
  if ( pi )
    boost::detail::sp_counted_base::release(v4);
}
