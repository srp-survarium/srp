Scaleform::GFx::DisplayObjContainer *__thiscall Scaleform::GFx::AS3::MovieRoot::GetRootMovie(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::DisplayObject *dobj)
{
  Scaleform::GFx::DisplayObjContainer *result; // eax

  if ( !dobj )
    return this->pStage.pObject->pRoot.pObject;
  result = (Scaleform::GFx::DisplayObjContainer *)Scaleform::GFx::AS3::AvmDisplayObj::GetRoot((Scaleform::GFx::AS3::AvmDisplayObj *)(&dobj->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable + dobj->AvmObjOffset));
  if ( !result )
    return this->pStage.pObject->pRoot.pObject;
  if ( (result->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x200) == 0 )
    return this->GetRootMovie(this, result->pParent);
  return result;
}
