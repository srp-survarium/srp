void __thiscall survarium::booby_trap_cook::booby_trap_cook(
        survarium::booby_trap_cook *this,
        survarium::game_world *gw)
{
  survarium::booby_trap_core_cook::booby_trap_core_cook(&s_booby_trap_cook);
  s_booby_trap_cook.m_game_world = gw;
  s_booby_trap_cook.__vftable = (survarium::booby_trap_cook_vtbl *)&survarium::booby_trap_cook::`vftable';
}
