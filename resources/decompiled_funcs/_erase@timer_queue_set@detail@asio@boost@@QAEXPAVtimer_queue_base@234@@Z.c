void __thiscall boost::asio::detail::timer_queue_set::erase(
        boost::asio::detail::timer_queue_set *this,
        boost::asio::detail::timer_queue_base *q)
{
  boost::asio::detail::timer_queue_base *p; // [esp+4h] [ebp-4h]

  if ( this->first_ )
  {
    if ( q == this->first_ )
    {
      this->first_ = q->next_;
      q->next_ = 0;
    }
    else
    {
      for ( p = this->first_; p->next_; p = p->next_ )
      {
        if ( p->next_ == q )
        {
          p->next_ = q->next_;
          q->next_ = 0;
          return;
        }
      }
    }
  }
}
