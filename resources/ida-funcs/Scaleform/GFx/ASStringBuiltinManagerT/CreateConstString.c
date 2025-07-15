Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *this,
        Scaleform::GFx::ASString *result,
        char *pstr)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax

  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(this->pStringManager, pstr, strlen(pstr), 0);
  ++ConstStringNode->RefCount;
  result->pNode = ConstStringNode;
  return result;
}
