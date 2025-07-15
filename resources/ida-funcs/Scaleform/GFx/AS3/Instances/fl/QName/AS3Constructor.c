void __thiscall Scaleform::GFx::AS3::Instances::fl::QName::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::ASString argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ebp
  Scaleform::GFx::AS3::Value *v5; // esi
  Scaleform::GFx::ASStringNode *v6; // ecx
  Scaleform::GFx::AS3::Value *v7; // esi
  bool v8; // zf
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v11; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> *p_Ns; // ebx
  unsigned int v13; // eax
  Scaleform::GFx::AS3::Value *v14; // esi
  unsigned int v15; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *v16; // ebp
  Scaleform::GFx::AS3::Value *Undefined; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *InternedInstance; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *pStringManager; // esi
  Scaleform::GFx::AS3::StringManager *sm; // [esp+10h] [ebp-4h]

  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  sm = StringManagerRef;
  if ( argc.pNode )
  {
    if ( argc.pNode == (Scaleform::GFx::ASStringNode *)1 )
    {
      if ( ((argv->Flags & 0x1F) == 0
         || Scaleform::GFx::AS3::Value::Convert2String(
              argv,
              (Scaleform::GFx::AS3::CheckResult *)&argv,
              &this->LocalName)->Result)
        && Scaleform::GFx::ASString::operator==(&this->LocalName, "*") )
      {
        pObject = this->Ns.pObject;
        if ( pObject )
        {
          if ( ((unsigned __int8)pObject & 1) != 0 )
          {
            this->Ns.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)pObject - 1);
            this->Ns.pObject = 0;
          }
          else
          {
            RefCount = pObject->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
            }
            this->Ns.pObject = 0;
          }
        }
      }
    }
    else
    {
      v11 = this->Ns.pObject;
      p_Ns = &this->Ns;
      if ( v11 )
      {
        if ( ((unsigned __int8)v11 & 1) != 0 )
        {
          p_Ns->pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v11 - 1);
        }
        else
        {
          v13 = v11->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & v13) != 0 )
          {
            v11->RefCount = v13 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
          }
        }
        p_Ns->pObject = 0;
      }
      v14 = argv;
      v15 = argv->Flags & 0x1F;
      if ( v15 - 12 > 3 || argv->value.VS._1.VInt )
      {
        if ( v15 == 11 )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Ns,
            (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)argv->value.VS._1.VInt);
        }
        else if ( Scaleform::GFx::AS3::IsQNameObject(argv) )
        {
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->Ns,
            (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)(v14->value.VS._1.VInt + 36));
        }
        else
        {
          argc.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
          ++argc.pNode->RefCount;
          if ( Scaleform::GFx::AS3::Value::Convert2String(v14, (Scaleform::GFx::AS3::CheckResult *)&argv, &argc)->Result )
          {
            v16 = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *)this->pTraits.pObject->pVM->TraitsNamespace.pObject->ITraits.pObject;
            Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
            InternedInstance = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInternedInstance(
                                                                                                     v16,
                                                                                                     (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&argv,
                                                                                                     NS_Public,
                                                                                                     &argc,
                                                                                                     Undefined);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Ns,
              (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)InternedInstance->pV);
          }
          pNode = argc.pNode;
          --argc.pNode->RefCount;
          if ( !pNode->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
      }
      if ( (v14[1].Flags & 0x1F) == 0xB )
      {
        Scaleform::GFx::AS3::Value::Convert2String(
          (Scaleform::GFx::AS3::Value *)(v14->value.VS._1.VInt + 40),
          (Scaleform::GFx::AS3::CheckResult *)&argv,
          &this->LocalName);
      }
      else if ( Scaleform::GFx::AS3::IsQNameObject(v14 + 1) )
      {
        Scaleform::GFx::ASString::operator=(
          &this->LocalName,
          (const Scaleform::GFx::ASString *)(v14[1].value.VS._1.VInt + 32));
      }
      else if ( (v14[1].Flags & 0x1F) != 0 )
      {
        Scaleform::GFx::AS3::Value::Convert2String(v14 + 1, (Scaleform::GFx::AS3::CheckResult *)&argv, &this->LocalName);
      }
      else
      {
        pStringManager = (Scaleform::GFx::AS3::Value *)sm->pStringManager;
        ++pStringManager[2].value.VS._2.VObj;
        v7 = pStringManager + 2;
        argv = v7;
        Scaleform::GFx::ASString::operator=(&this->LocalName, (const Scaleform::GFx::ASString *)&argv);
        v8 = v7->value.VS._2.VObj-- == (Scaleform::GFx::AS3::Object *)1;
        if ( v8 )
LABEL_5:
          Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v7);
      }
    }
  }
  else
  {
    v5 = (Scaleform::GFx::AS3::Value *)StringManagerRef->pStringManager;
    v5[2].value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)((char *)v5[2].value.VS._2.VObj + 2);
    v6 = this->LocalName.pNode;
    v7 = v5 + 2;
    v8 = v6->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    this->LocalName.pNode = (Scaleform::GFx::ASStringNode *)v7;
    v8 = v7->value.VS._2.VObj-- == (Scaleform::GFx::AS3::Object *)1;
    if ( v8 )
      goto LABEL_5;
  }
}
