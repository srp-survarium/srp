void __cdecl Scaleform::GFx::AS2::AvmSprite::SpriteDuplicateMovieClip(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::DisplayObjectBase *Target; // ebx
  Scaleform::GFx::DisplayObjectBase *v5; // edi
  int NArgs; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  const Scaleform::GFx::AS2::ObjectInterface *v8; // ebp
  Scaleform::GFx::AS2::Value *v9; // eax
  int v10; // eax
  Scaleform::GFx::AS2::AvmCharacter *v11; // edi
  Scaleform::GFx::AS2::Value *v12; // eax
  int v13; // eax
  Scaleform::GFx::InteractiveObject *v14; // eax
  Scaleform::GFx::InteractiveObject *v15; // edi
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::AS2::Environment *v17; // [esp-10h] [ebp-1Ch]
  Scaleform::GFx::AS2::Environment *v18; // [esp-Ch] [ebp-18h]
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-14h]

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  ThisPtr = v1->ThisPtr;
  if ( ThisPtr )
  {
    if ( ThisPtr->GetObjectType(v1->ThisPtr) == Object_Sprite )
      v5 = (Scaleform::GFx::DisplayObjectBase *)ThisPtr[1].__vftable;
    else
      v5 = 0;
    Target = v5;
  }
  else
  {
    Target = v1->Env->Target;
  }
  if ( Target )
  {
    NArgs = v1->NArgs;
    if ( NArgs >= 2 )
    {
      if ( NArgs == 3 )
      {
        Env = v1->Env;
        v7 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        v8 = Scaleform::GFx::AS2::Value::ToObjectInterface(v7, Env);
      }
      else
      {
        v8 = 0;
      }
      v17 = v1->Env;
      v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v9, (Scaleform::GFx::ASString *)&fn, v17, -1, 0);
      v10 = (*(int (__thiscall **)(int))(*((_DWORD *)&Target->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + Target->AvmObjOffset)
                                       + 4))((int)Target + 4 * Target->AvmObjOffset);
      v18 = v1->Env;
      v11 = (Scaleform::GFx::AS2::AvmCharacter *)v10;
      v12 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      v13 = (int)Scaleform::GFx::AS2::Value::ToNumber(v12, v18);
      v14 = Scaleform::GFx::AS2::AvmCharacter::CloneDisplayObject(
              v11,
              (const Scaleform::GFx::ASString *)&fn,
              v13 + 0x4000,
              v8);
      v15 = v14;
      if ( v14 )
        ++v14->RefCount;
      v16 = (Scaleform::GFx::ASStringNode *)fn;
      --fn->ThisFunctionRef.Function;
      if ( !v16->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(Target) >= 6 )
        Scaleform::GFx::AS2::Value::SetAsCharacter(v1->Result, v15);
      if ( v15 )
        Scaleform::RefCountNTSImpl::Release(v15);
    }
  }
}
