void __cdecl Scaleform::GFx::AS2::GASMatrixCtorFunction::GlobalCtor(
        Scaleform::Ptr<Scaleform::GFx::AS2::MatrixObject> fn)
{
  Scaleform::GFx::AS2::ObjectInterface *RootIndex; // eax
  Scaleform::GFx::AS2::MatrixObject *p_pProto; // eax
  Scaleform::GFx::AS2::Object *v4; // ebp
  Scaleform::MemoryHeap *v5; // ecx
  Scaleform::GFx::AS2::MatrixObject *v6; // eax
  Scaleform::GFx::AS2::MatrixObject *v7; // eax
  Scaleform::GFx::AS2::Environment *pObject; // eax
  const Scaleform::GFx::AS2::Value *v9; // edx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebx
  Scaleform::GFx::AS2::ObjectInterface *v11; // edi
  const Scaleform::GFx::AS2::Value *v12; // eax
  const Scaleform::GFx::AS2::Value *v13; // eax
  const Scaleform::GFx::AS2::Value *v14; // eax
  const Scaleform::GFx::AS2::Value *v15; // eax
  const Scaleform::GFx::AS2::Value *v16; // eax
  unsigned int RefCount; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::MatrixObject> pmatrix; // [esp+Ch] [ebp+4h]

  if ( fn.pObject->RootIndex
    && (*(int (__thiscall **)(unsigned int))(*(_DWORD *)fn.pObject->RootIndex + 8))(fn.pObject->RootIndex) == 15
    && !(*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)fn.pObject->RootIndex + 64))(fn.pObject->RootIndex) )
  {
    RootIndex = (Scaleform::GFx::AS2::ObjectInterface *)fn.pObject->RootIndex;
    if ( RootIndex )
    {
      p_pProto = (Scaleform::GFx::AS2::MatrixObject *)&RootIndex[-2].pProto;
      if ( p_pProto )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
      v4 = p_pProto;
      pmatrix.pObject = p_pProto;
    }
    else
    {
      v4 = 0;
      pmatrix.pObject = 0;
    }
  }
  else
  {
    v5 = *(Scaleform::MemoryHeap **)(fn.pObject->pProto.pObject[2].RefCount + 24);
    v6 = (Scaleform::GFx::AS2::MatrixObject *)v5->Alloc(v5, 52u, 0);
    if ( v6 )
      Scaleform::GFx::AS2::MatrixObject::MatrixObject(
        v6,
        (Scaleform::GFx::AS2::Environment *)fn.pObject->pProto.pObject);
    else
      v7 = 0;
    v4 = v7;
    pmatrix.pObject = v7;
  }
  Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)fn.pObject->pRCC, v4);
  if ( (int)fn.pObject->Members.mHash.pTable > 0 )
  {
    pObject = (Scaleform::GFx::AS2::Environment *)fn.pObject->pProto.pObject;
    v9 = 0;
    p_StringContext = &pObject->StringContext;
    if ( fn.pObject->ResolveHandler.Function <= (Scaleform::GFx::AS2::FunctionObject *)(32
                                                                                      * (pObject->Stack.Pages.Data.Size
                                                                                       - 1)
                                                                                      + pObject->Stack.pCurrent
                                                                                      - pObject->Stack.pPageStart) )
      v9 = &pObject->Stack.Pages.Data.Data[(unsigned int)fn.pObject->ResolveHandler.Function >> 5]->Values[(int)fn.pObject->ResolveHandler.Function & 0x1F];
    v4 = pmatrix.pObject;
    v11 = &pmatrix.pObject->Scaleform::GFx::AS2::ObjectInterface;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      &pmatrix.pObject->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      "a",
      v9);
    if ( (int)fn.pObject->Members.mHash.pTable > 1 )
    {
      v12 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)fn.pObject, 1);
      Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, p_StringContext, "b", v12);
      if ( (int)fn.pObject->Members.mHash.pTable > 2 )
      {
        v13 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)fn.pObject, 2);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, p_StringContext, "c", v13);
        if ( (int)fn.pObject->Members.mHash.pTable > 3 )
        {
          v14 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)fn.pObject, 3);
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, p_StringContext, "d", v14);
          if ( (int)fn.pObject->Members.mHash.pTable > 4 )
          {
            v15 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)fn.pObject, 4);
            Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, p_StringContext, "tx", v15);
            if ( (int)fn.pObject->Members.mHash.pTable > 5 )
            {
              v16 = Scaleform::GFx::AS2::FnCall::Arg((Scaleform::GFx::AS2::FnCall *)fn.pObject, 5);
              Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(v11, p_StringContext, "ty", v16);
            }
          }
        }
      }
    }
  }
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
