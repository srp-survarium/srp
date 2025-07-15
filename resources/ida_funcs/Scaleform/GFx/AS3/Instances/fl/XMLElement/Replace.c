Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASStringNode *i,
        const Scaleform::GFx::AS3::Value *value)
{
  unsigned int Size; // eax
  unsigned int v6; // edi
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_Children; // ebp
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v9; // ebp
  unsigned int RefCount; // eax
  const Scaleform::GFx::AS3::Value *v11; // ebp
  Scaleform::GFx::AS3::Value::V1U v12; // ebp
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v13; // eax
  unsigned int v14; // ebx
  Scaleform::GFx::AS3::Instances::fl::XML *v15; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *v16; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v18; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // ebx
  Scaleform::GFx::AS3::Instances::fl::XML *v23; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *v24; // ecx
  unsigned int v25; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v26; // ecx
  Scaleform::GFx::ASStringNode *VStr; // edi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *InstanceText; // eax
  bool resulta; // [esp+13h] [ebp-9h]
  Scaleform::GFx::AS3::VM::Error v31; // [esp+14h] [ebp-8h] BYREF

  Size = this->Children.Data.Size;
  v6 = (unsigned int)i;
  if ( (unsigned int)i >= Size )
  {
    p_Children = &this->Children;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      &this->Children,
      Size + 1);
    v6 = this->Children.Data.Size - 1;
    pObject = p_Children->Data.Data[v6].pObject;
    v9 = &p_Children->Data.Data[v6];
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        v9->pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)pObject - 1);
      }
      else
      {
        RefCount = pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      v9->pObject = 0;
    }
  }
  v11 = value;
  if ( (value->Flags & 0x1F) - 12 > 3
    || !Scaleform::GFx::AS3::IsXMLObject(value->value.VS._1.VObj)
    || (*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U))(*(_DWORD *)v11->value.VS._1.VInt + 92))(v11->value.VS._1) == 5 )
  {
    if ( (v11->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLListObject(v11->value.VS._1.VObj) )
    {
      this->DeleteByIndex(this, v6);
      resulta = this->InsertChildAt(this, &i, v6, v11)->Result;
      v20 = result;
      result->Result = resulta;
    }
    else
    {
      v22 = v6;
      v23 = this->Children.Data.Data[v6].pObject;
      if ( v23 )
      {
        v24 = v23->Parent.pObject;
        if ( v24 )
        {
          if ( ((unsigned __int8)v24 & 1) != 0 )
          {
            v23->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v24 - 1);
          }
          else
          {
            v25 = v24->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & v25) != 0 )
            {
              v24->RefCount = v25 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
            }
          }
          v23->Parent.pObject = 0;
        }
      }
      v26 = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject;
      VStr = v11->value.VS._1.VStr;
      ++VStr->RefCount;
      i = VStr;
      InstanceText = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
                                                                                           v26,
                                                                                           (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *)&value,
                                                                                           v26,
                                                                                           (const Scaleform::GFx::ASString *)&i,
                                                                                           this);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList>::operator=(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->Children.Data.Data[v22],
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList>)InstanceText->pV);
      if ( VStr->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
      v20 = result;
      result->Result = 1;
    }
  }
  else
  {
    v12 = v11->value.VS._1;
    if ( (*(int (__thiscall **)(Scaleform::GFx::AS3::Value::V1U))(*(_DWORD *)v12.VInt + 92))(v12) == 1 )
    {
      v13 = this;
      while ( v13 != (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v12.VInt )
      {
        v13 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v13->Parent.pObject;
        if ( !v13 )
          goto LABEL_15;
      }
      pVM = this->pTraits.pObject->pVM;
      Scaleform::GFx::AS3::VM::Error::Error(&v31, eXMLIllegalCyclicalLoop, pVM);
      Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v18);
      pNode = v31.Message.pNode;
      --v31.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v20 = result;
      result->Result = 0;
    }
    else
    {
LABEL_15:
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)(v12.VInt + 36),
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
      v14 = v6;
      v15 = this->Children.Data.Data[v6].pObject;
      if ( v15 )
      {
        v16 = v15->Parent.pObject;
        if ( v16 )
        {
          if ( ((unsigned __int8)v16 & 1) != 0 )
          {
            v15->Parent.pObject = (Scaleform::GFx::AS3::Instances::fl::XML *)((char *)v16 - 1);
          }
          else
          {
            v21 = v16->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & v21) != 0 )
            {
              v16->RefCount = v21 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
            }
          }
          v15->Parent.pObject = 0;
        }
      }
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Children.Data.Data[v14],
        (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v12.VInt);
      v20 = result;
      result->Result = 1;
    }
  }
  return v20;
}


Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const Scaleform::GFx::AS3::Multiname *prop_name,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::CheckResult *v5; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int ind; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v10; // [esp+8h] [ebp-8h] BYREF

  if ( Scaleform::GFx::AS3::GetVectorInd((Scaleform::GFx::AS3::CheckResult *)&prop_name, prop_name, &ind)->Result )
  {
    Scaleform::GFx::AS3::Instances::fl::XMLElement::Replace(this, result, (Scaleform::GFx::ASStringNode *)ind, value);
    return result;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v10, eXMLAssignmentToIndexedXMLNotAllowed, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v7);
    pNode = v10.Message.pNode;
    --v10.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v5 = result;
    result->Result = 0;
  }
  return v5;
}
