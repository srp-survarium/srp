void __thiscall vostok::ai::planning::goal_selector::goal_selector(vostok::ai::planning::goal_selector *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::ai::planning::goal_specificator *v3; // eax
  vostok::ai::planning::goal_specificator *v4; // [esp+0h] [ebp-14h]
  int *_Where; // [esp+8h] [ebp-Ch]
  vostok::ai::planning::goal_specificator *v7; // [esp+10h] [ebp-4h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  _Where = vostok::memory::doug_lea_allocator::malloc_impl(v2, 4u);
  v7 = (vostok::ai::planning::goal_specificator *)operator new(4u, _Where);
  if ( v7 )
  {
    vostok::ai::planning::goal_specificator::goal_specificator(v7);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  this->m_specificator = v4;
}
