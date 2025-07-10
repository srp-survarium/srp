Scaleform::GFx::ASString *__usercall Scaleform::GFx::AS3::InstanceTraits::fl::CreateStringFromCStr@<eax>(
        char *start@<edx>,
        const char *end@<eax>,
        Scaleform::GFx::ASStringNode **a3@<esi>,
        Scaleform::GFx::AS3::StringManager *sm)
{
  signed int v4; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax

  if ( end )
    v4 = end - start;
  else
    v4 = strlen(start);
  if ( v4 <= 0 )
  {
    pStringManager = sm->pStringManager;
    ++pStringManager->EmptyStringNode.RefCount;
    *a3 = &pStringManager->EmptyStringNode;
  }
  else
  {
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, start, v4);
    ++StringNode->RefCount;
    *a3 = StringNode;
  }
  return (Scaleform::GFx::ASString *)a3;
}
