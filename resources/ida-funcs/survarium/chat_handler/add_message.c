void __thiscall survarium::chat_handler::add_message(
        survarium::chat_handler *this,
        vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> channel,
        survarium::private_channel_tab *message_text,
        const char *sender_name,
        char *value)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  bool v6; // zf
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v7; // edi
  survarium::flash_movie *v8; // ecx
  const char *v9; // edi
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::network_client *v13; // ecx
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v14; // esi
  survarium::text_translator *v15; // ecx
  int v16; // eax
  survarium::flash_value *v17; // ecx
  int v18; // eax
  int v19; // esi
  survarium::flash_value *v20; // ecx
  survarium::private_channel_tab *m_reconstruction_size; // esi
  survarium::private_channel_tab *m_uid; // eax
  survarium::private_channel_tab *v23; // edi
  const char *v24; // eax
  survarium::chat_handler *v25; // ecx
  survarium::flash_value *v26; // ecx
  survarium::flash_value *v27; // ecx
  const char *v28; // [esp-4h] [ebp-4C4h]
  unsigned int v29; // [esp+0h] [ebp-4C0h]
  bool v30; // [esp+4h] [ebp-4BCh]
  char v31[512]; // [esp+10h] [ebp-4B0h] BYREF
  char string[512]; // [esp+210h] [ebp-2B0h] BYREF
  stlp_std::priv::_Impl_vector<survarium::private_channel_tab,survarium::std_allocator<survarium::private_channel_tab> > _Dst[6]; // [esp+410h] [ebp-B0h] BYREF
  survarium::flash_value v34; // [esp+458h] [ebp-68h] BYREF
  Scaleform::GFx::Value pargs; // [esp+470h] [ebp-50h] BYREF
  survarium::flash_value v36; // [esp+488h] [ebp-38h] BYREF
  survarium::chat_tab tab; // [esp+4A0h] [ebp-20h] BYREF
  int v38; // [esp+4BCh] [ebp-4h]

  m_object = channel.m_object;
  v6 = *((_BYTE *)&channel.m_object->vostok::resources::resource_flags + 14) == 0;
  v38 = 0;
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  channel.m_object = 0;
  if ( !v6
    && (message_text == (survarium::private_channel_tab *)4 || message_text == (survarium::private_channel_tab *)1) )
  {
    v7 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(LODWORD(m_object->m_reconstruction_info_actuality_tick) + 13840) + 1600);
  }
  else
  {
    v7 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&m_object->m_reconstruction_info_actuality_tick
       + 1;
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    v7,
    &channel);
  survarium::flash_movie::CreateObject(
    v8,
    (survarium::flash_value *)channel.m_object->m_lods[0].m_template.m_object,
    &pargs);
  v9 = value;
  *(_DWORD *)v36.body = 0;
  *(_DWORD *)&v36.body[4] = 0;
  survarium::flash_value::SetString(&v36, value);
  survarium::flash_value::SetMember(v10, &pargs, "name", &v36);
  survarium::flash_value::SetUInt(v11, (int)&v36, (unsigned int)message_text);
  survarium::flash_value::SetMember(v12, &pargs, "type", &v36);
  if ( *((_BYTE *)&m_object->vostok::resources::resource_flags + 14)
    && message_text == (survarium::private_channel_tab *)5 )
  {
    v14 = *(const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(LODWORD(m_object->m_reconstruction_info_actuality_tick) + 13912);
    value = (char *)survarium::network_client::get_player_team(v13, (int)v14, v9);
    if ( value == (char *)3
      || (v38 = 1,
          vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&message_text,
            v14 + 5175),
          v15 = (survarium::text_translator *)value,
          v16 = *(_DWORD *)&message_text->name[(_DWORD)&loc_11066 + 2],
          HIBYTE(value) = 1,
          *(survarium::text_translator **)(v16 + 440) == v15) )
    {
      HIBYTE(value) = 0;
    }
    if ( (v38 & 1) != 0 )
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&message_text);
    if ( HIBYTE(value) )
    {
      survarium::flash_value::SetString(&v36, "Red");
      survarium::flash_value::SetMember(v17, &pargs, "color", &v36);
      sprintf_s(string, 0x200u, (char *)&stru_7F9BE8.allocator, sender_name);
    }
    else
    {
      survarium::text_translator::translate_text(
        v15,
        LODWORD(m_object->m_reconstruction_info_actuality_tick) + 13944,
        "st_to_all",
        v31);
      sprintf_s(string, 0x200u, "[%s] %s", v31, sender_name);
    }
  }
  else
  {
    sprintf_s(string, 0x200u, (char *)&stru_7F9BE8.allocator, sender_name);
    if ( message_text == (survarium::private_channel_tab *)4 )
    {
      v18 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(LODWORD(m_object->m_reconstruction_info_actuality_tick) + 13912)
                                          + 68))(*(_DWORD *)(LODWORD(m_object->m_reconstruction_info_actuality_tick)
                                                           + 13912));
      if ( vostok::strings::compare((const char *)(v18 + 280), v9) )
      {
        v19 = *(&m_object->m_reconstruction_size + 1);
        sender_name = (const char *)(&m_object->m_reconstruction_size + 1);
        while ( v19 != m_object->m_uid )
        {
          if ( !vostok::strings::compare((const char *)v19, value) )
          {
            message_text = *(survarium::private_channel_tab **)(v19 + 64);
            if ( message_text )
              goto LABEL_29;
            break;
          }
          v19 += 68;
        }
        m_reconstruction_size = (survarium::private_channel_tab *)m_object->m_reconstruction_size;
        v28 = value;
        m_object->m_reconstruction_size = (unsigned int)&m_reconstruction_size->name[1];
        message_text = m_reconstruction_size;
        strcpy_s((char *)_Dst, 0x40u, v28);
        m_uid = (survarium::private_channel_tab *)m_object->m_uid;
        _Dst[5]._M_finish = m_reconstruction_size;
        if ( m_uid == (survarium::private_channel_tab *)m_object->m_children_resources.m_size )
        {
          stlp_std::priv::_Impl_vector<survarium::private_channel_tab,survarium::std_allocator<survarium::private_channel_tab>>::_M_insert_overflow(
            _Dst,
            (int)(&m_object->m_reconstruction_size + 1),
            m_uid,
            (const stlp_std::__true_type *)_Dst,
            v29,
            v30);
        }
        else
        {
          v23 = m_uid;
          v24 = sender_name;
          qmemcpy(v23, _Dst, sizeof(survarium::private_channel_tab));
          v25 = 0;
          *((_DWORD *)v24 + 1) += 68;
          m_reconstruction_size = message_text;
        }
        tab.channels = 0;
        tab.channels_count = 0;
        tab.name = value;
        tab.id = (unsigned int)m_reconstruction_size;
        tab.closeable = 1;
        tab.channel_to_send = 4;
        tab.save_history = 0;
        survarium::chat_handler::add_new_tab(
          v25,
          (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&channel,
          &tab);
      }
      else
      {
        tab.id = 0;
        *(_DWORD *)&tab.closeable = 0;
        Scaleform::GFx::Movie::Invoke(
          (Scaleform::GFx::Movie *)channel.m_object->m_lods[0].m_template.m_object->type,
          "root.active_tab_id",
          (Scaleform::GFx::Value *)&tab.id,
          0,
          0);
        message_text = (survarium::private_channel_tab *)tab.channels;
        Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&tab.id);
      }
LABEL_29:
      *(_DWORD *)v34.body = 0;
      *(_DWORD *)&v34.body[4] = 0;
      survarium::flash_value::SetUInt(v20, (int)&v34, (unsigned int)message_text);
      survarium::flash_value::SetMember(v26, &pargs, "tab_id", &v34);
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v34);
    }
  }
  survarium::flash_value::SetString(&v36, string);
  survarium::flash_value::SetMember(v27, &pargs, "text", &v36);
  Scaleform::GFx::Movie::Invoke(
    (Scaleform::GFx::Movie *)channel.m_object->m_lods[0].m_template.m_object->type,
    "root.add_chat_message",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v36);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&channel);
  Scaleform::GFx::Value::~Value(&pargs);
}
