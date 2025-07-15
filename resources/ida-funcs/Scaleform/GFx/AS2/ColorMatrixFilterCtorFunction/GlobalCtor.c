double __cdecl Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // ebx
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::ColorMatrixFilterObject *v5; // eax
  const Scaleform::GFx::AS2::FnCall *v6; // eax
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v8; // ecx
  Scaleform::GFx::AS2::Object *v9; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::Object_vtbl *v11; // ebx
  signed int i; // edi
  int v13; // eax
  double result; // st7
  Scaleform::GFx::AS2::Environment *v15; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::ASStringNode *v17; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v19; // [esp+24h] [ebp-64h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+28h] [ebp-60h] BYREF
  _DWORD v21[20]; // [esp+38h] [ebp-50h]

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_ColorMatrixFilter )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
      fn = (const Scaleform::GFx::AS2::FnCall *)&ThisPtr[-2].pProto;
    }
    else
    {
      p_pProto = 0;
      fn = 0;
    }
  }
  else
  {
    pHeap = v1->Env->StringContext.pContext->pHeap;
    v5 = (Scaleform::GFx::AS2::ColorMatrixFilterObject *)pHeap->Alloc(pHeap, 56u, 0);
    if ( v5 )
      Scaleform::GFx::AS2::ColorMatrixFilterObject::ColorMatrixFilterObject(v5, v1->Env);
    else
      v6 = 0;
    fn = v6;
    p_pProto = (Scaleform::GFx::AS2::Object *)v6;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, p_pProto);
  if ( v1->NArgs > 0 )
  {
    Env = v1->Env;
    v8 = 0;
    if ( v1->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v8 = &Env->Stack.Pages.Data.Data[(unsigned int)v1->FirstArgBottomIndex >> 5]->Values[v1->FirstArgBottomIndex
                                                                                         & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToObject(v8, Env);
    if ( v9 )
    {
      Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v1->Env->StringContext.pContext, ASBuiltin_Array);
      if ( v9->InstanceOf(&v9->Scaleform::GFx::AS2::ObjectInterface, v1->Env, Prototype, 1) )
      {
        v11 = p_pProto[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
        v21[0] = 0;
        v21[1] = 1;
        v21[2] = 2;
        v21[3] = 3;
        v21[4] = 16;
        v21[5] = 4;
        v21[6] = 5;
        v21[7] = 6;
        v21[8] = 7;
        v21[9] = 17;
        v21[10] = 8;
        v21[11] = 9;
        v21[12] = 10;
        v21[13] = 11;
        v21[14] = 18;
        v21[15] = 12;
        v21[16] = 13;
        v21[17] = 14;
        v21[18] = 15;
        v21[19] = 19;
        if ( v11 )
        {
          if ( v11->~Scaleform::GFx::AS2::Object == (void (__thiscall *)(struct Scaleform::GFx::AS2::Object *))8 )
          {
            for ( i = 0; i < (signed int)v9[1].RootIndex; *((float *)&v11->GetValue + v13) = *(float *)&v19 )
            {
              *(float *)&v19 = Scaleform::GFx::AS2::Value::ToNumber(
                                 (Scaleform::GFx::AS2::Value *)(&v9[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[i],
                                 v1->Env);
              v13 = v21[i];
              result = *(float *)&v19;
              ++i;
            }
          }
        }
        p_pProto = (Scaleform::GFx::AS2::Object *)fn;
      }
    }
  }
  v15 = v1->Env;
  pContext = v15->StringContext.pContext;
  v20.T.Type = 10;
  LOBYTE(fn) = 0;
  *(float *)&v19 = COERCE_FLOAT(
                     Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                       "matrix",
                       6u,
                       0));
  ++v19->RefCount;
  p_pProto->SetMemberRaw(
    &p_pProto->Scaleform::GFx::AS2::ObjectInterface,
    &v15->StringContext,
    (const Scaleform::GFx::ASString *)&v19,
    &v20,
    (const Scaleform::GFx::AS2::PropFlags *)&fn);
  v17 = v19;
  --v19->RefCount;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( v20.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v20);
  RefCount = p_pProto->RefCount;
  if ( (RefCount & 0x3FFFFFF) != 0 )
  {
    p_pProto->RefCount = RefCount - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
  }
  return result;
}
