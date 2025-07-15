void __thiscall survarium::booby_trap_set_cook::new_derived_resource(survarium::booby_trap_set_cook *this)
{
  if ( vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
         0x188u) )
  {
    survarium::booby_trap_set::booby_trap_set((survarium::booby_trap_set *)this->m_game_world, this->m_game_world);
  }
}
