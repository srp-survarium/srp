void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteGetInstanceAtDepth(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::DisplayObjContainer *Target; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  int v5; // eax
  Scaleform::GFx::DisplayObjectBase *CharacterAtDepth; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-Ch]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::DisplayObjContainer *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = (Scaleform::GFx::DisplayObjContainer *)fn->Env->Target;
  }
  if ( Target && fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v5 = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
    CharacterAtDepth = Scaleform::GFx::DisplayObjContainer::GetCharacterAtDepth(Target, v5 + 0x4000);
    if ( CharacterAtDepth )
      Scaleform::GFx::AS2::Value::SetAsCharacter(
        fn->Result,
        LOBYTE(CharacterAtDepth->Flags) >> 7 != 0 ? (Scaleform::GFx::InteractiveObject *)CharacterAtDepth : 0);
  }
}
