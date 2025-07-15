Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::SetProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int prop_name,
        Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::GFx::AS3::Multiname *v5; // esi
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v8; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // esi
  Scaleform::GFx::AS3::Traits *v10; // ebp
  Scaleform::GFx::AS3::Value *v11; // ebp
  int v12; // ecx
  int (__thiscall *v13)(int); // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v14; // ebp
  Scaleform::GFx::ASStringNode *TargetProperty; // eax
  _DWORD *v16; // eax
  int v17; // eax
  Scaleform::GFx::ASStringNode *pV; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::AS3::CheckResult *v20; // eax
  int v21; // esi
  Scaleform::GFx::ASStringNode *v22; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *v23; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *InstanceAttr; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v25; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *InstanceText; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v27; // esi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *InstanceElement; // eax
  unsigned int v29; // eax
  unsigned int v30; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *v31; // edx
  unsigned int v32; // eax
  unsigned int v33; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLElement_vtbl *v35; // ebp
  const Scaleform::GFx::AS3::Value *v36; // eax
  const Scaleform::GFx::AS3::Value *v37; // esi
  const Scaleform::GFx::ASString *v38; // eax
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value::Extra v40; // edx
  Scaleform::GFx::AS3::Value::V2U v41; // edx
  int v42; // eax
  bool v43; // zf
  int v44; // eax
  Scaleform::GFx::ASStringNode *v45; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v46; // esi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_List; // ebp
  int v48; // edi
  const Scaleform::GFx::ASString *v49; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v50; // eax
  Scaleform::GFx::ASStringNode *v51; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *Instance; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v53; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v55; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v56; // ecx
  unsigned int v57; // edi
  const Scaleform::GFx::AS3::Value *v58; // eax
  unsigned int j; // esi
  unsigned int v60; // ebx
  unsigned int v61; // ebx
  Scaleform::GFx::AS3::Instances::fl::XML *v62; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v63; // esi
  unsigned int v64; // eax
  int v65; // edi
  _DWORD *v66; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v67; // ecx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v68; // ebx
  const Scaleform::GFx::AS3::Value *v69; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v70; // eax
  Scaleform::GFx::ASStringNode *v71; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v72; // esi
  int v73; // eax
  bool v74; // bl
  unsigned int v75; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLList *v76; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v77; // edi
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v78; // eax
  Scaleform::GFx::AS3::Value *VInt; // esi
  Scaleform::GFx::AS3::Value *v80; // ebx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *v81; // eax
  unsigned int Size; // eax
  const Scaleform::GFx::AS3::VM::Error *v83; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v85; // [esp-10h] [ebp-8Ch]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v86; // [esp-Ch] [ebp-88h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v87; // [esp-8h] [ebp-84h]
  Scaleform::GFx::AS3::Instances::fl::XML *v88; // [esp-4h] [ebp-80h]
  const Scaleform::GFx::AS3::Value *v89; // [esp-4h] [ebp-80h]
  int v90; // [esp+10h] [ebp-6Ch] BYREF
  Scaleform::GFx::ASString n; // [esp+14h] [ebp-68h] BYREF
  unsigned int i; // [esp+18h] [ebp-64h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> c; // [esp+1Ch] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XML *parent; // [esp+20h] [ebp-5Ch] BYREF
  unsigned int csize; // [esp+24h] [ebp-58h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> new_xml; // [esp+28h] [ebp-54h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XML *r; // [esp+30h] [ebp-4Ch] BYREF
  Scaleform::GFx::AS3::Value v98; // [esp+34h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value V; // [esp+44h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+54h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+64h] [ebp-18h] BYREF

  n.pNode = 0;
  v5 = (const Scaleform::GFx::AS3::Multiname *)prop_name;
  pVM = this->pTraits.pObject->pVM;
  r = (Scaleform::GFx::AS3::Instances::fl::XML *)this;
  csize = (unsigned int)pVM;
  if ( !Scaleform::GFx::AS3::GetVectorInd(
          (Scaleform::GFx::AS3::CheckResult *)&prop_name,
          (const Scaleform::GFx::AS3::Multiname *)prop_name,
          &i)->Result )
  {
    Size = this->List.Data.Size;
    if ( Size > 1 )
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&v98, eXMLAssigmentOneItemLists, pVM);
      Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v83);
      pWeakProxy = (Scaleform::GFx::ASStringNode *)v98.Bonus.pWeakProxy;
      --v98.Bonus.pWeakProxy[1].pObject;
      if ( !pWeakProxy->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
      goto LABEL_167;
    }
    if ( !Size )
    {
      if ( !Scaleform::GFx::AS3::Instances::fl::XMLList::ResolveValue(
              this,
              (Scaleform::GFx::AS3::CheckResult *)&prop_name,
              &r)->Result
        || !r )
      {
        goto LABEL_167;
      }
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent>::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent>(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> *)&prop_name,
        (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent *)r);
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->List,
        (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&prop_name);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&prop_name);
    }
    if ( this->List.Data.Data->pObject->SetProperty(this->List.Data.Data->pObject, &value, v5, value)->Result )
      goto LABEL_164;
    goto LABEL_167;
  }
  pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)this->TargetObject.pObject;
  v8 = 0;
  v9 = 0;
  parent = 0;
  if ( pObject )
  {
    v10 = pObject->pTraits.pObject;
    if ( (v10->Flags & 0x20) != 0 )
      goto LABEL_167;
    if ( v10->TraitsType == Traits_XML )
    {
      v8 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)pObject;
      parent = pObject;
    }
    else
    {
      if ( v10->TraitsType != Traits_XMLList )
        goto LABEL_167;
      v9 = pObject;
      if ( !Scaleform::GFx::AS3::Instances::fl::XMLList::ResolveValue(
              (Scaleform::GFx::AS3::Instances::fl::XMLList *)pObject,
              (Scaleform::GFx::AS3::CheckResult *)&prop_name,
              &parent)->Result )
        goto LABEL_167;
      v8 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)parent;
    }
    if ( !v8 )
    {
LABEL_167:
      v20 = result;
      result->Result = 0;
      return v20;
    }
  }
  v11 = value;
  if ( i < this->List.Data.Size )
    goto LABEL_66;
  if ( v9 )
  {
    if ( v9[1].pNext == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1 )
    {
      v8 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v9[1]._pRCC->Scaleform::GFx::AS3::Instances::fl::Object::Scaleform::GFx::AS3::Instance::Scaleform::GFx::AS3::Object::Scaleform::GFx::AS3::GASRefCountBase::Scaleform::GFx::AS3::RefCountBaseGC<328>::$D5CF7A61EF1991BA0FEAF3F4ABE53B92::__vftable;
      parent = v8;
      goto LABEL_13;
    }
    goto LABEL_167;
  }
LABEL_13:
  if ( v8 && v8->GetKind(v8) != kElement )
    goto LABEL_167;
  v12 = *(_DWORD *)(csize + 36);
  v13 = *(int (__thiscall **)(int))(*(_DWORD *)v12 + 60);
  c.pObject = 0;
  v14 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v13(v12);
  if ( !this->TargetNamespace.pObject )
    goto LABEL_18;
  TargetProperty = this->TargetProperty;
  if ( !TargetProperty )
    goto LABEL_18;
  new_xml.pV = (Scaleform::GFx::AS3::Instances::fl::XML *)this->TargetProperty;
  ++TargetProperty->RefCount;
  Scaleform::GFx::AS3::Value::Value(&name, (const Scaleform::GFx::ASString *)&new_xml);
  v87 = this->TargetNamespace.pObject;
  n.pNode = (Scaleform::GFx::ASStringNode *)7;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, v87, &name);
  v17 = *v16 >> 3;
  LOBYTE(prop_name) = 1;
  if ( (v17 & 1) == 0 )
LABEL_18:
    LOBYTE(prop_name) = 0;
  if ( ((int)n.pNode & 4) != 0 )
  {
    n.pNode = (Scaleform::GFx::ASStringNode *)((unsigned int)n.pNode & 0xFFFFFFFB);
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  }
  if ( ((int)n.pNode & 2) != 0 )
  {
    n.pNode = (Scaleform::GFx::ASStringNode *)((unsigned int)n.pNode & 0xFFFFFFFD);
    Scaleform::GFx::AS3::Value::~Value(&name);
  }
  if ( ((int)n.pNode & 1) != 0 )
  {
    pV = (Scaleform::GFx::ASStringNode *)new_xml.pV;
    n.pNode = (Scaleform::GFx::ASStringNode *)((unsigned int)n.pNode & 0xFFFFFFFE);
    --new_xml.pV->pPrev;
    if ( !pV->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pV);
  }
  if ( !(_BYTE)prop_name )
  {
    v25 = (Scaleform::GFx::AS3::Instances::fl::XML *)this->TargetProperty;
    if ( v25 )
    {
      n.pNode = (Scaleform::GFx::ASStringNode *)((unsigned int)n.pNode | 8);
      ++v25->pPrev;
      new_xml.pV = v25;
      if ( !Scaleform::GFx::ASString::operator==((Scaleform::GFx::ASString *)&new_xml, "*") )
      {
        HIBYTE(v90) = 0;
        goto LABEL_42;
      }
    }
    else
    {
      v25 = new_xml.pV;
    }
    HIBYTE(v90) = 1;
LABEL_42:
    if ( ((int)n.pNode & 8) != 0 )
    {
      v43 = v25->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1;
      if ( v43 )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v25);
    }
    if ( HIBYTE(v90) )
    {
      Scaleform::StringDataPtr::StringDataPtr((Scaleform::StringDataPtr *)&new_xml, uri);
      InstanceText = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                                                                           v14,
                                                                                           (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *)&v98,
                                                                                           v14,
                                                                                           (const Scaleform::StringDataPtr *)&new_xml,
                                                                                           v8);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
        &c,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)InstanceText->pV);
    }
    else
    {
      v27 = (Scaleform::GFx::AS3::Instances::fl::XML *)this->TargetProperty;
      ++v27->pPrev;
      v86 = this->TargetNamespace.pObject;
      new_xml.pV = v27;
      InstanceElement = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                                                                                              v14,
                                                                                              (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&v98,
                                                                                              v14,
                                                                                              v86,
                                                                                              (const Scaleform::GFx::ASString *)&new_xml,
                                                                                              v8);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
        &c,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)InstanceElement->pV);
      v43 = v27->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1;
      if ( v43 )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v27);
    }
    goto LABEL_49;
  }
  new_xml.pV = (Scaleform::GFx::AS3::Instances::fl::XML *)this->TargetProperty;
  ++new_xml.pV->pPrev;
  Scaleform::GFx::AS3::Value::Value(&name, (const Scaleform::GFx::ASString *)&new_xml);
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, this->TargetNamespace.pObject, &name);
  Scaleform::GFx::AS3::Value::~Value(&name);
  v19 = (Scaleform::GFx::ASStringNode *)new_xml.pV;
  --new_xml.pV->pPrev;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( Scaleform::GFx::AS3::Instances::fl::XMLElement::FindAttr(
         v8,
         (Scaleform::GFx::AS3::SoundObject *)&mn,
         (unsigned int *)&new_xml) )
  {
    result->Result = 0;
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&c);
    return result;
  }
  v21 = *(_DWORD *)(*(_DWORD *)(csize + 12) + 248);
  v88 = parent;
  ++*(_DWORD *)(v21 + 44);
  v22 = this->TargetProperty;
  ++v22->RefCount;
  v23 = (Scaleform::GFx::AS3::Instances::fl::XML *)(v21 + 32);
  v85 = this->TargetNamespace.pObject;
  new_xml.pV = v23;
  n.pNode = v22;
  InstanceAttr = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceAttr(
                                                                                       v14,
                                                                                       (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLAttr> *)&v98,
                                                                                       v14,
                                                                                       v85,
                                                                                       &n,
                                                                                       (const Scaleform::GFx::ASString *)&new_xml,
                                                                                       v88);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
    &c,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)InstanceAttr->pV);
  v43 = v22->RefCount-- == 1;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  v43 = v23->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v23);
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)parent;
LABEL_49:
  v29 = this->List.Data.Size;
  i = v29;
  if ( !(_BYTE)prop_name )
  {
    if ( v8 )
    {
      v30 = v8->Children.Data.Size;
      if ( v29 )
      {
        v31 = this->List.Data.Data[v29 - 1].pObject;
        v32 = v30 - 1;
        v33 = 0;
        if ( v30 != 1 )
        {
          Data = v8->Children.Data.Data;
          do
          {
            if ( Data->pObject == v31 )
              break;
            ++v33;
            ++Data;
          }
          while ( v33 < v32 );
        }
      }
      else
      {
        v33 = v30 - 1;
      }
      v35 = v8->__vftable;
      Scaleform::GFx::AS3::Value::Value(&name, &c);
      LOBYTE(prop_name) = !v35->InsertChildAt(v8, (Scaleform::GFx::AS3::CheckResult *)&v90 + 3, v33 + 1, v36)->Result;
      Scaleform::GFx::AS3::Value::~Value(&name);
      if ( (_BYTE)prop_name )
      {
        result->Result = 0;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&c);
        return result;
      }
    }
    v37 = value;
    if ( Scaleform::GFx::AS3::IsXMLObject(value) )
    {
      v38 = (const Scaleform::GFx::ASString *)(*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U))(*(_DWORD *)v37->value.VS._1.VInt + 120))(v37->value.VS._1);
      Scaleform::GFx::AS3::Value::Value(&name, v38);
LABEL_64:
      Scaleform::GFx::AS3::Instances::fl::XML::AS3setName((Scaleform::GFx::AS3::Instances::fl::XML *)c.pObject, &name);
      Scaleform::GFx::AS3::Value::~Value(&name);
      goto LABEL_65;
    }
    if ( Scaleform::GFx::AS3::IsXMLListObject(v37) )
    {
      Scaleform::GFx::AS3::Value::Value(&name, *(Scaleform::GFx::ASStringNode **)(v37->value.VS._1.VInt + 36));
      goto LABEL_64;
    }
  }
LABEL_65:
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->List,
    (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&c);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&c);
  v11 = value;
LABEL_66:
  Flags = v11->Flags;
  v40.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v11->Bonus;
  V.value.VS._1.VInt = v11->value.VS._1.VInt;
  V.Bonus = v40;
  v41.VObj = (Scaleform::GFx::AS3::Object *)v11->value.VS._2;
  V.Flags = Flags;
  V.value.VS._2 = v41;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v11);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v11);
  }
  if ( (v11->Flags & 0x1F) - 12 > 3 || !Scaleform::GFx::AS3::IsXMLObject(v11->value.VS._1.VObj) )
  {
    v43 = !Scaleform::GFx::AS3::IsXMLListObject(v11);
LABEL_75:
    if ( !v43 )
      goto LABEL_79;
    goto LABEL_76;
  }
  v42 = (*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U))(*(_DWORD *)v11->value.VS._1.VInt + 104))(v11->value.VS._1);
  if ( v42 != 2 )
  {
    v43 = v42 == 5;
    goto LABEL_75;
  }
LABEL_76:
  v44 = *(_DWORD *)(*(_DWORD *)(csize + 12) + 248);
  prop_name = v44 + 32;
  ++*(_DWORD *)(v44 + 44);
  if ( !Scaleform::GFx::AS3::Value::Convert2String(
          v11,
          (Scaleform::GFx::AS3::CheckResult *)&value,
          (Scaleform::GFx::ASString *)&prop_name)->Result )
  {
    v51 = (Scaleform::GFx::ASStringNode *)prop_name;
    --*(_DWORD *)(prop_name + 12);
    v43 = v51->RefCount == 0;
    result->Result = 0;
    if ( v43 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v51);
    Scaleform::GFx::AS3::Value::~Value(&V);
    return result;
  }
  Scaleform::GFx::AS3::Value::Assign(&V, (const Scaleform::GFx::ASString *)&prop_name);
  v45 = (Scaleform::GFx::ASStringNode *)prop_name;
  --*(_DWORD *)(prop_name + 12);
  if ( !v45->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
LABEL_79:
  v46 = this->List.Data.Data[i].pObject;
  p_List = &this->List;
  v48 = v46->GetKind(v46);
  if ( v48 == 5 )
  {
    v49 = v46->GetName(v46);
    Scaleform::GFx::AS3::Value::Value(&v98, v49);
    v50 = v46->GetNamespace(v46);
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, v50, &v98);
    if ( (v98.Flags & 0x1F) > 9 )
    {
      if ( (v98.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v98);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v98);
    }
    v46->Parent.pObject->SetProperty(v46->Parent.pObject, (Scaleform::GFx::AS3::CheckResult *)&value, &mn, &V);
    Instance = Scaleform::GFx::AS3::Instances::fl::XMLList::MakeInstance(
                 this,
                 (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&prop_name);
    v53 = Instance->pV;
    v46->Parent.pObject->GetProperty(v46->Parent.pObject, (Scaleform::GFx::AS3::CheckResult *)&value, &mn, Instance->pV);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&p_List->Data.Data[i],
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)v53->List.Data.Data);
    if ( ((unsigned __int8)v53 & 1) == 0 )
    {
      RefCount = v53->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v53->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v53);
      }
    }
LABEL_90:
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    goto LABEL_153;
  }
  if ( !Scaleform::GFx::AS3::IsXMLListObject(&V) )
  {
    if ( !Scaleform::GFx::AS3::IsXMLObject(&V) && v48 != 2 && v48 != 3 && v48 != 4 )
    {
      Scaleform::GFx::AS3::Multiname::Multiname(&mn, (Scaleform::GFx::AS3::VM *)csize);
      if ( !p_List->Data.Data[i].pObject->SetProperty(
              p_List->Data.Data[i].pObject,
              (Scaleform::GFx::AS3::CheckResult *)&value,
              &mn,
              &V)->Result )
      {
        result->Result = 0;
        Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
        Scaleform::GFx::AS3::Value::~Value(&V);
        return result;
      }
      goto LABEL_90;
    }
    v77 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v46->Parent.pObject;
    if ( v77 && v46->GetChildIndex(v46, (Scaleform::GFx::AS3::CheckResult *)&value, &prop_name)->Result )
    {
      if ( !Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
              v77,
              (Scaleform::GFx::AS3::CheckResult *)&value,
              (Scaleform::GFx::ASStringNode *)prop_name,
              &V)->Result
        || v77->Children.Data.Size <= prop_name )
      {
        result->Result = 0;
        Scaleform::GFx::AS3::Value::~Value(&V);
        return result;
      }
      Scaleform::GFx::AS3::Value::Assign(&V, v77->Children.Data.Data[prop_name].pObject);
    }
    if ( (V.Flags & 0x1F) == 0xA )
    {
      v78 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(csize + 36)
                                                                                          + 60))(*(_DWORD *)(csize + 36));
      VInt = (Scaleform::GFx::AS3::Value *)V.value.VS._1.VInt;
      ++*(_DWORD *)(V.value.VS._1.VInt + 12);
      v80 = VInt;
      VInt = (Scaleform::GFx::AS3::Value *)((char *)VInt + 12);
      value = v80;
      v81 = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                                                                  v78,
                                                                                  (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *)&prop_name,
                                                                                  v78,
                                                                                  (const Scaleform::GFx::ASString *)&value,
                                                                                  v77);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&p_List->Data.Data[i],
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)v81->pV);
      v43 = VInt->Flags-- == 1;
      if ( v43 )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v80);
    }
    else
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&p_List->Data.Data[i],
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)V.value.VS._1.VInt);
    }
LABEL_153:
    if ( (V.Flags & 0x1F) > 9 )
    {
      if ( (V.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&V);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&V);
      v20 = result;
      result->Result = 1;
      return v20;
    }
LABEL_164:
    v20 = result;
    result->Result = 1;
    return v20;
  }
  v55 = Scaleform::GFx::AS3::Instances::fl::XMLList::ShallowCopy(
          (Scaleform::GFx::AS3::Instances::fl::XMLList *)V.value.VS._1.VInt,
          (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&value)->pV;
  v56 = v46->Parent.pObject;
  v57 = v55->List.Data.Size;
  c.pObject = v55;
  parent = v56;
  csize = v57;
  if ( v56 && v46->GetChildIndex(v46, (Scaleform::GFx::AS3::CheckResult *)&value, (unsigned int *)&new_xml)->Result )
  {
    Scaleform::GFx::AS3::Value::Value(&name, &c);
    LOBYTE(value) = !Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
                       (Scaleform::GFx::AS3::Instances::fl::XMLElement *)parent,
                       (Scaleform::GFx::AS3::CheckResult *)&prop_name,
                       (Scaleform::GFx::ASStringNode *)new_xml.pV,
                       v58)->Result;
    Scaleform::GFx::AS3::Value::~Value(&name);
    if ( (_BYTE)value )
    {
      result->Result = 0;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&c);
      Scaleform::GFx::AS3::Value::~Value(&V);
      return result;
    }
    for ( j = 0; j < v57; ++j )
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&c.pObject->List.Data.Data[j],
        *((Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)&parent[1].pUserDataHolder->pMovieView
        + (int)new_xml.pV
        + j));
  }
  v60 = this->List.Data.Size;
  if ( v57 > 1 )
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      p_List,
      v60 + v57 - 1);
  if ( v57 )
  {
    if ( v57 > 1 )
    {
      v61 = v60 - 1;
      if ( v61 > i )
      {
        value = (Scaleform::GFx::AS3::Value *)(4 * (v61 + csize));
        do
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)((char *)&p_List->Data.Data[-1]
                                                                                             + (unsigned int)value),
            (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&p_List->Data.Data[v61]);
          v62 = p_List->Data.Data[v61].pObject;
          v63 = &p_List->Data.Data[v61];
          if ( v62 )
          {
            if ( ((unsigned __int8)v62 & 1) != 0 )
            {
              v63->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v62 - 1);
            }
            else
            {
              v64 = v62->RefCount;
              if ( (v64 & 0x3FFFFF) != 0 )
              {
                v62->RefCount = v64 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v62);
              }
            }
            v63->pObject = 0;
          }
          value = (Scaleform::GFx::AS3::Value *)((char *)value - 4);
          --v61;
        }
        while ( v61 > i );
      }
    }
  }
  else
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>,2>,Scaleform::ArrayDefaultPolicy> > *)p_List,
      i);
  }
  v65 = 0;
  if ( !csize )
  {
LABEL_129:
    if ( ((int)c.pObject & 1) == 0 )
    {
      v75 = c.pObject->RefCount;
      if ( (v75 & 0x3FFFFF) != 0 )
      {
        v76 = c.pObject;
        c.pObject->RefCount = v75 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v76);
      }
    }
    goto LABEL_153;
  }
  while ( 1 )
  {
    v66 = &p_List->Data.Data[v65 + i].pObject->__vftable;
    v67 = c.pObject->List.Data.Data;
    v68 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v67[v65].pObject;
    if ( !v66
      || ((int (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *))v68->__vftable[1].SetProperty)(v67[v65].pObject) == 1 )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&p_List->Data.Data[v65 + i],
        v68);
      goto LABEL_128;
    }
    prop_name = (unsigned int)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                r->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                                "*",
                                1u,
                                0);
    ++*(_DWORD *)(prop_name + 12);
    Scaleform::GFx::AS3::Value::Value(&v98, (const Scaleform::GFx::ASString *)&prop_name);
    v89 = v69;
    v70 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)(*(int (__thiscall **)(_DWORD *))(*v66 + 136))(v66);
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, v70, v89);
    if ( (v98.Flags & 0x1F) > 9 )
    {
      if ( (v98.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v98);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v98);
    }
    v71 = (Scaleform::GFx::ASStringNode *)prop_name;
    --*(_DWORD *)(prop_name + 12);
    if ( !v71->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v71);
    (*(void (__thiscall **)(_DWORD *, Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *, _DWORD))(*v66 + 140))(
      v66,
      &new_xml,
      v66[9]);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&p_List->Data.Data[v65 + i],
      (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)new_xml.pV);
    v72 = new_xml.pV;
    parent = (Scaleform::GFx::AS3::Instances::fl::XML *)new_xml.pV->__vftable;
    Scaleform::GFx::AS3::Value::Value(&name, v68);
    v74 = *(_BYTE *)((int (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value **, Scaleform::GFx::AS3::Multiname *, int))parent->DynAttrs.mHash.pTable)(
                      v72,
                      &value,
                      &mn,
                      v73) == 0;
    if ( (name.Flags & 0x1F) > 9 )
    {
      if ( (name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
    }
    if ( v74 )
      break;
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
LABEL_128:
    if ( ++v65 >= csize )
      goto LABEL_129;
  }
  result->Result = 0;
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&c);
  if ( (V.Flags & 0x1F) > 9 )
  {
    if ( (V.Flags & 0x200) != 0 )
    {
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&V);
      return result;
    }
    Scaleform::GFx::AS3::Value::ReleaseInternal(&V);
  }
  return result;
}
