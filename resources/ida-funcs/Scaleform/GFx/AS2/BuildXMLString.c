void __cdecl Scaleform::GFx::AS2::BuildXMLString(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *proot,
        Scaleform::StringBuffer *dest)
{
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::XML::ShadowRefBase_vtbl *v5; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  void (__thiscall *v7)(int, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *); // edx
  int v8; // edi
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS2::GlobalContext *v11; // ecx
  Scaleform::GFx::AS2::StringManager *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::XML::ElementNode *i; // edi
  Scaleform::GFx::XML::DOMStringNode *pNode; // eax
  Scaleform::GFx::XML::ShadowRefBase_vtbl *v16; // edi
  Scaleform::GFx::XML::ElementNode *v17; // ebx
  Scaleform::GFx::XML::Attribute *j; // edi
  Scaleform::GFx::XML::ElementNode *k; // edi
  Scaleform::GFx::XML::DOMStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+10h] [ebp-2Ch] BYREF
  Scaleform::GFx::ASStringNode *v22; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::ASStringNode *v23; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value v24; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v25; // [esp+2Ch] [ebp-10h] BYREF

  if ( proot->Type == 1 )
  {
    pShadow = proot->pShadow;
    if ( pShadow
      && pShadow[1].__vftable
      && (*((int (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *))pShadow[1].__vftable[4].~Scaleform::GFx::XML::ShadowRefBase
          + 2))(pShadow[1].__vftable + 4) == 28 )
    {
      pContext = penv->StringContext.pContext;
      v5 = pShadow[1].__vftable;
      v24.T.Type = 0;
      StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          StringManager->pStringManager,
                          "xmlDecl",
                          7u,
                          0);
      ++ConstStringNode->RefCount;
      v7 = (void (__thiscall *)(int, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))*((_DWORD *)v5[4].~Scaleform::GFx::XML::ShadowRefBase + 4);
      v8 = (int)&v5[4];
      v7(v8, penv, &ConstStringNode, &v24);
      v9 = ConstStringNode;
      --ConstStringNode->RefCount;
      if ( !v9->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      if ( v24.T.Type && v24.T.Type != 10 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl(&v24, (Scaleform::GFx::ASString *)&v22, penv, -1, 0);
        Scaleform::StringBuffer::AppendString(dest, (const __m128i *)v22->pData, 0xFFFFFFFF);
        v10 = v22;
        --v22->RefCount;
        if ( !v10->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        v11 = penv->StringContext.pContext;
        v25.T.Type = 0;
        v12 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v11);
        v23 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v12->pStringManager, "ignoreWhite", 0xBu, 0);
        ++v23->RefCount;
        (*(void (__thiscall **)(int, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))(*(_DWORD *)v8 + 16))(
          v8,
          penv,
          &v23,
          &v25);
        v13 = v23;
        --v23->RefCount;
        if ( !v13->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        if ( !Scaleform::GFx::AS2::Value::ToBool(&v25, v8, penv) )
          Scaleform::StringBuffer::AppendString(dest, (const __m128i *)"\n", 0xFFFFFFFF);
        Scaleform::GFx::AS2::Value::~Value(&v25);
      }
      for ( i = (Scaleform::GFx::XML::ElementNode *)proot->FirstChild.pObject;
            i;
            i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
      {
        Scaleform::GFx::AS2::BuildXMLString(penv, i, dest);
      }
      Scaleform::GFx::AS2::Value::~Value(&v24);
    }
    else
    {
      Scaleform::StringBuffer::AppendString(dest, (const __m128i *)"<", 0xFFFFFFFF);
      pNode = proot->Prefix.pNode;
      if ( pNode->Size )
      {
        Scaleform::StringBuffer::AppendString(dest, (const __m128i *)pNode->pData, 0xFFFFFFFF);
        Scaleform::StringBuffer::AppendString(dest, (const __m128i *)":", 0xFFFFFFFF);
      }
      Scaleform::StringBuffer::AppendString(dest, (const __m128i *)proot->Value.pNode->pData, 0xFFFFFFFF);
      if ( pShadow && (v16 = pShadow[2].__vftable) != 0 )
      {
        *(_DWORD *)&v24.T.Type = &Scaleform::GFx::AS2::XMLAttributeStringBuilder::`vftable';
        *(_QWORD *)&v24.NV.NumberValue = __PAIR64__((unsigned int)dest, (unsigned int)penv);
        (*((void (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Value *, _DWORD, _DWORD))v16[4].~Scaleform::GFx::XML::ShadowRefBase
         + 8))(
          v16 + 4,
          &penv->StringContext,
          &v24,
          0,
          0);
        v17 = proot;
      }
      else
      {
        v17 = proot;
        for ( j = proot->FirstAttribute; j; j = j->Next )
        {
          Scaleform::StringBuffer::AppendString(dest, (const __m128i *)" ", 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(dest, (const __m128i *)j->Name.pNode->pData, 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(dest, (const __m128i *)"=\"", 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(dest, (const __m128i *)j->Value.pNode->pData, 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(dest, (const __m128i *)"\"", 0xFFFFFFFF);
        }
      }
      if ( Scaleform::GFx::XML::ElementNode::HasChildren(v17) )
        Scaleform::StringBuffer::AppendString(dest, (const __m128i *)">", 0xFFFFFFFF);
      else
        Scaleform::StringBuffer::AppendString(dest, (const __m128i *)" />", 0xFFFFFFFF);
      for ( k = (Scaleform::GFx::XML::ElementNode *)v17->FirstChild.pObject;
            k;
            k = (Scaleform::GFx::XML::ElementNode *)k->NextSibling.pObject )
      {
        Scaleform::GFx::AS2::BuildXMLString(penv, k, dest);
      }
      if ( Scaleform::GFx::XML::ElementNode::HasChildren(v17) )
      {
        Scaleform::StringBuffer::AppendString(dest, (const __m128i *)"</", 0xFFFFFFFF);
        v20 = v17->Prefix.pNode;
        if ( v20->Size )
        {
          Scaleform::StringBuffer::AppendString(dest, (const __m128i *)v20->pData, 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(dest, (const __m128i *)":", 0xFFFFFFFF);
        }
        Scaleform::StringBuffer::AppendString(dest, (const __m128i *)v17->Value.pNode->pData, 0xFFFFFFFF);
        Scaleform::StringBuffer::AppendString(dest, (const __m128i *)">", 0xFFFFFFFF);
      }
    }
  }
  else
  {
    Scaleform::StringBuffer::AppendString(dest, (const __m128i *)proot->Value.pNode->pData, 0xFFFFFFFF);
  }
}
