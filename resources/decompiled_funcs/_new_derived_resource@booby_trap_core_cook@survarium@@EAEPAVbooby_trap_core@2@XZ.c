survarium::booby_trap_core *__thiscall survarium::booby_trap_core_cook::new_derived_resource(
        survarium::booby_trap_core_cook *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  int v2; // eax
  void *_Where; // [esp+8h] [ebp-Ch]
  survarium::booby_trap_core *v6; // [esp+10h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v1, 0x1B8u);
  v6 = (survarium::booby_trap_core *)operator new(0x1B8u, _Where);
  if ( !v6 )
    return 0;
  survarium::booby_trap_core::booby_trap_core(v6);
  return (survarium::booby_trap_core *)v2;
}
