void __thiscall Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *parent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::Render::TreeNode *pObject; // ecx

  this->RefCount = 1;
  this->pWeakProxy = 0;
  this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  this->pASRoot = pasRoot;
  this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::DisplayObjectBase_vtbl *)&Scaleform::GFx::DisplayObjectBase::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::DisplayObjectBase::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  this->Id = id;
  this->pParent = parent;
  this->Depth = -1;
  this->CreateFrame = 0;
  this->pRenNode.pObject = 0;
  this->Flags = 0x4000;
  pObject = this->pRenNode.pObject;
  this->pGeomData = 0;
  this->pPerspectiveData = 0;
  this->pIndXFormData = 0;
  this->ClipDepth = 0;
  this->BlendMode = 0;
  this->AvmObjOffset = 0;
  if ( pObject )
    Scaleform::Render::TreeNode::SetVisible(pObject, 1);
}
