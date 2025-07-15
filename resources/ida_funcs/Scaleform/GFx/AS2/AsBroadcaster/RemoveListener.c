char __cdecl Scaleform::GFx::AS2::AsBroadcaster::RemoveListener(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::ObjectInterface *plistener)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v4; // esi
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::ArrayObject *v6; // esi
  int v7; // edi
  Scaleform::GFx::AS2::Value *v8; // ecx
  unsigned int RefCount; // eax
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Value listenersVal; // [esp+Ch] [ebp-10h] BYREF

  if ( !pthis || !plistener )
    return 0;
  pContext = penv->StringContext.pContext;
  v4 = pthis->__vftable;
  listenersVal.T.Type = 0;
  if ( !((unsigned __int8 (__stdcall *)(Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *))v4->GetMemberRaw)(
          &penv->StringContext,
          &pContext->pMovieRoot->pASMovieRoot.pObject[24].pMovieImpl,
          &listenersVal) )
    goto LABEL_12;
  v5 = Scaleform::GFx::AS2::Value::ToObject(&listenersVal, penv);
  v6 = (Scaleform::GFx::AS2::ArrayObject *)v5;
  if ( !v5 || v5->GetObjectType(&v5->Scaleform::GFx::AS2::ObjectInterface) != Object_Array )
    goto LABEL_12;
  v7 = v6->Elements.Data.Size - 1;
  v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  if ( v7 < 0 )
  {
LABEL_10:
    RefCount = v6->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
LABEL_12:
    if ( listenersVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&listenersVal);
    return 0;
  }
  while ( 1 )
  {
    v8 = v6->Elements.Data.Data[v7];
    if ( v8 )
    {
      if ( Scaleform::GFx::AS2::Value::ToObjectInterface(v8, penv) == plistener )
        break;
    }
    if ( --v7 < 0 )
      goto LABEL_10;
  }
  Scaleform::GFx::AS2::ArrayObject::RemoveElements(v6, v7, 1);
  v11 = v6->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v11) != 0 )
  {
    v6->RefCount = v11 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
  }
  if ( listenersVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&listenersVal);
  return 1;
}
