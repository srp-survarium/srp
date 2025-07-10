Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *__thiscall Scaleform::GFx::AS3::InstanceTraits::fl::Namespace::MakeInstance(
        Scaleform::GFx::AS3::InstanceTraits::fl::Namespace *this,
        Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *result,
        Scaleform::GFx::AS3::Abc::NamespaceKind kind,
        const Scaleform::GFx::ASString *uri,
        Scaleform::GFx::AS3::Value *prefix)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v7; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *v8; // eax
  int v9; // [esp+4h] [ebp-4h] BYREF

  v9 = 328;
  v6 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                          Scaleform::Memory::pGlobalHeap,
                                                          this,
                                                          56,
                                                          &v9);
  if ( v6 )
  {
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
      v6,
      this->pVM,
      (Scaleform::GFx::Resource *)this->pNamespaceFactory.pObject,
      kind,
      uri,
      prefix);
    result->pV = v7;
    return result;
  }
  else
  {
    v8 = result;
    result->pV = 0;
  }
  return v8;
}
