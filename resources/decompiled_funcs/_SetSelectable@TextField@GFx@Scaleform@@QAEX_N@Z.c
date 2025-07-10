void __thiscall Scaleform::GFx::TextField::SetSelectable(Scaleform::GFx::TextField *this, Scaleform::RefCountVImpl *v)
{
  Scaleform::Render::Text::DocView *pObject; // eax
  Scaleform::Render::Text::EditorKitBase *v4; // esi
  Scaleform::GFx::Resource **EditorKit; // edi
  Scaleform::GFx::Resource *v6; // edi

  pObject = this->pDocument.pObject;
  v4 = pObject->pEditorKit.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject->pEditorKit.pObject);
  if ( (_BYTE)v )
  {
    EditorKit = (Scaleform::GFx::Resource **)Scaleform::GFx::TextField::CreateEditorKit(this, (int)this, (int)&v);
    if ( *EditorKit )
      Scaleform::RefCountImpl::AddRef(*EditorKit);
    if ( v4 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
    v6 = *EditorKit;
    if ( v )
      Scaleform::RefCountImpl::Release(v);
    LOWORD(v6[10].pLib) |= 2u;
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
  }
  else if ( v4 )
  {
    LOWORD(v4[16].__vftable) &= ~2u;
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  }
}
