void __thiscall survarium::booby_trap_cook::new_derived_resource(survarium::booby_trap_cook *this)
{
  if ( vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
         0x1D8u) )
  {
    survarium::booby_trap::booby_trap((survarium::booby_trap *)this->m_game_world, this->m_game_world);
  }
}
