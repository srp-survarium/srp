Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASString::operator+(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result,
        char *pstr)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (char *)this->pNode->pData,
                 this->pNode->Size,
                 pstr,
                 (Scaleform::GFx::ASStringNode *)strlen(pstr));
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}
