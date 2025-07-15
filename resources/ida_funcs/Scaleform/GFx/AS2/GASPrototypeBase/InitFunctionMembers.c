void __userpurge Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
        Scaleform::GFx::AS2::GASPrototypeBase *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame@<esi>,
        Scaleform::GFx::AS2::Object *pthis,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::AS2::NameFunction *funcTable,
        Scaleform::GFx::ASStringNode *flags,
        int a8,
        int a9)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax
  const Scaleform::GFx::AS2::NameFunction *v10; // ebp
  Scaleform::GFx::AS2::Object *v11; // eax
  Scaleform::GFx::AS2::Object *v12; // esi
  void (__cdecl *Function)(const Scaleform::GFx::AS2::FnCall *); // ebx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // ebx
  unsigned int RefCount; // eax
  bool v16; // zf
  unsigned int v17; // ecx
  Scaleform::GFx::ASStringNode *pStringNode; // [esp+Ch] [ebp-24h]
  int i; // [esp+18h] [ebp-18h]
  Scaleform::GFx::AS2::Object *v22; // [esp+1Ch] [ebp-14h]
  Scaleform::GFx::AS2::Value v23; // [esp+20h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h]

  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  v22 = Prototype;
  if ( Prototype )
    Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
  v10 = funcTable;
  i = 0;
  if ( funcTable->Name )
  {
    do
    {
      v11 = (Scaleform::GFx::AS2::Object *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, Scaleform::GFx::AS2::LocalFrame **, int))psc->pContext->pHeap->Alloc)(
                                             psc->pContext->pHeap,
                                             56,
                                             0,
                                             p_pLocalFrame,
                                             a2);
      v12 = v11;
      if ( v11 )
      {
        Function = v10->Function;
        Scaleform::GFx::AS2::Object::Object(v11, psc);
        pStringNode = v23.V.pStringNode;
        v12->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
        v12->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
        v12[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)Function;
        Scaleform::GFx::AS2::Object::Set__proto__(
          (Scaleform::GFx::AS2::Object *)&v12->Scaleform::GFx::AS2::ObjectInterface,
          psc,
          (Scaleform::GFx::AS2::Object *)pStringNode);
        v14 = v12;
      }
      else
      {
        v14 = 0;
      }
      BYTE4(v23.NV.NumberValue) = 8;
      *((_DWORD *)&v23.NV + 3) = v14;
      if ( v14 )
        v14->RefCount = (v14->RefCount + 1) & 0x8FFFFFFF;
      retaddr = 0;
      flags = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                (char *)v10->Name,
                strlen(v10->Name),
                0);
      ++flags->RefCount;
      a2 = a9;
      p_pLocalFrame = &v23.V.FunctionValue.pLocalFrame;
      (*((void (__thiscall **)(const Scaleform::GFx::AS2::NameFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASStringNode **))funcTable->Name
       + 10))(
        funcTable,
        psc,
        &flags);
      if ( !--*(_DWORD *)&psc[1].SWFVersion )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)psc);
      if ( v23.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v23);
      if ( v14 )
      {
        RefCount = v14->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v14->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
        }
      }
      v16 = funcTable[i + 1].Name == 0;
      v10 = &funcTable[++i];
    }
    while ( !v16 );
    Prototype = v22;
  }
  if ( Prototype )
  {
    v17 = Prototype->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v17) != 0 )
    {
      Prototype->RefCount = v17 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Prototype);
    }
  }
}
