void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::SetChildren(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::ASStringNode *pVM; // ebx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *p_Children; // ebp
  Scaleform::GFx::AS3::Value *v5; // edi
  Scaleform::GFx::AS3::Value::V1U v6; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *pObject; // eax
  int v8; // eax
  Scaleform::GFx::ASStringNode *v9; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value::V1U v12; // edi
  int v13; // ebx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *v14; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v15; // eax
  int v16; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLText *pV; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString txt; // [esp+10h] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v20; // [esp+14h] [ebp-4h]

  pVM = (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM;
  p_Children = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> > *)&this->Children;
  txt.pNode = pVM;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Children,
    &this->Children,
    0);
  v5 = value;
  if ( (value->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLObject(value->value.VS._1.VObj) )
  {
    v6 = v5->value.VS._1;
    pObject = this;
    while ( pObject != (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v6.VInt )
    {
      pObject = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)pObject->Parent.pObject;
      if ( !pObject )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)(v6.VInt + 36),
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
        if ( v6.VInt )
          *(_DWORD *)(v6.VInt + 16) = (*(_DWORD *)(v6.VInt + 16) + 1) & 0x8FBFFFFF;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &p_Children->Data,
          p_Children,
          p_Children->Data.Size + 1);
        if ( &p_Children->Data.Data[p_Children->Data.Size] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)4 )
        {
          p_Children->Data.Data[p_Children->Data.Size - 1].pObject = v6.CTr;
          if ( !v6.VInt )
            return;
          *(_DWORD *)(v6.VInt + 16) = (*(_DWORD *)(v6.VInt + 16) + 1) & 0x8FBFFFFF;
        }
        if ( v6.VInt && !v6.VBool )
        {
          v8 = *(_DWORD *)(v6.VInt + 16);
          if ( ((unsigned int)&byte_3FFFFF & v8) != 0 )
          {
            *(_DWORD *)(v6.VInt + 16) = v8 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6.VObj);
          }
        }
        return;
      }
    }
  }
  else
  {
    if ( (v5->Flags & 0x1F) - 12 > 3 || !Scaleform::GFx::AS3::IsXMLListObject(v5->value.VS._1.VObj) )
    {
      v16 = *(_DWORD *)(pVM->RefCount + 248);
      txt.pNode = (Scaleform::GFx::ASStringNode *)(v16 + 32);
      ++*(_DWORD *)(v16 + 44);
      if ( Scaleform::GFx::AS3::Value::Convert2String(v5, (Scaleform::GFx::AS3::CheckResult *)&value, &txt)->Result )
      {
        pV = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceText(
               (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->pTraits.pObject,
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLText> *)&value,
               (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->pTraits.pObject,
               &txt,
               this)->pV;
        value = (Scaleform::GFx::AS3::Value *)pV;
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          p_Children,
          (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *)&value);
        if ( pV )
        {
          if ( ((unsigned __int8)pV & 1) == 0 )
          {
            RefCount = pV->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              pV->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
            }
          }
        }
      }
      pNode = txt.pNode;
      goto LABEL_30;
    }
    v12 = v5->value.VS._1;
    v13 = 0;
    value = *(Scaleform::GFx::AS3::Value **)(v12.VInt + 48);
    if ( !value )
    {
LABEL_23:
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> > *)p_Children,
        (const Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy> > *)(v12.VInt + 44));
      return;
    }
LABEL_19:
    v14 = *(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> **)(*(_DWORD *)(v12.VInt + 44)
                                                                                               + 4 * v13);
    v15 = this;
    while ( v15 != (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v14 )
    {
      v15 = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v15->Parent.pObject;
      if ( !v15 )
      {
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          v14 + 9,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
        if ( ++v13 < (unsigned int)value )
          goto LABEL_19;
        goto LABEL_23;
      }
    }
  }
  v9 = txt.pNode;
  Scaleform::GFx::AS3::VM::Error::Error(
    (Scaleform::GFx::AS3::VM::Error *)&txt,
    eXMLIllegalCyclicalLoop,
    (Scaleform::GFx::AS3::VM *)txt.pNode);
  Scaleform::GFx::AS3::VM::ThrowTypeError((Scaleform::GFx::AS3::VM *)v9, v10);
  pNode = v20;
LABEL_30:
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
