char __usercall Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance@<al>(
        int a1@<edi>,
        int a2@<esi>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface *pobj,
        int a5,
        int a6)
{
  Scaleform::GFx::AS2::ArrayObject *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::Object *v9; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v11; // ebp
  Scaleform::GFx::ASMovieRootBase *pObject; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v14; // [esp+18h] [ebp-10h] BYREF

  if ( !pobj )
    return 0;
  v7 = (Scaleform::GFx::AS2::ArrayObject *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int))psc->pContext->pHeap->Alloc)(
                                             psc->pContext->pHeap,
                                             80,
                                             0,
                                             a1,
                                             a2);
  if ( v7 )
  {
    Scaleform::GFx::AS2::ArrayObject::ArrayObject(v7, psc);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  pContext = psc->pContext;
  v11 = pobj->__vftable;
  BYTE3(v14.NV.NumberValue) = 1;
  pObject = pContext->pMovieRoot->pASMovieRoot.pObject;
  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)((char *)&v14.NV.NumberValue + 4), v9);
  ((void (__thiscall *)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **))v11->SetMemberRaw)(
    a6,
    psc,
    &pObject[24].pMovieImpl);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  if ( v9 )
  {
    RefCount = v9->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v9->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
  }
  return 1;
}
