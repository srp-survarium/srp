void __thiscall survarium::weapon_cook::weapon_cook(survarium::weapon_cook *this, survarium::game *g)
{
  survarium::weapon_core_cook::weapon_core_cook(&s_weapon_cook);
  s_weapon_cook.m_game = g;
  s_weapon_cook.__vftable = (survarium::weapon_cook_vtbl *)&survarium::weapon_cook::`vftable';
}
