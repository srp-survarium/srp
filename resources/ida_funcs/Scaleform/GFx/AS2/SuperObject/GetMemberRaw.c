int __thiscall Scaleform::GFx::AS2::SuperObject::GetMemberRaw(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  return ((int (__thiscall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[5].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           val);
}
