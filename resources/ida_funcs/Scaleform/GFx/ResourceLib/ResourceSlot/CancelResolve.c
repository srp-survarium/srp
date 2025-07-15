void __thiscall Scaleform::GFx::ResourceLib::ResourceSlot::CancelResolve(
        Scaleform::GFx::ResourceLib::ResourceSlot *this,
        char *perrorMessage)
{
  Scaleform::Lock *p_ResourceLock; // edi

  p_ResourceLock = &this->pLib.pObject->ResourceLock;
  EnterCriticalSection(&p_ResourceLock->cs);
  this->State = Resolve_Fail;
  Scaleform::String::operator=(&this->ErrorMessage, perrorMessage);
  Scaleform::HashSetBase<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp,Scaleform::AllocatorGH<Scaleform::GFx::ResourceWeakLib::ResourceNode,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ResourceWeakLib::ResourceNode,Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp>>::RemoveAlt<Scaleform::GFx::ResourceKey>(
    &this->pLib.pObject->Resources,
    &this->Key);
  Scaleform::Event::SetEvent(&this->ResolveComplete);
  LeaveCriticalSection(&p_ResourceLock->cs);
}
