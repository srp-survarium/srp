void __cdecl Scaleform::GFx::AS2::StyleSheetProto::Transform(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Value *v2; // eax
  Scaleform::GFx::AS2::Object *v3; // ebx
  Scaleform::GFx::AS2::TextFormatObject *v4; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS2::CSSTextFormatLoader tfl; // [esp+10h] [ebp-Ch] BYREF

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
          v4 = (Scaleform::GFx::AS2::TextFormatObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                          fn->Env,
                                                          fn->Env->StringContext.pContext->pGlobal.pObject,
                                                          (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[14].pASSupport,
                                                          0,
                                                          -1);
          tfl.pEnv = fn->Env;
          tfl.__vftable = (Scaleform::GFx::AS2::CSSTextFormatLoader_vtbl *)&Scaleform::GFx::AS2::CSSTextFormatLoader::`vftable';
          tfl.pTFO = v4;
          v3->VisitMembers(&v3->Scaleform::GFx::AS2::ObjectInterface, &tfl.pEnv->StringContext, &tfl, 0, 0);
          Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
          tfl.__vftable = (Scaleform::GFx::AS2::CSSTextFormatLoader_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
          if ( v4 )
          {
            RefCount = v4->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
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
