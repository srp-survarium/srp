void __thiscall Scaleform::Render::TreeText::Init(Scaleform::Render::TreeText *this, Scaleform::GFx::Resource *docView)
{
  Scaleform::RefCountVImpl **v2; // esi

  v2 = (Scaleform::RefCountVImpl **)&Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u)[18];
  if ( docView )
    Scaleform::RefCountImpl::AddRef(docView);
  if ( *v2 )
    Scaleform::RefCountImpl::Release(*v2);
  *v2 = (Scaleform::RefCountVImpl *)docView;
}
