void __thiscall Scaleform::GFx::AS3::XMLSupportImpl::DescribeType(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *v4; // ebp
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  const Scaleform::GFx::AS3::Value *v8; // ecx
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v9; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v10; // ebp
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v11; // ecx
  unsigned int RefCount; // eax
  unsigned int v13; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  const Scaleform::GFx::ASString *p_vm; // ebp
  Scaleform::GFx::ASString *(__thiscall *GetQualifiedName)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Traits::QNameFormat); // edx
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  const Scaleform::GFx::AS3::Value *v23; // eax
  const Scaleform::GFx::AS3::Traits *v24; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v25; // ebp
  const Scaleform::GFx::ASString *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  const Scaleform::GFx::AS3::Value *v29; // eax
  const Scaleform::GFx::AS3::Traits *v30; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v31; // ebp
  const Scaleform::GFx::ASString *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::ASString *p_true; // ebp
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::GFx::ASString *p_false; // ebp
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::ASString *v39; // ebp
  Scaleform::GFx::ASStringNode *v40; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v42; // eax
  Scaleform::GFx::ASStringNode *v43; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> xml; // [esp+10h] [ebp-20h] BYREF
  const Scaleform::GFx::AS3::Traits *tr; // [esp+14h] [ebp-1Ch]
  const Scaleform::GFx::AS3::Traits *parent; // [esp+18h] [ebp-18h]
  Scaleform::GFx::ASString _false; // [esp+1Ch] [ebp-14h] BYREF
  Scaleform::GFx::ASString _true; // [esp+20h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::XMLSupportImpl *v49; // [esp+24h] [ebp-Ch]
  Scaleform::GFx::ASString _type; // [esp+28h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::Instances::fl::XMLElement *pV; // [esp+2Ch] [ebp-4h]

  v4 = vm;
  StringManagerRef = vm->StringManagerRef;
  pObject = vm->PublicNamespace.pObject;
  v49 = this;
  parent = 0;
  tr = Scaleform::GFx::AS3::VM::GetValueTraits(vm, value);
  _true.pNode = StringManagerRef->Builtins[4].pNode;
  ++_true.pNode->RefCount;
  _false.pNode = StringManagerRef->Builtins[5].pNode;
  ++_false.pNode->RefCount;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      StringManagerRef->pStringManager,
                      "type",
                      4u,
                      0);
  v8 = value;
  _type.pNode = ConstStringNode;
  ++ConstStringNode->RefCount;
  if ( (v8->Flags & 0x1F) == 0xD )
    parent = v4->TraitsClassClass.pObject;
  else
    parent = tr->pParent.pObject;
  v9 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)v49->GetITraitsXML(v49);
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v9, &xml, v9, pObject, &_type, 0);
  v10 = result;
  v11 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)result->pObject;
  pV = xml.pV;
  if ( xml.pV != v11 )
  {
    if ( v11 )
    {
      if ( ((unsigned __int8)v11 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)v11 - 1);
      }
      else
      {
        RefCount = v11->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
        }
      }
    }
    v10->pObject = pV;
  }
  v13 = value->Flags & 0x1F;
  if ( v13 && (v13 - 12 > 3 || value->value.VS._1.VInt) )
  {
    v23 = (const Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                StringManagerRef->pStringManager,
                                                "name",
                                                4u,
                                                0);
    v24 = tr;
    value = (Scaleform::GFx::AS3::Value *)v23;
    ++v23->value.VS._2.VObj;
    v25 = xml.pV;
    v26 = v24->GetQualifiedName(v24, (Scaleform::GFx::ASString *)&result, qnfWithColons);
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v25, pObject, (const Scaleform::GFx::ASString *)&value, v26);
    v27 = (Scaleform::GFx::ASStringNode *)value;
    --value->value.VS._2.VObj;
    if ( !v27->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    v28 = (Scaleform::GFx::ASStringNode *)result;
    --result[3].pObject;
    if ( !v28->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    if ( parent )
    {
      v29 = (const Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                  StringManagerRef->pStringManager,
                                                  "base",
                                                  4u,
                                                  0);
      v30 = parent;
      value = (Scaleform::GFx::AS3::Value *)v29;
      ++v29->value.VS._2.VObj;
      v31 = xml.pV;
      v32 = v30->GetQualifiedName(v30, (Scaleform::GFx::ASString *)&result, qnfWithColons);
      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
        v31,
        pObject,
        (const Scaleform::GFx::ASString *)&value,
        v32);
      v33 = (Scaleform::GFx::ASStringNode *)value;
      --value->value.VS._2.VObj;
      if ( !v33->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
      v34 = (Scaleform::GFx::ASStringNode *)result;
      --result[3].pObject;
      if ( !v34->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    }
    p_true = &_true;
    if ( (tr->Flags & 2) == 0 )
      p_true = &_false;
    value = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                            StringManagerRef->pStringManager,
                                            "isDynamic",
                                            9u,
                                            0);
    ++value->value.VS._2.VObj;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
      xml.pV,
      pObject,
      (const Scaleform::GFx::ASString *)&value,
      p_true);
    v36 = (Scaleform::GFx::ASStringNode *)value;
    --value->value.VS._2.VObj;
    if ( !v36->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v36);
    p_false = &_true;
    if ( (tr->Flags & 0x40) == 0 )
      p_false = &_false;
    value = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                            StringManagerRef->pStringManager,
                                            "isFinal",
                                            7u,
                                            0);
    ++value->value.VS._2.VObj;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
      xml.pV,
      pObject,
      (const Scaleform::GFx::ASString *)&value,
      p_false);
    v38 = (Scaleform::GFx::ASStringNode *)value;
    --value->value.VS._2.VObj;
    if ( !v38->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v38);
    v39 = &_true;
    if ( (tr->Flags & 0x20) == 0 )
      v39 = &_false;
    value = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                            StringManagerRef->pStringManager,
                                            "isStatic",
                                            8u,
                                            0);
    ++value->value.VS._2.VObj;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
      xml.pV,
      pObject,
      (const Scaleform::GFx::ASString *)&value,
      v39);
    v40 = (Scaleform::GFx::ASStringNode *)value;
    --value->value.VS._2.VObj;
    if ( !v40->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v40);
    Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits(
      v49,
      vm,
      xml.pV,
      (Scaleform::GFx::AS3::InstanceTraits::UserDefined *)tr);
  }
  else
  {
    if ( v13 - 12 > 3 || value->value.VS._1.VInt )
    {
      GetQualifiedName = tr->GetQualifiedName;
      parent = (const Scaleform::GFx::AS3::Traits *)2;
      p_vm = GetQualifiedName(tr, (Scaleform::GFx::ASString *)&result, qnfWithColons);
    }
    else
    {
      pStringManager = StringManagerRef->pStringManager;
      parent = (const Scaleform::GFx::AS3::Traits *)1;
      vm = (Scaleform::GFx::AS3::VM *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                        pStringManager,
                                        "null",
                                        4u,
                                        0);
      ++vm->StringManagerRef;
      p_vm = (const Scaleform::GFx::ASString *)&vm;
    }
    value = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                            StringManagerRef->pStringManager,
                                            "name",
                                            4u,
                                            0);
    ++value->value.VS._2.VObj;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
      xml.pV,
      pObject,
      (const Scaleform::GFx::ASString *)&value,
      p_vm);
    v17 = (Scaleform::GFx::ASStringNode *)value;
    --value->value.VS._2.VObj;
    if ( !v17->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    if ( ((unsigned __int8)parent & 2) != 0 )
    {
      v18 = (Scaleform::GFx::ASStringNode *)result;
      parent = (const Scaleform::GFx::AS3::Traits *)((unsigned int)parent & 0xFFFFFFFD);
      --result[3].pObject;
      if ( !v18->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
    if ( ((unsigned __int8)parent & 1) != 0 )
    {
      v19 = (Scaleform::GFx::ASStringNode *)vm;
      --vm->StringManagerRef;
      if ( !v19->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    }
    value = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                            StringManagerRef->pStringManager,
                                            "isDynamic",
                                            9u,
                                            0);
    ++value->value.VS._2.VObj;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
      xml.pV,
      pObject,
      (const Scaleform::GFx::ASString *)&value,
      &_false);
    v20 = (Scaleform::GFx::ASStringNode *)value;
    --value->value.VS._2.VObj;
    if ( !v20->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    value = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                            StringManagerRef->pStringManager,
                                            "isFinal",
                                            7u,
                                            0);
    ++value->value.VS._2.VObj;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
      xml.pV,
      pObject,
      (const Scaleform::GFx::ASString *)&value,
      &_true);
    v21 = (Scaleform::GFx::ASStringNode *)value;
    --value->value.VS._2.VObj;
    if ( !v21->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    value = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                            StringManagerRef->pStringManager,
                                            "isStatic",
                                            8u,
                                            0);
    ++value->value.VS._2.VObj;
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
      xml.pV,
      pObject,
      (const Scaleform::GFx::ASString *)&value,
      &_false);
    v22 = (Scaleform::GFx::ASStringNode *)value;
    --value->value.VS._2.VObj;
    if ( !v22->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  }
  pNode = _type.pNode;
  --_type.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v42 = _false.pNode;
  --_false.pNode->RefCount;
  if ( !v42->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  v43 = _true.pNode;
  --_true.pNode->RefCount;
  if ( !v43->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
}
