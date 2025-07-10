void __thiscall survarium::weapon_core_inactive_state_cook::deallocate_resource(
        survarium::weapon_core_inactive_state_cook *this,
        void *buffer)
{
  vostok::memory::doug_lea_allocator *v2; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  ___free_helper_Vdoug_lea_allocator_memory_vostok____CBX_memory_vostok__YAXAAVdoug_lea_allocator_01_AAPBX_Z(
    v2,
    &buffer);
}
