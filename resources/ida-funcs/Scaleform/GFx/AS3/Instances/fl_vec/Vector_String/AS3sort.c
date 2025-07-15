void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::AS3sort(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *argc,
        Scaleform::GFx::AS3::Value *argv)
{
  char v4; // bl
  unsigned int v6; // eax
  Scaleform::GFx::AS3::VM *pVM; // ebp
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const char *pData; // edi
  Scaleform::GFx::AS3::ClassTraits::fl::String *pObject; // ecx
  const char *v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::StringDataPtr v18; // [esp-10h] [ebp-28h]
  Scaleform::StringDataPtr v19; // [esp-8h] [ebp-20h]
  Scaleform::GFx::AS3::VM::Error v20; // [esp+10h] [ebp-8h] BYREF

  v4 = 0;
  v20.ID = 0;
  if ( argc
    && (v6 = argv->Flags & 0x1F) != 0
    && (v6 - 12 > 3 || argv->value.VS._1.VInt)
    && ((argv->Flags & 0x1F) > 0xF || v6 == 14 || v6 == 5 || v6 == 15 || v6 == 6 || v6 == 7 || v6 == 12 || v6 == 13) )
  {
    Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String>(
      &this->V,
      result,
      (unsigned int)argc,
      argv,
      this);
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    if ( argc )
    {
      ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(pVM, argv);
      v4 = 1;
      pData = ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&argv)->pNode->pData;
    }
    else
    {
      pData = "undefined";
    }
    pObject = this->pTraits.pObject->pVM->TraitsString.pObject;
    v11 = pObject->GetName(pObject, (Scaleform::GFx::ASString *)&argc)->pNode->pData;
    v19.pStr = v11;
    if ( v11 )
      v12 = strlen(v11);
    else
      v12 = 0;
    v19.Size = v12;
    v18.pStr = pData;
    if ( pData )
      v13 = strlen(pData);
    else
      v13 = 0;
    v18.Size = v13;
    Scaleform::GFx::AS3::VM::Error::Error(&v20, eCheckTypeFailedError, (Scaleform::String)pVM, v18, v19);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v14);
    pNode = v20.Message.pNode;
    --v20.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v16 = argc;
    --argc->RefCount;
    if ( !v16->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    if ( (v4 & 1) != 0 )
    {
      v17 = (Scaleform::GFx::ASStringNode *)argv;
      --argv->value.VS._2.VObj;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
}
