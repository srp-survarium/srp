void __cdecl Scaleform::GFx::AS2::ObjectProto::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
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
  Scaleform::GFx::AS2::Value res; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+1Ch] [ebp-10h] BYREF

  v1 = fn;
  if ( fn->NArgs < 1 )
    goto LABEL_26;
  Env = fn->Env;
  v3 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  Type = v3->T.Type;
  res.T.Type = 0;
  switch ( Type )
  {
    case 3u:
    case 4u:
      v.T.Type = 3;
      v.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
      Scaleform::GFx::AS2::Value::operator=(&res, &v);
      goto LABEL_9;
    case 2u:
      v.T.Type = 2;
      v.V.BooleanValue = Scaleform::GFx::AS2::Value::ToBool(v3, Env);
      Scaleform::GFx::AS2::Value::operator=(&res, &v);
LABEL_9:
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      break;
    case 5u:
      Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
      v5 = (Scaleform::GFx::ASStringNode *)fn;
      ++fn->ThisFunctionRef.Function;
      v.T.Type = 5;
      v.NV.Int32Value = (int)v5;
      Scaleform::GFx::AS2::Value::operator=(&res, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      if ( v5->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      break;
    case 6u:
    case 7u:
      Scaleform::GFx::AS2::Value::operator=(&res, v3);
      break;
    default:
      goto LABEL_26;
  }
  if ( res.T.Type && res.T.Type != 10 )
  {
    Scaleform::GFx::AS2::Value::operator=(v1->Result, &res);
    if ( res.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&res);
    return;
  }
  if ( res.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&res);
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
  Scaleform::GFx::AS2::Environment::GetConstructor(v1->Env, (Scaleform::GFx::AS2::FunctionRef *)&res, ASBuiltin_Object);
  Scaleform::GFx::AS2::ObjectInterface::Set_constructor(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    &v1->Env->StringContext,
    (const Scaleform::GFx::AS2::FunctionRef *)&res);
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, p_pProto);
  v12 = BYTE4(res.NV.NumberValue);
  if ( (BYTE4(res.NV.NumberValue) & 2) == 0 )
  {
    v13 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&res.T.Type;
    if ( *(_DWORD *)&res.T.Type )
    {
      v14 = *(_DWORD *)(*(_DWORD *)&res.T.Type + 12);
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v14) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)&res.T.Type + 12) = v14 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
      }
    }
  }
  if ( (v12 & 1) == 0 )
  {
    pStringNode = res.V.pStringNode;
    if ( res.NV.Int32Value )
    {
      v16 = *(_DWORD *)(res.NV.Int32Value + 12);
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v16) != 0 )
      {
        *(_DWORD *)(res.NV.Int32Value + 12) = v16 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
      }
    }
  }
  if ( p_pProto )
  {
    RefCount = p_pProto->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      p_pProto->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
    }
  }
}
