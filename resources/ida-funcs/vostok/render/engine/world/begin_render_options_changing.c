void __thiscall vostok::render::engine::world::begin_render_options_changing(
        vostok::render::engine::world *this,
        volatile int *waiting_for)
{
  qmemcpy(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start + 77,
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start + 3,
    0x128u);
  if ( waiting_for )
    _InterlockedExchange(waiting_for, 0);
}
