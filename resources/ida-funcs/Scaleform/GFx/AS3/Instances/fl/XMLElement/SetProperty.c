Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::SetProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        Scaleform::GFx::AS3::Instances::fl::Namespace *value)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ebx
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS3::CheckResult *v9; // eax
  Scaleform::GFx::AS3::Value *v10; // esi
  unsigned int v11; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v12; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *pObject; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  const Scaleform::GFx::AS3::Multiname *v16; // esi
  Scaleform::GFx::AS3::Value::V1U v17; // edi
  unsigned int v18; // ebx
  unsigned int j; // esi
  int v20; // ecx
  __m128i *pData; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *VInt; // ecx
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v25; // ebx
  unsigned int v26; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *v27; // ebp
  Scaleform::GFx::AS3::Instances::fl::Namespace *Namespace; // eax
  Scaleform::GFx::AS3::CheckResult *v29; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v31; // eax
  $877A9988573213A5FC37040398A8D661 *v32; // edi
  const Scaleform::GFx::AS3::Multiname *v33; // esi
  Scaleform::MemoryHeap *MHeap; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v36; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v37; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v38; // edi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2,Scaleform::ArrayDefaultPolicy> *p_Attrs; // esi
  unsigned int Size; // ecx
  Scaleform::GFx::AS3::Value::V1U v41; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::ASStringNode *v43; // edi
  _DWORD *v44; // esi
  Scaleform::GFx::ASStringManager *v45; // eax
  Scaleform::GFx::ASStringNode *v46; // eax
  Scaleform::GFx::ASStringNode *v47; // ecx
  bool v48; // zf
  char IsAnyType; // al
  unsigned int v50; // esi
  int v51; // edi
  unsigned __int32 v52; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v53; // edi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v54; // ebx
  const Scaleform::GFx::AS3::Multiname *v55; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v56; // edi
  Scaleform::GFx::ASStringNode *v57; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v58; // ebx
  Scaleform::GFx::ASStringNode *VStr; // esi
  unsigned int v60; // eax
  Scaleform::GFx::ASStringNode *v61; // eax
  bool v62; // dl
  Scaleform::GFx::AS3::Object *pV; // [esp-4h] [ebp-6Ch]
  bool resulta; // [esp+12h] [ebp-56h] BYREF
  Scaleform::GFx::AS3::CheckResult v65; // [esp+13h] [ebp-55h] BYREF
  Scaleform::GFx::AS3::VM *vm; // [esp+14h] [ebp-54h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> a; // [esp+18h] [ebp-50h] BYREF
  Scaleform::GFx::ASString propName; // [esp+1Ch] [ebp-4Ch] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement> y; // [esp+20h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::StringManager *sm; // [esp+24h] [ebp-44h] BYREF
  Scaleform::GFx::ASStringNode *v71; // [esp+28h] [ebp-40h]
  unsigned int ind; // [esp+2Ch] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::Value c; // [esp+30h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value i; // [esp+40h] [ebp-28h] BYREF
  Scaleform::StringBuffer buf; // [esp+50h] [ebp-18h] BYREF

  pVM = this->pTraits.pObject->pVM;
  StringManagerRef = pVM->StringManagerRef;
  y.pObject = this;
  vm = pVM;
  sm = StringManagerRef;
  if ( Scaleform::GFx::AS3::GetVectorInd((Scaleform::GFx::AS3::CheckResult *)&resulta, prop_name, &ind)->Result )
  {
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&sm,
      eXMLAssignmentToIndexedXMLNotAllowed,
      pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v7);
    v8 = v71;
    --v71->RefCount;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    v9 = result;
    result->Result = 0;
    return v9;
  }
  v10 = (Scaleform::GFx::AS3::Value *)value;
  v11 = ((int)value->__vftable & 0x1F) - 12;
  c.Flags = 0;
  c.Bonus.pWeakProxy = 0;
  if ( v11 <= 3 && Scaleform::GFx::AS3::IsXMLObject((Scaleform::GFx::AS3::Object *)value->pNext) )
  {
    v12 = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::AS3::Instances::fl::Namespace **, _DWORD))(*(_DWORD *)v10->value.VS._1.VInt + 140))(
                                                                                v10->value.VS._1,
                                                                                &value,
                                                                                0);
    goto LABEL_8;
  }
  if ( (v10->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLListObject(v10->value.VS._1.VObj) )
  {
    v12 = Scaleform::GFx::AS3::Instances::fl::XMLList::DeepCopy(
            (Scaleform::GFx::AS3::Instances::fl::XMLList *)v10->value.VS._1.VInt,
            (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&value,
            0);
LABEL_8:
    pV = v12->pV;
    buf.pData = 0;
    buf.Size = 0;
    Scaleform::GFx::AS3::Value::PickUnsafe((Scaleform::GFx::AS3::Value *)&buf, pV);
    Scaleform::GFx::AS3::Value::Assign(&c, (const Scaleform::GFx::AS3::Value *)&buf);
    if ( ((int)buf.pData & 0x1F) > 9u )
    {
      if ( ((int)buf.pData & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&buf);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&buf);
    }
    goto LABEL_21;
  }
  pStringManager = StringManagerRef->pStringManager;
  a.pObject = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)&pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(
          v10,
          (Scaleform::GFx::AS3::CheckResult *)&value,
          (Scaleform::GFx::ASString *)&a)->Result )
  {
    pObject = (Scaleform::GFx::ASStringNode *)a.pObject;
    --a.pObject->pPrev;
    result->Result = 0;
    if ( !pObject->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
    Scaleform::GFx::AS3::Value::~Value(&c);
    return result;
  }
  Scaleform::GFx::AS3::Value::Assign(&c, (const Scaleform::GFx::ASString *)&a);
  v15 = (Scaleform::GFx::ASStringNode *)a.pObject;
  --a.pObject->pPrev;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
LABEL_21:
  v16 = prop_name;
  if ( (prop_name->Kind & 8) != 0 )
  {
    if ( (c.Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLListObject(c.value.VS._1.VObj) )
    {
      v17 = c.value.VS._1;
      Scaleform::StringBuffer::StringBuffer(&buf, vm->MHeap);
      v18 = *(_DWORD *)(v17.VInt + 48);
      for ( j = 0; j < v18; ++j )
      {
        if ( j )
          Scaleform::StringBuffer::AppendChar(&buf, 0x20u);
        v20 = *(_DWORD *)(*(_DWORD *)(v17.VInt + 44) + 4 * j);
        (*(void (__thiscall **)(int, Scaleform::StringBuffer *, _DWORD))(*(_DWORD *)v20 + 96))(v20, &buf, 0);
      }
      pData = (__m128i *)buf.pData;
      if ( !buf.pData )
        pData = (__m128i *)uri;
      value = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                                 sm->pStringManager,
                                                                 pData,
                                                                 buf.Size);
      ++value->pPrev;
      Scaleform::GFx::AS3::Value::Assign(&c, (const Scaleform::GFx::ASString *)&value);
      v22 = (Scaleform::GFx::ASStringNode *)value;
      --value->pPrev;
      if ( !v22->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v22);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buf);
    }
    else
    {
      if ( Scaleform::GFx::AS3::IsXMLObject(&c) )
      {
        VInt = (Scaleform::GFx::AS3::Instances::fl::XML *)c.value.VS._1.VInt;
        value = (Scaleform::GFx::AS3::Instances::fl::Namespace *)&StringManagerRef->pStringManager->EmptyStringNode;
        ++value->pPrev;
        Scaleform::GFx::AS3::Instances::fl::XML::AS3toString(VInt, (Scaleform::GFx::ASString *)&value);
      }
      else
      {
        value = c.value.VS._1.VNs;
        ++*(_DWORD *)(c.value.VS._1.VInt + 12);
      }
      Scaleform::GFx::AS3::Value::Assign(&c, (const Scaleform::GFx::ASString *)&value);
      v24 = (Scaleform::GFx::ASStringNode *)value;
      --value->pPrev;
      if ( !v24->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
    }
    v25 = 0;
    v26 = 0;
    a.pObject = 0;
    if ( this->Attrs.Data.Size )
    {
      do
      {
        if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(
               this->Attrs.Data.Data[v26].pObject,
               (Scaleform::GFx::AS3::SoundObject *)prop_name) )
        {
          if ( v25 )
          {
            if ( !this->DeleteProperty(this, &value, prop_name)->Result )
            {
              v29 = result;
              result->Result = 0;
              goto LABEL_48;
            }
          }
          else
          {
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&a,
              (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->Attrs.Data.Data[v26]);
            v25 = a.pObject;
          }
        }
        ++v26;
      }
      while ( v26 < this->Attrs.Data.Size );
      if ( v25 )
        goto LABEL_68;
    }
    v27 = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject;
    if ( (prop_name->Kind & 3u) > 1 )
      Namespace = vm->DefXMLNamespace.pObject;
    else
      Namespace = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)prop_name);
    value = Namespace;
    if ( !Namespace )
      value = vm->PublicNamespace.pObject;
    v31 = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)c.value.VS._1.VInt;
    ++*(_DWORD *)(c.value.VS._1.VInt + 12);
    v32 = &v31->12;
    a.pObject = v31;
    v33 = (const Scaleform::GFx::AS3::Multiname *)prop_name->Name.value.VS._1.VInt;
    ++v33->Name.Bonus.pWeakProxy;
    MHeap = v27->pVM->MHeap;
    Alloc = MHeap->Alloc;
    prop_name = v33;
    v36 = (Scaleform::GFx::AS3::Instances::fl::XMLAttr *)Alloc(MHeap, 48u, 0);
    if ( v36 )
    {
      Scaleform::GFx::AS3::Instances::fl::XMLAttr::XMLAttr(
        v36,
        v27,
        value,
        (const Scaleform::GFx::ASString *)&prop_name,
        (const Scaleform::GFx::ASString *)&a,
        y.pObject);
      if ( v37 )
        v25 = v37;
    }
    v48 = v33->Name.Bonus.pWeakProxy-- == (Scaleform::GFx::AS3::WeakProxy *)1;
    if ( v48 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v33);
    v48 = v32->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1;
    if ( v48 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)a.pObject);
    v38 = y.pObject;
    p_Attrs = &y.pObject->Attrs;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&y.pObject->Attrs,
      &y.pObject->Attrs,
      y.pObject->Attrs.Data.Size + 1);
    Size = p_Attrs->Data.Size;
    if ( &p_Attrs->Data.Data[Size] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *)4 )
    {
      p_Attrs->Data.Data[Size - 1].pObject = v25;
      if ( v25 )
        v25->RefCount = (v25->RefCount + 1) & 0x8FBFFFFF;
    }
    v38->AddInScopeNamespace(v38, value);
LABEL_68:
    v41 = c.value.VS._1;
    ++*(_DWORD *)(c.value.VS._1.VInt + 12);
    ++*(_DWORD *)(v41.VInt + 12);
    pNode = v25->Data.pNode;
    v43 = (Scaleform::GFx::ASStringNode *)v41.VInt;
    v44 = (_DWORD *)(v41.VInt + 12);
    v48 = pNode->RefCount-- == 1;
    if ( v48 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v25->Data.pNode = v43;
    v48 = (*v44)-- == 1;
    if ( v48 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v43);
    v29 = result;
    result->Result = 1;
    if ( v25 )
    {
LABEL_48:
      if ( ((unsigned __int8)v25 & 1) == 0 )
      {
        RefCount = v25->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v25->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
        }
      }
    }
    if ( (c.Flags & 0x1F) <= 9 )
      return v29;
    if ( (c.Flags & 0x200) != 0 )
    {
LABEL_53:
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&c);
      return v29;
    }
    goto LABEL_135;
  }
  i.Bonus.pWeakProxy = 0;
  i.Flags = 0;
  v45 = StringManagerRef->pStringManager;
  propName.pNode = &v45->EmptyStringNode;
  ++v45->EmptyStringNode.RefCount;
  resulta = 1;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(&v16->Name, (Scaleform::GFx::AS3::CheckResult *)&value, &propName)->Result )
  {
    v46 = propName.pNode;
    v29 = result;
    --propName.pNode->RefCount;
    v47 = v46;
    v48 = v46->RefCount == 0;
    result->Result = 0;
LABEL_127:
    if ( v48 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v47);
    if ( (i.Flags & 0x1F) > 9 )
    {
      if ( (i.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&i);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&i);
    }
    if ( (c.Flags & 0x1F) <= 9 )
      return v29;
    if ( (c.Flags & 0x200) != 0 )
      goto LABEL_53;
LABEL_135:
    Scaleform::GFx::AS3::Value::ReleaseInternal(&c);
    return v29;
  }
  if ( Scaleform::GFx::AS3::IsXMLObject(&c)
    || Scaleform::GFx::AS3::IsXMLListObject(&c)
    || (IsAnyType = Scaleform::GFx::AS3::Multiname::IsAnyType(v16), LOBYTE(value) = 1, IsAnyType) )
  {
    LOBYTE(value) = 0;
  }
  v50 = this->Children.Data.Size;
  if ( v50 )
  {
    v51 = 4 * v50 - 4;
    do
    {
      if ( Scaleform::GFx::AS3::Instances::fl::XML::Matches(
             *(Scaleform::GFx::AS3::Instances::fl::XML **)((char *)&this->Children.Data.Data->pObject + v51),
             (Scaleform::GFx::AS3::SoundObject *)prop_name) )
      {
        if ( (i.Flags & 0x1F) != 0 )
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
            (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children,
            i.value.VS._1.VUInt);
        Scaleform::GFx::AS3::Value::SetSInt32(&i, v50 - 1);
      }
      --v50;
      v51 -= 4;
    }
    while ( v50 );
  }
  if ( (i.Flags & 0x1F) != 0 )
  {
LABEL_114:
    if ( (_BYTE)value )
    {
      v58 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)this->Children.Data.Data[i.value.VS._1.VInt].pObject;
      if ( v58 )
        v58->RefCount = (v58->RefCount + 1) & 0x8FBFFFFF;
      v58->DeleteChildren(v58, 0);
      VStr = c.value.VS._1.VStr;
      ++*(_DWORD *)(c.value.VS._1.VInt + 12);
      LOBYTE(prop_name) = VStr->Size != 0;
      v48 = VStr->RefCount-- == 1;
      if ( v48 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
      if ( (_BYTE)prop_name && v58->GetKind(v58) == kElement )
        resulta = Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
                    v58,
                    (Scaleform::GFx::AS3::CheckResult *)&prop_name,
                    0,
                    &c)->Result;
      if ( ((unsigned __int8)v58 & 1) == 0 )
      {
        v60 = v58->RefCount;
        if ( (v60 & 0x3FFFFF) != 0 )
        {
          v58->RefCount = v60 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v58);
        }
      }
      goto LABEL_126;
    }
LABEL_125:
    resulta = Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
                this,
                (Scaleform::GFx::AS3::CheckResult *)&prop_name,
                i.value.VS._1.VStr,
                &c)->Result;
LABEL_126:
    v61 = propName.pNode;
    v29 = result;
    v62 = resulta;
    --propName.pNode->RefCount;
    v47 = v61;
    v48 = v61->RefCount == 0;
    result->Result = v62;
    goto LABEL_127;
  }
  Scaleform::GFx::AS3::Value::SetSInt32(&i, this->Children.Data.Size);
  if ( !(_BYTE)value )
    goto LABEL_125;
  v52 = prop_name->Kind & 3;
  v53 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject;
  if ( v52 <= 1 && prop_name->Obj.pObject )
    v54 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)prop_name);
  else
    v54 = vm->DefXMLNamespace.pObject;
  if ( !v54 )
    v54 = vm->PublicNamespace.pObject;
  v55 = (const Scaleform::GFx::AS3::Multiname *)prop_name->Name.value.VS._1.VInt;
  ++v55->Name.Bonus.pWeakProxy;
  prop_name = v55;
  v56 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
          v53,
          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&sm,
          v53,
          v54,
          (const Scaleform::GFx::ASString *)&prop_name,
          this)->pV;
  v48 = v55->Name.Bonus.pWeakProxy-- == (Scaleform::GFx::AS3::WeakProxy *)1;
  y.pObject = v56;
  if ( v48 )
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v55);
  buf.pData = 0;
  buf.Size = 0;
  Scaleform::GFx::AS3::Value::AssignUnsafe((Scaleform::GFx::AS3::Value *)&buf, v56);
  LOBYTE(prop_name) = !Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
                         this,
                         &v65,
                         i.value.VS._1.VStr,
                         (const Scaleform::GFx::AS3::Value *)&buf)->Result;
  if ( ((int)buf.pData & 0x1F) > 9u )
  {
    if ( ((int)buf.pData & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef((Scaleform::GFx::AS3::Value *)&buf);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&buf);
  }
  if ( !(_BYTE)prop_name )
  {
    v56->AddInScopeNamespace(v56, v54);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&y);
    goto LABEL_114;
  }
  result->Result = 0;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&y);
  v57 = propName.pNode;
  --propName.pNode->RefCount;
  if ( !v57->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  if ( (i.Flags & 0x1F) > 9 )
  {
    if ( (i.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&i);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&i);
  }
  if ( (c.Flags & 0x1F) > 9 )
  {
    if ( (c.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&c);
      return result;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&c);
  }
  return result;
}
