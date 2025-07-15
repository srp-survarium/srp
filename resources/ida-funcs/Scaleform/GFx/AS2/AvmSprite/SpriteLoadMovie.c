void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteLoadMovie(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::InteractiveObject *Target; // ebp
  Scaleform::GFx::InteractiveObject *v4; // esi
  int NArgs; // eax
  Scaleform::GFx::LoadQueueEntry::LoadMethod v6; // ebx
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // esi
  Scaleform::GFx::ASStringNode *v9; // eax
  bool v10; // zf
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-20h]
  Scaleform::GFx::AS2::Environment *v14; // [esp-10h] [ebp-20h]
  Scaleform::GFx::ASString v15; // [esp+Ch] [ebp-4h] BYREF

  v1 = fn;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(fn->ThisPtr) == Object_Sprite )
      v4 = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    else
      v4 = 0;
    Target = v4;
  }
  else
  {
    Target = fn->Env->Target;
  }
  if ( Target )
  {
    NArgs = v1->NArgs;
    if ( NArgs > 0 )
    {
      v6 = LM_None;
      if ( NArgs > 1 )
      {
        Env = v1->Env;
        v7 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
        Scaleform::GFx::AS2::Value::ToStringImpl(v7, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
        v8 = Scaleform::GFx::ASConstString::ToLowerNode((Scaleform::GFx::ASConstString *)&fn);
        ++v8->RefCount;
        v9 = (Scaleform::GFx::ASStringNode *)fn;
        --fn->ThisFunctionRef.Function;
        v15.pNode = v8;
        if ( !v9->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        if ( Scaleform::GFx::ASString::operator==(&v15, "get") )
        {
          v6 = LM_Get;
        }
        else if ( Scaleform::GFx::ASString::operator==(&v15, "post") )
        {
          v6 = LM_Post;
        }
        v10 = v8->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      }
      v14 = v1->Env;
      v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v11, (Scaleform::GFx::ASString *)&fn, v14, -1, 0);
      v12 = (Scaleform::GFx::ASStringNode *)fn;
      Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
        (Scaleform::GFx::AS2::MovieRoot *)Target->pASRoot,
        (Scaleform::String)Target,
        (const __m128i *)fn->__vftable,
        v6,
        0);
      v10 = v12->RefCount-- == 1;
      if ( v10 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    }
  }
}
