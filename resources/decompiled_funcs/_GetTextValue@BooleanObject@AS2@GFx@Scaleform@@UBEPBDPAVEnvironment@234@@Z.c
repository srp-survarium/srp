survarium::keyboard_key_descr **__thiscall Scaleform::GFx::AS2::BooleanObject::GetTextValue(
        Scaleform::GFx::AS2::BooleanObject *this,
        Scaleform::GFx::AS2::Environment *__formal)
{
  survarium::keyboard_key_descr **result; // eax

  result = &stru_95AF78.m_key_bindings[4].m_keyboard[1];
  if ( !LOBYTE(this->ResolveHandler.pLocalFrame) )
    return (survarium::keyboard_key_descr **)&stru_95AF78.m_key_bindings[6];
  return result;
}
