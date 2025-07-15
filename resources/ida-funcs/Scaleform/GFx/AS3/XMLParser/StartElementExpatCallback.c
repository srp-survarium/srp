void __cdecl Scaleform::GFx::AS3::XMLParser::StartElementExpatCallback(
        char *userData,
        __m128i *name,
        const char **atts)
{
  const void *v3; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v4; // edi
  unsigned int v5; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax
  Scaleform::GFx::AS3::VM *v7; // ebp
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  const Scaleform::MemoryHeap *MHeap; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *i; // ebx
  const char *v11; // edx
  unsigned int v12; // ecx
  Scaleform::GFx::ASStringNode *v13; // esi
  Scaleform::GFx::ASStringNode *v14; // eax
  __m128i *pRCC; // eax
  Scaleform::GFx::ASStringManager *v16; // ecx
  Scaleform::GFx::ASStringNode *v17; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v18; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v19; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v21; // ebx
  unsigned int v22; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v23; // esi
  unsigned int v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  const char *v26; // eax
  const char *v27; // ebx
  unsigned int v28; // eax
  const Scaleform::GFx::AS3::VM::Error *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v31; // esi
  const Scaleform::GFx::AS3::VM::Error *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::ASStringNode *v36; // edi
  bool v37; // zf
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v40; // ebx
  Scaleform::GFx::ASStringNode *VStr; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi
  int v43; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v44; // esi
  int v45; // eax
  int v46; // ecx
  int v47; // eax
  Scaleform::GFx::ASStringNode *v48; // ebp
  int v49; // ecx
  int (__thiscall *v50)(int, int, _DWORD); // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v51; // ebx
  _DWORD *v52; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v53; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v54; // eax
  unsigned int v55; // eax
  Scaleform::GFx::AS3::VM *v56; // esi
  const Scaleform::GFx::AS3::VM::Error *v57; // eax
  Scaleform::GFx::ASStringNode *v58; // eax
  Scaleform::GFx::ASStringNode *v59; // ecx
  Scaleform::GFx::ASStringNode *v60; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v61; // esi
  int v62; // ecx
  unsigned int v63; // eax
  const void *v64; // ebx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *v65; // edi
  unsigned int v66; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v67; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v68; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v69; // eax
  unsigned int v70; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v71; // ebp
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Namespaces; // edi
  unsigned int v74; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v75; // ecx
  _DWORD *p_pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v77; // eax
  Scaleform::GFx::ASStringManager *v78; // ebp
  const char **v79; // edx
  Scaleform::GFx::ASStringNode *v80; // ebp
  __m128i *v81; // esi
  int v82; // eax
  int v83; // edi
  Scaleform::GFx::ASStringNode *v84; // ebx
  Scaleform::GFx::ASStringNode *v85; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v86; // esi
  Scaleform::GFx::ASStringNode *v87; // esi
  Scaleform::GFx::ASStringNode *v88; // eax
  Scaleform::GFx::ASStringNode *v89; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v90; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> v91; // ecx
  unsigned int RefCount; // eax
  unsigned int v93; // edx
  Scaleform::GFx::AS3::Instances::fl::XML *v94; // ecx
  Scaleform::GFx::ASStringNode *v95; // ecx
  Scaleform::GFx::ASStringNode *v96; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v97; // esi
  Scaleform::StringDataPtr v98; // [esp+0h] [ebp-68h]
  Scaleform::StringDataPtr v99; // [esp+0h] [ebp-68h]
  Scaleform::StringDataPtr v100; // [esp+0h] [ebp-68h]
  char v101; // [esp+1Bh] [ebp-4Dh]
  Scaleform::GFx::AS3::StringManager *sm; // [esp+1Ch] [ebp-4Ch]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> ptr_el; // [esp+20h] [ebp-48h] BYREF
  Scaleform::GFx::ASString ns_prefix; // [esp+24h] [ebp-44h] BYREF
  Scaleform::GFx::ASStringNode *v105; // [esp+28h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+2Ch] [ebp-3Ch]
  Scaleform::GFx::ASString el_name; // [esp+30h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v108; // [esp+34h] [ebp-34h]
  Scaleform::GFx::ASString aname; // [esp+38h] [ebp-30h] BYREF
  Scaleform::GFx::ASString ns_uri; // [esp+3Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::ASString value; // [esp+40h] [ebp-28h] BYREF
  Scaleform::GFx::ASStringNode *v112; // [esp+44h] [ebp-24h]
  Scaleform::ArrayDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> namespaces; // [esp+48h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value prefix; // [esp+58h] [ebp-10h] BYREF
  const char **attsa; // [esp+74h] [ebp+Ch]

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
  v7 = *(Scaleform::GFx::AS3::VM **)(*((_DWORD *)userData + 2) + 64);
  StringManagerRef = v7->StringManagerRef;
  MHeap = v7->MHeap;
  value.pNode = (Scaleform::GFx::ASStringNode *)*((_DWORD *)userData + 2);
  vm = v7;
  sm = StringManagerRef;
  memset(&namespaces, 0, 12);
  namespaces.Data.pHeap = MHeap;
  if ( !*atts )
  {
LABEL_48:
    strchr(name->m128i_i8, *userData);
    v27 = v26;
    if ( v26 == (const char *)name )
    {
      v98.pStr = (const char *)name;
      if ( name )
        v28 = strlen(name->m128i_i8);
      else
        v28 = 0;
      v98.Size = v28;
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&value, eXMLBadQName, vm, v98);
      Scaleform::GFx::AS3::VM::ThrowTypeError(vm, v32);
      v33 = v112;
      --v112->RefCount;
      if ( !v33->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
      goto LABEL_53;
    }
    ns_prefix.pNode = &sm->pStringManager->EmptyStringNode;
    ++ns_prefix.pNode->RefCount;
    pStringManager = sm->pStringManager;
    ++pStringManager->EmptyStringNode.RefCount;
    p_EmptyStringNode = &pStringManager->EmptyStringNode;
    if ( v26 )
    {
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, name, v26 - (const char *)name);
      StringNode->RefCount += 2;
      pNode = ns_prefix.pNode;
      --ns_prefix.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      ns_prefix.pNode = StringNode;
      v37 = StringNode->RefCount-- == 1;
      if ( v37 )
        Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
      v36 = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, (__m128i *)(v27 + 1));
      v36->RefCount += 2;
      v37 = p_EmptyStringNode->RefCount-- == 1;
      if ( v37 )
        Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
      v37 = v36->RefCount-- == 1;
    }
    else
    {
      v36 = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, name);
      v36->RefCount += 2;
      v37 = p_EmptyStringNode->RefCount-- == 1;
      if ( v37 )
        Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
      v37 = v36->RefCount-- == 1;
    }
    el_name.pNode = v36;
    if ( v37 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v36);
    v40 = 0;
    if ( namespaces.Data.Size )
    {
      VStr = (Scaleform::GFx::ASStringNode *)userData;
      while ( 1 )
      {
        pObject = namespaces.Data.Data[v40].pObject;
        if ( (pObject->Prefix.Flags & 0x1F) != 0xA
          || (VStr = pObject->Prefix.value.VS._1.VStr,
              v105 = (Scaleform::GFx::ASStringNode *)((unsigned int)v105 | 1),
              ++VStr->RefCount,
              v101 = 1,
              VStr != ns_prefix.pNode) )
        {
          v101 = 0;
        }
        if ( ((unsigned __int8)v105 & 1) != 0 )
        {
          v105 = (Scaleform::GFx::ASStringNode *)((unsigned int)v105 & 0xFFFFFFFE);
          v37 = VStr->RefCount-- == 1;
          if ( v37 )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
        }
        if ( v101 )
          break;
        if ( ++v40 >= namespaces.Data.Size )
          goto LABEL_81;
      }
      v44 = pObject;
    }
    else
    {
LABEL_81:
      v43 = *((_DWORD *)userData + 4);
      if ( !v43
        || (v44 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)(*(int (__thiscall **)(int, Scaleform::GFx::ASString *, _DWORD))(*(_DWORD *)v43 + 192))(
                                                                     v43,
                                                                     &ns_prefix,
                                                                     0)) == 0 )
      {
        if ( ns_prefix.pNode->Size )
        {
          Scaleform::GFx::AS3::Value::Value(&prefix, &ns_prefix);
          v100.pStr = (const char *)name;
          if ( name )
            v55 = strlen(name->m128i_i8);
          else
            v55 = 0;
          v56 = vm;
          v100.Size = v55;
          Scaleform::GFx::AS3::VM::Error::Error(
            (Scaleform::GFx::AS3::VM::Error *)&value,
            eXMLPrefixNotBound,
            vm,
            &prefix,
            v100);
          Scaleform::GFx::AS3::VM::ThrowTypeError(v56, v57);
          v58 = v112;
          --v112->RefCount;
          if ( !v58->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v58);
          if ( (prefix.Flags & 0x1F) > 9 )
          {
            if ( (prefix.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prefix);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&prefix);
          }
          XML_StopParser(*((_DWORD *)userData + 3), 0);
          v59 = el_name.pNode;
          v37 = el_name.pNode->RefCount-- == 1;
          if ( v37 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v59);
          v60 = ns_prefix.pNode;
          --ns_prefix.pNode->RefCount;
          if ( !v60->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v60);
          v61 = namespaces.Data.Data;
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)namespaces.Data.Data,
            namespaces.Data.Size);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v61);
          return;
        }
        v44 = vm->DefXMLNamespace.pObject;
        if ( v44 )
        {
          v45 = 0;
          if ( namespaces.Data.Size )
          {
            while ( namespaces.Data.Data[v45].pObject->Uri.pNode != v44->Uri.pNode )
            {
              if ( ++v45 >= namespaces.Data.Size )
                goto LABEL_88;
            }
            v44 = namespaces.Data.Data[v45].pObject;
          }
          else
          {
LABEL_88:
            v46 = *((_DWORD *)userData + 4);
            if ( v46 )
            {
              v47 = (*(int (__thiscall **)(int, Scaleform::GFx::ASString *, _DWORD))(*(_DWORD *)v46 + 196))(
                      v46,
                      &v44->Uri,
                      0);
              if ( v47 )
                v44 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v47;
            }
          }
        }
        else
        {
          v44 = vm->PublicNamespace.pObject;
        }
      }
    }
    v48 = value.pNode;
    v49 = *(_DWORD *)(value.pNode[2].HashFlags + 32);
    v50 = *(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v49 + 40);
    v51 = (Scaleform::GFx::AS3::Instances::fl::XML *)*((_DWORD *)userData + 4);
    v52 = userData + 16;
    ns_uri.pNode = (Scaleform::GFx::ASStringNode *)(userData + 16);
    v53 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v50(v49, 80, 0);
    if ( v53 )
    {
      Scaleform::GFx::AS3::Instances::fl::XMLElement::XMLElement(
        v53,
        (Scaleform::GFx::AS3::InstanceTraits::Traits *)v48,
        v44,
        &el_name,
        v51);
      v108 = v54;
    }
    else
    {
      v108 = 0;
    }
    v62 = *v52;
    ptr_el.pObject = v108;
    if ( v62 && (*(int (__thiscall **)(int))(*(_DWORD *)v62 + 104))(v62) == 1 )
    {
      (*(void (__thiscall **)(_DWORD, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *))(*(_DWORD *)*v52 + 92))(
        *v52,
        &ptr_el);
    }
    else
    {
      v63 = *((_DWORD *)userData + 6);
      v64 = (const void *)*((_DWORD *)userData + 8);
      v65 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)(userData + 20);
      v66 = v63 + 1;
      if ( v63 + 1 >= v63 )
      {
        if ( v66 >= *((_DWORD *)userData + 7) )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v65,
            v64,
            v66 + (v66 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&v65->Data[v66],
          0xFFFFFFFF);
        if ( v66 < *((_DWORD *)userData + 7) >> 1 )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v65,
            v64,
            v66);
      }
      v67 = v65->Data;
      *((_DWORD *)userData + 6) = v66;
      v68 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)&v67[v66 - 1];
      if ( v68 )
      {
        v68->pObject = ptr_el.pObject;
        v69 = ptr_el.pObject;
        if ( ptr_el.pObject )
        {
          ++ptr_el.pObject->RefCount;
          v69->RefCount &= 0x8FBFFFFF;
        }
      }
    }
    v70 = 0;
    if ( namespaces.Data.Size )
    {
      v71 = namespaces.Data.Data;
      do
      {
        if ( (v71[v70].pObject->Prefix.Flags & 0x1F) == 0xA )
        {
          Size = v108->Namespaces.Data.Size;
          p_Namespaces = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v108->Namespaces;
          v74 = Size + 1;
          if ( Size + 1 >= Size )
          {
            if ( v74 >= v108->Namespaces.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                p_Namespaces,
                p_Namespaces,
                v74 + (v74 >> 2));
          }
          else
          {
            Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&p_Namespaces->Data[v74],
              0xFFFFFFFF);
            if ( v74 < p_Namespaces->Policy.Capacity >> 1 )
              Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                p_Namespaces,
                p_Namespaces,
                v74);
          }
          v75 = p_Namespaces->Data;
          p_Namespaces->Size = v74;
          p_pObject = &v75[v74 - 1].pObject;
          if ( p_pObject )
          {
            v77 = v71[v70].pObject;
            *p_pObject = v77;
            if ( v77 )
              v77->RefCount = (v77->RefCount + 1) & 0x8FBFFFFF;
          }
        }
        ++v70;
      }
      while ( v70 < namespaces.Data.Size );
    }
    v78 = sm->pStringManager;
    v79 = atts;
    ++v78->EmptyStringNode.RefCount;
    v80 = &v78->EmptyStringNode;
    if ( *atts )
    {
      do
      {
        v81 = (__m128i *)*v79;
        if ( strlen(*v79) > 4
          && v81->m128i_i8[0] == 120
          && v81->m128i_i8[1] == 109
          && v81->m128i_i8[2] == 108
          && v81->m128i_i8[3] == 110
          && v81->m128i_i8[4] == 115 )
        {
          attsa = v79 + 1;
        }
        else
        {
          strchr(v81->m128i_i8, *userData);
          v83 = v82;
          attsa = atts + 1;
          v84 = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, (__m128i *)*attsa);
          ++v84->RefCount;
          value.pNode = v84;
          if ( v83 )
          {
            v105 = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, v81, v83 - (_DWORD)v81);
            ++v105->RefCount;
            v87 = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, (__m128i *)(v83 + 1));
            v87->RefCount += 2;
            v37 = v80->RefCount-- == 1;
            if ( v37 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v80);
            v37 = v87->RefCount-- == 1;
            v80 = v87;
            aname.pNode = v87;
            if ( v37 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v87);
            v86 = ptr_el.pObject->FindNamespaceByPrefix(ptr_el.pObject, &v105, 0);
            if ( !v86 )
              v86 = vm->PublicNamespace.pObject;
            v88 = v105;
            --v105->RefCount;
            if ( !v88->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v88);
          }
          else
          {
            v85 = Scaleform::GFx::ASStringManager::CreateStringNode(sm->pStringManager, v81);
            v85->RefCount += 2;
            v37 = v80->RefCount-- == 1;
            if ( v37 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v80);
            v37 = v85->RefCount-- == 1;
            v80 = v85;
            aname.pNode = v85;
            if ( v37 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v85);
            v86 = vm->PublicNamespace.pObject;
          }
          Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v108, v86, &aname, &value);
          v37 = v84->RefCount-- == 1;
          if ( v37 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v84);
        }
        v79 = attsa + 1;
        v37 = attsa[1] == 0;
        atts = attsa + 1;
      }
      while ( !v37 );
    }
    v89 = ns_uri.pNode;
    if ( &ptr_el != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)ns_uri.pNode )
    {
      v90 = ptr_el.pObject;
      if ( ptr_el.pObject )
      {
        ++ptr_el.pObject->RefCount;
        v90->RefCount &= 0x8FBFFFFF;
      }
      v91.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)v89->pData;
      if ( v89->pData )
      {
        if ( ((int)v91.pObject & 1) != 0 )
        {
          v89->pData = (char *)&v91.pObject[-1].Parent.pObject + 3;
        }
        else
        {
          RefCount = v91.pObject->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v91.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v91.pObject);
          }
        }
      }
      v89->pData = (const char *)ptr_el.pObject;
    }
    v37 = v80->RefCount-- == 1;
    if ( v37 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v80);
    if ( ptr_el.pObject )
    {
      if ( ((int)ptr_el.pObject & 1) != 0 )
      {
        --ptr_el.pObject;
      }
      else
      {
        v93 = ptr_el.pObject->RefCount;
        v94 = ptr_el.pObject;
        if ( (v93 & 0x3FFFFF) != 0 )
        {
          ptr_el.pObject->RefCount = v93 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v94);
        }
      }
    }
    v95 = el_name.pNode;
    v37 = el_name.pNode->RefCount-- == 1;
    if ( v37 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v95);
    v96 = ns_prefix.pNode;
    --ns_prefix.pNode->RefCount;
    if ( !v96->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v96);
    v97 = namespaces.Data.Data;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)namespaces.Data.Data,
      namespaces.Data.Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v97);
    return;
  }
  for ( i = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)atts; ; i = v108 )
  {
    v11 = (const char *)i->__vftable;
    v12 = strlen((const char *)i->__vftable);
    if ( v12 )
    {
      if ( *v11 == *userData )
        break;
    }
    if ( v12 <= 4 || *v11 != 120 || v11[1] != 109 || v11[2] != 108 || v11[3] != 110 || v11[4] != 115 )
    {
      v108 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)&i->4;
      goto LABEL_47;
    }
    el_name.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
    ++el_name.pNode->RefCount;
    if ( v12 > 5 && v11[5] == *userData )
    {
      v13 = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, (__m128i *)(v11 + 6));
      v13->RefCount += 2;
      v14 = el_name.pNode;
      --el_name.pNode->RefCount;
      if ( !v14->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      el_name.pNode = v13;
      v37 = v13->RefCount-- == 1;
      if ( v37 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    }
    pRCC = (__m128i *)i->_pRCC;
    v16 = StringManagerRef->pStringManager;
    v108 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)&i->4;
    v17 = Scaleform::GFx::ASStringManager::CreateStringNode(v16, pRCC);
    ++v17->RefCount;
    v18 = v7->TraitsNamespace.pObject->ITraits.pObject;
    ns_uri.pNode = v17;
    Scaleform::GFx::AS3::Value::Value(&prefix, &el_name);
    aname.pNode = (Scaleform::GFx::ASStringNode *)328;
    v19 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             v18,
                                                             56,
                                                             &aname);
    if ( v19 )
    {
      Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
        v19,
        v18->pVM,
        (Scaleform::GFx::Resource *)v18[1].RefCount,
        NS_Public,
        &ns_uri,
        &prefix);
      v21 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v20;
    }
    else
    {
      v21 = 0;
    }
    if ( (prefix.Flags & 0x1F) > 9 )
    {
      if ( (prefix.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prefix);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&prefix);
    }
    v22 = namespaces.Data.Size + 1;
    if ( namespaces.Data.Size + 1 >= namespaces.Data.Size )
    {
      if ( v22 >= namespaces.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&namespaces,
          namespaces.Data.pHeap,
          v22 + (v22 >> 2));
    }
    else
    {
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&namespaces.Data.Data[v22],
        0xFFFFFFFF);
      if ( v22 < namespaces.Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&namespaces,
          namespaces.Data.pHeap,
          v22);
    }
    namespaces.Data.Size = v22;
    v23 = &namespaces.Data.Data[v22 - 1];
    if ( !v23 )
      goto LABEL_38;
    v23->pObject = v21;
    if ( v21 )
    {
      v21->RefCount = (v21->RefCount + 1) & 0x8FBFFFFF;
LABEL_38:
      if ( v21 )
      {
        if ( ((unsigned __int8)v21 & 1) == 0 )
        {
          v24 = v21->RefCount;
          if ( (v24 & 0x3FFFFF) != 0 )
          {
            v21->RefCount = v24 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
          }
        }
      }
    }
    v37 = v17->RefCount-- == 1;
    if ( v37 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    v25 = el_name.pNode;
    --el_name.pNode->RefCount;
    if ( !v25->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
LABEL_47:
    v37 = v108->pRCCRaw == 0;
    v108 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)v108 + 4);
    if ( v37 )
      goto LABEL_48;
    StringManagerRef = sm;
  }
  v99.Size = strlen(v11);
  v99.pStr = (const char *)i->__vftable;
  Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&value, eXMLBadQName, v7, v99);
  Scaleform::GFx::AS3::VM::ThrowTypeError(v7, v29);
  v30 = v112;
  --v112->RefCount;
  if ( !v30->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
LABEL_53:
  XML_StopParser(*((_DWORD *)userData + 3), 0);
  v31 = namespaces.Data.Data;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)namespaces.Data.Data,
    namespaces.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v31);
}
