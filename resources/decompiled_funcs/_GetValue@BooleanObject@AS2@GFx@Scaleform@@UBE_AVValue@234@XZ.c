Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::BooleanObject::GetValue(
        Scaleform::GFx::AS2::BooleanObject *this,
        Scaleform::GFx::AS2::Value *result)
{
  Scaleform::GFx::AS2::Value *v2; // eax
  bool bValue; // cl

  v2 = result;
  bValue = this->bValue;
  result->T.Type = 2;
  result->V.BooleanValue = bValue;
  return v2;
}
