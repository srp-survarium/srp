void __usercall survarium::game_world_ui::update_back_slot(
        survarium::game_world_ui *this@<ecx>,
        const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *inv_item@<eax>)
{
  survarium::dictionary_item *v4; // eax
  survarium::dictionary_item *v5; // ecx
  survarium::inventory_item *m_object; // ecx
  survarium::flash_value *v7; // ecx
  survarium::flash_value *v8; // ecx
  int v9; // edx
  survarium::flash_value *v10; // ecx
  Scaleform::GFx::Value *v11; // esi
  int i; // edi
  survarium::dictionary_item v13; // [esp+8h] [ebp-1B8h] BYREF
  survarium::flash_value v14; // [esp+188h] [ebp-38h] BYREF
  _BYTE v15[24]; // [esp+1A0h] [ebp-20h] BYREF
  _WORD v16[2]; // [esp+1B8h] [ebp-8h] BYREF
  unsigned __int16 v17; // [esp+1BCh] [ebp-4h]
  unsigned __int8 v18; // [esp+1BEh] [ebp-2h]

  survarium::game_world_ui::show_oxygene(this, (int)this, inv_item->m_object != 0);
  if ( inv_item->m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v4 = survarium::items_dictionary::item_by_id(
           this->m_game_world->m_game->m_items_dictionary.m_object,
           (survarium::items_dictionary_vtbl *)inv_item->m_object->m_dict_id);
    survarium::dictionary_item::dictionary_item(v5, &v13, (int)v4);
    if ( v13.item_category == 4 )
    {
      m_object = inv_item->m_object;
      v16[0] = 0;
      v16[1] = 0;
      v17 = 0;
      v18 = 0;
      m_object->get_item_props(m_object, (survarium::inventory_item_props *)v16);
      v7 = &v14;
      do
      {
        survarium::flash_value::flash_value(v7);
        v7 = v8 + 1;
      }
      while ( v9 - 1 >= 0 );
      survarium::flash_value::SetUInt(v7, (int)&v14, v18);
      survarium::flash_value::SetUInt(v10, (int)v15, v17);
      Scaleform::GFx::Movie::Invoke(
        this->m_game_hud_ui.m_object->movie->m_movie,
        "root.set_oxygen",
        0,
        (const Scaleform::GFx::Value *)&v14,
        2u);
      v11 = (Scaleform::GFx::Value *)v16;
      for ( i = 1; i >= 0; --i )
        Scaleform::GFx::Value::~Value(--v11);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13.item_cfg);
  }
}
