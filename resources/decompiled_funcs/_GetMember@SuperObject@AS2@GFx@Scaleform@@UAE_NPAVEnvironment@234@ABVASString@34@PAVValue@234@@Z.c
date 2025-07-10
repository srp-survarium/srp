int __thiscall Scaleform::GFx::AS2::SuperObject::GetMember(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  return ((int (__thiscall *)(Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Value> *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->ResolveHandler.pLocalFrame->Variables.mHash.pTable[2].EntryCount)(
           &this->ResolveHandler.pLocalFrame->Variables,
           penv,
           name,
           val);
}
