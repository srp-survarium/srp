void __cdecl Scaleform::GFx::AS2::FunctionProto::Apply(Scaleform::GFx::AS2::RefCountBaseGC<323> *fn)
{
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // esi
  _DWORD *RootIndex; // edx
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v5; // eax
  Scaleform::GFx::AS2::ObjectInterface *v6; // eax
  Scaleform::GFx::AS2::ObjectInterface *v7; // esi
  Scaleform::RefCountNTSImpl *v8; // esi
  Scaleform::GFx::AS2::Object *v9; // eax
  _DWORD *v10; // edx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // ecx
  Scaleform::GFx::AS2::Object *v13; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // ebp
  int RefCount; // eax
  int i; // ebx
  unsigned int v17; // esi
  Scaleform::GFx::AS2::Value *v18; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v19; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // esi
  Scaleform::GFx::AS2::Environment *v21; // eax
  signed int v22; // ebp
  int v23; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v24; // edx
  unsigned int v25; // ecx
  unsigned int v26; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v27; // esi
  Scaleform::GFx::AS2::Environment *v28; // eax
  int v29; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v30; // eax
  void (__thiscall *Finalize_GC)(Scaleform::GFx::AS2::RefCountBaseGC<323> *); // edx
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int v34; // eax
  Scaleform::GFx::AS2::Environment *v35; // [esp-4h] [ebp-5Ch]
  Scaleform::GFx::AS2::ObjectInterface *v36; // [esp+10h] [ebp-48h]
  unsigned int n; // [esp+14h] [ebp-44h]
  Scaleform::RefCountNTSImpl *v38; // [esp+18h] [ebp-40h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *p_pProto; // [esp+1Ch] [ebp-3Ch]
  Scaleform::GFx::AS2::Value *v; // [esp+20h] [ebp-38h]
  Scaleform::GFx::AS2::Value v41; // [esp+24h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v42; // [esp+34h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v43; // [esp+5Ch] [ebp+4h]

  pRCC = fn->pRCC;
  p_pProto = 0;
  v38 = 0;
  v36 = 0;
  n = 0;
  Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)pRCC);
  LOBYTE(pRCC->__vftable) = 0;
  v43 = 0;
  if ( (int)fn[1].RefCount < 1 )
    goto LABEL_20;
  RootIndex = (_DWORD *)fn[1].RootIndex;
  v4 = 0;
  if ( fn[2].__vftable <= (Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *)(32 * (RootIndex[6] - 1)
                                                                          + ((RootIndex[1] - RootIndex[2]) >> 4)) )
    v4 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(RootIndex[5] + 4 * ((unsigned int)fn[2].__vftable >> 5))
                                      + 16 * ((int)fn[2].__vftable & 0x1F));
  v35 = (Scaleform::GFx::AS2::Environment *)fn[1].RootIndex;
  if ( v4->T.Type == 7 )
  {
    v5 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v4, v35);
    if ( v5 )
    {
      v6 = &v5->Scaleform::GFx::AS2::ObjectInterface;
      goto LABEL_7;
    }
LABEL_15:
    v36 = 0;
    goto LABEL_20;
  }
  v9 = Scaleform::GFx::AS2::Value::ToObject(v4, v35);
  if ( !v9 )
    goto LABEL_15;
  v6 = &v9->Scaleform::GFx::AS2::ObjectInterface;
LABEL_7:
  v36 = v6;
  if ( v6 )
  {
    v7 = v6;
    if ( (unsigned int)(v6->GetObjectType(v6) - 2) > 3 )
    {
      if ( v7 != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        v7[-1].pProto.pObject = (Scaleform::GFx::AS2::Object *)(((int)&v7[-1].pProto.pObject->__vftable + 1) & 0x8FFFFFFF);
      p_pProto = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7[-2].pProto;
    }
    else if ( (unsigned int)(v7->GetObjectType(v7) - 2) > 3 )
    {
      v38 = 0;
    }
    else
    {
      v8 = (Scaleform::RefCountNTSImpl *)v7[1].__vftable;
      if ( v8 )
        ++v8->RefCount;
      v38 = v8;
    }
  }
LABEL_20:
  if ( (int)fn[1].RefCount >= 2 )
  {
    v10 = (_DWORD *)fn[1].RootIndex;
    v11 = (unsigned int)&fn[2].__vftable[-1].~Scaleform::GFx::AS2::RefCountBaseGC<323> + 3;
    v12 = 0;
    if ( v11 <= 32 * (v10[6] - 1) + ((v10[1] - v10[2]) >> 4) )
      v12 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v10[5] + 4 * (v11 >> 5)) + 16 * (v11 & 0x1F));
    v13 = Scaleform::GFx::AS2::Value::ToObject(v12, (Scaleform::GFx::AS2::Environment *)fn[1].RootIndex);
    v14 = v13;
    if ( v13 )
    {
      if ( v13->GetObjectType(&v13->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
      {
        RefCount = v14[3].RefCount;
        v14->RefCount = (v14->RefCount + 1) & 0x8FFFFFFF;
        v43 = v14;
        n = RefCount;
        if ( RefCount > 0 )
        {
          for ( i = RefCount - 1; i >= 0; --i )
          {
            v17 = fn[1].RootIndex;
            v18 = *(Scaleform::GFx::AS2::Value **)(v14[3].RootIndex + 4 * i);
            *(_DWORD *)(v17 + 4) += 16;
            v19 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v17 + 4);
            v = v18;
            if ( v19->pCurrent >= v19->pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v19);
            pCurrent = v19->pCurrent;
            if ( pCurrent )
              Scaleform::GFx::AS2::Value::Value(pCurrent, v);
          }
        }
      }
    }
  }
  v41.T.Type = 0;
  if ( fn->RefCount )
  {
    v21 = (Scaleform::GFx::AS2::Environment *)fn[1].RootIndex;
    v22 = n;
    v23 = v21->Stack.pCurrent - v21->Stack.pPageStart + 32 * v21->Stack.Pages.Data.Size - 32;
    v42.Result = &v41;
    v42.ThisPtr = v36;
    v24 = fn[1].__vftable;
    v42.FirstArgBottomIndex = v23;
    v25 = fn->RefCount;
    v42.Env = v21;
    v42.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    memset(&v42.ThisFunctionRef, 0, 9);
    v42.NArgs = n;
    (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS2::FnCall *, Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *, _DWORD))(*(_DWORD *)v25 + 40))(
      v25,
      &v42,
      v24,
      0);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v42);
  }
  else
  {
    v26 = fn->RootIndex;
    if ( v26 )
    {
      v27 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)(v26 - 16);
      if ( v27 )
        v27->RefCount = (v27->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      v27 = 0;
    }
    v28 = (Scaleform::GFx::AS2::Environment *)fn[1].RootIndex;
    v22 = n;
    v29 = v28->Stack.pCurrent - v28->Stack.pPageStart + 32 * v28->Stack.Pages.Data.Size - 32;
    v42.Result = &v41;
    v42.FirstArgBottomIndex = v29;
    v42.Env = v28;
    v30 = v27->__vftable;
    v42.ThisPtr = v36;
    Finalize_GC = v30[3].Finalize_GC;
    v42.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    memset(&v42.ThisFunctionRef, 0, 9);
    v42.NArgs = n;
    ((void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::FnCall *, _DWORD, _DWORD))Finalize_GC)(
      v27,
      &v42,
      0,
      0);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v42);
    v32 = v27->RefCount;
    if ( (v32 & 0x3FFFFFF) != 0 )
    {
      v27->RefCount = v32 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v27);
    }
  }
  if ( v22 > 0 )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(
      (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(fn[1].RootIndex + 4),
      v22);
  Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)fn->pRCC, &v41);
  if ( v41.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v41);
  if ( v43 )
  {
    v33 = v43->RefCount;
    if ( (v33 & 0x3FFFFFF) != 0 )
    {
      v43->RefCount = v33 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v43);
    }
  }
  if ( v38 )
    Scaleform::RefCountNTSImpl::Release(v38);
  if ( p_pProto )
  {
    v34 = p_pProto->RefCount;
    if ( (v34 & 0x3FFFFFF) != 0 )
    {
      p_pProto->RefCount = v34 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
    }
  }
}
