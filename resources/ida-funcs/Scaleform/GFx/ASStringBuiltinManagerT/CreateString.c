Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this,
        Scaleform::GFx::ASString *result,
        __m128i *pstr)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pStringManager, pstr);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}


Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *this,
        Scaleform::GFx::ASString *result,
        wchar_t *pwstr,
        int len)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pStringManager, pwstr, len);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}


Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::String *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pStringManager,
                 (__m128i *)((str->HeapTypeBits & 0xFFFFFFFC) + 8),
                 *(_DWORD *)(str->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}


Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *this,
        Scaleform::GFx::ASString *result,
        __m128i *pstr)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pStringManager, pstr);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}


Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *this,
        Scaleform::GFx::ASString *result,
        __m128i *pstr,
        unsigned int length)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pStringManager, pstr, length);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}


Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
        Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62> *this,
        Scaleform::GFx::ASString *result,
        wchar_t *pwstr,
        int len)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pStringManager, pwstr, len);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}
