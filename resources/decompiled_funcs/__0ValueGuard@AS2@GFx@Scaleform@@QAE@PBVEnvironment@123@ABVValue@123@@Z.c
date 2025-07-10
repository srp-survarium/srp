void __thiscall Scaleform::GFx::AS2::ValueGuard::ValueGuard(
        Scaleform::GFx::AS2::ValueGuard *this,
        const Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::GFx::InteractiveObject *v6; // ecx

  this->pEnv = penv;
  Scaleform::GFx::AS2::Value::Value(&this->mValue, val);
  if ( val->T.Type == 7 )
  {
    if ( this->pEnv
      && (pStringNode = val->V.pStringNode) != 0
      && (v5 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
                 (Scaleform::GFx::CharacterHandle *)pStringNode,
                 this->pEnv->Target->pASRoot->pMovieImpl)) != 0 )
    {
      v6 = LOBYTE(v5->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0 ? v5 : 0;
    }
    else
    {
      v6 = 0;
    }
    this->pChar = v6;
    if ( v6 )
      ++v6->RefCount;
  }
  else
  {
    this->pChar = 0;
  }
}
