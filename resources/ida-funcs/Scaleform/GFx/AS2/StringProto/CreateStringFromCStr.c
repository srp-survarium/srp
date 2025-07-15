Scaleform::GFx::ASString *__cdecl Scaleform::GFx::AS2::StringProto::CreateStringFromCStr(
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::ASStringContext *psc,
        __m128i *start,
        const char *end)
{
  signed int v4; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASString *v6; // eax
  Scaleform::GFx::ASStringNode *RefCount; // ecx

  if ( end )
    v4 = end - (const char *)start;
  else
    v4 = strlen(start->m128i_i8);
  if ( v4 <= 0 )
  {
    RefCount = (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
    v6 = result;
    ++RefCount->RefCount;
    result->pNode = RefCount;
  }
  else
  {
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                   (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                   start,
                   v4);
    ++StringNode->RefCount;
    result->pNode = StringNode;
    return result;
  }
  return v6;
}
