void __thiscall boost::detail::sp_counted_base::release(boost::detail::sp_counted_base *this)
{
  if ( !_InterlockedDecrement(&this->use_count_) )
  {
    this->dispose(this);
    if ( !_InterlockedDecrement(&this->weak_count_) )
      this->destroy(this);
  }
}
