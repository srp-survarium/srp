const char *__thiscall Scaleform::GFx::AS2::BooleanObject::GetTextValue(
        Scaleform::GFx::AS2::BooleanObject *this,
        Scaleform::GFx::AS2::Environment *__formal)
{
  const char *result; // eax

  result = "true";
  if ( !LOBYTE(this->ResolveHandler.pLocalFrame) )
    return "false";
  return result;
}
