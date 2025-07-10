void __cdecl Scaleform::GFx::AS3::XMLParser::StartElementExpatCallback(char *userData, char *name, const char **atts)
{
  const void *v3; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v4; // edi
  unsigned int v5; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax
  Scaleform::GFx::AS3::VM *HashFlags; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ecx
  const Scaleform::MemoryHeap *MHeap; // edx
  const char **v10; // ebp
  const char *v11; // edx
  unsigned int v12; // ecx
  Scaleform::GFx::AS3::StringManager *v13; // edi
  Scaleform::GFx::ASStringNode *v14; // esi
  Scaleform::GFx::ASStringNode *v15; // eax
  char *v16; // eax
  const char **v17; // ebp
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::AS3::VM *v19; // ecx
  Scaleform::GFx::ASStringNode *v20; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v21; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v22; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v23; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v24; // ebx
  unsigned int v25; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v26; // esi
  unsigned int v27; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  const char *v29; // eax
  const char *v30; // ebx
  const Scaleform::GFx::AS3::VM::Error *v31; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v33; // esi
  const Scaleform::GFx::AS3::VM::Error *v34; // eax
  Scaleform::GFx::ASStringNode *v35; // eax
  Scaleform::GFx::AS3::StringManager *v36; // ebp
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::ASStringManager *v38; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringNode *v40; // edi
  bool v41; // zf
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v44; // ebp
  int v45; // ebx
  Scaleform::GFx::ASStringNode *VStr; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi
  int v48; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v49; // esi
  int v50; // eax
  int v51; // ecx
  int v52; // eax
  Scaleform::GFx::ASStringNode *v53; // ebp
  int v54; // ecx
  int (__thiscall *v55)(int, int, _DWORD); // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v56; // ebx
  _DWORD *v57; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v58; // eax
  Scaleform::GFx::ASStringNode *v59; // eax
  const Scaleform::GFx::AS3::VM::Error *v60; // eax
  Scaleform::GFx::ASStringNode *v61; // eax
  Scaleform::GFx::ASStringNode *v62; // ecx
  Scaleform::GFx::ASStringNode *v63; // eax
  int v64; // ecx
  unsigned int v65; // eax
  const void *v66; // ebx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v67; // edi
  unsigned int v68; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v69; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v70; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v71; // eax
  unsigned int v72; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v73; // ebp
  const char *pData; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Size; // edi
  unsigned int v76; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v77; // ecx
  _DWORD *p_pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v79; // eax
  Scaleform::GFx::ASStringManager *v80; // ebp
  const char **v81; // edx
  Scaleform::GFx::ASStringNode *v82; // ebp
  char *v83; // esi
  int v84; // eax
  int v85; // edi
  Scaleform::GFx::ASStringNode *v86; // ebx
  Scaleform::GFx::ASStringNode *v87; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v88; // esi
  Scaleform::GFx::ASStringNode *v89; // esi
  Scaleform::GFx::ASStringNode *v90; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Flags; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v92; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> v93; // ecx
  unsigned int RefCount; // eax
  unsigned int v95; // edx
  Scaleform::GFx::AS3::Instances::fl::XML *v96; // ecx
  Scaleform::GFx::ASStringNode *v97; // ecx
  Scaleform::GFx::ASStringNode *v98; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v99; // esi
  char v100; // [esp+1Fh] [ebp-45h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> ptr_el; // [esp+20h] [ebp-44h] BYREF
  Scaleform::GFx::AS3::StringManager *sm; // [esp+24h] [ebp-40h]
  Scaleform::GFx::AS3::VM *vm; // [esp+28h] [ebp-3Ch]
  Scaleform::GFx::ASString ns_prefix; // [esp+2Ch] [ebp-38h] BYREF
  Scaleform::GFx::ASStringNode *v105; // [esp+30h] [ebp-34h] BYREF
  Scaleform::GFx::ASString v; // [esp+34h] [ebp-30h] BYREF
  Scaleform::GFx::ASString ns_uri; // [esp+38h] [ebp-2Ch] BYREF
  Scaleform::GFx::ASString aname; // [esp+3Ch] [ebp-28h] BYREF
  Scaleform::GFx::ASString value; // [esp+40h] [ebp-24h] BYREF
  Scaleform::GFx::AS3::Value prefix; // [esp+44h] [ebp-20h] BYREF
  Scaleform::ArrayDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> namespaces; // [esp+54h] [ebp-10h] BYREF
  const char **attsa; // [esp+70h] [ebp+Ch]

  v105 = 0;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind((Scaleform::GFx::AS3::XMLParser *)userData, kElement);
  v3 = (const void *)*((_DWORD *)userData + 13);
  v4 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)(userData + 40);
  v5 = *((_DWORD *)userData + 11) + 1;
  if ( v5 >= *((_DWORD *)userData + 11) )
  {
    if ( v5 >= *((_DWORD *)userData + 12) )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v4,
        v3,
        v5 + (v5 >> 2));
  }
  else if ( v5 < *((_DWORD *)userData + 12) >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v4,
      v3,
      *((_DWORD *)userData + 11) + 1);
  }
  Data = v4->Data;
  *((_DWORD *)userData + 11) = v5;
  Data[v5 - 1] = (const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)1;
  value.pNode = (Scaleform::GFx::ASStringNode *)*((_DWORD *)userData + 2);
  HashFlags = (Scaleform::GFx::AS3::VM *)value.pNode[2].HashFlags;
  StringManagerRef = HashFlags->StringManagerRef;
  MHeap = HashFlags->MHeap;
  vm = HashFlags;
  sm = StringManagerRef;
  memset(&namespaces, 0, 12);
  namespaces.Data.pHeap = MHeap;
  if ( !*atts )
  {
LABEL_47:
    strchr(name, *userData);
    v30 = v29;
    if ( v29 == name )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&prefix, eXMLBadQName, vm);
      Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v31);
      pWeakProxy = (Scaleform::GFx::ASStringNode *)prefix.Bonus.pWeakProxy;
      --prefix.Bonus.pWeakProxy[1].pObject;
      if ( !pWeakProxy->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
      goto LABEL_50;
    }
    v36 = sm;
    ns_prefix.pNode = &sm->pStringManager->EmptyStringNode;
    ++ns_prefix.pNode->RefCount;
    pStringManager = v36->pStringManager;
    ++pStringManager->EmptyStringNode.RefCount;
    v38 = v36->pStringManager;
    p_EmptyStringNode = &pStringManager->EmptyStringNode;
    if ( v29 )
    {
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(v38, name, v29 - name);
      StringNode->RefCount += 2;
      pNode = ns_prefix.pNode;
      --ns_prefix.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      ns_prefix.pNode = StringNode;
      v41 = StringNode->RefCount-- == 1;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
      v40 = Scaleform::GFx::ASStringManager::CreateStringNode(v36->pStringManager, (char *)v30 + 1);
      v40->RefCount += 2;
      v41 = p_EmptyStringNode->RefCount-- == 1;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
      v41 = v40->RefCount-- == 1;
    }
    else
    {
      v40 = Scaleform::GFx::ASStringManager::CreateStringNode(v38, name);
      v40->RefCount += 2;
      v41 = p_EmptyStringNode->RefCount-- == 1;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
      v41 = v40->RefCount-- == 1;
    }
    ns_uri.pNode = v40;
    if ( v41 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v40);
    v44 = namespaces.Data.Data;
    v45 = 0;
    if ( namespaces.Data.Size )
    {
      VStr = (Scaleform::GFx::ASStringNode *)userData;
      while ( 1 )
      {
        pObject = v44[v45].pObject;
        if ( (pObject->Prefix.Flags & 0x1F) != 0xA
          || (VStr = pObject->Prefix.value.VS._1.VStr,
              v105 = (Scaleform::GFx::ASStringNode *)((unsigned int)v105 | 1),
              ++VStr->RefCount,
              v100 = 1,
              VStr != ns_prefix.pNode) )
        {
          v100 = 0;
        }
        if ( ((unsigned __int8)v105 & 1) != 0 )
        {
          v105 = (Scaleform::GFx::ASStringNode *)((unsigned int)v105 & 0xFFFFFFFE);
          v41 = VStr->RefCount-- == 1;
          if ( v41 )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
        }
        if ( v100 )
          break;
        if ( ++v45 >= namespaces.Data.Size )
          goto LABEL_77;
      }
      v49 = pObject;
    }
    else
    {
LABEL_77:
      v48 = *((_DWORD *)userData + 4);
      if ( !v48
        || (v49 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)(*(int (__thiscall **)(int, Scaleform::GFx::ASString *, _DWORD))(*(_DWORD *)v48 + 180))(
                                                                     v48,
                                                                     &ns_prefix,
                                                                     0)) == 0 )
      {
        if ( ns_prefix.pNode->Size )
        {
          Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&prefix, eXMLPrefixNotBound, vm);
          Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v60);
          v61 = (Scaleform::GFx::ASStringNode *)prefix.Bonus.pWeakProxy;
          --prefix.Bonus.pWeakProxy[1].pObject;
          if ( !v61->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v61);
          XML_StopParser(*((_DWORD *)userData + 3), 0);
          v62 = ns_uri.pNode;
          v41 = ns_uri.pNode->RefCount-- == 1;
          if ( v41 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v62);
          v63 = ns_prefix.pNode;
          --ns_prefix.pNode->RefCount;
          if ( !v63->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v63);
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)v44,
            namespaces.Data.Size);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v44);
          return;
        }
        v49 = vm->DefXMLNamespace.pObject;
        if ( v49 )
        {
          v50 = 0;
          if ( namespaces.Data.Size )
          {
            while ( v44[v50].pObject->Uri.pNode != v49->Uri.pNode )
            {
              if ( ++v50 >= namespaces.Data.Size )
                goto LABEL_84;
            }
            v49 = v44[v50].pObject;
          }
          else
          {
LABEL_84:
            v51 = *((_DWORD *)userData + 4);
            if ( v51 )
            {
              v52 = (*(int (__thiscall **)(int, Scaleform::GFx::ASString *, _DWORD))(*(_DWORD *)v51 + 184))(
                      v51,
                      &v49->Uri,
                      0);
              if ( v52 )
                v49 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v52;
            }
          }
        }
        else
        {
          v49 = vm->PublicNamespace.pObject;
        }
      }
    }
    v53 = value.pNode;
    v54 = *(_DWORD *)(value.pNode[2].HashFlags + 32);
    v55 = *(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v54 + 40);
    v56 = (Scaleform::GFx::AS3::Instances::fl::XML *)*((_DWORD *)userData + 4);
    v57 = userData + 16;
    prefix.Flags = (unsigned int)(userData + 16);
    v58 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v55(v54, 80, 0);
    if ( v58 )
    {
      Scaleform::GFx::AS3::Instances::fl::XMLElement::XMLElement(
        v58,
        (Scaleform::GFx::AS3::InstanceTraits::Traits *)v53,
        v49,
        &ns_uri,
        v56);
      v.pNode = v59;
    }
    else
    {
      v.pNode = 0;
    }
    v64 = *v57;
    ptr_el.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v.pNode;
    if ( v64 && (*(int (__thiscall **)(int))(*(_DWORD *)v64 + 92))(v64) == 1 )
    {
      (*(void (__thiscall **)(_DWORD, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *))(*(_DWORD *)*v57 + 80))(
        *v57,
        &ptr_el);
    }
    else
    {
      v65 = *((_DWORD *)userData + 6);
      v66 = (const void *)*((_DWORD *)userData + 8);
      v67 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)(userData + 20);
      v68 = v65 + 1;
      if ( v65 + 1 >= v65 )
      {
        if ( v68 >= *((_DWORD *)userData + 7) )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v67,
            v66,
            v68 + (v68 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&v67->Data[v68],
          0xFFFFFFFF);
        if ( v68 < *((_DWORD *)userData + 7) >> 1 )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v67,
            v66,
            v68);
      }
      v69 = v67->Data;
      *((_DWORD *)userData + 6) = v68;
      v70 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v69[v68 - 1];
      if ( v70 )
      {
        v70->pObject = ptr_el.pObject;
        v71 = ptr_el.pObject;
        if ( ptr_el.pObject )
        {
          ++ptr_el.pObject->RefCount;
          v71->RefCount &= 0x8FBFFFFF;
        }
      }
    }
    v72 = 0;
    if ( namespaces.Data.Size )
    {
      v73 = namespaces.Data.Data;
      do
      {
        if ( (v73[v72].pObject->Prefix.Flags & 0x1F) == 0xA )
        {
          pData = v.pNode[2].pData;
          p_Size = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v.pNode[1].Size;
          v76 = (unsigned int)(pData + 1);
          if ( pData + 1 >= pData )
          {
            if ( (Scaleform::GFx::ASStringManager *)v76 >= v.pNode[2].pManager )
              Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                p_Size,
                p_Size,
                v76 + (v76 >> 2));
          }
          else
          {
            Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&p_Size->Data[v76],
              0xFFFFFFFF);
            if ( v76 < p_Size->Policy.Capacity >> 1 )
              Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                p_Size,
                p_Size,
                v76);
          }
          v77 = p_Size->Data;
          p_Size->Size = v76;
          p_pObject = &v77[v76 - 1].pObject;
          if ( p_pObject )
          {
            v79 = v73[v72].pObject;
            *p_pObject = v79;
            if ( v79 )
              v79->RefCount = (v79->RefCount + 1) & 0x8FBFFFFF;
          }
        }
        ++v72;
      }
      while ( v72 < namespaces.Data.Size );
    }
    v80 = sm->pStringManager;
    v81 = atts;
    ++v80->EmptyStringNode.RefCount;
    v82 = &v80->EmptyStringNode;
    if ( *atts )
    {
      do
      {
        v83 = (char *)*v81;
        if ( strlen(*v81) > 4 && *v83 == 120 && v83[1] == 109 && v83[2] == 108 && v83[3] == 110 && v83[4] == 115 )
        {
          attsa = v81 + 1;
        }
        else
        {
          strchr(v83, *userData);
          v85 = v84;
          attsa = atts + 1;
          v86 = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, (char *)*attsa);
          ++v86->RefCount;
          value.pNode = v86;
          if ( v85 )
          {
            v105 = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, v83, v85 - (_DWORD)v83);
            ++v105->RefCount;
            v89 = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, (char *)(v85 + 1));
            v89->RefCount += 2;
            v41 = v82->RefCount-- == 1;
            if ( v41 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v82);
            v41 = v89->RefCount-- == 1;
            v82 = v89;
            aname.pNode = v89;
            if ( v41 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v89);
            v88 = ptr_el.pObject->FindNamespaceByPrefix(ptr_el.pObject, &v105, 0);
            if ( !v88 )
              v88 = vm->PublicNamespace.pObject;
            v90 = v105;
            --v105->RefCount;
            if ( !v90->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v90);
          }
          else
          {
            v87 = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, v83);
            v87->RefCount += 2;
            v41 = v82->RefCount-- == 1;
            if ( v41 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v82);
            v41 = v87->RefCount-- == 1;
            v82 = v87;
            aname.pNode = v87;
            if ( v41 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v87);
            v88 = vm->PublicNamespace.pObject;
          }
          Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
            (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v.pNode,
            v88,
            &aname,
            &value);
          v41 = v86->RefCount-- == 1;
          if ( v41 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v86);
        }
        v81 = attsa + 1;
        v41 = attsa[1] == 0;
        atts = attsa + 1;
      }
      while ( !v41 );
    }
    Flags = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)prefix.Flags;
    if ( &ptr_el != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)prefix.Flags )
    {
      v92 = ptr_el.pObject;
      if ( ptr_el.pObject )
      {
        ++ptr_el.pObject->RefCount;
        v92->RefCount &= 0x8FBFFFFF;
      }
      v93.pObject = Flags->pObject;
      if ( Flags->pObject )
      {
        if ( ((int)v93.pObject & 1) != 0 )
        {
          Flags->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v93.pObject - 1);
        }
        else
        {
          RefCount = v93.pObject->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            v93.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v93.pObject);
          }
        }
      }
      Flags->pObject = ptr_el.pObject;
    }
    v41 = v82->RefCount-- == 1;
    if ( v41 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v82);
    if ( ptr_el.pObject )
    {
      if ( ((int)ptr_el.pObject & 1) != 0 )
      {
        --ptr_el.pObject;
      }
      else
      {
        v95 = ptr_el.pObject->RefCount;
        v96 = ptr_el.pObject;
        if ( ((unsigned int)&byte_3FFFFF & v95) != 0 )
        {
          ptr_el.pObject->RefCount = v95 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v96);
        }
      }
    }
    v97 = ns_uri.pNode;
    v41 = ns_uri.pNode->RefCount-- == 1;
    if ( v41 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v97);
    v98 = ns_prefix.pNode;
    --ns_prefix.pNode->RefCount;
    if ( !v98->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v98);
    v99 = namespaces.Data.Data;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)namespaces.Data.Data,
      namespaces.Data.Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v99);
    return;
  }
  v10 = atts;
  while ( 1 )
  {
    v11 = *v10;
    v12 = strlen(*v10);
    if ( v12 )
    {
      if ( *v11 == *userData )
        break;
    }
    if ( v12 > 4 && *v11 == 120 && v11[1] == 109 && v11[2] == 108 && v11[3] == 110 && v11[4] == 115 )
    {
      v13 = sm;
      v.pNode = &sm->pStringManager->EmptyStringNode;
      ++v.pNode->RefCount;
      if ( v12 > 5 && v11[5] == *userData )
      {
        v14 = Scaleform::GFx::ASStringManager::CreateStringNode(v13->pStringManager, (char *)v11 + 6);
        v14->RefCount += 2;
        v15 = v.pNode;
        --v.pNode->RefCount;
        if ( !v15->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        v.pNode = v14;
        v41 = v14->RefCount-- == 1;
        if ( v41 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      }
      v16 = (char *)v10[1];
      v17 = v10 + 1;
      v18 = Scaleform::GFx::ASStringManager::CreateStringNode(v13->pStringManager, v16);
      v19 = vm;
      v20 = v18;
      ++v18->RefCount;
      v21 = v19->TraitsNamespace.pObject->ITraits.pObject;
      ns_uri.pNode = v18;
      Scaleform::GFx::AS3::Value::Value(&prefix, &v);
      aname.pNode = (Scaleform::GFx::ASStringNode *)328;
      v22 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               v21,
                                                               56,
                                                               &aname);
      if ( v22 )
      {
        Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
          v22,
          v21->pVM,
          (Scaleform::GFx::Resource *)v21[1].RefCount,
          NS_Public,
          &ns_uri,
          &prefix);
        v24 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v23;
      }
      else
      {
        v24 = 0;
      }
      if ( (prefix.Flags & 0x1F) > 9 )
      {
        if ( (prefix.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prefix);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&prefix);
      }
      v25 = namespaces.Data.Size + 1;
      if ( namespaces.Data.Size + 1 >= namespaces.Data.Size )
      {
        if ( v25 >= namespaces.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&namespaces,
            namespaces.Data.pHeap,
            v25 + (v25 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&namespaces.Data.Data[v25],
          0xFFFFFFFF);
        if ( v25 < namespaces.Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&namespaces,
            namespaces.Data.pHeap,
            v25);
      }
      namespaces.Data.Size = v25;
      v26 = &namespaces.Data.Data[v25 - 1];
      if ( v26 )
      {
        v26->pObject = v24;
        if ( v24 )
        {
          v24->RefCount = (v24->RefCount + 1) & 0x8FBFFFFF;
          goto LABEL_37;
        }
      }
      else
      {
LABEL_37:
        if ( v24 )
        {
          if ( ((unsigned __int8)v24 & 1) == 0 )
          {
            v27 = v24->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & v27) != 0 )
            {
              v24->RefCount = v27 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
            }
          }
        }
      }
      v41 = v20->RefCount-- == 1;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
      v28 = v.pNode;
      --v.pNode->RefCount;
      if ( !v28->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      goto LABEL_46;
    }
    v17 = v10 + 1;
LABEL_46:
    v10 = v17 + 1;
    if ( !*v10 )
      goto LABEL_47;
  }
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&prefix, eXMLBadQName, vm);
  Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v34);
  v35 = (Scaleform::GFx::ASStringNode *)prefix.Bonus.pWeakProxy;
  --prefix.Bonus.pWeakProxy[1].pObject;
  if ( !v35->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
LABEL_50:
  XML_StopParser(*((_DWORD *)userData + 3), 0);
  v33 = namespaces.Data.Data;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)namespaces.Data.Data,
    namespaces.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v33);
}
