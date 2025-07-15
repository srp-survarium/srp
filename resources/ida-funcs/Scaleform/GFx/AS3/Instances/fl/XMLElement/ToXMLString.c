void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::ToXMLString(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::StringBuffer *buf,
        int ident,
        const Scaleform::GFx::AS3::NamespaceArray *ancestorNamespaces,
        Scaleform::GFx::AS3::Instances::fl::Namespace *usedNotDeclared)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::Class *Constructor; // eax
  int pRCC; // ecx
  char v10; // al
  unsigned int v11; // edi
  unsigned int Size; // ebx
  const Scaleform::MemoryHeap *MHeap; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v14; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v15; // ebp
  unsigned int pRCCRaw; // ebx
  unsigned int j; // edi
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v18; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v19; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pV; // edx
  int v22; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v23; // ecx
  unsigned int v24; // ebp
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v25; // ecx
  int v26; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v27; // ebx
  int v28; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v29; // ecx
  unsigned int RefCount; // eax
  unsigned int v31; // ebp
  unsigned int k; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v33; // edi
  const Scaleform::GFx::AS3::NamespaceArray *pStringManager; // eax
  Scaleform::GFx::ASStringNode *v35; // eax
  Scaleform::StringBuffer *v36; // ebp
  Scaleform::GFx::AS3::Instances::fl::Namespace *v37; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v38; // esi
  Scaleform::GFx::AS3::Value::V1U v39; // esi
  bool v40; // zf
  Scaleform::StringBuffer *v41; // edi
  int (__thiscall *v42)(Scaleform::StringBuffer *); // eax
  int v43; // eax
  const Scaleform::GFx::AS3::NamespaceArray *v44; // esi
  int v45; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v46; // ecx
  const Scaleform::MemoryHeap **p_pHeap; // ebx
  Scaleform::GFx::AS3::Value *p_Policy; // esi
  const Scaleform::GFx::AS3::NamespaceArray *v49; // eax
  int v50; // edx
  Scaleform::GFx::ASStringNode *v51; // eax
  Scaleform::GFx::ASStringNode *v52; // ebx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v53; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *VInt; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v56; // ecx
  unsigned int v57; // eax
  unsigned int m; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v59; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *Namespace; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v61; // ebx
  Scaleform::GFx::ASStringManager *v62; // eax
  Scaleform::GFx::ASStringNode *v63; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v64; // eax
  Scaleform::GFx::AS3::Value::V1U v65; // esi
  unsigned int v66; // eax
  unsigned int v67; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v68; // ebx
  unsigned int v69; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v70; // esi
  bool v71; // al
  int v72; // ebx
  unsigned int n; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v74; // ecx
  int ii; // edi
  unsigned int v76; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v77; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *Data; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v79; // esi
  Scaleform::GFx::AS3::Value::V1U v80; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v81; // ecx
  unsigned int v82; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *v83; // esi
  bool prettyPrinting; // [esp+21h] [ebp-65h]
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v85; // [esp+22h] [ebp-64h]
  Scaleform::GFx::AS3::VM *vm; // [esp+26h] [ebp-60h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> result; // [esp+2Ah] [ebp-5Ch] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> v88; // [esp+2Eh] [ebp-58h] BYREF
  unsigned int i; // [esp+32h] [ebp-54h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> nsCopy; // [esp+36h] [ebp-50h]
  Scaleform::GFx::ASStringNode *v91; // [esp+3Ah] [ebp-4Ch]
  unsigned int sizeAD; // [esp+3Eh] [ebp-48h]
  int prettyIndent; // [esp+42h] [ebp-44h]
  Scaleform::GFx::AS3::NamespaceArray ancestorsAndDeclarations; // [esp+46h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::NamespaceArray namespaceDeclarations; // [esp+56h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::NamespaceArray attrNamespaces; // [esp+66h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+76h] [ebp-10h] BYREF

  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  v85 = this;
  vm = pVM;
  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(pObject);
  pRCC = (int)Constructor[1]._pRCC;
  v10 = HIBYTE(Constructor[1].__vftable);
  v11 = 0;
  prettyIndent = pRCC;
  prettyPrinting = v10;
  if ( pRCC >= 0 )
  {
    if ( v10 && ident > 0 )
      Scaleform::GFx::AS3::Instances::fl::XML::AppendIdent(buf, ident);
  }
  else
  {
    prettyPrinting = 0;
    prettyIndent = 0;
  }
  ancestorsAndDeclarations.Namespaces.Data.pHeap = pVM->MHeap;
  memset((void *)&ancestorsAndDeclarations, 0, 12);
  if ( ancestorNamespaces )
    Scaleform::GFx::AS3::NamespaceArray::AddUnique(&ancestorsAndDeclarations, ancestorNamespaces);
  Size = this->Namespaces.Data.Size;
  MHeap = pVM->MHeap;
  memset((void *)&namespaceDeclarations, 0, 12);
  namespaceDeclarations.Namespaces.Data.pHeap = MHeap;
  if ( Size )
  {
    do
    {
      v14 = this->Namespaces.Data.Data[v11].pObject;
      if ( !Scaleform::GFx::AS3::NamespaceArray::Find(&ancestorsAndDeclarations, v14) )
      {
        Scaleform::GFx::AS3::NamespaceArray::Add(&namespaceDeclarations, v14, 1);
        Scaleform::GFx::AS3::NamespaceArray::Add(&ancestorsAndDeclarations, v14, 0);
      }
      ++v11;
    }
    while ( v11 < Size );
  }
  v15 = usedNotDeclared;
  if ( usedNotDeclared )
  {
    pRCCRaw = usedNotDeclared->pRCCRaw;
    for ( j = 0; j < pRCCRaw; ++j )
    {
      v18 = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)*((_DWORD *)&v15->ForEachChild_GC + j);
      if ( !Scaleform::GFx::AS3::NamespaceArray::Find(&ancestorsAndDeclarations, v18) )
      {
        Scaleform::GFx::AS3::NamespaceArray::Add(&namespaceDeclarations, v18, 1);
        Scaleform::GFx::AS3::NamespaceArray::Add(&ancestorsAndDeclarations, v18, 0);
      }
    }
  }
  v19 = v85->Ns.pObject;
  attrNamespaces.Namespaces.Data.pHeap = vm->MHeap;
  VMRef = v19->VMRef;
  memset((void *)&attrNamespaces, 0, 12);
  Scaleform::GFx::AS3::VM::MakeNamespace(VMRef, &result, NS_Public, &v19->Uri, &v19->Prefix);
  pV = result.pV;
  v22 = 0;
  if ( ancestorsAndDeclarations.Namespaces.Data.Size )
  {
    while ( 1 )
    {
      v23 = ancestorsAndDeclarations.Namespaces.Data.Data[v22].pObject;
      if ( v23->Uri.pNode == result.pV->Uri.pNode )
        break;
      if ( ++v22 >= ancestorsAndDeclarations.Namespaces.Data.Size )
        goto LABEL_22;
    }
    Scaleform::GFx::AS3::Value::Assign(&result.pV->Prefix, &v23->Prefix);
    pV = result.pV;
  }
LABEL_22:
  nsCopy.pObject = pV;
  Scaleform::GFx::AS3::NamespaceArray::Add(&attrNamespaces, pV, 1);
  v24 = 0;
  usedNotDeclared = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v85->Attrs.Data.Size;
  if ( usedNotDeclared )
  {
    do
    {
      v25 = v85->Attrs.Data.Data[v24].pObject;
      v26 = (int)v25->GetNamespace(v25);
      Scaleform::GFx::AS3::VM::MakeNamespace(
        *(Scaleform::GFx::AS3::VM **)(v26 + 24),
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&ancestorNamespaces,
        NS_Public,
        (const Scaleform::GFx::ASString *)(v26 + 28),
        (const Scaleform::GFx::AS3::Value *)(v26 + 40));
      v27 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)ancestorNamespaces;
      v28 = 0;
      if ( ancestorsAndDeclarations.Namespaces.Data.Size )
      {
        while ( 1 )
        {
          v29 = ancestorsAndDeclarations.Namespaces.Data.Data[v28].pObject;
          if ( v29->Uri.pNode == (Scaleform::GFx::ASStringNode *)ancestorNamespaces[1].Namespaces.Data.pHeap )
            break;
          if ( ++v28 >= ancestorsAndDeclarations.Namespaces.Data.Size )
            goto LABEL_28;
        }
        Scaleform::GFx::AS3::Value::Assign(
          (Scaleform::GFx::AS3::Value *)&ancestorNamespaces[2].Namespaces.Data.Policy,
          &v29->Prefix);
        v27 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)ancestorNamespaces;
      }
LABEL_28:
      Scaleform::GFx::AS3::NamespaceArray::Add(&attrNamespaces, v27, 1);
      if ( v27 )
      {
        if ( ((unsigned __int8)v27 & 1) == 0 )
        {
          RefCount = v27->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v27->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27);
          }
        }
      }
      ++v24;
    }
    while ( v24 < (unsigned int)usedNotDeclared );
  }
  v31 = attrNamespaces.Namespaces.Data.Size;
  for ( k = 0; k < v31; ++k )
  {
    v33 = attrNamespaces.Namespaces.Data.Data[k].pObject;
    if ( !Scaleform::GFx::AS3::NamespaceArray::Find(&ancestorsAndDeclarations, v33) && v33->Uri.pNode->Size )
    {
      if ( (v33->Prefix.Flags & 0x1F) == 0 )
      {
        pStringManager = (const Scaleform::GFx::AS3::NamespaceArray *)vm->StringManagerRef->pStringManager;
        ancestorNamespaces = pStringManager + 2;
        ++pStringManager[2].Namespaces.Data.pHeap;
        while ( Scaleform::GFx::AS3::NamespaceArray::FindByPrefix(
                  &ancestorsAndDeclarations,
                  (const Scaleform::GFx::ASString *)&ancestorNamespaces) )
          Scaleform::GFx::ASString::Append(
            (Scaleform::GFx::ASString *)&ancestorNamespaces,
            (const __m128i *)"aaa",
            (Scaleform::GFx::ASStringNode *)3);
        Scaleform::GFx::AS3::Value::Value(&other, (const Scaleform::GFx::ASString *)&ancestorNamespaces);
        Scaleform::GFx::AS3::Value::Assign(&v33->Prefix, &other);
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
        v35 = (Scaleform::GFx::ASStringNode *)ancestorNamespaces;
        --ancestorNamespaces->Namespaces.Data.pHeap;
        if ( !v35->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
      }
      Scaleform::GFx::AS3::NamespaceArray::Add(&namespaceDeclarations, v33, 1);
      Scaleform::GFx::AS3::NamespaceArray::Add(&ancestorsAndDeclarations, v33, 1);
    }
  }
  v36 = buf;
  Scaleform::StringBuffer::AppendChar(buf, 0x3Cu);
  v37 = v85->pTraits.pObject->pVM->DefXMLNamespace.pObject;
  v38 = attrNamespaces.Namespaces.Data.Data->pObject;
  if ( (!v37 || v37->Uri.pNode != v38->Uri.pNode || !Scaleform::GFx::AS3::StrictEqual(&v37->Prefix, &v38->Prefix))
    && (v38->Prefix.Flags & 0x1F) == 0xA )
  {
    v39 = v38->Prefix.value.VS._1;
    if ( *(_DWORD *)(v39.VInt + 20) )
    {
      Scaleform::StringBuffer::AppendString(v36, *(const __m128i **)v39.VInt, *(_DWORD *)(v39.VInt + 20));
      Scaleform::StringBuffer::AppendChar(v36, 0x3Au);
    }
  }
  Scaleform::StringBuffer::AppendString(v36, (const __m128i *)v85->Text.pNode->pData, v85->Text.pNode->Size);
  v40 = v85->Attrs.Data.Size == 0;
  i = 0;
  if ( !v40 )
  {
    do
    {
      Scaleform::StringBuffer::AppendChar(v36, 0x20u);
      v41 = (Scaleform::StringBuffer *)v85->Attrs.Data.Data[i].pObject;
      v42 = (int (__thiscall *)(Scaleform::StringBuffer *))*((_DWORD *)v41->pData + 31);
      buf = v41;
      v43 = v42(v41);
      Scaleform::GFx::AS3::VM::MakeNamespace(
        *(Scaleform::GFx::AS3::VM **)(v43 + 24),
        &v88,
        NS_Public,
        (const Scaleform::GFx::ASString *)(v43 + 28),
        (const Scaleform::GFx::AS3::Value *)(v43 + 40));
      v44 = (const Scaleform::GFx::AS3::NamespaceArray *)v88.pV;
      v45 = 0;
      if ( ancestorsAndDeclarations.Namespaces.Data.Size )
      {
        while ( 1 )
        {
          v46 = ancestorsAndDeclarations.Namespaces.Data.Data[v45].pObject;
          if ( v46->Uri.pNode == v88.pV->Uri.pNode )
            break;
          if ( ++v45 >= ancestorsAndDeclarations.Namespaces.Data.Size )
            goto LABEL_60;
        }
        Scaleform::GFx::AS3::Value::Assign(&v88.pV->Prefix, &v46->Prefix);
        v44 = (const Scaleform::GFx::AS3::NamespaceArray *)v88.pV;
LABEL_60:
        v41 = buf;
      }
      v40 = v44[1].Namespaces.Data.pHeap->OwnerThreadId == 0;
      p_pHeap = &v44[1].Namespaces.Data.pHeap;
      usedNotDeclared = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v44;
      if ( !v40 )
      {
        p_Policy = (Scaleform::GFx::AS3::Value *)&v44[2].Namespaces.Data.Policy;
        if ( (p_Policy->Flags & 0x1F) == 0 )
        {
          v49 = (const Scaleform::GFx::AS3::NamespaceArray *)vm->StringManagerRef->pStringManager;
          ancestorNamespaces = v49 + 2;
          ++v49[2].Namespaces.Data.pHeap;
          sizeAD = ancestorsAndDeclarations.Namespaces.Data.Size;
          while ( Scaleform::GFx::AS3::NamespaceArray::FindByPrefix(
                    &ancestorsAndDeclarations,
                    (const Scaleform::GFx::ASString *)&ancestorNamespaces) )
            Scaleform::GFx::ASString::Append(
              (Scaleform::GFx::ASString *)&ancestorNamespaces,
              (const __m128i *)"aaa",
              (Scaleform::GFx::ASStringNode *)3);
          Scaleform::GFx::AS3::Value::Value(&other, (const Scaleform::GFx::ASString *)&ancestorNamespaces);
          Scaleform::GFx::AS3::Value::Assign(p_Policy, &other);
          if ( (other.Flags & 0x1F) > 9 )
          {
            if ( (other.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
          }
          v50 = 0;
          LOBYTE(buf) = 0;
          if ( sizeAD )
          {
            v51 = (Scaleform::GFx::ASStringNode *)*p_pHeap;
            v52 = (Scaleform::GFx::ASStringNode *)ancestorNamespaces;
            v91 = v51;
            while ( 1 )
            {
              v53 = ancestorsAndDeclarations.Namespaces.Data.Data[v50].pObject;
              if ( (v53->Prefix.Flags & 0x1F) == 0
                || (v53->Prefix.Flags & 0x1F) - 12 <= 3 && !v53->Prefix.value.VS._1.VInt )
              {
                if ( !ancestorNamespaces[1].Namespaces.Data.Size
                  || (pNode = v53->Uri.pNode, LOBYTE(buf) = 0, pNode == v91) )
                {
                  LOBYTE(buf) = 1;
                }
              }
              if ( v53->Uri.pNode == v91 && ((*((_BYTE *)usedNotDeclared + 20) ^ *((_BYTE *)v53 + 20)) & 0xF) == 0 )
                break;
              if ( ++v50 >= sizeAD )
              {
                if ( (_BYTE)buf )
                  break;
                goto LABEL_82;
              }
            }
          }
          else
          {
LABEL_82:
            Scaleform::GFx::AS3::NamespaceArray::Add(&namespaceDeclarations, usedNotDeclared, 1);
            v52 = (Scaleform::GFx::ASStringNode *)ancestorNamespaces;
          }
          if ( !--v52->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v52);
        }
      }
      if ( (usedNotDeclared->Prefix.Flags & 0x1F) == 0xA )
      {
        VInt = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *)usedNotDeclared->Prefix.value.VS._1.VInt;
        if ( VInt[5].pObject )
        {
          Scaleform::StringBuffer::AppendString(v36, (const __m128i *)VInt->pObject, (unsigned int)VInt[5].pObject);
          Scaleform::StringBuffer::AppendChar(v36, 0x3Au);
        }
      }
      Scaleform::StringBuffer::AppendString(
        v36,
        *(const __m128i **)v41[1].BufferSize,
        *(_DWORD *)(v41[1].BufferSize + 20));
      Scaleform::StringBuffer::AppendString(v36, (const __m128i *)"=\"", 0xFFFFFFFF);
      (*((void (__thiscall **)(Scaleform::StringBuffer *, Scaleform::StringBuffer *, int, Scaleform::GFx::AS3::NamespaceArray *, _DWORD))v41->pData
       + 25))(
        v41,
        v36,
        ident,
        &ancestorsAndDeclarations,
        0);
      Scaleform::StringBuffer::AppendChar(v36, 0x22u);
      v56 = usedNotDeclared;
      if ( ((unsigned __int8)usedNotDeclared & 1) == 0 )
      {
        v57 = usedNotDeclared->RefCount;
        if ( (v57 & 0x3FFFFF) != 0 )
        {
          usedNotDeclared->RefCount = v57 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v56);
        }
      }
      ++i;
    }
    while ( i < v85->Attrs.Data.Size );
  }
  for ( m = 0; m < namespaceDeclarations.Namespaces.Data.Size; ++m )
  {
    v59 = namespaceDeclarations.Namespaces.Data.Data[m].pObject;
    Scaleform::StringBuffer::AppendString(v36, (const __m128i *)" xmlns", 0xFFFFFFFF);
    Namespace = Scaleform::GFx::AS3::VM::MakeNamespace(
                  vm,
                  (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&ancestorNamespaces,
                  NS_Public,
                  &v59->Uri,
                  &v59->Prefix);
    v61 = Namespace->pV;
    if ( Namespace->pV->Uri.pNode->Size && (v61->Prefix.Flags & 0x1F) == 0 )
    {
      v62 = vm->StringManagerRef->pStringManager;
      buf = (Scaleform::StringBuffer *)&v62->EmptyStringNode;
      ++v62->EmptyStringNode.RefCount;
      while ( Scaleform::GFx::AS3::NamespaceArray::FindByPrefix(
                &ancestorsAndDeclarations,
                (const Scaleform::GFx::ASString *)&buf) )
        Scaleform::GFx::ASString::Append(
          (Scaleform::GFx::ASString *)&buf,
          (const __m128i *)"aaa",
          (Scaleform::GFx::ASStringNode *)3);
      Scaleform::GFx::AS3::Value::Value(&other, (const Scaleform::GFx::ASString *)&buf);
      Scaleform::GFx::AS3::Value::Assign(&v61->Prefix, &other);
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
      v63 = (Scaleform::GFx::ASStringNode *)buf;
      --buf->GrowSize;
      if ( !v63->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v63);
    }
    v64 = v85->pTraits.pObject->pVM->DefXMLNamespace.pObject;
    if ( (!v64 || v64->Uri.pNode != v61->Uri.pNode || !Scaleform::GFx::AS3::StrictEqual(&v64->Prefix, &v61->Prefix))
      && (v61->Prefix.Flags & 0x1F) == 0xA )
    {
      v65 = v61->Prefix.value.VS._1;
      if ( *(_DWORD *)(v65.VInt + 20) )
      {
        Scaleform::StringBuffer::AppendChar(v36, 0x3Au);
        Scaleform::StringBuffer::AppendString(v36, *(const __m128i **)v65.VInt, *(_DWORD *)(v65.VInt + 20));
      }
    }
    Scaleform::StringBuffer::AppendString(v36, (const __m128i *)"=\"", 0xFFFFFFFF);
    Scaleform::StringBuffer::AppendString(v36, (const __m128i *)v61->Uri.pNode->pData, v61->Uri.pNode->Size);
    Scaleform::StringBuffer::AppendChar(v36, 0x22u);
    if ( ((unsigned __int8)v61 & 1) == 0 )
    {
      v66 = v61->RefCount;
      if ( (v66 & 0x3FFFFF) != 0 )
      {
        v61->RefCount = v66 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v61);
      }
    }
  }
  v67 = v85->Children.Data.Size;
  v68 = nsCopy.pObject;
  if ( v67 )
  {
    Scaleform::StringBuffer::AppendChar(v36, 0x3Eu);
    v71 = v67 > 1 || v85->Children.Data.Data->pObject->GetKind(v85->Children.Data.Data->pObject) != kText;
    LOBYTE(buf) = v71;
    if ( prettyPrinting && v71 )
      v72 = prettyIndent + ident;
    else
      v72 = 0;
    for ( n = 0; n < v67; ++n )
    {
      if ( prettyPrinting && (_BYTE)buf )
        Scaleform::StringBuffer::AppendChar(v36, 0xAu);
      v74 = v85->Children.Data.Data[n].pObject;
      v74->ToXMLString(v74, v36, v72, &ancestorsAndDeclarations, 0);
    }
    if ( prettyPrinting )
    {
      if ( (_BYTE)buf )
      {
        Scaleform::StringBuffer::AppendChar(v36, 0xAu);
        for ( ii = ident; ii; ii -= v76 )
        {
          v76 = ii;
          if ( ii >= 10 )
            v76 = 10;
          Scaleform::StringBuffer::AppendString(v36, (const __m128i *)offsets[v76], v76);
        }
      }
    }
    Scaleform::StringBuffer::AppendString(v36, (const __m128i *)"</", 0xFFFFFFFF);
    v77 = v85->pTraits.pObject->pVM->DefXMLNamespace.pObject;
    Data = attrNamespaces.Namespaces.Data.Data;
    v79 = attrNamespaces.Namespaces.Data.Data->pObject;
    if ( (!v77 || v77->Uri.pNode != v79->Uri.pNode || !Scaleform::GFx::AS3::StrictEqual(&v77->Prefix, &v79->Prefix))
      && (v79->Prefix.Flags & 0x1F) == 0xA )
    {
      v80 = v79->Prefix.value.VS._1;
      if ( *(_DWORD *)(v80.VInt + 20) )
      {
        Scaleform::StringBuffer::AppendString(v36, *(const __m128i **)v80.VInt, *(_DWORD *)(v80.VInt + 20));
        Scaleform::StringBuffer::AppendChar(v36, 0x3Au);
      }
    }
    Scaleform::StringBuffer::AppendString(v36, (const __m128i *)v85->Text.pNode->pData, v85->Text.pNode->Size);
    Scaleform::StringBuffer::AppendChar(v36, 0x3Eu);
    v81 = nsCopy.pObject;
    if ( nsCopy.pObject )
    {
      if ( ((int)nsCopy.pObject & 1) == 0 )
      {
        v82 = nsCopy.pObject->RefCount;
        if ( (v82 & 0x3FFFFF) != 0 )
        {
          nsCopy.pObject->RefCount = v82 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v81);
        }
      }
    }
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)Data,
      attrNamespaces.Namespaces.Data.Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  }
  else
  {
    Scaleform::StringBuffer::AppendString(v36, (const __m128i *)"/>", 0xFFFFFFFF);
    if ( v68 )
    {
      if ( ((unsigned __int8)v68 & 1) == 0 )
      {
        v69 = v68->RefCount;
        if ( (v69 & 0x3FFFFF) != 0 )
        {
          v68->RefCount = v69 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v68);
        }
      }
    }
    v70 = attrNamespaces.Namespaces.Data.Data;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)attrNamespaces.Namespaces.Data.Data,
      attrNamespaces.Namespaces.Data.Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v70);
  }
  v83 = namespaceDeclarations.Namespaces.Data.Data;
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)namespaceDeclarations.Namespaces.Data.Data,
    namespaceDeclarations.Namespaces.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v83);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)ancestorsAndDeclarations.Namespaces.Data.Data,
    ancestorsAndDeclarations.Namespaces.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ancestorsAndDeclarations.Namespaces.Data.Data);
}
