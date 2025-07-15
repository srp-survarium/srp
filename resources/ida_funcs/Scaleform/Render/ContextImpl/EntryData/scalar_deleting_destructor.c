Scaleform::Render::ContextImpl::EntryData *__thiscall Scaleform::Render::ContextImpl::EntryData::`scalar deleting destructor'(
        Scaleform::Render::ContextImpl::EntryData *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::ContextImpl::EntryData_vtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
