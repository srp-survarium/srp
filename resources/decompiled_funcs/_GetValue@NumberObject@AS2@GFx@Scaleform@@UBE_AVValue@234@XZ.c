Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::NumberObject::GetValue(
        Scaleform::GFx::AS2::NumberObject *this,
        Scaleform::GFx::AS2::Value *result)
{
  Scaleform::GFx::AS2::Value *v2; // eax

  v2 = result;
  result->NV.NumberValue = this->mValue;
  result->T.Type = 3;
  return v2;
}
