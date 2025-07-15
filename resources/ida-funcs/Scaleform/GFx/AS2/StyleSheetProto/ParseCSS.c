void __cdecl Scaleform::GFx::AS2::StyleSheetProto::ParseCSS(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebx
  Scaleform::GFx::AS2::Value *v4; // esi
  const Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // edi
  bool v7; // al
  Scaleform::GFx::AS2::Value *Result; // esi
  bool v9; // bl
  Scaleform::GFx::AS2::Value v11; // [esp+4h] [ebp-10h] BYREF

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_StyleSheet )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        if ( v1->NArgs >= 1 )
        {
          v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
          Scaleform::GFx::AS2::Value::Value(&v11, v5);
          Scaleform::GFx::AS2::Value::ToStringImpl(&v11, (Scaleform::GFx::ASString *)&fn, v1->Env, -1, 0);
          v6 = (Scaleform::GFx::ASStringNode *)fn;
          v7 = Scaleform::GFx::Text::StyleManager::ParseCSS(
                 (Scaleform::GFx::Text::StyleManager *)&p_pProto[13],
                 (const char *)fn->__vftable,
                 *(_DWORD *)&fn->ThisFunctionRef.Flags);
          Result = v1->Result;
          v9 = v7;
          Scaleform::GFx::AS2::Value::DropRefs(Result);
          Result->T.Type = 2;
          Result->V.BooleanValue = v9;
          if ( v6->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v6);
          if ( v11.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v11);
        }
        else
        {
          v4 = v1->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v4);
          v4->T.Type = 2;
          v4->V.BooleanValue = 0;
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "StyleSheet");
  }
}
