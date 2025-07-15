Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS2::Value::ToCharacter(
        Scaleform::GFx::AS2::Value *this,
        const Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  Scaleform::GFx::InteractiveObject *v3; // eax

  if ( this->T.Type == 7
    && penv
    && (pStringNode = this->V.pStringNode) != 0
    && (v3 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
               (Scaleform::GFx::CharacterHandle *)pStringNode,
               penv->Target->pASRoot->pMovieImpl)) != 0 )
  {
    return LOBYTE(v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0 ? v3 : 0;
  }
  else
  {
    return 0;
  }
}
