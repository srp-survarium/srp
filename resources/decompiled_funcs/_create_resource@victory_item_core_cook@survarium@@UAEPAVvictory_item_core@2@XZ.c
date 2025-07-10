survarium::victory_item_core *__thiscall survarium::victory_item_core_cook::create_resource(
        survarium::victory_item_core_cook *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  int v2; // eax
  int *_Where; // [esp+8h] [ebp-Ch]
  survarium::victory_item_core *v6; // [esp+10h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v1, 0x178u);
  v6 = (survarium::victory_item_core *)operator new(0x178u, _Where);
  if ( !v6 )
    return 0;
  survarium::victory_item_core::victory_item_core(v6);
  return (survarium::victory_item_core *)v2;
}
