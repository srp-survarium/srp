void __thiscall survarium::chat_handler::scaleform_call(
        survarium::chat_handler *this,
        survarium::flash_function_handler_params *params)
{
  vostok::messaging::message_channel_enum v3; // esi
  survarium::flash_value *v4; // ecx
  char *String; // eax
  stlp_std::_Locale_impl *v6; // ecx
  const stlp_std::locale *v7; // eax
  survarium::chat_handler *v8; // ecx
  boost::algorithm::detail::is_classifiedF v9; // [esp-Ch] [ebp-64h]
  stlp_std::locale v10; // [esp-4h] [ebp-5Ch] BYREF
  stlp_std::allocator<char> v11; // [esp+Bh] [ebp-4Dh] BYREF
  stlp_std::locale v12; // [esp+Ch] [ebp-4Ch] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > Input; // [esp+10h] [ebp-48h] BYREF
  survarium::flash_value value; // [esp+28h] [ebp-30h] BYREF
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > IsSpace; // [esp+40h] [ebp-18h] BYREF

  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  survarium::flash_value::GetMember((survarium::flash_value *)this, params->pArgs->body, "text", &value);
  v3 = *(_DWORD *)&params->pArgs[1].body[8];
  String = (char *)survarium::flash_value::GetString(v4, (int)&value);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &Input,
    String,
    &v11);
  stlp_std::locale::locale(&v12);
  v10._M_impl = v6;
  v9.m_Locale._M_impl = (stlp_std::_Locale_impl *)1;
  stlp_std::locale::locale(&v10, v7);
  v9.m_Type = (stlp_std::ctype_base::mask)&IsSpace;
  boost::algorithm::trim_copy_if<stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>,boost::algorithm::detail::is_classifiedF>(
    &Input,
    v9);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::operator=(
    &Input,
    (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&IsSpace);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&IsSpace);
  stlp_std::locale::~locale(&v12);
  if ( Input._M_finish != Input._M_start_of_storage._M_data )
    survarium::chat_handler::on_message_typed(
      v8,
      &this[-1].m_private_channels._M_impl._M_end_of_storage._M_data,
      Input._M_start_of_storage._M_data,
      v3);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&Input);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
}
