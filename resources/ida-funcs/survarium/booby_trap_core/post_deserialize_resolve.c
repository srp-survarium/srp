void __thiscall survarium::booby_trap_core::post_deserialize_resolve(
        survarium::booby_trap_core *this,
        survarium::game_world_core *game_world_core)
{
  if ( this->m_class_id == fs_iterator_class )
    survarium::usable_object::post_deserialize_resolve(
      (survarium::usable_object *)this,
      (survarium::usable_object *)&this[-1].m_transform,
      game_world_core);
}
