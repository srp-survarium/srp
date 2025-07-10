void __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::Resource *factory,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        const Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Value *prefix)
{
  int v7; // edx
  Scaleform::GFx::ASStringNode *pNode; // eax

  v7 = *((_DWORD *)this + 5);
  this->pRCCRaw = (unsigned int)vm->GC.GC;
  this->VMRef = vm;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::Namespace_vtbl *)&Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable';
  *((_DWORD *)this + 5) = v7 & 0xFFFFFFE0 | kind & 0xF;
  pNode = uri->pNode;
  this->Uri = (Scaleform::GFx::ASString)uri->pNode;
  ++pNode->RefCount;
  if ( factory )
    Scaleform::RefCountImpl::AddRef(factory);
  this->pFactory.pObject = (Scaleform::GFx::AS3::NamespaceInstanceFactory *)factory;
  this->Prefix = *prefix;
  if ( (prefix->Flags & 0x1F) > 9 )
  {
    if ( (prefix->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(prefix);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(prefix);
  }
}
