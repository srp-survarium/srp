void __cdecl Scaleform::GFx::AS2::ColorTransformCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::AS2::Value *v10; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-Ch]
  Scaleform::GFx::AS2::Environment *v13; // [esp-8h] [ebp-Ch]
  Scaleform::GFx::AS2::Environment *v14; // [esp-8h] [ebp-Ch]
  Scaleform::GFx::AS2::Environment *v15; // [esp-8h] [ebp-Ch]
  Scaleform::GFx::AS2::Environment *v16; // [esp-8h] [ebp-Ch]
  Scaleform::GFx::AS2::Environment *v17; // [esp-8h] [ebp-Ch]
  Scaleform::GFx::AS2::Environment *v18; // [esp-8h] [ebp-Ch]
  Scaleform::GFx::AS2::Environment *v19; // [esp-8h] [ebp-Ch]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_ColorTransform )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      p_pProto = 0;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, p_pProto);
    if ( fn->NArgs > 7 )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      *(float *)&p_pProto[1].RefCount = Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
      v13 = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      *(float *)&p_pProto[1].Scaleform::GFx::AS2::ObjectInterface::__vftable = Scaleform::GFx::AS2::Value::ToNumber(
                                                                                 v4,
                                                                                 v13);
      v14 = fn->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
      *(float *)&p_pProto[1].pUserDataHolder = Scaleform::GFx::AS2::Value::ToNumber(v5, v14);
      v15 = fn->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
      *(float *)&p_pProto[1].pProto.pObject = Scaleform::GFx::AS2::Value::ToNumber(v6, v15);
      v16 = fn->Env;
      v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
      *(float *)&p_pProto[1].Members.mHash.pTable = Scaleform::GFx::AS2::Value::ToNumber(v7, v16);
      v17 = fn->Env;
      v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
      *(float *)&p_pProto[1].ResolveHandler.Function = Scaleform::GFx::AS2::Value::ToNumber(v8, v17);
      v18 = fn->Env;
      v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 6);
      *(float *)&p_pProto[1].ResolveHandler.pLocalFrame = Scaleform::GFx::AS2::Value::ToNumber(v9, v18);
      v19 = fn->Env;
      v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 7);
      *(float *)&p_pProto[1].ResolveHandler.Flags = Scaleform::GFx::AS2::Value::ToNumber(v10, v19);
    }
    if ( p_pProto )
    {
      RefCount = p_pProto->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        p_pProto->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
      }
    }
  }
}
