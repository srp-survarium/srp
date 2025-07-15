void __thiscall vostok::ai::sensors::vision_sensor::on_object_destruction(
        vostok::ai::sensors::vision_sensor *this,
        const vostok::ai::game_object *destroyed_object)
{
  survarium::game_camera *v2; // ecx
  vostok::memory::doug_lea_allocator *v3; // eax
  vostok::ai::sensed_visual_object *object_to_be_deleted; // [esp+2Ch] [ebp-4h] BYREF

  object_to_be_deleted = vostok::ai::sensors::vision_sensor::find_visual_object_in_list(
                           destroyed_object,
                           &this->m_visible_objects);
  if ( object_to_be_deleted )
  {
    if ( vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
           &this->m_visible_objects,
           object_to_be_deleted) )
    {
      survarium::weapon_user_dead_state::finalize(v2);
      vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::game_material,vostok::memory::detail::call_destructor_predicate>(
        v3,
        (survarium::game_camera **)&object_to_be_deleted);
    }
  }
}
