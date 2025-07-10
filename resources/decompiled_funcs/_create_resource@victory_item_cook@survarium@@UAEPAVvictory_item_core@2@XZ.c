void __thiscall survarium::victory_item_cook::create_resource(survarium::victory_item_cook *this)
{
  int *v2; // eax

  v2 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
         0x188u);
  if ( v2 )
    survarium::victory_item::victory_item(
      (survarium::victory_item *)this->m_game_world,
      (survarium::victory_item *)v2,
      (vostok::resources::query_result *)this->m_game_world);
}
