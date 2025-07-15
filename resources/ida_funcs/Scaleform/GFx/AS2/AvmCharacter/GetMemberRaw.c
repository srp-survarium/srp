int __thiscall Scaleform::GFx::AS2::AvmCharacter::GetMemberRaw(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::AvmCharacter_vtbl *v5; // edi
  int v6; // eax

  v5 = this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
  v6 = ((int (__thiscall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this[-1].EventHandlers.mHash.pTable[15].SizeMask)(
         &this[-1].EventHandlers,
         name,
         val);
  return ((int (__thiscall *)(Scaleform::GFx::AS2::AvmCharacter *, int))v5->ToAvmTextFieldBase)(this, v6);
}
