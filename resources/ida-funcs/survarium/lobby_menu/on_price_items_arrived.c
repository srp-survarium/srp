void __thiscall survarium::lobby_menu::on_price_items_arrived(
        survarium::lobby_menu *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> trader_id,
        unsigned __int8 a3)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  vostok::configs::binary_config_value *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  const vostok::configs::binary_config_value *v6; // esi
  unsigned __int8 v7; // al
  char *pointer; // edi
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  int v11; // edx
  survarium::flash_value *v12; // ecx
  survarium::text_translator *v13; // ecx
  unsigned int *v14; // eax
  survarium::flash_value *v15; // ecx
  survarium::lobby_client *v16; // eax
  survarium::flash_movie *v17; // ecx
  unsigned __int16 *v18; // edi
  unsigned int m_uid; // eax
  survarium::flash_value *v20; // ecx
  survarium::flash_value *v21; // ecx
  survarium::flash_value *v22; // ecx
  survarium::flash_value *v23; // ecx
  survarium::flash_value *v24; // ecx
  survarium::flash_value *v25; // ecx
  survarium::flash_value *v26; // ecx
  Scaleform::GFx::Value *v27; // esi
  int i; // edi
  char v29[512]; // [esp+10h] [ebp-2E8h] BYREF
  char _Dest[32]; // [esp+210h] [ebp-E8h] BYREF
  survarium::flash_value v31; // [esp+230h] [ebp-C8h] BYREF
  Scaleform::GFx::Value pvalue; // [esp+248h] [ebp-B0h] BYREF
  _BYTE v33[24]; // [esp+260h] [ebp-98h] BYREF
  survarium::flash_value v34; // [esp+278h] [ebp-80h] BYREF
  _BYTE v35[24]; // [esp+290h] [ebp-68h] BYREF
  char v36; // [esp+2A8h] [ebp-50h] BYREF
  survarium::flash_value v37; // [esp+2ACh] [ebp-4Ch] BYREF
  survarium::flash_value v38; // [esp+2C4h] [ebp-34h] BYREF
  const vostok::configs::binary_config_value *v39; // [esp+2DCh] [ebp-1Ch]
  unsigned int v40; // [esp+2E0h] [ebp-18h]
  unsigned int value; // [esp+2E4h] [ebp-14h]
  int v42; // [esp+2E8h] [ebp-10h]
  survarium::lobby_client *v43; // [esp+2ECh] [ebp-Ch]
  int v44; // [esp+2F0h] [ebp-8h]
  unsigned __int8 v45; // [esp+2F7h] [ebp-1h]

  m_object = trader_id.m_object;
  v43 = survarium::lobby_menu::lobby_client(this, (int)trader_id.m_object);
  sprintf_s<32>((char (*)[32])_Dest, "faction_%d", a3);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &trader_id,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3412]->m_name[217]);
  v4 = vostok::configs::binary_config_value::operator[](
         (vostok::configs::binary_config_value *)trader_id.m_object->m_lods[0].m_template.m_object,
         "factions_dict");
  v5 = vostok::configs::binary_config_value::operator[](v4, _Dest);
  v6 = vostok::configs::binary_config_value::operator[](v5, "levels");
  v39 = v6;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&trader_id);
  v7 = 24 * v6->count / 24;
  HIBYTE(trader_id.m_object) = 0;
  v45 = v7;
  v43 = (survarium::lobby_client *)((char *)v43 + 8 * a3 + 12744);
  if ( v7 )
  {
    value = 0;
    v44 = 0;
    while ( 1 )
    {
      pointer = (char *)vostok::configs::binary_config_value::operator[](
                          (vostok::configs::binary_config_value *)((char *)v6->data.pointer + v44),
                          "name")->data.pointer;
      v9 = &v31;
      do
      {
        survarium::flash_value::flash_value(v9);
        v9 = v10 + 1;
      }
      while ( v11 - 1 >= 0 );
      survarium::flash_value::SetUInt(v9, (int)&v31, a3);
      Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object[2].m_uid + 264) + 4), &pvalue);
      survarium::flash_value::SetUInt(v12, (int)v33, value);
      survarium::text_translator::translate_text(
        v13,
        (int)&m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3421],
        pointer,
        v29);
      survarium::flash_value::SetString(&v34, v29);
      v14 = (unsigned int *)vostok::configs::binary_config_value::operator[](
                              (vostok::configs::binary_config_value *)((char *)v39->data.pointer + v44),
                              "value");
      survarium::flash_value::SetUInt(v15, (int)v35, *v14);
      v16 = v43;
      v17 = 0;
      *(_DWORD *)v38.body = 0;
      *(_DWORD *)&v38.body[4] = 0;
      v40 = 0;
      if ( *(_WORD *)&v43->account_nickname[4] )
      {
        v42 = 0;
        do
        {
          v18 = (unsigned __int16 *)(v42 + *(_DWORD *)v16->account_nickname);
          LOBYTE(v17) = HIBYTE(trader_id.m_object);
          if ( *((_BYTE *)v18 + 8) == HIBYTE(trader_id.m_object) )
          {
            m_uid = m_object[2].m_uid;
            *(_DWORD *)v37.body = 0;
            *(_DWORD *)&v37.body[4] = 0;
            survarium::flash_movie::CreateObject(
              v17,
              *(survarium::flash_value **)(m_uid + 264),
              (Scaleform::GFx::Value *)&v37);
            survarium::flash_value::SetUInt(v20, (int)&v38, *v18);
            survarium::flash_value::SetMember(v21, &v37, "dictId", &v38);
            survarium::flash_value::SetUInt(v22, (int)&v38, 0xAu);
            survarium::flash_value::SetMember(v23, &v37, "count", &v38);
            survarium::flash_value::SetUInt(v24, (int)&v38, *((_DWORD *)v18 + 1));
            survarium::flash_value::SetMember(v25, &v37, "cost", &v38);
            survarium::flash_value::PushBack(v26, &pvalue, &v37);
            Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v37);
            v16 = v43;
          }
          v17 = (survarium::flash_movie *)*(unsigned __int16 *)&v16->account_nickname[4];
          ++v40;
          v42 += 12;
        }
        while ( v40 < (unsigned int)v17 );
      }
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object[2].m_uid + 264) + 4),
        "root.setup_shop_data",
        0,
        (const Scaleform::GFx::Value *)&v31,
        5u);
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v38);
      v27 = (Scaleform::GFx::Value *)&v36;
      for ( i = 4; i >= 0; --i )
        Scaleform::GFx::Value::~Value(--v27);
      ++HIBYTE(trader_id.m_object);
      ++value;
      v44 += 24;
      if ( HIBYTE(trader_id.m_object) >= v45 )
        break;
      v6 = v39;
    }
  }
}
