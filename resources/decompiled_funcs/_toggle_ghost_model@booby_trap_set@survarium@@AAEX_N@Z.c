void __thiscall survarium::booby_trap_set::toggle_ghost_model(survarium::booby_trap_set *this, bool enable)
{
  char visible_place_transform; // al
  vostok::math::float4x4 transform; // [esp+8h] [ebp-40h] BYREF

  if ( enable )
  {
    visible_place_transform = survarium::booby_trap_set_core::get_visible_place_transform(this, &transform);
    survarium::booby_trap_set::pick_current_ghost_model(this, &transform, visible_place_transform);
  }
  else
  {
    survarium::booby_trap_set::remove_current_ghost_model(this, (int)this);
  }
}
