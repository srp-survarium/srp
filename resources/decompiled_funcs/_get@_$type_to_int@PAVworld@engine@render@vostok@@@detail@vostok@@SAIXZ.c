survarium::game_action_id *__cdecl vostok::detail::type_to_int<vostok::render::engine::world *>::get()
{
  if ( !`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_finish )
  {
    while ( _InterlockedExchange(
              (volatile __int32 *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_end_of_storage,
              1) )
      ;
    if ( !`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_finish )
      `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_finish = (survarium::game_action_id *)(_InterlockedIncrement(&vostok::detail::global_type_id_holder<int>::s_next_type_id.m_reference_count) - 1);
    _InterlockedExchange(
      (volatile __int32 *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_end_of_storage,
      0);
  }
  return `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_finish;
}
