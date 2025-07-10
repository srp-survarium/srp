Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::String *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pStringManager,
                 (char *)((str->HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(str->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}
