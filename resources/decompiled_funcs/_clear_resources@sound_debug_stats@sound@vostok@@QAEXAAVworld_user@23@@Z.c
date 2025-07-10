void __thiscall vostok::sound::sound_debug_stats::clear_resources(
        vostok::sound::sound_debug_stats *this,
        vostok::sound::world_user *user)
{
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+27h] [ebp-9h] BYREF
  vostok::memory::base_allocator *allocator; // [esp+28h] [ebp-8h]
  char v5; // [esp+2Dh] [ebp-3h]
  char v6; // [esp+2Eh] [ebp-2h]
  char v7; // [esp+2Fh] [ebp-1h]

  v7 = 0;
  this->m_ui_world->destroy_window(this->m_ui_world, this->m_main_window);
  this->m_main_window = 0;
  v6 = 0;
  v5 = 0;
  allocator = this->m_allocator;
  call_destructor_predicate = 0;
  vostok::memory::detail::delete_array_helper_impl<vostok::memory::base_allocator,vostok::ui::progress_bar *,vostok::memory::detail::call_destructor_predicate>(
    allocator,
    &this->m_progress_bars,
    &call_destructor_predicate);
  this->m_actual_statistic = -1;
}
