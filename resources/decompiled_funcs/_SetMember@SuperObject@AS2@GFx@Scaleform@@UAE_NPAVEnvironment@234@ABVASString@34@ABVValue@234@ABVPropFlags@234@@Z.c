int __thiscall Scaleform::GFx::AS2::SuperObject::SetMember(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  return ((int (__thiscall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[1].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           penv,
           name,
           val,
           flags);
}
