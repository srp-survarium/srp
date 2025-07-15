int __thiscall Scaleform::GFx::AS2::SuperObject::FindMember(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Member *pmember)
{
  return ((int (__thiscall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Member *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[2].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           pmember);
}
