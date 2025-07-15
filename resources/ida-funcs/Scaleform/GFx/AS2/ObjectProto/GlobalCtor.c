void __cdecl Scaleform::GFx::AS2::ObjectProto::GlobalCtor(Scaleform::GFx::ASStringNode *a1)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::Environment *pData; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  unsigned __int8 Type; // dl
  Scaleform::GFx::ASStringNode *v5; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v10; // eax
  Scaleform::GFx::AS2::Object *v11; // eax
  char v12; // bl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // ecx
  int v14; // eax
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  int v16; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v18; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+1Ch] [ebp-10h] BYREF

  v1 = (const Scaleform::GFx::AS2::FnCall *)a1;
  if ( (int)a1[1].pManager < 1 )
    goto LABEL_26;
  pData = (Scaleform::GFx::AS2::Environment *)a1[1].pData;
  v3 = 0;
  if ( a1[1].pLower <= (Scaleform::GFx::ASStringNode *)(32 * (pData->Stack.Pages.Data.Size - 1)
                                                      + pData->Stack.pCurrent
                                                      - pData->Stack.pPageStart) )
    v3 = &pData->Stack.Pages.Data.Data[(unsigned int)a1[1].pLower >> 5]->Values[(int)a1[1].pLower & 0x1F];
  Type = v3->T.Type;
  v18.T.Type = 0;
  switch ( Type )
  {
    case 3u:
    case 4u:
      v.T.Type = 3;
      v.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(v3, pData);
      Scaleform::GFx::AS2::Value::operator=(&v18, &v);
      goto LABEL_9;
    case 2u:
      v.T.Type = 2;
      v.V.BooleanValue = Scaleform::GFx::AS2::Value::ToBool(v3, (int)a1, pData);
      Scaleform::GFx::AS2::Value::operator=(&v18, &v);
LABEL_9:
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      break;
    case 5u:
      Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&a1, pData, -1, 0);
      v5 = a1;
      ++a1->RefCount;
      v.T.Type = 5;
      v.NV.Int32Value = (int)v5;
      Scaleform::GFx::AS2::Value::operator=(&v18, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      if ( v5->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      break;
    case 6u:
    case 7u:
      Scaleform::GFx::AS2::Value::operator=(&v18, v3);
      break;
    default:
      goto LABEL_26;
  }
  if ( v18.T.Type && v18.T.Type != 10 )
  {
    Scaleform::GFx::AS2::Value::operator=(v1->Result, &v18);
    if ( v18.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v18);
    return;
  }
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
LABEL_26:
  ThisPtr = v1->ThisPtr;
  if ( ThisPtr )
  {
    p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
    if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
  }
  else
  {
    pHeap = v1->Env->StringContext.pContext->pHeap;
    v10 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
    if ( v10 )
      Scaleform::GFx::AS2::Object::Object(v10, v1->Env);
    else
      v11 = 0;
    p_pProto = v11;
  }
  Scaleform::GFx::AS2::Environment::GetConstructor(v1->Env, (Scaleform::GFx::AS2::FunctionRef *)&v18, ASBuiltin_Object);
  Scaleform::GFx::AS2::ObjectInterface::Set_constructor(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    &v1->Env->StringContext,
    (const Scaleform::GFx::AS2::FunctionRef *)&v18);
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, p_pProto);
  v12 = BYTE4(v18.NV.NumberValue);
  if ( (BYTE4(v18.NV.NumberValue) & 2) == 0 )
  {
    v13 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v18.T.Type;
    if ( *(_DWORD *)&v18.T.Type )
    {
      v14 = *(_DWORD *)(*(_DWORD *)&v18.T.Type + 12);
      if ( (v14 & 0x3FFFFFF) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)&v18.T.Type + 12) = v14 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
  }
  if ( (v12 & 1) == 0 )
  {
    pStringNode = v18.V.pStringNode;
    if ( v18.NV.Int32Value )
    {
      v16 = *(_DWORD *)(v18.NV.Int32Value + 12);
      if ( (v16 & 0x3FFFFFF) != 0 )
      {
        *(_DWORD *)(v18.NV.Int32Value + 12) = v16 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
      }
    }
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
