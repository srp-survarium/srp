bool __thiscall Scaleform::GFx::AS2::Value::TypesMatch(
        Scaleform::GFx::AS2::Value *this,
        const Scaleform::GFx::AS2::Value *val)
{
  unsigned __int8 Type; // al
  unsigned __int8 v3; // cl

  Type = this->T.Type;
  v3 = val->T.Type;
  if ( Type == val->T.Type )
    return 1;
  return (Type == 3 || Type == 4) && (v3 == 3 || v3 == 4);
}
