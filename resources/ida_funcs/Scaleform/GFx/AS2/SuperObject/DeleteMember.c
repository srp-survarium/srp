int __thiscall Scaleform::GFx::AS2::SuperObject::DeleteMember(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name)
{
  return ((int (__thiscall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[3].EntryCount)(
           &this->ResolveHandler.pLocalFrame->Variables,
           psc,
           name);
}
