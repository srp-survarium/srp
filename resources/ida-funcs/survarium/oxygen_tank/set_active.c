void __usercall survarium::oxygen_tank::set_active(survarium::oxygen_tank *this@<edi>, bool bactive@<al>)
{
  survarium::oxygen_tank::item_influence *v2; // ebx
  survarium::inventory_holder_vtbl *v3; // eax
  survarium::damage_model **v4; // eax
  survarium::damage_model *v5; // ecx
  int *v6; // eax
  unsigned int v7; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  this->m_active = bactive;
  if ( bactive )
    survarium::game_world_core::register_tickable_object(
      (survarium::game_world_core *)&this->survarium::tickable_object,
      (int)this->m_game_world_core);
  else
    survarium::game_world_core::unregister_tickable_object(this->m_game_world_core, &this->survarium::tickable_object);
  v7 = 0;
  if ( this->m_influences_count )
  {
    v8 = 0;
    do
    {
      v2 = &this->m_influences[v8];
      v3 = this->m_inventory->m_holder->__vftable;
      if ( this->m_active )
      {
        v4 = (survarium::damage_model **)((int (*)(void))v3->damage_model)();
        survarium::damage_model::register_body_part_damage_protector(
          *v4,
          &this->m_influences[v8].protector,
          v5,
          v2->body_part_name);
      }
      else
      {
        v6 = (int *)((int (*)(void))v3->damage_model)();
        survarium::damage_model::unregister_body_part_damage_protector(
          (survarium::damage_model *)&this->m_influences[v8],
          *v6,
          v2->body_part_name,
          &this->m_influences[v8].protector);
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_influences_count );
  }
}
