void __thiscall Scaleform::GFx::AS3::Classes::fl_ui::Multitouch::supportedGesturesGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Multitouch *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_String> *result)
{
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITraitsVectorString; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v4; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v5; // eax
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *v6; // esi
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // esi
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // esi
  Scaleform::GFx::ASStringNode *v12; // esi
  Scaleform::GFx::ASStringNode *v13; // esi
  char m; // [esp+10h] [ebp-4h]

  pVM = this->pTraits.pObject->pVM;
  m = Scaleform::GFx::MovieImpl::GetSupportedGesturesMask((Scaleform::GFx::MovieImpl *)pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM);
  ITraitsVectorString = Scaleform::GFx::AS3::VM::GetITraitsVectorString(pVM);
  v4 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)Scaleform::GFx::AS3::Traits::Alloc(ITraitsVectorString);
  if ( v4 )
  {
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::Vector_String(v4, ITraitsVectorString);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  pObject = result->pObject;
  if ( v6 != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_String *)((char *)pObject - 1);
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
    }
    result->pObject = v6;
  }
  if ( (m & 1) != 0 )
  {
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        pVM->StringManagerRef->pStringManager,
                        "pan",
                        3u,
                        0);
    ++ConstStringNode->RefCount;
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(result->pObject, ConstStringNode);
    v10 = ConstStringNode->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  }
  if ( (m & 4) != 0 )
  {
    v11 = Scaleform::GFx::ASStringManager::CreateConstStringNode(pVM->StringManagerRef->pStringManager, "rotate", 6u, 0);
    ++v11->RefCount;
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(result->pObject, v11);
    v10 = v11->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  if ( (m & 8) != 0 )
  {
    v12 = Scaleform::GFx::ASStringManager::CreateConstStringNode(pVM->StringManagerRef->pStringManager, "swipe", 5u, 0);
    ++v12->RefCount;
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(result->pObject, v12);
    v10 = v12->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  }
  if ( (m & 2) != 0 )
  {
    v13 = Scaleform::GFx::ASStringManager::CreateConstStringNode(pVM->StringManagerRef->pStringManager, "zoom", 4u, 0);
    ++v13->RefCount;
    Scaleform::GFx::AS3::Instances::fl_vec::Vector_String::PushBack(result->pObject, v13);
    v10 = v13->RefCount-- == 1;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
}
