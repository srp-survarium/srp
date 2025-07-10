int __thiscall Scaleform::GFx::AS2::SuperObject::SetMemberRaw(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        const Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  return ((int (__thiscall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[5].EntryCount)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           val,
           flags);
}
