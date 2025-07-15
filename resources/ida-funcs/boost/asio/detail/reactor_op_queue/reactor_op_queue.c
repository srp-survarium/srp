void __thiscall boost::asio::detail::reactor_op_queue<unsigned int>::reactor_op_queue<unsigned int>(
        boost::asio::detail::reactor_op_queue<unsigned int> *this)
{
  this->operations_.size_ = 0;
  this->operations_.values_._M_impl._M_node._M_data._M_next = &this->operations_.values_._M_impl._M_node._M_data;
  this->operations_.values_._M_impl._M_node._M_data._M_prev = &this->operations_.values_._M_impl._M_node._M_data;
  this->operations_.spares_._M_impl._M_node._M_data._M_next = &this->operations_.spares_._M_impl._M_node._M_data;
  this->operations_.spares_._M_impl._M_node._M_data._M_prev = &this->operations_.spares_._M_impl._M_node._M_data;
  this->operations_.buckets_ = 0;
  this->operations_.num_buckets_ = 0;
}
