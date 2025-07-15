Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::StringObject::GetValue(
        Scaleform::GFx::AS2::StringObject *this,
        Scaleform::GFx::AS2::Value *result)
{
  Scaleform::GFx::AS2::Value *v2; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx

  v2 = result;
  pNode = this->sValue.pNode;
  ++pNode->RefCount;
  result->T.Type = 5;
  result->NV.Int32Value = (int)pNode;
  return v2;
}
