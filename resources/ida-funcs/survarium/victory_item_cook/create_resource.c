survarium::victory_item *__thiscall survarium::victory_item_cook::create_resource(
        survarium::victory_item_cook *this,
        vostok::physics::world *physics_world)
{
  char *v3; // eax
  survarium::victory_item *v4; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  const char *v9; // [esp+0h] [ebp-Ch]
  const char *v10; // [esp+4h] [ebp-8h]
  unsigned int v11; // [esp+8h] [ebp-4h]

  v3 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)this,
         (int)survarium::g_allocator,
         0xB10u,
         "victory_item",
         v9,
         v10,
         v11);
  if ( v3 )
  {
    survarium::victory_item::victory_item(v4, v3, this->m_game_world, physics_world);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  if ( v6 == -488 )
    v7 = 0;
  else
    survarium::portable_interactive_object::portable_interactive_object(
      (survarium::portable_interactive_object *)v4,
      v6 + 488,
      this->m_game_world,
      ik_locator_id_bone);
  *(_DWORD *)(v6 + 444) = v7;
  return (survarium::victory_item *)v6;
}
