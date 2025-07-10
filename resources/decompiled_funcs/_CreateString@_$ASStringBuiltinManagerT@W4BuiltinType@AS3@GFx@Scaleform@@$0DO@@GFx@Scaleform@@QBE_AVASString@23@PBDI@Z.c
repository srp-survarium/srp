Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *this,
        Scaleform::GFx::ASString *result,
        char *pstr,
        unsigned int length)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pStringManager, pstr, length);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}
