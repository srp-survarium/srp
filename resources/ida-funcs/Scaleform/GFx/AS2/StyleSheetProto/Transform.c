void __cdecl Scaleform::GFx::AS2::StyleSheetProto::Transform(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Value *v2; // eax
  Scaleform::GFx::AS2::Object *v3; // ebx
  Scaleform::GFx::AS2::Object *v4; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+4h] [ebp-18h]
  void **v7; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::GFx::AS2::Environment *v8; // [esp+14h] [ebp-8h]
  Scaleform::GFx::AS2::Object *v9; // [esp+18h] [ebp-4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_StyleSheet )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 && fn->NArgs >= 1 )
      {
        Env = fn->Env;
        v2 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v3 = Scaleform::GFx::AS2::Value::ToObject(v2, Env);
        if ( v3 )
        {
          v4 = Scaleform::GFx::AS2::Environment::OperatorNew(
                 fn->Env,
                 fn->Env->StringContext.pContext->pGlobal.pObject,
                 (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[14].pASSupport,
                 0,
                 -1);
          v8 = fn->Env;
          v7 = &Scaleform::GFx::AS2::CSSTextFormatLoader::`vftable';
          v9 = v4;
          v3->VisitMembers(
            &v3->Scaleform::GFx::AS2::ObjectInterface,
            &v8->StringContext,
            (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)&v7,
            0,
            0);
          Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
          v7 = &Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
          if ( v4 )
          {
            RefCount = v4->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              v4->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
            }
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "StyleSheet");
  }
}
