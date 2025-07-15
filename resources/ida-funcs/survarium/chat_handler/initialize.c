void __thiscall survarium::chat_handler::initialize(
        survarium::chat_handler *this,
        const vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *ui,
        vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *is_game_mode,
        char a4)
{
  unsigned int m_object; // eax
  unsigned int v6; // eax
  survarium::flash_movie *v7; // ecx
  survarium::flash_movie *v8; // ecx
  survarium::chat_channel *v9; // edi
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  survarium::flash_value *v12; // ecx
  survarium::chat_handler *v13; // ecx
  unsigned int id; // [esp-4h] [ebp-60h]
  Scaleform::GFx::Value pvalue; // [esp+Ch] [ebp-50h] BYREF
  survarium::flash_value value; // [esp+24h] [ebp-38h] BYREF
  Scaleform::GFx::Value v17; // [esp+3Ch] [ebp-20h] BYREF
  int v18; // [esp+54h] [ebp-8h]
  survarium::chat_channel *is_game_modea; // [esp+68h] [ebp+Ch]

  m_object = (unsigned int)is_game_mode->m_object;
  pvalue.pObjectInterface = 0;
  pvalue.Type = VT_Undefined;
  Scaleform::GFx::Movie::CreateArray(*(Scaleform::GFx::Movie **)(*(_DWORD *)(m_object + 264) + 4), &pvalue);
  v6 = (unsigned int)is_game_mode->m_object;
  v17.pObjectInterface = 0;
  v17.Type = VT_Undefined;
  survarium::flash_movie::CreateObject(v7, *(survarium::flash_value **)(v6 + 264), &v17);
  v9 = survarium::chat_channels;
  is_game_modea = survarium::chat_channels;
  v18 = 9;
  while ( 1 )
  {
    survarium::flash_movie::CreateObject(v8, (survarium::flash_value *)is_game_mode->m_object->movie, &v17);
    id = v9->id;
    *(_DWORD *)value.body = 0;
    *(_DWORD *)&value.body[4] = 0;
    survarium::flash_value::SetUInt(v10, (int)&value, id);
    survarium::flash_value::SetMember(v11, &v17, "id", &value);
    survarium::flash_value::SetString(&value, v9->color);
    survarium::flash_value::SetMember(v12, &v17, "color", &value);
    pvalue.pObjectInterface->PushBack(pvalue.pObjectInterface, (void *)pvalue.mValue.IValue, &v17);
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
    ++is_game_modea;
    if ( !--v18 )
      break;
    v9 = is_game_modea;
  }
  Scaleform::GFx::Movie::Invoke(is_game_mode->m_object->movie->m_movie, "root.set_channels", 0, &pvalue, 1u);
  survarium::chat_handler::initialize_tabs(v13, ui, is_game_mode, a4);
  Scaleform::GFx::Value::~Value(&v17);
  Scaleform::GFx::Value::~Value(&pvalue);
}
