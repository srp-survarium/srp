void __cdecl stlp_std::__destroy_range<vostok::ai::planning::pddl_world_state_property_impl *,vostok::ai::planning::pddl_world_state_property_impl>(
        vostok::ai::planning::pddl_world_state_property_impl *__first,
        vostok::ai::planning::pddl_world_state_property_impl *__last)
{
  while ( __first != __last )
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(0, __first++);
}


void __cdecl stlp_std::__destroy_range<vostok::fixed_vector<unsigned int,32> *,vostok::fixed_vector<unsigned int,32>>(
        vostok::fixed_vector<unsigned int,32> *__first,
        vostok::fixed_vector<unsigned int,32> *__last)
{
  unsigned int *i; // [esp+4h] [ebp-8h]

  while ( __first != __last )
  {
    for ( i = __first->m_begin; i != __first->m_end; ++i )
      ;
    __first->m_end = __first->m_begin;
    ++__first;
  }
}


void __cdecl stlp_std::__destroy_range<boost::shared_ptr<boost::asio::detail::win_mutex> *,boost::shared_ptr<boost::asio::detail::win_mutex>>(
        boost::shared_ptr<boost::asio::detail::win_mutex> *__first,
        boost::shared_ptr<boost::asio::detail::win_mutex> *__last)
{
  while ( __first != __last )
  {
    if ( __first->pn.pi_ )
      boost::detail::sp_counted_base::release(__first->pn.pi_);
    ++__first;
  }
}
