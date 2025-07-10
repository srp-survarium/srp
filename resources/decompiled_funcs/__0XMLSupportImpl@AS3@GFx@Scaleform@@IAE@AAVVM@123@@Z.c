void __userpurge Scaleform::GFx::AS3::XMLSupportImpl::XMLSupportImpl(
        Scaleform::GFx::AS3::XMLSupportImpl *this@<ecx>,
        int a2@<ebp>,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::ClassTraits::Traits *val)
{
  Scaleform::GFx::AS3::VM *v4; // esi
  Scaleform::GFx::AS3::ASRefCountCollector *GC; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::XML *v7; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::XML *v8; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::XML *v9; // ebx
  Scaleform::GFx::AS3::VMAppDomain *SystemDomain; // ebp
  const Scaleform::GFx::ASString *v11; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::XMLList *v12; // eax
  Scaleform::GFx::AS3::VM *v13; // eax
  Scaleform::GFx::AS3::VM *v14; // ebx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // ecx
  Scaleform::GFx::AS3::VMAppDomain *v16; // esi
  const Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ebp
  const Scaleform::GFx::ASString *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *ns; // [esp+18h] [ebp-4h] BYREF
  Scaleform::GFx::ASStringNode *retaddr; // [esp+1Ch] [ebp+0h] BYREF

  v4 = vm;
  GC = vm->GC.GC;
  this->RefCount = 1;
  this->pRCCRaw = (unsigned int)GC;
  this->Enabled = 1;
  this->__vftable = (Scaleform::GFx::AS3::XMLSupportImpl_vtbl *)&Scaleform::GFx::AS3::XMLSupportImpl::`vftable';
  this->VMRef = v4;
  v7 = (Scaleform::GFx::AS3::ClassTraits::fl::XML *)v4->MHeap->Alloc(v4->MHeap, 104u, 0);
  if ( v7 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::XML::XML(v7, v4);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  SystemDomain = v4->SystemDomain;
  v11 = (const Scaleform::GFx::ASString *)((int (__thiscall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::AS3::Instances::fl::Namespace **, int))v9->ITraits.pObject->GetName)(
                                            v9->ITraits.pObject,
                                            &ns,
                                            a2);
  val = v9;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &SystemDomain->ClassTraitsSet,
    v11,
    ns,
    &val);
  if ( !--retaddr->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(retaddr);
  this->TraitsXML.pObject = v9;
  v12 = (Scaleform::GFx::AS3::ClassTraits::fl::XMLList *)v4->MHeap->Alloc(v4->MHeap, 104u, 0);
  if ( v12 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::XMLList::XMLList(v12, v4);
    v14 = v13;
  }
  else
  {
    v14 = 0;
  }
  pWeakProxy = v14->ExceptionObj.Bonus.pWeakProxy;
  v16 = v4->SystemDomain;
  pObject = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)pWeakProxy[12].pObject;
  v18 = (const Scaleform::GFx::ASString *)(*(int (__cdecl **)(Scaleform::GFx::ASStringNode **))(pWeakProxy->RefCount + 16))(&retaddr);
  vm = v14;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v16->ClassTraitsSet,
    v18,
    pObject,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&vm);
  v19 = (Scaleform::GFx::ASStringNode *)ns;
  --ns->pPrev;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  this->TraitsXMLList.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::XMLList *)v14;
}
