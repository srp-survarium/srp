void __thiscall Scaleform::GFx::AS3::Multiname::Multiname(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::Instances::fl::Namespace *ns,
        const Scaleform::GFx::AS3::Value *name)
{
  this->Kind = MN_QName;
  this->Obj.pObject = ns;
  if ( ns )
    ns->RefCount = (ns->RefCount + 1) & 0x8FBFFFFF;
  this->Name.Flags = 0;
  this->Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(this, name);
}
