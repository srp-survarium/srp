void __thiscall Scaleform::Render::TreeShape::SetShape(
        Scaleform::Render::TreeShape *this,
        Scaleform::Render::ContextImpl::EntryData_vtbl *pshape)
{
  Scaleform::Render::ContextImpl::EntryData *v3; // esi

  v3 = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u) + 18;
  if ( pshape )
    (*((void (__thiscall **)(void (__thiscall **)(Scaleform::Render::ContextImpl::EntryData *, void *)))pshape->CopyTo
     + 1))(&pshape->CopyTo);
  if ( v3->__vftable )
    (*((void (__thiscall **)(void (__thiscall **)(Scaleform::Render::ContextImpl::EntryData *, void *)))v3->CopyTo + 2))(&v3->CopyTo);
  v3->__vftable = pshape;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(this);
}
