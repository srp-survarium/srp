void __thiscall Scaleform::GFx::AS3::AvmBitmap::AvmBitmap(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        const Scaleform::GFx::CharacterCreateInfo *ccinfo,
        Scaleform::GFx::InteractiveObject *pparent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::MovieDefImpl *pBindDefImpl; // edi
  Scaleform::GFx::ImageResource *pResource; // edi
  Scaleform::GFx::MovieDefImpl *pObject; // ecx
  Scaleform::GFx::ImageResource *v9; // ecx
  Scaleform::GFx::ResourceHandle rh; // [esp+Ch] [ebp-8h] BYREF

  Scaleform::GFx::DisplayObject::DisplayObject(this, pasRoot, pparent, id);
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(&this->Scaleform::GFx::AS3::AvmDisplayObj, this);
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::AS3::AvmBitmap_vtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS3::AvmDisplayObj_vtbl *)&Scaleform::GFx::AS3::AvmBitmap::`vftable';
  pBindDefImpl = ccinfo->pBindDefImpl;
  if ( pBindDefImpl )
    Scaleform::RefCountImpl::AddRef(ccinfo->pBindDefImpl);
  this->pDefImpl.pObject = pBindDefImpl;
  this->pImage.pObject = 0;
  pResource = (Scaleform::GFx::ImageResource *)ccinfo->pResource;
  if ( id.Id != 0x40000 )
  {
    pObject = this->pDefImpl.pObject;
    rh.HType = RH_Pointer;
    rh.BindIndex = 0;
    if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
           pObject->pBindData.pObject->pDataDef.pObject->pData.pObject,
           (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&rh,
           id) )
    {
      pResource = (Scaleform::GFx::ImageResource *)Scaleform::GFx::ResourceHandle::GetResource(
                                                     &rh,
                                                     &this->pDefImpl.pObject->pBindData.pObject->ResourceBinding);
    }
    if ( rh.HType == RH_Pointer && rh.BindIndex )
      Scaleform::GFx::Resource::Release(rh.pResource);
  }
  if ( pResource && (pResource->GetResourceTypeCode(pResource) & 0xFF00) == 0x100 )
  {
    Scaleform::RefCountImpl::AddRef(pResource);
    v9 = this->pImage.pObject;
    if ( v9 )
      Scaleform::GFx::Resource::Release(v9);
    this->pImage.pObject = pResource;
  }
}
