Scaleform::GFx::ASString *__thiscall Scaleform::GFx::ASStringManager::CreateConstString(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASString *result,
        char *pstr)
{
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax

  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(this, pstr, strlen(pstr), 0);
  ++ConstStringNode->RefCount;
  result->pNode = ConstStringNode;
  return result;
}
