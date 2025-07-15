void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteSetMask(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::InteractiveObject *Target; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::InteractiveObject *v5; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-Ch]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( Target && fn->NArgs >= 1 )
  {
    if ( Scaleform::GFx::AS2::FnCall::Arg(fn, 0)->T.Type == 1
      || (Env = fn->Env,
          v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0),
          (v5 = Scaleform::GFx::AS2::Value::ToCharacter(v4, Env)) == 0) )
    {
      Scaleform::GFx::DisplayObject::SetMask(Target, 0);
    }
    else
    {
      Scaleform::GFx::DisplayObject::SetMask(
        Target,
        (v5->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? v5 : 0);
    }
  }
}
