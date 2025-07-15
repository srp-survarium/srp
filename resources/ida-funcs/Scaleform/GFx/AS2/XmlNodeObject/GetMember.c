char __thiscall Scaleform::GFx::AS2::XmlNodeObject::GetMember(
        Scaleform::GFx::AS2::XmlNodeObject *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  const Scaleform::GFx::ASString *v4; // ebx
  Scaleform::GFx::AS2::Environment *v6; // edi
  int v7; // ebx
  Scaleform::GFx::XML::ElementNode *v8; // ebx
  Scaleform::GFx::XML::ShadowRefBase *v9; // eax
  Scaleform::GFx::AS2::Object *v10; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *Shadow; // eax
  Scaleform::GFx::AS2::XmlNodeObject *v12; // eax
  unsigned int v13; // edx
  char v14; // al
  Scaleform::GFx::AS2::Value *v15; // esi
  Scaleform::GFx::AS2::Value *v16; // esi
  int v17; // eax
  Scaleform::GFx::XML::ElementNode *v18; // eax
  Scaleform::GFx::XML::ShadowRefBase *v19; // ecx
  Scaleform::GFx::AS2::Object *v20; // ecx
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *v21; // eax
  int v22; // eax
  Scaleform::GFx::AS2::ArrayObject *v23; // eax
  Scaleform::GFx::AS2::ArrayObject *v24; // eax
  Scaleform::GFx::AS2::ArrayObject *v25; // ebx
  Scaleform::GFx::XML::ElementNode *i; // ebp
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // eax
  Scaleform::GFx::AS2::Object *v28; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *v29; // eax
  const Scaleform::GFx::AS2::Value *v30; // eax
  unsigned int v31; // edx
  Scaleform::GFx::AS2::XmlNodeObject *pObject; // ecx
  unsigned int v33; // eax
  int v34; // esi
  int v35; // eax
  __m128i *v36; // ebp
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  int v39; // esi
  __m128i **v40; // eax
  __m128i *v41; // esi
  Scaleform::GFx::AS2::StringManager *v42; // eax
  Scaleform::GFx::ASStringNode *v43; // esi
  Scaleform::GFx::AS2::Value *v44; // ecx
  bool v45; // zf
  int v46; // esi
  int v47; // esi
  Scaleform::GFx::AS2::Object *v48; // eax
  int v49; // eax
  int v50; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v51; // ecx
  unsigned int RefCount; // eax
  int v53; // ebx
  Scaleform::GFx::XML::ElementNode *v54; // ebx
  Scaleform::GFx::XML::ShadowRefBase *v55; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *v56; // eax
  int v57; // eax
  Scaleform::GFx::XML::ElementNode *v58; // eax
  Scaleform::GFx::XML::ShadowRefBase *v59; // ecx
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *v60; // eax
  int v61; // eax
  Scaleform::GFx::XML::ElementNode *v62; // eax
  Scaleform::GFx::XML::ShadowRefBase *v63; // ecx
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *v64; // eax
  __m128i *v65; // esi
  Scaleform::GFx::AS2::StringManager *v66; // eax
  Scaleform::GFx::AS2::Environment *StringNode; // eax
  Scaleform::GFx::AS2::Value *v68; // ecx
  int v69; // esi
  int v70; // esi
  __m128i *v71; // esi
  Scaleform::GFx::AS2::StringManager *v72; // eax
  int v73; // esi
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [esp+18h] [ebp-34h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v75; // [esp+1Ch] [ebp-30h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v76; // [esp+20h] [ebp-2Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v77; // [esp+24h] [ebp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v78; // [esp+28h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value v79; // [esp+2Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v80; // [esp+3Ch] [ebp-10h] BYREF

  v4 = name;
  v6 = (Scaleform::GFx::AS2::Environment *)penv;
  if ( !*(_DWORD *)&this->ResolveHandler.Flags )
    return Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::GetMember(
             (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::GASIme,Scaleform::GFx::AS2::Environment> *)this,
             v6,
             v4,
             val);
  switch ( Scaleform::GFx::AS2::XmlNodeObject::GetStandardMemberConstant(
             (Scaleform::GFx::AS2::XmlNodeObject *)((char *)this - 16),
             (Scaleform::GFx::AS2::Environment *)penv,
             name) )
  {
    case M_x:
      v46 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v46 )
        goto LABEL_13;
      v47 = *(_DWORD *)(v46 + 28);
      if ( !*(_DWORD *)(v47 + 8) )
      {
        v48 = (Scaleform::GFx::AS2::Object *)v6->StringContext.pContext->pHeap->Alloc(
                                               v6->StringContext.pContext->pHeap,
                                               52u,
                                               0);
        if ( v48 )
        {
          Scaleform::GFx::AS2::Object::Object(v48, v6);
          v50 = v49;
        }
        else
        {
          v50 = 0;
        }
        v51 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v47 + 8);
        if ( v51 )
        {
          RefCount = v51->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v51->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v51);
          }
        }
        *(_DWORD *)(v47 + 8) = v50;
      }
      v10 = *(Scaleform::GFx::AS2::Object **)(v47 + 8);
      goto LABEL_58;
    case M_y:
      v22 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v22 || *(_BYTE *)(v22 + 32) != 1 )
        goto LABEL_13;
      v23 = (Scaleform::GFx::AS2::ArrayObject *)v6->StringContext.pContext->pHeap->Alloc(
                                                  v6->StringContext.pContext->pHeap,
                                                  80u,
                                                  0);
      if ( v23 )
      {
        Scaleform::GFx::AS2::ArrayObject::ArrayObject(v23, v6);
        v25 = v24;
      }
      else
      {
        v25 = 0;
      }
      for ( i = *(Scaleform::GFx::XML::ElementNode **)(*(_DWORD *)&this->ResolveHandler.Flags + 52);
            i;
            i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
      {
        pShadow = i->pShadow;
        if ( pShadow && (v28 = (Scaleform::GFx::AS2::Object *)pShadow[1].__vftable) != 0 )
        {
          Scaleform::GFx::AS2::Value::Value(&v79, v28);
          Scaleform::GFx::AS2::ArrayObject::PushBack(v25, &v79);
          Scaleform::GFx::AS2::Value::~Value(&v79);
        }
        else
        {
          v29 = Scaleform::GFx::AS2::CreateShadow(
                  &v75,
                  v6,
                  i,
                  (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
          Scaleform::GFx::AS2::Value::Value(&v80, v29->pObject);
          Scaleform::GFx::AS2::ArrayObject::PushBack(v25, v30);
          Scaleform::GFx::AS2::Value::~Value(&v80);
          if ( v75.pObject )
          {
            v31 = v75.pObject->RefCount;
            pObject = v75.pObject;
            if ( (v31 & 0x3FFFFFF) != 0 )
            {
              v75.pObject->RefCount = v31 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
            }
          }
        }
      }
      Scaleform::GFx::AS2::Value::SetAsObject(val, v25);
      if ( !v25 )
        return 1;
      v33 = v25->RefCount;
      if ( (v33 & 0x3FFFFFF) == 0 )
        return 1;
      v25->RefCount = v33 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v25);
      return 1;
    case M_xscale:
      v7 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v7 )
        goto LABEL_13;
      if ( *(_BYTE *)(v7 + 32) != 1
        || !Scaleform::GFx::XML::ElementNode::HasChildren(*(Scaleform::GFx::XML::ElementNode **)&this->ResolveHandler.Flags) )
      {
        goto LABEL_12;
      }
      v8 = *(Scaleform::GFx::XML::ElementNode **)(v7 + 52);
      v9 = v8->pShadow;
      if ( v9 )
      {
        v10 = (Scaleform::GFx::AS2::Object *)v9[1].__vftable;
        if ( v10 )
          goto LABEL_58;
      }
      Shadow = Scaleform::GFx::AS2::CreateShadow(
                 (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *)&name,
                 v6,
                 v8,
                 (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(val, Shadow->pObject);
      v12 = (Scaleform::GFx::AS2::XmlNodeObject *)name;
      goto LABEL_9;
    case M_yscale:
      v53 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v53 )
        goto LABEL_13;
      if ( *(_BYTE *)(v53 + 32) != 1
        || !Scaleform::GFx::XML::ElementNode::HasChildren(*(Scaleform::GFx::XML::ElementNode **)&this->ResolveHandler.Flags) )
      {
        goto LABEL_12;
      }
      v54 = *(Scaleform::GFx::XML::ElementNode **)(v53 + 56);
      v55 = v54->pShadow;
      if ( v55 )
      {
        v10 = (Scaleform::GFx::AS2::Object *)v55[1].__vftable;
        if ( v10 )
        {
LABEL_58:
          Scaleform::GFx::AS2::Value::SetAsObject(val, v10);
          return 1;
        }
      }
      v56 = Scaleform::GFx::AS2::CreateShadow(
              &v76,
              v6,
              v54,
              (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(val, v56->pObject);
      v12 = v76.pObject;
      goto LABEL_9;
    case M_currentframe:
      v34 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( v34 && *(_BYTE *)(v34 + 32) == 1 )
        goto LABEL_77;
      goto LABEL_13;
    case M_totalframes:
      v69 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v69 || *(_BYTE *)(v69 + 32) != 1 )
        goto LABEL_13;
      v40 = *(__m128i ***)(v69 + 40);
      goto LABEL_45;
    case M_alpha:
      v17 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v17 )
        goto LABEL_13;
      v18 = *(Scaleform::GFx::XML::ElementNode **)(v17 + 24);
      if ( !v18 )
        goto LABEL_12;
      v19 = v18->pShadow;
      if ( v19 )
      {
        v20 = (Scaleform::GFx::AS2::Object *)v19[1].__vftable;
        if ( v20 )
          goto LABEL_19;
      }
      v21 = Scaleform::GFx::AS2::CreateShadow(
              &result,
              v6,
              v18,
              (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(val, v21->pObject);
      v12 = result.pObject;
      goto LABEL_9;
    case M_visible:
      v34 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v34 )
        goto LABEL_13;
      if ( *(_BYTE *)(v34 + 32) != 1 )
        goto LABEL_12;
      v35 = *(_DWORD *)(v34 + 36);
      if ( *(_DWORD *)(v35 + 12) )
      {
        v36 = *(__m128i **)v35;
        StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v6->StringContext.pContext);
        penv = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager->pStringManager, v36);
        ++penv->RefCount;
        Scaleform::GFx::ASString::operator+=((Scaleform::GFx::ASString *)&penv, (const __m128i *)":");
        Scaleform::GFx::ASString::operator+=((Scaleform::GFx::ASString *)&penv, **(const __m128i ***)(v34 + 12));
        Scaleform::GFx::AS2::Value::SetString(val, (const Scaleform::GFx::ASString *)&penv);
        v38 = penv;
        --penv->RefCount;
        if ( v38->RefCount )
          return 1;
        Scaleform::GFx::ASStringNode::ReleaseNode(v38);
        return 1;
      }
LABEL_77:
      v65 = **(__m128i ***)(v34 + 12);
      v66 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v6->StringContext.pContext);
      StringNode = (Scaleform::GFx::AS2::Environment *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                         v66->pStringManager,
                                                         v65);
      v68 = val;
      v43 = (Scaleform::GFx::ASStringNode *)StringNode;
      ++StringNode->Stack.pPageEnd;
      penv = (Scaleform::GFx::ASStringNode *)StringNode;
      Scaleform::GFx::AS2::Value::SetString(v68, (const Scaleform::GFx::ASString *)&penv);
      v45 = v43->RefCount-- == 1;
      if ( v45 )
      {
LABEL_47:
        Scaleform::GFx::ASStringNode::ReleaseNode(v43);
        return 1;
      }
      return 1;
    case M_width:
      v73 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v73 )
        goto LABEL_13;
      Scaleform::GFx::AS2::Value::SetNumber(val, (double)*(unsigned __int8 *)(v73 + 32));
      return 1;
    case M_height:
      v39 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v39 )
        goto LABEL_13;
      if ( *(_BYTE *)(v39 + 32) == 1 )
        goto LABEL_12;
      v40 = *(__m128i ***)(v39 + 12);
LABEL_45:
      v41 = *v40;
      v42 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v6->StringContext.pContext);
      v43 = Scaleform::GFx::ASStringManager::CreateStringNode(v42->pStringManager, v41);
LABEL_46:
      v44 = val;
      ++v43->RefCount;
      penv = v43;
      Scaleform::GFx::AS2::Value::SetString(v44, (const Scaleform::GFx::ASString *)&penv);
      v45 = v43->RefCount-- == 1;
      if ( v45 )
        goto LABEL_47;
      return 1;
    case M_rotation:
      v61 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v61 )
        goto LABEL_13;
      v62 = *(Scaleform::GFx::XML::ElementNode **)(v61 + 16);
      if ( !v62 )
        goto LABEL_12;
      v63 = v62->pShadow;
      if ( v63 )
      {
        v20 = (Scaleform::GFx::AS2::Object *)v63[1].__vftable;
        if ( v20 )
          goto LABEL_19;
      }
      v64 = Scaleform::GFx::AS2::CreateShadow(
              &v78,
              v6,
              v62,
              (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(val, v64->pObject);
      v12 = v78.pObject;
      goto LABEL_9;
    case M_target:
      v70 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v70 || *(_BYTE *)(v70 + 32) != 1 )
        goto LABEL_13;
      v71 = **(__m128i ***)(v70 + 36);
      v72 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v6->StringContext.pContext);
      v43 = Scaleform::GFx::ASStringManager::CreateStringNode(v72->pStringManager, v71);
      goto LABEL_46;
    case M_framesloaded:
      v57 = *(_DWORD *)&this->ResolveHandler.Flags;
      if ( !v57 )
      {
LABEL_13:
        v16 = val;
        Scaleform::GFx::AS2::Value::DropRefs(val);
        v16->T.Type = 0;
        return 1;
      }
      v58 = *(Scaleform::GFx::XML::ElementNode **)(v57 + 20);
      if ( !v58 )
      {
LABEL_12:
        v15 = val;
        Scaleform::GFx::AS2::Value::DropRefs(val);
        v15->T.Type = 1;
        return 1;
      }
      v59 = v58->pShadow;
      if ( !v59 || (v20 = (Scaleform::GFx::AS2::Object *)v59[1].__vftable) == 0 )
      {
        v60 = Scaleform::GFx::AS2::CreateShadow(
                &v77,
                v6,
                v58,
                (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
        Scaleform::GFx::AS2::Value::SetAsObject(val, v60->pObject);
        v12 = v77.pObject;
LABEL_9:
        if ( v12 )
        {
          v13 = v12->RefCount;
          if ( (v13 & 0x3FFFFFF) != 0 )
          {
            v12->RefCount = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
            return 1;
          }
        }
        return 1;
      }
LABEL_19:
      Scaleform::GFx::AS2::Value::SetAsObject(val, v20);
      v14 = 1;
      break;
    default:
      return Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::GetMember(
               (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::GASIme,Scaleform::GFx::AS2::Environment> *)this,
               v6,
               v4,
               val);
  }
  return v14;
}
