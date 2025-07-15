void __usercall Scaleform::GFx::AS2::NameFunction::AddConstMembers(
        unsigned __int8 *p_flags@<ebx>,
        Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame@<ebp>,
        Scaleform::GFx::AS2::ObjectInterface *pobj,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::AS2::NameFunction *pfunctions,
        unsigned __int8 flags,
        int a7)
{
  Scaleform::MemoryHeap *v7; // esi
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::Object *v9; // esi
  Scaleform::GFx::AS2::Object_vtbl *v10; // ebp
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // ebx
  unsigned int RefCount; // eax
  bool v13; // zf
  Scaleform::GFx::ASStringNode *pStringNode; // [esp+Ch] [ebp-28h]
  Scaleform::GFx::ASStringNode *v17; // [esp+18h] [ebp-1Ch]
  Scaleform::MemoryHeap *pheap; // [esp+1Ch] [ebp-18h]
  Scaleform::GFx::AS2::Object *pfuncProto; // [esp+20h] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+24h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+34h] [ebp+0h]

  v7 = psc->pContext->pHeap;
  pheap = v7;
  pfuncProto = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  if ( pfunctions->Name )
  {
    while ( 1 )
    {
      v8 = (Scaleform::GFx::AS2::Object *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, Scaleform::GFx::AS2::LocalFrame **, unsigned __int8 *))v7->Alloc)(
                                            v7,
                                            56,
                                            0,
                                            p_pLocalFrame,
                                            p_flags);
      v9 = v8;
      if ( v8 )
      {
        v10 = *(Scaleform::GFx::AS2::Object_vtbl **)(a7 + 4);
        Scaleform::GFx::AS2::Object::Object(v8, psc);
        pStringNode = v20.V.pStringNode;
        v9->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
        v9->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
        v9[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = v10;
        Scaleform::GFx::AS2::Object::Set__proto__(
          (Scaleform::GFx::AS2::Object *)&v9->Scaleform::GFx::AS2::ObjectInterface,
          psc,
          (Scaleform::GFx::AS2::Object *)pStringNode);
        v11 = v9;
      }
      else
      {
        v11 = 0;
      }
      BYTE4(v20.NV.NumberValue) = 8;
      *((_DWORD *)&v20.NV + 3) = v11;
      if ( v11 )
        v11->RefCount = (v11->RefCount + 1) & 0x8FFFFFFF;
      retaddr = 0;
      pfuncProto = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                    (Scaleform::GFx::ASStringManager *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                                    *(char **)a7,
                                                    strlen(*(const char **)a7),
                                                    0);
      ++pfuncProto->RefCount;
      p_flags = &flags;
      p_pLocalFrame = &v20.V.FunctionValue.pLocalFrame;
      (*((void (__thiscall **)(const Scaleform::GFx::AS2::NameFunction *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object **))pfunctions->Name
       + 10))(
        pfunctions,
        psc,
        &pfuncProto);
      if ( !--v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      if ( v20.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v20);
      if ( v11 )
      {
        RefCount = v11->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
      v13 = pfunctions[1].Name == 0;
      ++pfunctions;
      if ( v13 )
        break;
      v7 = pheap;
    }
  }
}
