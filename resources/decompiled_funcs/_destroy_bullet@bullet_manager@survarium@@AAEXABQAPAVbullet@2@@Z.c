void __thiscall survarium::bullet_manager::destroy_bullet(
        survarium::bullet_manager *this,
        survarium::bullet ***destroying_bullet_iterator)
{
  survarium::game_camera *v2; // ecx
  vostok::ai::planning::action_parameter **end; // [esp+38h] [ebp-8h] BYREF
  survarium::bullet *destroying_bullet; // [esp+3Ch] [ebp-4h] BYREF

  destroying_bullet = **destroying_bullet_iterator;
  end = (vostok::ai::planning::action_parameter **)(*destroying_bullet_iterator + 1);
  vostok::buffer_vector<vostok::ai::planning::action_parameter *>::erase(
    (vostok::buffer_vector<vostok::ai::planning::action_parameter *> *)this,
    (vostok::ai::planning::action_parameter ***)destroying_bullet_iterator,
    &end);
  survarium::weapon_user_dead_state::finalize(v2);
  vostok::memory::detail::delete_helper_impl<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>,survarium::bullet,vostok::memory::detail::call_destructor_predicate>(
    this->m_bullets_allocator_ref.m_variable,
    &destroying_bullet);
}
