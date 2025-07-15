void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3setNamespace(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *ns)
{
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v4; // eax
  Scaleform::GFx::AS3::Instances::fl::XML::Kind v5; // edi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *Namespace; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // ebx
  void (__thiscall *AS3Constructor)(Scaleform::GFx::AS3::Instances::fl::Namespace *, unsigned int, const Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::Instances::fl::XML *v9; // ecx
  Scaleform::GFx::AS3::Instances::fl::XML_vtbl *v10; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace> ns2; // [esp+8h] [ebp-4h] BYREF

  v4 = this->GetKind(this);
  v5 = v4;
  if ( v4 == kText || v4 == kComment || v4 == kInstruction )
    return;
  Namespace = Scaleform::GFx::AS3::VM::MakeNamespace(
                this->pTraits.pObject->pVM,
                (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace> *)&ns2,
                NS_Public);
  AS3Constructor = Namespace->pV->AS3Constructor;
  ns2.pObject = Namespace->pV;
  pObject = ns2.pObject;
  AS3Constructor(ns2.pObject, 1u, ns);
  if ( v5 == kAttr )
  {
    v9 = this->Parent.pObject;
    if ( !v9 )
    {
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&ns2);
      return;
    }
    v10 = v9->__vftable;
  }
  else
  {
    if ( v5 != kElement )
      goto LABEL_11;
    v10 = this->__vftable;
  }
  ((void (__stdcall *)(Scaleform::GFx::AS3::Instances::fl::Namespace *))v10->AddInScopeNamespace)(pObject);
LABEL_11:
  this->SetNamespace(this, pObject);
  if ( ((unsigned __int8)pObject & 1) == 0 )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
}
