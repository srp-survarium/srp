void __thiscall Scaleform::GFx::AS3::Classes::fl::XML::Construct(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::ASStringNode *argv,
        bool extCall)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v6; // ebp
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::Value *v8; // edi
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // edx
  unsigned int v11; // eax
  const Scaleform::GFx::AS3::VM::Error *v12; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *InstanceText; // eax
  Scaleform::GFx::ASStringNode *v15; // edi
  Scaleform::GFx::ASStringNode *v16; // esi
  bool v17; // zf
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *v18; // eax
  Scaleform::GFx::AS3::Value::V1U v19; // edi
  const Scaleform::GFx::AS3::VM::Error *v20; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // esi
  Scaleform::GFx::AS3::Instance *v23; // eax
  Scaleform::GFx::AS3::Object *v24; // edi
  Scaleform::GFx::ASString src; // [esp+10h] [ebp-5Ch] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> result; // [esp+18h] [ebp-54h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> v27; // [esp+1Ch] [ebp-50h] BYREF
  Scaleform::GFx::AS3::VM::Error v28; // [esp+24h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::VM::Error v29; // [esp+2Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::XMLParser parser; // [esp+34h] [ebp-38h] BYREF

  pObject = this->pTraits.pObject;
  v6 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)pObject[1].__vftable;
  pVM = pObject->pVM;
  src.pNode = (Scaleform::GFx::ASStringNode *)this;
  if ( argc )
  {
    v8 = (Scaleform::GFx::AS3::Value *)argv;
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(pVM, (const Scaleform::GFx::AS3::Value *)argv);
    TraitsType = ValueTraits->TraitsType;
    v11 = (unsigned int)ValueTraits->Flags >> 5;
    if ( (v11 & 1) != 0 )
    {
      if ( !extCall )
        Scaleform::GFx::AS3::VSBase::PopBack(&pVM->OpStack, argc);
      Scaleform::GFx::AS3::VM::Error::Error(&v28, eInvokeOnIncompatibleObjectError, pVM);
      Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v12);
      pNode = v28.Message.pNode;
LABEL_6:
      if ( !--pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return;
    }
    if ( (v8->Flags & 0x1F) != 0 && ((v8->Flags & 0x1F) - 12 > 3 || v8->value.VS._1.VInt) && (v11 & 1) == 0 )
    {
      switch ( TraitsType )
      {
        case Traits_Boolean:
        case Traits_SInt:
        case Traits_UInt:
        case Traits_Number:
          argv = &pVM->StringManagerRef->pStringManager->EmptyStringNode;
          ++argv->RefCount;
          Scaleform::GFx::AS3::Value::Convert2String(
            v8,
            (Scaleform::GFx::AS3::CheckResult *)&extCall,
            (Scaleform::GFx::ASString *)&argv);
          InstanceText = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                           v6,
                           &result,
                           v6,
                           (const Scaleform::GFx::ASString *)&argv,
                           0);
          Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::fl::XML>(
            _this,
            (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText>)InstanceText->pV);
          pNode = argv;
          goto LABEL_6;
        case Traits_String:
          argv = v8->value.VS._1.VStr;
          ++argv->RefCount;
          if ( *Scaleform::GFx::ASUtils::SkipWhiteSpace(argv->pData, argv->Size) == 60 )
            Scaleform::GFx::AS3::XMLParser::XMLParser(&parser, v6);
          v15 = src.pNode;
          if ( BYTE2(src.pNode[1].HashFlags) )
          {
            v16 = Scaleform::GFx::ASConstString::TruncateWhitespaceNode((Scaleform::GFx::ASConstString *)&argv);
            ++v16->RefCount;
            src.pNode = v16;
            Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&argv, &src);
            v17 = v16->RefCount-- == 1;
            if ( v17 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v16);
          }
          v18 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                  *(Scaleform::GFx::AS3::InstanceTraits::fl::XML **)(v15->Size + 100),
                  &v27,
                  *(Scaleform::GFx::AS3::InstanceTraits::Traits **)(v15->Size + 100),
                  (const Scaleform::GFx::ASString *)&argv,
                  0);
          Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::fl::XML>(
            _this,
            (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText>)v18->pV);
          pNode = argv;
          goto LABEL_6;
        case Traits_XML:
          (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, Scaleform::GFx::ASStringNode **, _DWORD))(*(_DWORD *)v8->value.VS._1.VInt + 128))(
            v8->value.VS._1,
            &argv,
            0);
          Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::fl::XML>(
            _this,
            (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText>)argv);
          return;
        case Traits_XMLList:
          v19 = v8->value.VS._1;
          if ( *(_DWORD *)(v19.VInt + 48) == 1 )
          {
            Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::fl::Object>(
              _this,
              *(const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> **)(v19.VInt + 44));
            return;
          }
          if ( !extCall )
            Scaleform::GFx::AS3::VSBase::PopBack(&pVM->OpStack, argc);
          Scaleform::GFx::AS3::VM::Error::Error(&v29, eInvokeOnIncompatibleObjectError, pVM);
          Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v20);
          pNode = v29.Message.pNode;
          break;
        default:
          goto LABEL_27;
      }
      goto LABEL_6;
    }
  }
LABEL_27:
  pStringManager = pVM->StringManagerRef->pStringManager;
  ++pStringManager->EmptyStringNode.RefCount;
  p_EmptyStringNode = &pStringManager->EmptyStringNode;
  v23 = (Scaleform::GFx::AS3::Instance *)v6->pVM->MHeap->Alloc(v6->pVM->MHeap, 40u, 0);
  v24 = v23;
  if ( v23 )
  {
    Scaleform::GFx::AS3::Instance::Instance(v23, v6);
    v24->__vftable = (Scaleform::GFx::AS3::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XML::`vftable';
    v24[1].__vftable = (Scaleform::GFx::AS3::Object_vtbl *)p_EmptyStringNode;
    ++p_EmptyStringNode->RefCount;
    v24[1].pRCCRaw = 0;
    v24->__vftable = (Scaleform::GFx::AS3::Object_vtbl *)&Scaleform::GFx::AS3::Instances::fl::XMLText::`vftable';
  }
  else
  {
    v24 = 0;
  }
  Scaleform::GFx::AS3::Value::Pick(_this, v24);
  v17 = p_EmptyStringNode->RefCount-- == 1;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}
