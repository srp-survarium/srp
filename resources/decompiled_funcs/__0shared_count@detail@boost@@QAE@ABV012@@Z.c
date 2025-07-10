void __thiscall boost::detail::shared_count::shared_count(
        boost::detail::shared_count *this,
        const boost::detail::shared_count *r)
{
  this->pi_ = r->pi_;
  if ( this->pi_ )
    _InterlockedExchangeAdd(&this->pi_->use_count_, 1u);
}
