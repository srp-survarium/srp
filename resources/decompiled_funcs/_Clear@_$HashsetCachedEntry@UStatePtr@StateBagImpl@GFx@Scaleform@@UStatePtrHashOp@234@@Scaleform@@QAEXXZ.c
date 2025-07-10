void __thiscall Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>::Clear(
        Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp> *this)
{
  Scaleform::GFx::State *pObject; // ecx

  pObject = this->Value.pState.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->NextInChain = -2;
}
