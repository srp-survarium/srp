Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this,
        Scaleform::GFx::ASString *result,
        char *pstr)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pStringManager, pstr);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}
