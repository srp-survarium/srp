void __thiscall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::Namespace(
        Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *this,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::ClassInfo *ci)
{
  Scaleform::GFx::AS3::NamespaceInstanceFactory *v4; // eax
  Scaleform::GFx::AS3::NamespaceInstanceFactory *v5; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(this, vm, ci);
  this->__vftable = (Scaleform::GFx::AS3::InstanceTraits::fl::Namespace_vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::`vftable';
  this->pNamespaceFactory.pObject = 0;
  this->TraitsType = Traits_Namespace;
  v4 = (Scaleform::GFx::AS3::NamespaceInstanceFactory *)vm->MHeap->Alloc(vm->MHeap, 16, 0);
  if ( v4 )
  {
    v4->__vftable = (Scaleform::GFx::AS3::NamespaceInstanceFactory_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v4->RefCount = 1;
    v4->__vftable = (Scaleform::GFx::AS3::NamespaceInstanceFactory_vtbl *)&Scaleform::GFx::AS3::NamespaceInstanceFactory::`vftable';
    v4->NamespaceSet.pTable = 0;
    v4->pNamespaceInstanceTraits = this;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pNamespaceFactory.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pNamespaceFactory.pObject = v5;
}
