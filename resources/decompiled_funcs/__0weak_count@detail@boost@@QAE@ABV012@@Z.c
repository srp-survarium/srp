void __thiscall boost::detail::weak_count::weak_count(
        boost::detail::weak_count *this,
        const boost::detail::weak_count *r)
{
  this->pi_ = r->pi_;
  if ( this->pi_ )
    _InterlockedExchangeAdd(&this->pi_->weak_count_, 1u);
}
