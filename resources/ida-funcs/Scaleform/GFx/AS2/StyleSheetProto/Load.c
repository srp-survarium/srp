void __cdecl Scaleform::GFx::AS2::StyleSheetProto::Load(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebp
  Scaleform::GFx::AS2::Object *p_pProto; // ebp
  Scaleform::GFx::AS2::Value *v4; // esi
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::Resource *v6; // eax
  Scaleform::GFx::Resource *v7; // edi
  Scaleform::GFx::ASStringNode *v8; // ebx
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-14h] [ebp-1Ch]

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_StyleSheet )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        if ( v1->NArgs )
        {
          Env = v1->Env;
          v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
          Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
          p_pProto[1].pUserDataHolder = (Scaleform::GFx::AS2::ObjectInterface::UserDataHolder *)1;
          v6 = (Scaleform::GFx::Resource *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 20, 0);
          if ( v6 )
          {
            v6->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
            v6->RefCount.Value = 1;
            v6->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl::`vftable';
            v6->pLib = 0;
            v6[1].__vftable = 0;
            v6[1].RefCount.Value = 0;
            v7 = v6;
          }
          else
          {
            v7 = 0;
          }
          v8 = (Scaleform::GFx::ASStringNode *)fn;
          Scaleform::GFx::AS2::MovieRoot::AddCssLoadQueueEntry(
            (Scaleform::GFx::AS2::MovieRoot *)v1->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
            p_pProto,
            v7,
            (char *)fn->__vftable,
            LM_None);
          Result = v1->Result;
          Scaleform::GFx::AS2::Value::DropRefs(Result);
          Result->T.Type = 2;
          Result->V.BooleanValue = 1;
          if ( v7 )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
          if ( v8->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v8);
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
