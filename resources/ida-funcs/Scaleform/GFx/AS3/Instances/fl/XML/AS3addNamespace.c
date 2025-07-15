void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3addNamespace(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        const Scaleform::GFx::AS3::Value *ns)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::Value vns; // [esp+14h] [ebp-10h] BYREF

  if ( (ns->Flags & 0x1F) == 0 || (ns->Flags & 0x1F) - 12 <= 3 && !ns->value.VS._1.VInt )
  {
LABEL_13:
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
    return;
  }
  pVM = this->pTraits.pObject->pVM;
  vns.Flags = 0;
  vns.Bonus.pWeakProxy = 0;
  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(pVM->TraitsNamespace.pObject->ITraits.pObject);
  Constructor->Construct(Constructor, &vns, 1u, ns, 1);
  if ( !pVM->HandleException )
  {
    this->AddInScopeNamespace(this, (const Scaleform::GFx::AS3::Instances::fl::Namespace *)vns.value.VS._1.VInt);
    if ( (vns.Flags & 0x1F) > 9 )
    {
      if ( (vns.Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&vns);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
        return;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(&vns);
    }
    goto LABEL_13;
  }
  if ( (vns.Flags & 0x1F) > 9 )
  {
    if ( (vns.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&vns);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&vns);
  }
}
