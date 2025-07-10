Scaleform::Render::ContextImpl::Entry *__thiscall Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry(
        Scaleform::Render::ContextImpl::RTHandle *this)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pObject; // eax

  pObject = this->pData.pObject;
  if ( this->pData.pObject && pObject->State == State_Valid )
    return pObject->pEntry;
  else
    return 0;
}
