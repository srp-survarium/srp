void __thiscall vostok::ai::planning::position_filter::add_filtered_item(
        vostok::ai::planning::position_filter *this,
        const vostok::math::float3 *target_position,
        const vostok::math::float3 *eyes_direction,
        const vostok::math::float3 *preferable_velocity,
        const char *animation)
{
  const vostok::ai::planning::movement_target_wrapper *v5; // eax
  vostok::ai::planning::movement_target_wrapper v7; // [esp+48h] [ebp-138h] BYREF

  vostok::ai::planning::movement_target_wrapper::movement_target_wrapper(
    &v7,
    target_position,
    eyes_direction,
    preferable_velocity,
    animation);
  stlp_std::priv::_Impl_list<vostok::ai::planning::movement_target_wrapper,vostok::ai::std_allocator<vostok::ai::planning::movement_target_wrapper>>::push_back(
    &this->m_filtered_items._M_impl,
    v5);
}
