void __thiscall Scaleform::GFx::TextField::TextDocumentListener::TranslatorChanged(
        Scaleform::GFx::TextField::TextDocumentListener *this)
{
  Scaleform::RefCountVImpl *v2; // eax

  v2 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(char *, int))(*((_DWORD *)this[-13].View_OnHScroll + 2) + 12))(
                                     (char *)this[-13].View_OnHScroll + 8,
                                     1);
  if ( v2 && v2[1].RefCount )
    this->HandlersMask |= 1u;
  else
    this->HandlersMask &= ~1u;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
}
