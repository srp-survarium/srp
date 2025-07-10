Scaleform::GFx::AS2::Object *__usercall Scaleform::GFx::AS2::GlobalContext::AddPackage@<eax>(
        char *a1@<ebp>,
        int a2@<edi>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pparent,
        Scaleform::GFx::AS2::Object *objProto,
        const char *packageName,
        Scaleform::GFx::AS2::Object *proto)
{
  char *v7; // ebx
  Scaleform::GFx::AS2::Object *v8; // esi
  const char *v9; // eax
  const char *v10; // edi
  unsigned int v11; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::ASStringManager *pMovieImpl; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl **v14; // esi
  Scaleform::GFx::AS2::Object *v15; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // edi
  Scaleform::GFx::AS2::Object *v17; // eax
  Scaleform::GFx::AS2::Object *v18; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v19; // ebx
  int v20; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  Scaleform::GFx::AS2::Object *parent; // [esp+24h] [ebp-138h]
  Scaleform::GFx::ASString memberName; // [esp+28h] [ebp-134h] BYREF
  const char *p; // [esp+2Ch] [ebp-130h]
  const char *pname; // [esp+30h] [ebp-12Ch] BYREF
  char *v32; // [esp+34h] [ebp-128h]
  unsigned int nameSz; // [esp+38h] [ebp-124h]
  Scaleform::GFx::AS2::Value pkgObjVal; // [esp+3Ch] [ebp-120h] BYREF
  Scaleform::GFx::AS2::Value v35; // [esp+4Ch] [ebp-110h] BYREF
  unsigned __int8 v36[256]; // [esp+5Ch] [ebp-100h] BYREF

  v7 = (char *)packageName;
  nameSz = strlen(packageName) + 1;
  if ( pparent )
    pparent->RefCount = (pparent->RefCount + 1) & 0x8FFFFFFF;
  v8 = pparent;
  parent = pparent;
  if ( packageName )
  {
    v32 = (char *)&v35.NV + 15;
    do
    {
      strchr(v7, 0x2Eu);
      v10 = v9;
      p = v9;
      if ( v9 )
      {
        v11 = v9 - v7 + 1;
        v10 = v9 + 1;
        p = v9 + 1;
      }
      else
      {
        v11 = (unsigned int)&packageName[nameSz - (_DWORD)v7];
      }
      if ( v11 > 0x100 )
        v11 = 256;
      memcpy(v36, (unsigned __int8 *)v7, v11 - 1);
      pContext = psc->pContext;
      v32[v11] = 0;
      pkgObjVal.T.Type = 0;
      pMovieImpl = (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
      v7 = (char *)v10;
      pname = v10;
      memberName.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(pMovieImpl, (char *)v36);
      ++memberName.pNode->RefCount;
      v14 = &parent->Scaleform::GFx::AS2::ObjectInterface::__vftable;
      if ( parent->GetMemberRaw(&parent->Scaleform::GFx::AS2::ObjectInterface, psc, &memberName, &pkgObjVal) )
      {
        v15 = Scaleform::GFx::AS2::Value::ToObject(&pkgObjVal, 0);
        if ( v15 )
          v15->RefCount = (v15->RefCount + 1) & 0x8FFFFFFF;
        v16 = v15;
      }
      else
      {
        v17 = (Scaleform::GFx::AS2::Object *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, char *))psc->pContext->pHeap->Alloc)(
                                               psc->pContext->pHeap,
                                               52,
                                               0,
                                               a2,
                                               a1);
        if ( v17 )
          Scaleform::GFx::AS2::Object::Object(v17, psc, proto);
        else
          v18 = 0;
        v19 = *v14;
        a1 = (char *)&memberName.pNode + 3;
        v16 = v18;
        HIBYTE(memberName.pNode) = 0;
        Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)((char *)&v35.NV.NumberValue + 4), v18);
        a2 = v20;
        ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface_vtbl **, Scaleform::GFx::AS2::ASStringContext *, const char **))v19->SetMemberRaw)(
          v14,
          psc,
          &pname);
        if ( v35.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v35);
        v7 = (char *)pname;
      }
      if ( v16 )
        v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
      RefCount = parent->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        parent->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(parent);
      }
      pNode = memberName.pNode;
      --memberName.pNode->RefCount;
      parent = (Scaleform::GFx::AS2::Object *)v16;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v16 )
      {
        v23 = v16->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v23) != 0 )
        {
          v16->RefCount = v23 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
        }
      }
      if ( pkgObjVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pkgObjVal);
    }
    while ( p );
    v8 = (Scaleform::GFx::AS2::Object *)v16;
  }
  if ( v8 )
  {
    v24 = v8->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v24) != 0 )
    {
      v8->RefCount = v24 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return v8;
}
