void __userpurge survarium::player::apply_damage_model_affect(
        survarium::affect_event_type_enum event_type@<eax>,
        survarium::player *this,
        const char *part_name,
        survarium::hit_affects_type_enum affect)
{
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  survarium::game_world_ui *v6; // esi
  int v7; // eax

  v5 = this->damage_model(this);
  survarium::damage_model::apply_affect(v5->m_object, part_name, affect, event_type);
  v6 = *(survarium::game_world_ui **)((char *)&dword_10F7C + (_DWORD)this);
  if ( v6 )
  {
    v7 = *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_10F04 + (_DWORD)this) + 952) + 8);
    if ( v7 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        if ( *(_BYTE *)(v7 + 52) == this->id )
          survarium::game_world_ui::on_damage_affect_applying(v6, part_name, affect, event_type);
      }
    }
  }
}
