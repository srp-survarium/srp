int __thiscall Scaleform::GFx::AS2::SuperObject::HasMember(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        int inclPrototypes)
{
  return ((int (__thiscall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, int))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[4].SizeMask)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name,
           inclPrototypes);
}
