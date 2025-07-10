void __thiscall Scaleform::GFx::AS3::Instances::fl_system::Domain::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_system::Domain *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::VMAppDomain *FrameAppDomain; // eax
  Scaleform::GFx::AS3::VM *v6; // [esp-4h] [ebp-8h]

  pVM = this->pTraits.pObject->pVM;
  if ( argc && (argv->Flags & 0x1F) != 0 && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt) )
  {
    this->VMDomain = Scaleform::GFx::AS3::VMAppDomain::AddNewChild(
                       *(Scaleform::GFx::AS3::VMAppDomain **)(argv->value.VS._1.VInt + 32),
                       pVM);
  }
  else
  {
    v6 = pVM;
    FrameAppDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(pVM);
    this->VMDomain = Scaleform::GFx::AS3::VMAppDomain::AddNewChild(FrameAppDomain, v6);
  }
}
