void __thiscall boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime>>::swap_heap(
        boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> > *this,
        unsigned int index1,
        unsigned int index2)
{
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::heap_entry *v3; // edx
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::heap_entry *v4; // eax
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::heap_entry *v5; // eax
  __int64 tmp; // [esp+1Ch] [ebp-10h]
  boost::asio::detail::timer_queue<boost::asio::time_traits<boost::posix_time::ptime> >::per_timer_data *tmp_8; // [esp+24h] [ebp-8h]
  int tmp_12; // [esp+28h] [ebp-4h]

  v3 = &this->heap_._M_impl._M_start[index1];
  tmp = v3->time_.time_.time_count_.value_;
  tmp_8 = v3->timer_;
  tmp_12 = *((_DWORD *)&v3->timer_ + 1);
  v4 = &this->heap_._M_impl._M_start[index2];
  LODWORD(v3->time_.time_.time_count_.value_) = v4->time_.time_.time_count_.value_;
  HIDWORD(v3->time_.time_.time_count_.value_) = HIDWORD(v4->time_.time_.time_count_.value_);
  v3->timer_ = v4->timer_;
  *((_DWORD *)&v3->timer_ + 1) = *((_DWORD *)&v4->timer_ + 1);
  v5 = &this->heap_._M_impl._M_start[index2];
  v5->time_.time_.time_count_.value_ = tmp;
  v5->timer_ = tmp_8;
  *((_DWORD *)&v5->timer_ + 1) = tmp_12;
  this->heap_._M_impl._M_start[index1].timer_->heap_index_ = index1;
  this->heap_._M_impl._M_start[index2].timer_->heap_index_ = index2;
}
