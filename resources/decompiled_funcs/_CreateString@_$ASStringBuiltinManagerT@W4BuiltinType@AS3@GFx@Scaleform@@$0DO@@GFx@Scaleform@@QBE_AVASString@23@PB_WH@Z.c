Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *this,
        Scaleform::GFx::ASString *result,
        const wchar_t *pwstr,
        int len)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pStringManager, pwstr, len);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}
