void __userpurge survarium::game_world_ui::on_attached_to_player(
        survarium::game_world_ui *this@<ecx>,
        survarium::game_world_ui *a2@<eax>,
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> player)
{
  survarium::game_world_ui *v4; // ecx
  survarium::flash_movie_resource *m_object; // edx
  survarium::interactive_object *v6; // edi
  survarium::game_world_ui *v7; // ecx
  survarium::interactive_object *v8; // eax
  survarium::weapon_core *v9; // ebx
  survarium::weapon_ammo_info info; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::Value pargs; // [esp+20h] [ebp-18h] BYREF

  if ( player.m_object->m_is_alive )
  {
    m_object = a2->m_game_hud_ui.m_object;
    v6 = 0;
    pargs.pObjectInterface = 0;
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = 1;
    Scaleform::GFx::Movie::Invoke(m_object->movie->m_movie, "root.show_slots", 0, &pargs, 1u);
    v7 = (survarium::game_world_ui *)((unsigned int)pargs.Type >> 6);
    if ( (pargs.Type & 0x40) != 0 )
      pargs.pObjectInterface->ObjectRelease(pargs.pObjectInterface, &pargs, (void *)pargs.mValue.IValue);
    survarium::game_world_ui::fill_quick_slots(v7, a2);
    v8 = player.m_object->m_current_active_object.m_object;
    if ( v8 )
    {
      v6 = player.m_object->m_current_active_object.m_object;
      _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
    }
    v9 = v6->cast_weapon_core(v6);
    if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    if ( v9 )
    {
      survarium::weapon_core::get_ammo_info(v9, (survarium::weapon_core *)&info);
      survarium::game_world_ui::show_ammo_indicator(a2, 1);
      survarium::game_world_ui::set_ammo_total_count(a2, info.ammo1_total, info.ammo2_total);
      survarium::game_world_ui::set_ammo_in_magazine(a2, info.ammo_in_magazine + info.round_is_chambered);
      survarium::game_world_ui::set_fire_queue_size(a2, info.fire_queue_size);
      survarium::game_world_ui::set_ammo_type(a2, info.current_ammo_type);
      vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&player);
    }
    else
    {
      survarium::game_world_ui::show_ammo_indicator(a2, 0);
      vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&player);
    }
  }
  else
  {
    survarium::game_world_ui::show_ammo_indicator(a2, 0);
    survarium::game_world_ui::show_quick_slots(v4, a2, 0);
    vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base>(&player);
  }
}
