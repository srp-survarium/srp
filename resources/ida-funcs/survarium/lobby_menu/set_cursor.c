void __userpurge survarium::lobby_menu::set_cursor(
        unsigned __int8 id@<al>,
        survarium::flash_value *a2@<ecx>,
        survarium::lobby_menu *this)
{
  Scaleform::GFx::Value pargs; // [esp+8h] [ebp-1Ch] BYREF

  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_value::SetUInt(a2, (int)&pargs, id);
  Scaleform::GFx::Movie::Invoke(this->m_cursor_ui.m_object->movie->m_movie, "root.setCursor", 0, &pargs, 1u);
  Scaleform::GFx::Value::~Value(&pargs);
}
