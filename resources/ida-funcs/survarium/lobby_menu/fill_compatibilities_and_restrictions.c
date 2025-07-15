void __thiscall survarium::lobby_menu::fill_compatibilities_and_restrictions(
        survarium::lobby_menu *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v3; // esi
  unsigned int m_uid; // eax
  const vostok::configs::binary_config_value *v5; // eax
  survarium::flash_movie *v6; // ecx
  unsigned int *v7; // eax
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  unsigned int *v10; // eax
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  unsigned int v13; // eax
  const vostok::configs::binary_config_value *v14; // eax
  survarium::flash_movie *v15; // ecx
  unsigned int *v16; // eax
  survarium::flash_value *v17; // ecx
  survarium::flash_value *v18; // ecx
  unsigned int *v19; // eax
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  Scaleform::GFx::Value pvalue; // [esp+Ch] [ebp-88h] BYREF
  survarium::flash_value v23; // [esp+24h] [ebp-70h] BYREF
  survarium::flash_value value; // [esp+3Ch] [ebp-58h] BYREF
  Scaleform::GFx::Value pargs; // [esp+54h] [ebp-40h] BYREF
  Scaleform::GFx::Value v26; // [esp+6Ch] [ebp-28h] BYREF
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v27; // [esp+84h] [ebp-10h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+88h] [ebp-Ch] BYREF
  vostok::configs::binary_config_value *pointer; // [esp+8Ch] [ebp-8h]

  m_object = a2.m_object;
  v3 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)a2.m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3412];
  m_uid = a2.m_object[2].m_uid;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(m_uid + 264) + 4), &pvalue);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  v27 = v3 + 67;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &a2,
    v3 + 67);
  pointer = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      (vostok::configs::binary_config_value *)a2.m_object->m_lods[0].m_template.m_object,
                                                      "items_compatibility")->data.pointer;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  while ( 1 )
  {
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v28,
      v27);
    v5 = vostok::configs::binary_config_value::operator[](
           (vostok::configs::binary_config_value *)v28.m_object->m_lods[0].m_template.m_object,
           "items_compatibility");
    HIBYTE(a2.m_object) = pointer != (vostok::configs::binary_config_value *)v5->data.pointer + v5->count;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
    if ( !HIBYTE(a2.m_object) )
      break;
    v26.pObjectInterface = 0;
    v26.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v6, *(survarium::flash_value **)(m_object[2].m_uid + 264), &v26);
    v7 = (unsigned int *)vostok::configs::binary_config_value::operator[](pointer, "first_item");
    survarium::flash_value::SetUInt(v8, (int)&value, *v7);
    survarium::flash_value::SetMember(v9, &v26, "first_item_dict_id", &value);
    v10 = (unsigned int *)vostok::configs::binary_config_value::operator[](pointer, "second_item");
    survarium::flash_value::SetUInt(v11, (int)&value, *v10);
    survarium::flash_value::SetMember(v12, &v26, "second_item_dict_id", &value);
    pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v26);
    Scaleform::GFx::Value::~Value(&v26);
    ++pointer;
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object[2].m_uid + 264) + 4),
    "root.set_items_compatibility",
    0,
    &pvalue,
    1u);
  v13 = m_object[2].m_uid;
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v13 + 264) + 4), &pargs);
  *(_DWORD *)v23.body = 0;
  *(_DWORD *)&v23.body[4] = 0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &a2,
    v27);
  pointer = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      (vostok::configs::binary_config_value *)a2.m_object->m_lods[0].m_template.m_object,
                                                      "slots_restrictions")->data.pointer;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  while ( 1 )
  {
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v28,
      v27);
    v14 = vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)v28.m_object->m_lods[0].m_template.m_object,
            "slots_restrictions");
    HIBYTE(a2.m_object) = pointer != (vostok::configs::binary_config_value *)v14->data.pointer + v14->count;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
    if ( !HIBYTE(a2.m_object) )
      break;
    v26.pObjectInterface = 0;
    v26.Type = VT_Undefined;
    survarium::flash_movie::CreateObject(v15, *(survarium::flash_value **)(m_object[2].m_uid + 264), &v26);
    v16 = (unsigned int *)vostok::configs::binary_config_value::operator[](pointer, "profile_slot_id");
    survarium::flash_value::SetUInt(v17, (int)&v23, *v16);
    survarium::flash_value::SetMember(v18, &v26, "slot_id", &v23);
    v19 = (unsigned int *)vostok::configs::binary_config_value::operator[](pointer, "category_id");
    survarium::flash_value::SetUInt(v20, (int)&v23, *v19);
    survarium::flash_value::SetMember(v21, &v26, "category_id", &v23);
    pargs.pObjectInterface->PushBack(pargs.pObjectInterface, (void *)pargs.mValue.IValue, &v26);
    Scaleform::GFx::Value::~Value(&v26);
    ++pointer;
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object[2].m_uid + 264) + 4),
    "root.set_profile_slots_restrictions",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v23);
  Scaleform::GFx::Value::~Value(&pargs);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pvalue);
}
