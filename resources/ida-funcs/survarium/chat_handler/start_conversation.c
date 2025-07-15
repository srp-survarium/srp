void __thiscall survarium::chat_handler::start_conversation(
        survarium::chat_handler *this,
        const char (*name)[64],
        char *right)
{
  int i; // esi
  survarium::flash_value *v4; // ecx
  survarium::private_channel_tab *v5; // esi
  survarium::private_channel_tab *v6; // edi
  survarium::chat_handler *v7; // ecx
  Scaleform::GFx::Value *p_id; // ecx
  survarium::flash_value *v9; // ecx
  survarium::chat_handler *v10; // ecx
  unsigned int v11; // [esp-4h] [ebp-94h]
  unsigned int v12; // [esp+0h] [ebp-90h]
  bool v13; // [esp+4h] [ebp-8Ch]
  stlp_std::priv::_Impl_vector<survarium::private_channel_tab,survarium::std_allocator<survarium::private_channel_tab> > _Dst[6]; // [esp+10h] [ebp-80h] BYREF
  Scaleform::GFx::Value pargs; // [esp+5Ch] [ebp-34h] BYREF
  survarium::chat_tab tab; // [esp+74h] [ebp-1Ch] BYREF

  for ( i = *(_DWORD *)&(*name)[28]; i != *(_DWORD *)&(*name)[32]; i += 68 )
  {
    if ( !vostok::strings::compare((const char *)i, right) )
    {
      v11 = *(_DWORD *)(i + 64);
      tab.id = 0;
      *(_DWORD *)&tab.closeable = 0;
      survarium::flash_value::SetUInt(v4, (int)&tab.id, v11);
      Scaleform::GFx::Movie::Invoke(
        *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&(*name)[20] + 264) + 4),
        "root.focus_tab",
        0,
        (const Scaleform::GFx::Value *)&tab.id,
        1u);
      survarium::chat_handler::focus(v7, (int)name, 1);
      p_id = (Scaleform::GFx::Value *)&tab.id;
      goto LABEL_10;
    }
  }
  v5 = *(survarium::private_channel_tab **)&(*name)[24];
  *(_DWORD *)&(*name)[24] = &v5->name[1];
  strcpy_s((char *)_Dst, 0x40u, right);
  v6 = *(survarium::private_channel_tab **)&(*name)[32];
  _Dst[5]._M_finish = v5;
  if ( v6 == *(survarium::private_channel_tab **)&(*name)[36] )
  {
    stlp_std::priv::_Impl_vector<survarium::private_channel_tab,survarium::std_allocator<survarium::private_channel_tab>>::_M_insert_overflow(
      _Dst,
      (int)&(*name)[28],
      v6,
      (const stlp_std::__true_type *)_Dst,
      v12,
      v13);
  }
  else
  {
    qmemcpy(v6, _Dst, sizeof(survarium::private_channel_tab));
    *(_DWORD *)&(*name)[32] += 68;
  }
  tab.name = (const char *)_Dst;
  tab.id = (unsigned int)v5;
  tab.closeable = 1;
  tab.channels = 0;
  tab.channels_count = 0;
  tab.channel_to_send = 4;
  tab.save_history = 1;
  survarium::chat_handler::add_new_tab(
    (survarium::chat_handler *)&tab,
    (const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *)&(*name)[20],
    &tab);
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt(v9, (int)&pargs, (unsigned int)v5);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)&(*name)[20] + 264) + 4),
    "root.focus_tab",
    0,
    &pargs,
    1u);
  survarium::chat_handler::focus(v10, (int)name, 1);
  p_id = &pargs;
LABEL_10:
  Scaleform::GFx::Value::~Value(p_id);
}
