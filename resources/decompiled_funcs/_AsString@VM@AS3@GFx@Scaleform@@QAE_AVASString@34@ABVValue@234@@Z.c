Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::VM::AsString(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::ASString *v3; // esi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  Scaleform::GFx::AS3::Value *v5; // ecx

  v3 = result;
  p_EmptyStringNode = &this->StringManagerRef->pStringManager->EmptyStringNode;
  v5 = value;
  result->pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  Scaleform::GFx::AS3::Value::Convert2String(v5, (Scaleform::GFx::AS3::CheckResult *)&result, v3);
  return v3;
}
