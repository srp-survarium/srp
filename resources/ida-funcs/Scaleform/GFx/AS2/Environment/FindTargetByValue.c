Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS2::Environment::FindTargetByValue(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASStringNode *val)
{
  Scaleform::GFx::ASStringManager *pManager; // ecx
  Scaleform::GFx::InteractiveObject *v4; // eax
  Scaleform::GFx::InteractiveObject *Target; // eax
  Scaleform::GFx::ASStringNode *v7; // ecx
  bool v8; // zf
  Scaleform::GFx::InteractiveObject *v9; // esi

  if ( LOBYTE(val->pData) == 7 )
  {
    if ( this )
    {
      pManager = val->pManager;
      if ( pManager )
      {
        v4 = Scaleform::GFx::CharacterHandle::ResolveCharacter(
               (Scaleform::GFx::CharacterHandle *)pManager,
               this->Target->pASRoot->pMovieImpl);
        if ( v4 )
          return LOBYTE(v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7 != 0 ? v4 : 0;
      }
    }
    return 0;
  }
  if ( LOBYTE(val->pData) != 5 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(this, "Invalid movie clip path; neither string nor object");
    return 0;
  }
  Scaleform::GFx::AS2::Value::ToStringImpl(
    (Scaleform::GFx::AS2::Value *)val,
    (Scaleform::GFx::ASString *)&val,
    this,
    -1,
    0);
  Target = Scaleform::GFx::AS2::Environment::FindTarget(this, (const Scaleform::GFx::ASString *)&val, 0);
  v7 = val;
  v8 = val->RefCount-- == 1;
  v9 = Target;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  return v9;
}
