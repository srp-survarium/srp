Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::DeepCopy(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Instances::fl::XML *parent)
{
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v3; // ebp
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // esi
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v5; // edi
  Scaleform::MemoryHeap *MHeap; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v8; // eax
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_RefCount; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLAttr *v11; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *pV; // ebx
  unsigned int v13; // eax
  unsigned int v14; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v16; // esi
  unsigned int RefCount; // eax
  unsigned int v18; // esi
  Scaleform::GFx::AS3::Class *Constructor; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *v20; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *v21; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *v22; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML *v23; // ebx
  unsigned int pNode; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_pUserDataHolder; // edi
  unsigned int v26; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v27; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v28; // esi
  unsigned int v29; // eax
  bool v30; // zf
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::Value *Undefined; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v34; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v35; // edi
  Scaleform::GFx::AS3::ClassTraits::Traits *v36; // ebx
  Scaleform::GFx::AS3::Slots::Pair *v37; // ebp
  Scaleform::GFx::ASStringNode *v38; // ecx
  Scaleform::GFx::Resource *v39; // ecx
  Scaleform::RefCountVImpl *v40; // ecx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v41; // edi
  unsigned int v42; // eax
  unsigned int v43; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v44; // edx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v45; // esi
  unsigned int v46; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *v47; // eax
  unsigned int i; // [esp+18h] [ebp-14h] BYREF
  unsigned int size; // [esp+1Ch] [ebp-10h]
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *itr; // [esp+20h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v51; // [esp+24h] [ebp-8h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v52; // [esp+28h] [ebp-4h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XML *parenta; // [esp+34h] [ebp+8h]

  v3 = this;
  pObject = this->Ns.pObject;
  v5 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject;
  MHeap = v5->pVM->MHeap;
  Alloc = MHeap->Alloc;
  v51 = v3;
  itr = v5;
  v8 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)Alloc(MHeap, 80u, 0);
  if ( v8 )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLElement::XMLElement(v8, v5, pObject, &v3->Text, parent);
    parenta = v9;
  }
  else
  {
    parenta = 0;
  }
  size = v3->Attrs.Data.Size;
  i = 0;
  if ( size )
  {
    p_RefCount = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&parenta[1].RefCount;
    while ( 1 )
    {
      v11 = v3->Attrs.Data.Data[i].pObject;
      pV = v11->DeepCopy(v11, (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *)&v52, parenta)->pV;
      v13 = (unsigned int)parenta[1].pTraits.pObject;
      v14 = v13 + 1;
      if ( v13 + 1 >= v13 )
      {
        if ( (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Object::DynAttrsKey,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::NodeHashF> >::TableType *)v14 >= parenta[1].DynAttrs.mHash.pTable )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_RefCount,
            p_RefCount,
            v14 + (v14 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&p_RefCount->Data[v13 + 1],
          0xFFFFFFFF);
        if ( v14 < (unsigned int)parenta[1].DynAttrs.mHash.pTable >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_RefCount,
            p_RefCount,
            v14);
      }
      Data = p_RefCount->Data;
      parenta[1].pTraits.pObject = (Scaleform::GFx::AS3::Traits *)v14;
      v16 = &Data[v14 - 1];
      if ( !v16 )
        goto LABEL_14;
      v16->pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)pV;
      if ( pV )
        break;
LABEL_18:
      if ( ++i >= size )
        goto LABEL_19;
    }
    pV->RefCount = (pV->RefCount + 1) & 0x8FBFFFFF;
LABEL_14:
    if ( pV )
    {
      if ( ((unsigned __int8)pV & 1) == 0 )
      {
        RefCount = pV->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pV->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
        }
      }
    }
    goto LABEL_18;
  }
LABEL_19:
  v18 = 0;
  size = v3->Children.Data.Size;
  i = 0;
  if ( size )
  {
    while ( 1 )
    {
      Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(itr);
      v20 = v3->Children.Data.Data[v18].pObject;
      if ( v20->GetKind(v20) == kComment && LOBYTE(Constructor[1].__vftable) )
        goto LABEL_37;
      v21 = v3->Children.Data.Data[v18].pObject;
      if ( v21->GetKind(v21) == kInstruction )
      {
        if ( BYTE1(Constructor[1].__vftable) )
          goto LABEL_37;
      }
      v22 = v3->Children.Data.Data[v18].pObject;
      v23 = v22->DeepCopy(v22, (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XML> *)&v52, parenta)->pV;
      pNode = (unsigned int)parenta[1].Text.pNode;
      p_pUserDataHolder = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&parenta[1].pUserDataHolder;
      v26 = pNode + 1;
      if ( pNode + 1 >= pNode )
      {
        if ( (Scaleform::GFx::AS3::Instances::fl::XML *)v26 >= parenta[1].Parent.pObject )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_pUserDataHolder,
            p_pUserDataHolder,
            v26 + (v26 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&p_pUserDataHolder->Data[v26],
          0xFFFFFFFF);
        if ( v26 < (unsigned int)parenta[1].Parent.pObject >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_pUserDataHolder,
            p_pUserDataHolder,
            v26);
      }
      v27 = p_pUserDataHolder->Data;
      parenta[1].Text.pNode = (Scaleform::GFx::ASStringNode *)v26;
      v28 = &v27[v26 - 1];
      if ( !v28 )
        goto LABEL_32;
      v28->pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)v23;
      if ( v23 )
        break;
LABEL_36:
      v18 = i;
LABEL_37:
      i = ++v18;
      if ( v18 >= size )
        goto LABEL_38;
    }
    v23->RefCount = (v23->RefCount + 1) & 0x8FBFFFFF;
LABEL_32:
    if ( v23 )
    {
      if ( ((unsigned __int8)v23 & 1) == 0 )
      {
        v29 = v23->RefCount;
        if ( (v29 & 0x3FFFFF) != 0 )
        {
          v23->RefCount = v29 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
        }
      }
    }
    goto LABEL_36;
  }
LABEL_38:
  v30 = v3->Namespaces.Data.Size == 0;
  size = 0;
  if ( !v30 )
  {
    v52 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&parenta[1].4;
    while ( 1 )
    {
      pVM = v3->pTraits.pObject->pVM;
      i = (unsigned int)&pVM->StringManagerRef->pStringManager->EmptyStringNode;
      ++*(_DWORD *)(i + 12);
      Undefined = Scaleform::GFx::AS3::Value::GetUndefined();
      Scaleform::GFx::AS3::VM::MakeNamespace(
        pVM,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&itr,
        NS_Public,
        (const Scaleform::GFx::ASString *)&i,
        Undefined);
      v33 = (Scaleform::GFx::ASStringNode *)i;
      --*(_DWORD *)(i + 12);
      if ( !v33->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
      v34 = itr;
      v35 = v3->Namespaces.Data.Data[size].pObject;
      v36 = (Scaleform::GFx::AS3::ClassTraits::Traits *)itr;
      if ( itr != (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v35 )
      {
        Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)&itr->Set, &v35->Prefix);
        v37 = (Scaleform::GFx::AS3::Slots::Pair *)v35->Uri.pNode;
        ++v37->Value.pNs.pObject;
        v38 = (Scaleform::GFx::ASStringNode *)v34->VArray.Data.Data;
        v30 = v38->RefCount-- == 1;
        if ( v30 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v38);
        v34->VArray.Data.Data = v37;
        v34->FirstOwnSlotNum ^= (v34->FirstOwnSlotNum ^ ((int)(*((_DWORD *)v35 + 5) << 28) >> 28)) & 0xF;
        v39 = (Scaleform::GFx::Resource *)v35->pFactory.pObject;
        if ( v39 )
          Scaleform::RefCountImpl::AddRef(v39);
        v40 = (Scaleform::RefCountVImpl *)v34->VArray.Data.Size;
        if ( v40 )
          Scaleform::RefCountImpl::Release(v40);
        v3 = v51;
        v34->VArray.Data.Size = (unsigned int)v35->pFactory.pObject;
      }
      v41 = v52;
      v42 = v52->Size;
      v43 = v42 + 1;
      if ( v42 + 1 >= v42 )
      {
        if ( v43 >= v52->Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v52,
            v52,
            v43 + (v43 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&v52->Data[v43],
          0xFFFFFFFF);
        if ( v43 < v41->Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v41,
            v41,
            v43);
      }
      v44 = v41->Data;
      v41->Size = v43;
      v45 = &v44[v43 - 1];
      if ( !v45 )
        goto LABEL_58;
      v45->pObject = v36;
      if ( v36 )
        break;
LABEL_62:
      if ( ++size >= v3->Namespaces.Data.Size )
      {
        v47 = result;
        result->pV = parenta;
        return v47;
      }
    }
    v36->RefCount = (v36->RefCount + 1) & 0x8FBFFFFF;
LABEL_58:
    if ( v36 && ((unsigned __int8)v36 & 1) == 0 )
    {
      v46 = v36->RefCount;
      if ( (v46 & 0x3FFFFF) != 0 )
      {
        v36->RefCount = v46 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v36);
      }
    }
    goto LABEL_62;
  }
  v47 = result;
  result->pV = parenta;
  return v47;
}
