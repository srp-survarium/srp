void __thiscall survarium::game_options::reset_bindings(survarium::game_options *this, int is_default, bool a3)
{
  survarium::key_bind_descr *v3; // ebx
  int action_dik; // eax
  survarium::key_binder *v5; // ecx
  survarium::flash_value *v6; // ecx
  survarium::flash_value *v7; // ecx
  int v8; // edx
  survarium::text_translator *v9; // ecx
  vostok::buffer_string *v10; // ecx
  survarium::flash_value *v11; // ecx
  vostok::buffer_string *v12; // ecx
  char *v13; // esi
  int i; // edi
  survarium::flash_value *v15; // [esp-4h] [ebp-264h]
  int v16; // [esp+0h] [ebp-260h]
  char *v17; // [esp+10h] [ebp-250h]
  int v18; // [esp+14h] [ebp-24Ch]
  survarium::flash_value v19; // [esp+18h] [ebp-248h] BYREF
  survarium::flash_value v20; // [esp+30h] [ebp-230h] BYREF
  _BYTE v21[24]; // [esp+48h] [ebp-218h] BYREF
  char value[512]; // [esp+60h] [ebp-200h] BYREF

  v3 = survarium::key_bind_descriptions;
  v18 = 41;
  do
  {
    action_dik = survarium::key_binder::get_action_dik(
                   v3->action_id,
                   *(survarium::key_binder **)(*(_DWORD *)(is_default + 52) + 144),
                   v16);
    v17 = (char *)survarium::key_binder::dik_to_keyname(v5, action_dik);
    v6 = &v19;
    do
    {
      survarium::flash_value::flash_value(v6);
      v6 = v7 + 1;
    }
    while ( v8 - 1 >= 0 );
    survarium::flash_value::SetUInt(v6, (int)&v19, v3->action_id);
    if ( v17 )
    {
      survarium::text_translator::translate_text(v9, *(_DWORD *)(is_default + 52) + 13944, v17, value);
      survarium::flash_value::SetString(&v20, value);
      vostok::fs_new::path_string_impl::assignf(
        &v3->old_binded_key.m_begin,
        v10,
        (vostok::buffer_string *)&stru_7F9BE8.allocator,
        v17);
      v11 = v15;
    }
    else
    {
      vostok::fs_new::path_string_impl::assignf(
        &v3->old_binded_key.m_begin,
        (vostok::buffer_string *)v9,
        (vostok::buffer_string *)&stru_7F9BE8.allocator,
        uri);
      survarium::flash_value::SetString(&v20, uri);
    }
    survarium::flash_value::SetBoolean(v11, (int)v21, a3);
    vostok::fs_new::path_string_impl::assignf(
      &v3->new_binded_key.m_begin,
      v12,
      (vostok::buffer_string *)&stru_7F9BE8.allocator,
      v3->old_binded_key.m_begin);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(is_default + 12) + 264) + 4),
      "root.set_keybind",
      0,
      (const Scaleform::GFx::Value *)&v19,
      3u);
    v13 = value;
    for ( i = 2; i >= 0; --i )
    {
      v13 -= 24;
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)v13);
    }
    ++v3;
    --v18;
  }
  while ( v18 );
}
