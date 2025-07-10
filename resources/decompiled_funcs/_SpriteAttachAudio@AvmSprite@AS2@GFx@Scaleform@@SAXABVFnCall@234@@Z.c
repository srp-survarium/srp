void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteAttachAudio(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::DisplayObject *Target; // edi
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::Object *v9; // ebx
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::RefCountVImpl *v11; // eax
  Scaleform::RefCountVImpl *v12; // esi
  int v13; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-10h]

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  ThisPtr = v1->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(v1->ThisPtr) == Object_Sprite )
      Target = (Scaleform::GFx::DisplayObject *)ThisPtr[1].__vftable;
    else
      Target = 0;
  }
  else
  {
    Target = v1->Env->Target;
  }
  if ( Target )
  {
    if ( v1->NArgs >= 1 )
    {
      Env = v1->Env;
      v7 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      v8 = Scaleform::GFx::AS2::Value::ToObject(v7, Env);
      v9 = v8;
      if ( v8 )
      {
        if ( v8->GetObjectType(&v8->Scaleform::GFx::AS2::ObjectInterface) == Object_NetStream )
        {
          pMovieImpl = v1->Env->Target->pASRoot->pMovieImpl;
          v11 = (Scaleform::RefCountVImpl *)pMovieImpl->GetStateAddRef(
                                              &pMovieImpl->Scaleform::GFx::StateBag,
                                              State_Video);
          v12 = v11;
          if ( v11 )
          {
            Scaleform::RefCountImpl::Release(v11);
            if ( ((int (__thiscall *)(Scaleform::RefCountVImpl *))v12->AddRef)(v12) )
            {
              v13 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v12->AddRef)(v12);
              (*(void (__thiscall **)(int, Scaleform::GFx::AS2::Object *, Scaleform::GFx::DisplayObject *))(*(_DWORD *)v13 + 12))(
                v13,
                v9,
                Target);
            }
          }
        }
      }
    }
    else
    {
      Name = Scaleform::GFx::DisplayObject::GetName(Target, (Scaleform::GFx::ASString *)&fn);
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "%s.attachAudio() needs one Argument",
        Name->pNode->pData);
      v6 = (Scaleform::GFx::ASStringNode *)fn;
      --fn->ThisFunctionRef.Function;
      if ( !v6->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    }
  }
}
