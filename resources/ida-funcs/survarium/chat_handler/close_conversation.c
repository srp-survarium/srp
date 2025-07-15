void __usercall survarium::chat_handler::close_conversation(
        survarium::chat_handler *this@<edi>,
        unsigned int tab_id@<eax>)
{
  survarium::flash_value *M_finish; // ecx
  survarium::private_channel_tab *i; // eax
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-18h] BYREF

  M_finish = (survarium::flash_value *)this->m_private_channels._M_impl._M_finish;
  for ( i = this->m_private_channels._M_impl._M_start;
        i != (survarium::private_channel_tab *)M_finish && i->id != tab_id;
        ++i )
  {
    ;
  }
  if ( &i[1] != (survarium::private_channel_tab *)M_finish )
    stlp_std::priv::__copy_trivial((unsigned __int8 *)&i[1], (unsigned __int8 *)M_finish, (unsigned __int8 *)i);
  --this->m_private_channels._M_impl._M_finish;
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt(M_finish, (int)&pargs, tab_id);
  Scaleform::GFx::Movie::Invoke(this->m_current_chat_ui.m_object->movie->m_movie, "root.remove_tab", 0, &pargs, 1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
