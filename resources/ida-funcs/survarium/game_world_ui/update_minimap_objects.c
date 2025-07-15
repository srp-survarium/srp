void __thiscall survarium::game_world_ui::update_minimap_objects(survarium::game_world_ui *this, int a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // edi
  int v4; // eax
  survarium::flash_movie *v5; // ecx
  int v6; // eax
  survarium::flash_value *v7; // ecx
  _DWORD *v8; // esi
  unsigned int *v9; // esi
  survarium::flash_value *v10; // ecx
  const char *v11; // edi
  survarium::flash_value *v12; // ecx
  survarium::flash_value *v13; // ecx
  survarium::flash_value *v14; // ecx
  survarium::flash_value *v15; // ecx
  survarium::flash_value *v16; // ecx
  survarium::flash_movie *v17; // ecx
  survarium::flash_value *v18; // ecx
  survarium::flash_value *v19; // ecx
  survarium::flash_value *v20; // ecx
  float *v21; // edi
  survarium::flash_value *v22; // ecx
  survarium::flash_value *v23; // ecx
  survarium::flash_value *v24; // ecx
  survarium::flash_value *v25; // ecx
  Scaleform::GFx::Value pvalue; // [esp+18h] [ebp-70h] BYREF
  Scaleform::GFx::Value v27; // [esp+30h] [ebp-58h] BYREF
  survarium::flash_value value; // [esp+48h] [ebp-40h] BYREF
  Scaleform::GFx::Value v29; // [esp+60h] [ebp-28h] BYREF
  float *v30; // [esp+78h] [ebp-10h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v31; // [esp+7Ch] [ebp-Ch] BYREF
  int v32; // [esp+80h] [ebp-8h]
  char v33; // [esp+93h] [ebp+Bh]
  unsigned __int8 i; // [esp+93h] [ebp+Bh]

  survarium::base_network_client::get_current_player(
    *(survarium::base_network_client **)(*(_DWORD *)(*(_DWORD *)(a2 + 20) + 160) + 13912),
    &v31);
  m_object = v31.m_object;
  if ( v31.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v32 = *(_DWORD *)(v31.m_object[88].m_is_playing + 440);
  }
  else
  {
    v32 = 0;
  }
  v4 = *(_DWORD *)(a2 + 8);
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(v4 + 264) + 4), &pvalue);
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  if ( !m_object || (v33 = 1, !*(_DWORD *)(m_object->m_lods[0].m_emitter_instance_list.m_size + 380)) )
    v33 = 0;
  v6 = *(_DWORD *)(a2 + 8);
  v27.pObjectInterface = 0;
  v27.Type = VT_Undefined;
  survarium::flash_movie::CreateObject(v5, *(survarium::flash_value **)(v6 + 264), &v27);
  v8 = (_DWORD *)(a2 + 340);
  if ( v32 )
    v8 = (_DWORD *)(a2 + 352);
  *((_DWORD *)&v29.mValue.BValue + 1) = *v8;
  v9 = v8 + 1;
  v29.DataAux = *v9;
  *(&v29.DataAux + 1) = v9[1];
  v30 = (float *)(*(&v29.DataAux + 1) ^ _mask__NegFloat_);
  survarium::flash_value::SetUInt(v7, (int)&value, v32 + 20);
  survarium::flash_value::SetMember(v10, &v27, "id", &value);
  v11 = "base_highlighted";
  if ( !v33 )
    v11 = "base";
  survarium::flash_value::SetString(&value, v11);
  survarium::flash_value::SetMember(v12, &v27, "type", &value);
  survarium::flash_value::SetNumber(v13, (int)&value, *((float *)&v29.mValue.BValue + 1));
  survarium::flash_value::SetMember(v14, &v27, "pos_x", &value);
  survarium::flash_value::SetNumber(v15, (int)&value, *(float *)&v30);
  survarium::flash_value::SetMember(v16, &v27, "pos_y", &value);
  pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v27);
  for ( i = 0; i < *(_BYTE *)(a2 + 484); ++i )
  {
    v29.pObjectInterface = 0;
    v29.Type = VT_Undefined;
    v30 = (float *)(12 * i + a2 + 364);
    survarium::flash_movie::CreateObject(v17, *(survarium::flash_value **)(*(_DWORD *)(a2 + 8) + 264), &v29);
    survarium::flash_value::SetUInt(v18, (int)&value, i + 22);
    survarium::flash_value::SetMember(v19, &v29, "id", &value);
    survarium::flash_value::SetString(&value, "artifact");
    survarium::flash_value::SetMember(v20, &v29, "type", &value);
    v21 = v30;
    survarium::flash_value::SetNumber(v22, (int)&value, *v30);
    survarium::flash_value::SetMember(v23, &v29, "pos_x", &value);
    survarium::flash_value::SetNumber(v24, (int)&value, COERCE_FLOAT(*((_DWORD *)v21 + 2) ^ _mask__NegFloat_));
    survarium::flash_value::SetMember(v25, &v29, "pos_y", &value);
    pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v29);
    Scaleform::GFx::Value::~Value(&v29);
  }
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 264) + 4),
    "root.update_objects",
    0,
    &pvalue,
    1u);
  Scaleform::GFx::Value::~Value(&v27);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pvalue);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
}
