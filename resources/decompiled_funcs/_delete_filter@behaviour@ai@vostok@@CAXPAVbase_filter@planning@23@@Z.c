void __cdecl vostok::ai::behaviour::delete_filter(vostok::ai::planning::base_filter *filter_to_be_deleted)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  vostok::ai::planning::base_filter *subfilter_to_be_deleted; // [esp+Ch] [ebp-4h]

  while ( 1 )
  {
    subfilter_to_be_deleted = vostok::ai::planning::base_filter::pop_subfilter(filter_to_be_deleted);
    if ( !subfilter_to_be_deleted )
      break;
    vostok::ai::behaviour::delete_filter(subfilter_to_be_deleted);
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&filter_to_be_deleted);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::planning::oracle>(
    v1,
    (vostok::ai::planning::oracle **)&filter_to_be_deleted);
}
