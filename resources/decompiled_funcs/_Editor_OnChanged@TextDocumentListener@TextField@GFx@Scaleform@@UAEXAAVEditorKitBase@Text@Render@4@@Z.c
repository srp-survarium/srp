void __thiscall Scaleform::GFx::TextField::TextDocumentListener::Editor_OnChanged(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::EditorKitBase *editor)
{
  Scaleform::GFx::DisplayObjectBase *p_HandlersMask; // esi
  unsigned __int8 AvmObjOffset; // al
  int v4; // eax
  unsigned __int8 v5; // al
  int v6; // eax
  Scaleform::Render::TreeText *RenderNode; // eax

  p_HandlersMask = (Scaleform::GFx::DisplayObjectBase *)&this[-15].HandlersMask;
  Scaleform::Render::Text::DocView::GetText(
    *((Scaleform::Render::Text::DocView **)&this[-15].HandlersMask + 32),
    (Scaleform::String *)&this[-15].HandlersMask + 37);
  AvmObjOffset = p_HandlersMask->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v4 = (*(int (__thiscall **)(int))(*((_DWORD *)&p_HandlersMask->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + AvmObjOffset)
                                    + 16))((int)p_HandlersMask + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 124))(v4);
  }
  v5 = p_HandlersMask->AvmObjOffset;
  if ( v5 )
  {
    v6 = (*(int (__thiscall **)(int))(*((_DWORD *)&p_HandlersMask->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + v5)
                                    + 16))((int)p_HandlersMask + 4 * v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 100))(v6);
  }
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(p_HandlersMask);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}
