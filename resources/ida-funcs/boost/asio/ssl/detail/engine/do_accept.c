int __thiscall boost::asio::ssl::detail::engine::do_accept(
        boost::asio::ssl::detail::engine *this,
        void *__formal,
        unsigned int a3)
{
  int v5; // [esp+Ch] [ebp-Ch]
  boost::asio::detail::scoped_lock<boost::asio::detail::win_static_mutex> lock; // [esp+10h] [ebp-8h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&lock);
  lock.mutex_ = (boost::asio::detail::win_static_mutex *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.survarium::flash_external_handler;
  EnterCriticalSection((LPCRITICAL_SECTION)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.impl);
  lock.locked_ = 1;
  v5 = SSL_accept(this->ssl_);
  if ( lock.locked_ )
    LeaveCriticalSection(&lock.mutex_->crit_section_);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&lock);
  return v5;
}
