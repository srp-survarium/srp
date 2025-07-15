void __cdecl Scaleform::GFx::AS2::BuildXMLString(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *proot,
        Scaleform::StringBuffer *dest)
{
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::XML::ShadowRefBase_vtbl *v5; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  void (__thiscall *v7)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::XMLAttributeStringBuilder *); // edx
  Scaleform::GFx::XML::ShadowRefBase_vtbl *v8; // edi
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::GlobalContext *v11; // ecx
  Scaleform::GFx::AS2::StringManager *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::XML::ElementNode *i; // edi
  Scaleform::GFx::XML::Node_vtbl *v15; // eax
  Scaleform::GFx::XML::ShadowRefBase_vtbl *v16; // edi
  Scaleform::GFx::XML::ElementNode *v17; // ebx
  Scaleform::GFx::XML::ObjectManager *j; // edi
  Scaleform::GFx::XML::Node *k; // edi
  Scaleform::GFx::XML::DOMStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+10h] [ebp-2Ch] BYREF
  Scaleform::GFx::ASString result; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::ASStringNode *v23; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::XMLAttributeStringBuilder attrvis; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value ignorews; // [esp+2Ch] [ebp-10h] BYREF

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
      LOBYTE(attrvis.__vftable) = 0;
      StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          StringManager->pStringManager,
                          "xmlDecl",
                          7u,
                          0);
      ++ConstStringNode->RefCount;
      v7 = (void (__thiscall *)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::XMLAttributeStringBuilder *))*((_DWORD *)v5[4].~Scaleform::GFx::XML::ShadowRefBase + 4);
      v8 = v5 + 4;
      v7(v8, penv, &ConstStringNode, &attrvis);
      v9 = ConstStringNode;
      --ConstStringNode->RefCount;
      if ( !v9->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      if ( LOBYTE(attrvis.__vftable) && LOBYTE(attrvis.__vftable) != 10 )
      {
        Scaleform::GFx::AS2::Value::ToStringImpl((Scaleform::GFx::AS2::Value *)&attrvis, &result, penv, -1, 0);
        Scaleform::StringBuffer::AppendString(dest, (char *)result.pNode->pData, 0xFFFFFFFF);
        pNode = result.pNode;
        --result.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v11 = penv->StringContext.pContext;
        ignorews.T.Type = 0;
        v12 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v11);
        v23 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v12->pStringManager, "ignoreWhite", 0xBu, 0);
        ++v23->RefCount;
        (*((void (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))v8->~Scaleform::GFx::XML::ShadowRefBase
         + 4))(
          v8,
          penv,
          &v23,
          &ignorews);
        v13 = v23;
        --v23->RefCount;
        if ( !v13->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        if ( !Scaleform::GFx::AS2::Value::ToBool(&ignorews, penv) )
          Scaleform::StringBuffer::AppendString(dest, "\n", 0xFFFFFFFF);
        Scaleform::GFx::AS2::Value::~Value(&ignorews);
      }
      for ( i = (Scaleform::GFx::XML::ElementNode *)proot->FirstChild.pObject;
            i;
            i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
      {
        Scaleform::GFx::AS2::BuildXMLString(penv, i, dest);
      }
      Scaleform::GFx::AS2::Value::~Value((Scaleform::GFx::AS2::Value *)&attrvis);
    }
    else
    {
      Scaleform::StringBuffer::AppendString(dest, "<", 0xFFFFFFFF);
      v15 = (Scaleform::GFx::XML::Node_vtbl *)proot->Prefix.pNode;
      if ( v15[1].Clone )
      {
        Scaleform::StringBuffer::AppendString(dest, (char *)v15->~Scaleform::GFx::XML::Node, 0xFFFFFFFF);
        Scaleform::StringBuffer::AppendString(dest, (char *)&stru_95963C.m_max_end, 0xFFFFFFFF);
      }
      Scaleform::StringBuffer::AppendString(dest, (char *)proot->Value.pNode->pData, 0xFFFFFFFF);
      if ( pShadow && (v16 = pShadow[2].__vftable) != 0 )
      {
        attrvis.__vftable = (Scaleform::GFx::AS2::XMLAttributeStringBuilder_vtbl *)&Scaleform::GFx::AS2::XMLAttributeStringBuilder::`vftable';
        attrvis.pEnv = penv;
        attrvis.Dest = dest;
        (*((void (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::XMLAttributeStringBuilder *, _DWORD, _DWORD))v16[4].~Scaleform::GFx::XML::ShadowRefBase
         + 8))(
          v16 + 4,
          &penv->StringContext,
          &attrvis,
          0,
          0);
        v17 = proot;
      }
      else
      {
        v17 = proot;
        for ( j = (Scaleform::GFx::XML::ObjectManager *)proot->FirstAttribute;
              j;
              j = (Scaleform::GFx::XML::ObjectManager *)j->Scaleform::GFx::ExternalLibPtr::__vftable )
        {
          Scaleform::StringBuffer::AppendString(dest, (char *)&stru_95AF78, 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(dest, (char *)j->~Scaleform::GFx::XML::ObjectManager, 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(dest, "=\"", 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(dest, *(char **)j->RefCount, 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(dest, "\"", 0xFFFFFFFF);
        }
      }
      if ( Scaleform::GFx::XML::ElementNode::HasChildren(v17) )
        Scaleform::StringBuffer::AppendString(dest, ">", 0xFFFFFFFF);
      else
        Scaleform::StringBuffer::AppendString(dest, " />", 0xFFFFFFFF);
      for ( k = v17->FirstChild.pObject; k; k = k->NextSibling.pObject )
        Scaleform::GFx::AS2::BuildXMLString(penv, k, dest);
      if ( Scaleform::GFx::XML::ElementNode::HasChildren(v17) )
      {
        Scaleform::StringBuffer::AppendString(dest, "</", 0xFFFFFFFF);
        v20 = v17->Prefix.pNode;
        if ( v20->Size )
        {
          Scaleform::StringBuffer::AppendString(dest, (char *)v20->pData, 0xFFFFFFFF);
          Scaleform::StringBuffer::AppendString(dest, (char *)&stru_95963C.m_max_end, 0xFFFFFFFF);
        }
        Scaleform::StringBuffer::AppendString(dest, (char *)v17->Value.pNode->pData, 0xFFFFFFFF);
        Scaleform::StringBuffer::AppendString(dest, ">", 0xFFFFFFFF);
      }
    }
  }
  else
  {
    Scaleform::StringBuffer::AppendString(dest, (char *)proot->Value.pNode->pData, 0xFFFFFFFF);
  }
}
