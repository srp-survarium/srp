char __thiscall Scaleform::GFx::AS3::Instances::fl_net::SharedObject::FlushImpl(
        Scaleform::GFx::AS3::Instances::fl_net::SharedObject *this,
        Scaleform::GFx::SharedObjectVisitor *writer)
{
  Scaleform::GFx::SharedObjectVisitor_vtbl *v3; // edx
  Scaleform::GFx::AS3::Instances::fl::Object *pObject; // edi
  void (__thiscall *Begin)(Scaleform::GFx::SharedObjectVisitor *); // eax
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject::FlushImpl::__l4::DataWriter visitor; // [esp+4h] [ebp-Ch] BYREF

  if ( !writer )
    return 0;
  v3 = writer->__vftable;
  pObject = this->DataObj.pObject;
  visitor.pVM = this->pTraits.pObject->pVM;
  Begin = v3->Begin;
  visitor.VisitedObjects.mHash.pTable = 0;
  visitor.pWriter = writer;
  Begin(writer);
  Scaleform::GFx::AS3::Instances::fl_net::SharedObject::FlushImpl_::_4_::DataWriter::VisitMembers(
    &visitor,
    &visitor,
    pObject);
  writer->End(writer);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Object *,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>,Scaleform::HashNode<Scaleform::GFx::AS2::Object *,Scaleform::GFx::AS2::Object *,Scaleform::IdentityHash<Scaleform::GFx::AS2::Object *>>::NodeHashF>>(&visitor.VisitedObjects.mHash);
  return 1;
}
