void __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        char *uri)
{
  int v5; // edx
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax

  v5 = *((_DWORD *)this + 5);
  this->pRCCRaw = (unsigned int)vm->GC.GC;
  this->VMRef = vm;
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::Namespace_vtbl *)&Scaleform::GFx::AS3::Instances::fl::Namespace::`vftable';
  *((_DWORD *)this + 5) = v5 & 0xFFFFFFE0 | kind & 0xF;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      vm->StringManagerRef->pStringManager,
                      uri,
                      strlen(uri),
                      0);
  this->Uri.pNode = ConstStringNode;
  ++ConstStringNode->RefCount;
  this->pFactory.pObject = 0;
  this->Prefix.Flags = 0;
  this->Prefix.Bonus.pWeakProxy = 0;
}
