void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3comments(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *result)
{
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v2; // ebp
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edx
  Scaleform::GFx::ASStringManager *pStringManager; // esi
  Scaleform::GFx::ASStringNode *p_NullStringNode; // esi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v7; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v8; // ebx
  unsigned int RefCount; // eax
  unsigned int v11; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *v12; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLList *v13; // ebx
  unsigned int v14; // edi
  unsigned int v15; // ebp
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2,Scaleform::ArrayDefaultPolicy> *p_List; // esi
  unsigned int v17; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *v18; // [esp-10h] [ebp-30h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> r; // [esp+10h] [ebp-10h] BYREF
  unsigned int i; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v21; // [esp+18h] [ebp-8h]
  unsigned int size; // [esp+1Ch] [ebp-4h]

  v2 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this;
  pVM = this->pTraits.pObject->pVM;
  pObject = pVM->PublicNamespace.pObject;
  pStringManager = pVM->StringManagerRef->pStringManager;
  ++pStringManager->NullStringNode.RefCount;
  p_NullStringNode = &pStringManager->NullStringNode;
  v18 = (Scaleform::GFx::AS3::InstanceTraits::fl::XMLList *)v2->pTraits.pObject;
  v21 = v2;
  i = (unsigned int)p_NullStringNode;
  Scaleform::GFx::AS3::InstanceTraits::fl::XMLList::MakeInstance(
    v18,
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&r,
    v18,
    v2,
    (const Scaleform::GFx::ASString *)&i,
    pObject);
  v7 = result->pObject;
  v8 = r.pObject;
  if ( r.pObject != result->pObject )
  {
    if ( v7 )
    {
      if ( ((unsigned __int8)v7 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)((char *)v7 - 1);
      }
      else
      {
        RefCount = v7->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v7->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
        }
      }
    }
    result->pObject = v8;
  }
  if ( p_NullStringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_NullStringNode);
  v11 = 0;
  size = v2->V.ValueA.Data.Size;
  i = 0;
  if ( size )
  {
    do
    {
      v12 = (Scaleform::GFx::AS3::Instances::fl::XML *)*(&v2->V.ValueA.Data.Data->Flags + v11);
      if ( v12->GetKind(v12) == kElement )
      {
        r.pObject = 0;
        Scaleform::GFx::AS3::Instances::fl::XML::AS3comments(v12, &r);
        v13 = r.pObject;
        v14 = r.pObject->List.Data.Size;
        if ( v14 )
        {
          v15 = result->pObject->List.Data.Size;
          p_List = &result->pObject->List;
          r.pObject = (Scaleform::GFx::AS3::Instances::fl::XMLList *)r.pObject->List.Data.Data;
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_List,
            p_List,
            v14 + v15);
          Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>>::ConstructArray(
            &p_List->Data.Data[v15],
            v14,
            (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *)r.pObject);
          v11 = i;
          v2 = v21;
        }
        if ( ((unsigned __int8)v13 & 1) == 0 )
        {
          v17 = v13->RefCount;
          if ( (v17 & 0x3FFFFF) != 0 )
          {
            v13->RefCount = v17 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
          }
        }
      }
      i = ++v11;
    }
    while ( v11 < size );
  }
}
