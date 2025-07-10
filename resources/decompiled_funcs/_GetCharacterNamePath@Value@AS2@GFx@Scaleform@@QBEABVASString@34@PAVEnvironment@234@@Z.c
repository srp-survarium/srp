const Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS2::Value::GetCharacterNamePath(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *pStringNode; // ecx

  pStringNode = this->V.pStringNode;
  if ( pStringNode
    && Scaleform::GFx::CharacterHandle::ResolveCharacter(
         (Scaleform::GFx::CharacterHandle *)pStringNode,
         penv->Target->pASRoot->pMovieImpl) )
  {
    return (const Scaleform::GFx::ASString *)(this->NV.Int32Value + 12);
  }
  else
  {
    return (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  }
}
