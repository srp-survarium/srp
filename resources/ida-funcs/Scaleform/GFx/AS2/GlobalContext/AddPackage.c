Scaleform::GFx::AS2::Object *__usercall Scaleform::GFx::AS2::GlobalContext::AddPackage@<eax>(
        char *a1@<ebp>,
        int a2@<edi>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pparent,
        Scaleform::GFx::AS2::Object *objProto,
        __m128i *packageName,
        Scaleform::GFx::AS2::Object *proto)
{
  __m128i *v7; // ebx
  Scaleform::GFx::AS2::Object *v8; // esi
  int v9; // eax
  __m128i *v10; // edi
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
  Scaleform::GFx::ASStringNode *v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // eax
  Scaleform::GFx::AS2::Object *v28; // [esp+24h] [ebp-138h]
  Scaleform::GFx::ASStringNode *StringNode; // [esp+28h] [ebp-134h] BYREF
  int v30; // [esp+2Ch] [ebp-130h]
  __m128i *v31; // [esp+30h] [ebp-12Ch] BYREF
  char *v32; // [esp+34h] [ebp-128h]
  unsigned int v33; // [esp+38h] [ebp-124h]
  Scaleform::GFx::AS2::Value v34; // [esp+3Ch] [ebp-120h] BYREF
  Scaleform::GFx::AS2::Value v35; // [esp+4Ch] [ebp-110h] BYREF
  __m128i v36[16]; // [esp+5Ch] [ebp-100h] BYREF

  v7 = packageName;
  v33 = strlen(packageName->m128i_i8) + 1;
  if ( pparent )
    pparent->RefCount = (pparent->RefCount + 1) & 0x8FFFFFFF;
  v8 = pparent;
  v28 = pparent;
  if ( packageName )
  {
    v32 = (char *)&v35.NV + 15;
    do
    {
      strchr(v7->m128i_i8, 0x2Eu);
      v10 = (__m128i *)v9;
      v30 = v9;
      if ( v9 )
      {
        v11 = v9 - (_DWORD)v7 + 1;
        v10 = (__m128i *)(v9 + 1);
        v30 = v9 + 1;
      }
      else
      {
        v11 = (unsigned int)packageName->m128i_u32 + v33 - (_DWORD)v7;
      }
      if ( v11 > 0x100 )
        v11 = 256;
      memcpy((int)v36, v7, v11 - 1);
      pContext = psc->pContext;
      v32[v11] = 0;
      v34.T.Type = 0;
      pMovieImpl = (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
      v7 = v10;
      v31 = v10;
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pMovieImpl, v36);
      ++StringNode->RefCount;
      v14 = &v28->Scaleform::GFx::AS2::ObjectInterface::__vftable;
      if ( v28->GetMemberRaw(
             &v28->Scaleform::GFx::AS2::ObjectInterface,
             psc,
             (const Scaleform::GFx::ASString *)&StringNode,
             &v34) )
      {
        v15 = Scaleform::GFx::AS2::Value::ToObject(&v34, 0);
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
        a1 = (char *)&StringNode + 3;
        v16 = v18;
        HIBYTE(StringNode) = 0;
        Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)((char *)&v35.NV.NumberValue + 4), v18);
        a2 = v20;
        ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface_vtbl **, Scaleform::GFx::AS2::ASStringContext *, __m128i **))v19->SetMemberRaw)(
          v14,
          psc,
          &v31);
        if ( v35.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v35);
        v7 = v31;
      }
      if ( v16 )
        v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
      RefCount = v28->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v28->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v28);
      }
      v22 = StringNode;
      --StringNode->RefCount;
      v28 = (Scaleform::GFx::AS2::Object *)v16;
      if ( !v22->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      if ( v16 )
      {
        v23 = v16->RefCount;
        if ( (v23 & 0x3FFFFFF) != 0 )
        {
          v16->RefCount = v23 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
        }
      }
      if ( v34.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v34);
    }
    while ( v30 );
    v8 = (Scaleform::GFx::AS2::Object *)v16;
  }
  if ( v8 )
  {
    v24 = v8->RefCount;
    if ( (v24 & 0x3FFFFFF) != 0 )
    {
      v8->RefCount = v24 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return v8;
}
