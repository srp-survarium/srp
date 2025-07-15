void __thiscall survarium::game_world_ui::initialize_quick_slots(
        survarium::game_world_ui *this,
        survarium::profile_slot_enum a2)
{
  int v3; // eax
  survarium::flash_movie *v4; // ecx
  survarium::profile_slot_enum v5; // esi
  int v6; // eax
  survarium::game_world_ui *v7; // ecx
  survarium::flash_value *v8; // [esp-8h] [ebp-6Ch]
  Scaleform::GFx::Value pvalue; // [esp+10h] [ebp-54h] BYREF
  Scaleform::GFx::Value v10; // [esp+28h] [ebp-3Ch] BYREF
  survarium::flash_value v11; // [esp+40h] [ebp-24h] BYREF
  const survarium::profile_slot_enum *v12; // [esp+58h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+5Ch] [ebp-8h] BYREF
  unsigned int v14; // [esp+6Ch] [ebp+8h]

  survarium::base_network_client::get_current_player(
    *(survarium::base_network_client **)(*(_DWORD *)(*(_DWORD *)(a2 + 20) + 160) + 13912),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11.body[16]);
  *(_DWORD *)&v11.body[12] = *(_DWORD *)(*(_DWORD *)&v11.body[16] + 268);
  v3 = *(_DWORD *)(a2 + 8);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v3 + 264) + 4), &pvalue);
  v14 = 0;
  v12 = quick_slots_0;
  *(_DWORD *)&v11.body[20] = 6;
  do
  {
    v5 = *v12;
    v6 = *(_DWORD *)(a2 + 8);
    v10.pObjectInterface = 0;
    v10.Type = VT_Undefined;
    v8 = *(survarium::flash_value **)(v6 + 264);
    *(_DWORD *)&v11.body[8] = v5;
    survarium::flash_movie::CreateObject(v4, v8, &v10);
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v13,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)&v11.body[12] + 4 * v5 + 272));
    if ( v13.m_object )
    {
      *(_WORD *)v11.body = 0;
      *(_WORD *)&v11.body[2] = 0;
      *(_WORD *)&v11.body[4] = 0;
      v11.body[6] = 0;
      v13.m_object->__vftable[1].increase_quality_to_target(
        v13.m_object,
        (vostok::resources::query_result_for_cook *)&v11);
      survarium::game_world_ui::create_slot_value(v7, a2, *(survarium::inventory_item_props **)&v11.body[8], &v11, &v10);
      pvalue.pObjectInterface->SetElement(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, v14++, &v10);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
    Scaleform::GFx::Value::~Value(&v10);
    ++v12;
    --*(_DWORD *)&v11.body[20];
  }
  while ( *(_DWORD *)&v11.body[20] );
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 264) + 4),
    "root.fill_slots",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value(&pvalue);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11.body[16]);
}
