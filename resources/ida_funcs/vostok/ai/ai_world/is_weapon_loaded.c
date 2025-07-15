int __thiscall vostok::ai::ai_world::is_weapon_loaded(
        vostok::ai::ai_world *this,
        const vostok::ai::weapon *target_weapon)
{
  return ((int (__thiscall *)(const vostok::ai::weapon *, vostok::ai::ai_world *))target_weapon->is_loaded)(
           target_weapon,
           this);
}
