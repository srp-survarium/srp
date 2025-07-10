Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASString::operator+(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result,
        const Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (char *)this->pNode->pData,
                 this->pNode->Size,
                 (char *)str->pNode->pData,
                 (Scaleform::GFx::ASStringNode *)str->pNode->Size);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}
