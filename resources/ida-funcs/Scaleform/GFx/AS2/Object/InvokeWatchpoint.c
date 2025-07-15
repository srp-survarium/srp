char __thiscall Scaleform::GFx::AS2::Object::InvokeWatchpoint(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *prop,
        const Scaleform::GFx::AS2::Value *newVal,
        Scaleform::GFx::AS2::Value *resultVal)
{
  bool (__thiscall *GetMember)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *); // eax
  bool v7; // cc
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // ecx
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324> > v9; // esi
  int v10; // eax
  int v11; // eax
  Scaleform::GFx::AS2::Object::Watchpoint *CaseInsensitive; // edi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // eax
  Scaleform::GFx::InteractiveObject *v16; // eax
  Scaleform::RefCountNTSImpl *v17; // ebp
  int v18; // eax
  Scaleform::GFx::AS2::ObjectInterface *v19; // ecx
  const Scaleform::GFx::AS2::FnCall *v20; // eax
  int v21; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisIn; // [esp+14h] [ebp-58h]
  Scaleform::GFx::AS2::Value ResIn; // [esp+18h] [ebp-54h] BYREF
  Scaleform::GFx::AS2::Value v26; // [esp+28h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value v27; // [esp+38h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v28; // [esp+48h] [ebp-24h] BYREF

  GetMember = this->GetMember;
  v26.T.Type = 0;
  ThisIn = &this->Scaleform::GFx::AS2::ObjectInterface;
  ((void (__stdcall *)(Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))GetMember)(
    penv,
    prop,
    &v26);
  v7 = penv->StringContext.SWFVersion <= 6u;
  pWatchpoints = this->pWatchpoints;
  ResIn.T.Type = 0;
  if ( v7 )
  {
    CaseInsensitive = Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor,324>>::GetCaseInsensitive(
                        pWatchpoints,
                        prop);
  }
  else
  {
    v9.mHash.pTable = pWatchpoints->mHash.pTable;
    if ( !pWatchpoints->mHash.pTable )
      goto LABEL_45;
    v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Object::Watchpoint,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
            &pWatchpoints->mHash,
            prop,
            prop->pNode->HashFlags & v9.mHash.pTable->SizeMask);
    if ( v10 < 0 )
      goto LABEL_45;
    v11 = (int)(&v9.mHash.pTable[1].SizeMask + 9 * v10);
    if ( !v11 )
      goto LABEL_45;
    CaseInsensitive = (Scaleform::GFx::AS2::Object::Watchpoint *)(v11 + 4);
  }
  if ( CaseInsensitive && this->pWatchpoints )
  {
    ++penv->Stack.pCurrent;
    p_Stack = &penv->Stack;
    if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
    if ( p_Stack->pCurrent )
      Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, &CaseInsensitive->UserData);
    ++p_Stack->pCurrent;
    if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
    if ( p_Stack->pCurrent )
      Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, newVal);
    ++p_Stack->pCurrent;
    if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
    if ( p_Stack->pCurrent )
      Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, &v26);
    pNode = prop->pNode;
    ++pNode->RefCount;
    ++p_Stack->pCurrent;
    v27.NV.Int32Value = (int)pNode;
    pCurrent = p_Stack->pCurrent;
    v27.T.Type = 5;
    if ( pCurrent >= penv->Stack.pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
    if ( !p_Stack->pCurrent || (Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, &v27), v27.T.Type >= 5u) )
      Scaleform::GFx::AS2::Value::DropRefs(&v27);
    v16 = this->GetASCharacter(this);
    v17 = v16;
    if ( v16 )
    {
      ++v16->RefCount;
      v18 = (*(int (__thiscall **)(int))(*((_DWORD *)&v16->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + v16->AvmObjOffset)
                                       + 4))((int)v16 + 4 * v16->AvmObjOffset);
      if ( v18 )
        v19 = (Scaleform::GFx::AS2::ObjectInterface *)(v18 + 4);
      else
        v19 = 0;
      Scaleform::GFx::AS2::FnCall::FnCall(
        &v28,
        &ResIn,
        v19,
        penv,
        4,
        penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32);
    }
    else
    {
      Scaleform::GFx::AS2::FnCall::FnCall(
        &v28,
        &ResIn,
        ThisIn,
        penv,
        4,
        penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32);
    }
    CaseInsensitive->Callback.Function->Invoke(
      CaseInsensitive->Callback.Function,
      v20,
      CaseInsensitive->Callback.pLocalFrame,
      0);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v28);
    v21 = 4;
    do
    {
      if ( p_Stack->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
      --p_Stack->pCurrent;
      if ( penv->Stack.pCurrent < penv->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
      --v21;
    }
    while ( v21 );
    Scaleform::GFx::AS2::Value::operator=(resultVal, &ResIn);
    if ( v17 )
      Scaleform::RefCountNTSImpl::Release(v17);
    if ( ResIn.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&ResIn);
    if ( v26.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v26);
    return 1;
  }
LABEL_45:
  if ( v26.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v26);
  return 0;
}
