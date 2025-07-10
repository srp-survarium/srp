void __thiscall Scaleform::GFx::Text::EditorKit::~EditorKit(Scaleform::GFx::Text::EditorKit *this)
{
  Scaleform::GFx::Text::EditorKit::RestrictParams *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  this->__vftable = (Scaleform::GFx::Text::EditorKit_vtbl *)&Scaleform::GFx::Text::EditorKit::`vftable';
  pObject = this->pRestrict.pObject;
  if ( pObject )
  {
    if ( this->pRestrict.Owner )
    {
      this->pRestrict.Owner = 0;
      Scaleform::GFx::Text::EditorKit::RestrictParams::`scalar deleting destructor'(pObject, 1);
    }
    this->pRestrict.pObject = 0;
  }
  this->pRestrict.Owner = 0;
  v3 = (Scaleform::RefCountVImpl *)this->pComposStr.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::RefCountVImpl *)this->pKeyMap.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::RefCountVImpl *)this->pClipboard.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pDocView.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->__vftable = (Scaleform::GFx::Text::EditorKit_vtbl *)&Scaleform::Render::RenderBufferManager::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
