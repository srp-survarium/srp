void __userpurge survarium::game_options::assign_binding(
        unsigned int action_id@<eax>,
        survarium::game_options *this,
        char *key)
{
  survarium::key_bind_descr *v5; // eax
  vostok::fixed_string<32> *p_new_binded_key; // esi
  vostok::buffer_string *v7; // ecx
  survarium::flash_value *v8; // ecx
  survarium::flash_value *v9; // ecx
  int v10; // edx
  survarium::text_translator *v11; // ecx
  survarium::flash_value *v12; // ecx
  Scaleform::GFx::Value *v13; // esi
  int i; // edi
  char value[512]; // [esp+10h] [ebp-250h] BYREF
  survarium::flash_value v16; // [esp+210h] [ebp-50h] BYREF
  survarium::flash_value v17; // [esp+228h] [ebp-38h] BYREF
  _BYTE v18[24]; // [esp+240h] [ebp-20h] BYREF
  char v19; // [esp+258h] [ebp-8h] BYREF
  bool v20[4]; // [esp+25Ch] [ebp-4h]
  unsigned __int8 v21; // [esp+26Bh] [ebp+Bh]

  v20[0] = 0;
  v21 = 0;
  while ( 1 )
  {
    v5 = &survarium::key_bind_descriptions[v21];
    if ( v5->action_id == action_id )
      break;
LABEL_5:
    if ( ++v21 >= 0x29u )
      goto LABEL_8;
  }
  p_new_binded_key = &v5->new_binded_key;
  if ( vostok::strings::compare(v5->new_binded_key.m_begin, key) )
  {
    vostok::fs_new::path_string_impl::assignf(
      p_new_binded_key,
      v7,
      (vostok::buffer_string *)&stru_7F9BE8.allocator,
      key);
    goto LABEL_5;
  }
  v20[0] = 1;
LABEL_8:
  v8 = &v16;
  do
  {
    survarium::flash_value::flash_value(v8);
    v8 = v9 + 1;
  }
  while ( v10 - 1 >= 0 );
  survarium::flash_value::SetUInt(v8, (int)&v16, action_id);
  survarium::text_translator::translate_text(v11, (int)&this->m_game->m_text_translator, key, value);
  survarium::flash_value::SetString(&v17, value);
  survarium::flash_value::SetBoolean(v12, (int)v18, v20[0]);
  Scaleform::GFx::Movie::Invoke(
    this->m_options_ui.m_object->movie->m_movie,
    "root.set_keybind",
    0,
    (const Scaleform::GFx::Value *)&v16,
    3u);
  v13 = (Scaleform::GFx::Value *)&v19;
  for ( i = 2; i >= 0; --i )
    Scaleform::GFx::Value::~Value(--v13);
}
