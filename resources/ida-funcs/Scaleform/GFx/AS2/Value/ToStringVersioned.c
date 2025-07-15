Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS2::Value::ToStringVersioned(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int version)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::ASString *v5; // eax

  if ( this->T.Type && this->T.Type != 10 )
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(this, result, penv, -1, 0);
    return result;
  }
  else
  {
    if ( version - 1 > 5 )
      pMovieImpl = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[18].pMovieImpl;
    else
      pMovieImpl = (Scaleform::GFx::MovieImpl *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
    v5 = result;
    result->pNode = (Scaleform::GFx::ASStringNode *)pMovieImpl;
    ++pMovieImpl->pASMovieRoot.pObject;
  }
  return v5;
}
