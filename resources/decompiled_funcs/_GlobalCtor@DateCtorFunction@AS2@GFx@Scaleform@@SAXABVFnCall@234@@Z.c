void __usercall Scaleform::GFx::AS2::DateCtorFunction::GlobalCtor(
        unsigned int a1@<ebx>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::DateObject *p_pProto; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::DateObject *v5; // eax
  Scaleform::GFx::AS2::DateObject *v6; // eax
  DWORD TimeZoneInformation; // eax
  int Bias; // ecx
  int NArgs; // eax
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v11; // ecx
  __int64 Date; // rax
  Scaleform::GFx::AS2::Value *v13; // eax
  char *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // ebp
  int v16; // ebx
  Scaleform::GFx::AS2::Value *v17; // eax
  Scaleform::GFx::AS2::Value *v18; // eax
  Scaleform::GFx::AS2::Value *v19; // eax
  Scaleform::GFx::AS2::Value *v20; // eax
  Scaleform::GFx::AS2::Value *v21; // eax
  Scaleform::GFx::AS2::Value *v22; // eax
  Scaleform::GFx::AS2::Value *v23; // esi
  Scaleform::GFx::ASStringNode *v24; // ecx
  bool v25; // zf
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v27; // [esp-Ch] [ebp-DCh]
  Scaleform::GFx::AS2::Environment *v28; // [esp-Ch] [ebp-DCh]
  Scaleform::GFx::AS2::Environment *v29; // [esp-Ch] [ebp-DCh]
  Scaleform::GFx::AS2::Environment *v30; // [esp-Ch] [ebp-DCh]
  Scaleform::GFx::AS2::Environment *v31; // [esp-Ch] [ebp-DCh]
  Scaleform::GFx::AS2::Environment *v32; // [esp-Ch] [ebp-DCh]
  Scaleform::GFx::AS2::Environment *v33; // [esp-Ch] [ebp-DCh]
  int y; // [esp+8h] [ebp-C8h]
  Scaleform::GFx::ASString result; // [esp+Ch] [ebp-C4h] BYREF
  int i; // [esp+10h] [ebp-C0h]
  timeb t; // [esp+14h] [ebp-BCh] BYREF
  _TIME_ZONE_INFORMATION tz; // [esp+24h] [ebp-ACh] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Date )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::DateObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      p_pProto = 0;
    }
  }
  else
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v5 = (Scaleform::GFx::AS2::DateObject *)pHeap->Alloc(pHeap, 104u, 0);
    if ( v5 )
      Scaleform::GFx::AS2::DateObject::DateObject(v5, fn->Env);
    else
      v6 = 0;
    p_pProto = v6;
  }
  _ftime64(a1, (__timeb64 *)&t);
  TimeZoneInformation = GetTimeZoneInformation(&tz);
  Bias = tz.Bias;
  if ( TimeZoneInformation == 1 )
  {
    Bias = tz.StandardBias + tz.Bias;
  }
  else if ( TimeZoneInformation == 2 )
  {
    Bias = tz.DaylightBias + tz.Bias;
  }
  p_pProto->LocalOffset = -60000 * Bias;
  Scaleform::GFx::AS2::DateObject::SetDate(p_pProto, t.millitm + 1000 * t.time);
  NArgs = fn->NArgs;
  if ( NArgs == 1 )
  {
    Env = fn->Env;
    v11 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v11 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                          & 0x1F];
    Date = (unsigned __int64)Scaleform::GFx::AS2::Value::ToNumber(v11, fn->Env);
  }
  else
  {
    if ( NArgs < 2 )
      goto LABEL_36;
    v27 = fn->Env;
    v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v14 = (char *)(int)Scaleform::GFx::AS2::Value::ToNumber(v13, v27);
    if ( (unsigned int)v14 <= 0x63 )
      v14 += 1900;
    y = (int)v14;
    result.pNode = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS2::StartOfYear(v14);
    pNode = result.pNode;
    v28 = fn->Env;
    v16 = 0;
    v17 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
    i = (int)Scaleform::GFx::AS2::Value::ToNumber(v17, v28);
    if ( i )
      pNode = (Scaleform::GFx::ASStringNode *)((char *)result.pNode
                                             + dword_865024[12 * Scaleform::GFx::AS2::IsLeapYear(y) + i]);
    if ( fn->NArgs >= 3 )
    {
      v29 = fn->Env;
      v18 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
      pNode = (Scaleform::GFx::ASStringNode *)((char *)pNode + (int)Scaleform::GFx::AS2::Value::ToNumber(v18, v29) - 1);
    }
    if ( fn->NArgs >= 4 )
    {
      v30 = fn->Env;
      v19 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
      v16 = 3600000 * (int)Scaleform::GFx::AS2::Value::ToNumber(v19, v30);
    }
    if ( fn->NArgs >= 5 )
    {
      v31 = fn->Env;
      v20 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
      v16 += 60000 * (int)Scaleform::GFx::AS2::Value::ToNumber(v20, v31);
    }
    if ( fn->NArgs >= 6 )
    {
      v32 = fn->Env;
      v21 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
      v16 += 1000 * (int)Scaleform::GFx::AS2::Value::ToNumber(v21, v32);
    }
    if ( fn->NArgs >= 7 )
    {
      v33 = fn->Env;
      v22 = Scaleform::GFx::AS2::FnCall::Arg(fn, 6);
      v16 += (int)Scaleform::GFx::AS2::Value::ToNumber(v22, v33);
    }
    p_pProto->LJDate = (char *)pNode - (char *)result.pNode;
    p_pProto->LYear = y;
    p_pProto->LTime = v16;
    p_pProto->LDate = v16 + 86400000LL * (int)pNode;
    Scaleform::GFx::AS2::DateObject::UpdateGMT(p_pProto);
    Date = p_pProto->Date;
  }
  Scaleform::GFx::AS2::DateObject::SetDate(p_pProto, Date);
LABEL_36:
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, p_pProto);
  Scaleform::GFx::AS2::Value::ToStringImpl(fn->Result, &result, fn->Env, -1, 0);
  v23 = fn->Result;
  if ( v23->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v23);
  v24 = result.pNode;
  v23->T.Type = 5;
  v23->NV.Int32Value = (int)v24;
  v25 = ++v24->RefCount == 1;
  --v24->RefCount;
  if ( v25 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  RefCount = p_pProto->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
}
