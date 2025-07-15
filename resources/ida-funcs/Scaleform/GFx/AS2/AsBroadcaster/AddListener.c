char __cdecl Scaleform::GFx::AS2::AsBroadcaster::AddListener(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::ObjectInterface *plistener)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v4; // esi
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::ArrayObject *v6; // esi
  unsigned int Size; // ebp
  int v8; // edi
  Scaleform::GFx::AS2::Value *v9; // ecx
  unsigned int RefCount; // eax
  unsigned int v12; // eax
  Scaleform::GFx::AS2::Value listenersVal; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+1Ch] [ebp-10h] BYREF

  if ( !pthis || !plistener )
    return 0;
  pContext = penv->StringContext.pContext;
  v4 = pthis->__vftable;
  listenersVal.T.Type = 0;
  if ( !((unsigned __int8 (__stdcall *)(Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *))v4->GetMemberRaw)(
          &penv->StringContext,
          &pContext->pMovieRoot->pASMovieRoot.pObject[24].pMovieImpl,
          &listenersVal) )
    goto LABEL_14;
  v5 = Scaleform::GFx::AS2::Value::ToObject(&listenersVal, penv);
  v6 = (Scaleform::GFx::AS2::ArrayObject *)v5;
  if ( !v5 || v5->GetObjectType(&v5->Scaleform::GFx::AS2::ObjectInterface) != Object_Array )
    goto LABEL_14;
  Size = v6->Elements.Data.Size;
  v8 = 0;
  v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  if ( !Size )
  {
LABEL_10:
    val.T.Type = 0;
    Scaleform::GFx::AS2::Value::SetAsObjectInterface(&val, plistener);
    Scaleform::GFx::AS2::ArrayObject::PushBack(v6, &val);
    if ( val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&val);
    RefCount = v6->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
LABEL_14:
    if ( listenersVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&listenersVal);
    return 1;
  }
  while ( 1 )
  {
    v9 = v6->Elements.Data.Data[v8];
    if ( v9 )
    {
      if ( Scaleform::GFx::AS2::Value::ToObjectInterface(v9, penv) == plistener )
        break;
    }
    if ( ++v8 >= Size )
      goto LABEL_10;
  }
  v12 = v6->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v12) != 0 )
  {
    v6->RefCount = v12 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
  }
  if ( listenersVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&listenersVal);
  return 0;
}
