void __userpurge survarium::chat_handler::set_local_player_name(
        const char (*account_name)[64]@<edi>,
        survarium::chat_handler *this)
{
  survarium::flash_value v2; // [esp+8h] [ebp-1Ch] BYREF

  *(_DWORD *)v2.body = 0;
  *(_DWORD *)&v2.body[4] = 0;
  survarium::flash_value::SetString(&v2, (const char *)account_name);
  Scaleform::GFx::Movie::Invoke(
    this->m_current_chat_ui.m_object->movie->m_movie,
    "root.set_local_player",
    0,
    (const Scaleform::GFx::Value *)&v2,
    1u);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v2);
}
