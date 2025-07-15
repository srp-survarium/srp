void __cdecl Scaleform::GFx::AS2::XmlProto::CreateElement(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Value *v2; // eax
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // edi
  const Scaleform::GFx::AS2::Value *v5; // ebx
  Scaleform::GFx::AS2::Environment *v6; // edi
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v8; // edi
  Scaleform::GFx::AS2::Value *pCurrent; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::AS2::Object *v11; // edi
  Scaleform::GFx::AS2::Environment *v12; // esi
  Scaleform::GFx::AS2::Value *v13; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v14; // esi
  int v15; // ebp
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString classname; // [esp+4h] [ebp-4h] BYREF

  if ( Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu) )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr && ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
    {
      v2 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Env = fn->Env;
      ++Env->Stack.pCurrent;
      p_Stack = &Env->Stack;
      v5 = v2;
      if ( p_Stack->pCurrent >= p_Stack->pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
      if ( p_Stack->pCurrent )
        Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, v5);
      v6 = fn->Env;
      v7 = ++v6->Stack.pCurrent;
      v8 = &v6->Stack;
      if ( v7 >= v8->pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v8);
      pCurrent = v8->pCurrent;
      if ( pCurrent )
      {
        pCurrent->T.Type = 4;
        pCurrent->NV.Int32Value = 1;
      }
      StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(fn->Env->StringContext.pContext);
      classname.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          StringManager->pStringManager,
                          "XMLNode",
                          7u,
                          0);
      ++classname.pNode->RefCount;
      v11 = Scaleform::GFx::AS2::Environment::OperatorNew(
              fn->Env,
              fn->Env->StringContext.pContext->pGlobal.pObject,
              &classname,
              2,
              -1);
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v11);
      v12 = fn->Env;
      v13 = v12->Stack.pCurrent;
      v14 = &v12->Stack;
      if ( &v13[-2] >= v14->pPageStart )
      {
        Scaleform::GFx::AS2::Value::~Value(v13);
        Scaleform::GFx::AS2::Value::~Value(--v14->pCurrent);
        --v14->pCurrent;
      }
      else
      {
        v15 = 2;
        do
        {
          Scaleform::GFx::AS2::Value::~Value(v14->pCurrent);
          if ( --v14->pCurrent < v14->pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v14);
          --v15;
        }
        while ( v15 );
      }
      if ( v11 )
      {
        RefCount = v11->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
      pNode = classname.pNode;
      --classname.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
  else
  {
    Scaleform::GFx::AS2::FnCall::ThisPtrError(fn, "XML", 0, 0);
  }
}
