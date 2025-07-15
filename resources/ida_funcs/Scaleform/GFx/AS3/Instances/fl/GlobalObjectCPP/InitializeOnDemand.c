const Scaleform::GFx::AS3::SlotInfo *__thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::InitializeOnDemand(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        const Scaleform::GFx::AS3::SlotInfo *si,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        unsigned int *index)
{
  const Scaleform::GFx::AS3::SlotInfo *v5; // ebp
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::AS3::VMAppDomain *FrameAppDomain; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v9; // eax
  Scaleform::GFx::AS3::Class *Constructor; // eax

  v5 = si;
  if ( !si && (*((_BYTE *)ns + 20) & 0xF) == 0 )
  {
    pVM = this->pTraits.pObject->pVM;
    FrameAppDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(pVM);
    v9 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(pVM, name, ns, FrameAppDomain);
    if ( v9 )
    {
      Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(v9->ITraits.pObject);
      ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
      return Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(
               this,
               Constructor,
               (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const >)ns,
               index);
    }
  }
  return v5;
}
