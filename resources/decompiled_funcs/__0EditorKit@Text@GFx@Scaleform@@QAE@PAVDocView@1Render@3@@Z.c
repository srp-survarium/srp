void __thiscall Scaleform::GFx::Text::EditorKit::EditorKit(
        Scaleform::GFx::Text::EditorKit *this,
        Scaleform::GFx::Resource *pdocview)
{
  Scaleform::RefCountVImpl *pLib; // ecx
  float pdocviewa; // [esp+10h] [ebp+4h]

  this->__vftable = (Scaleform::GFx::Text::EditorKit_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::Text::EditorKit_vtbl *)&Scaleform::GFx::Text::EditorKit::`vftable';
  if ( pdocview )
    Scaleform::RefCountImpl::AddRef(pdocview);
  this->pDocView.pObject = (Scaleform::Render::Text::DocView *)pdocview;
  this->pClipboard.pObject = 0;
  this->pKeyMap.pObject = 0;
  this->pComposStr.pObject = 0;
  this->pRestrict.pObject = 0;
  this->pRestrict.Owner = 1;
  this->CursorRect.Value.x1 = 0.0;
  this->CursorRect.Value.y1 = 0.0;
  this->CursorRect.Value.x2 = 0.0;
  this->CursorRect.FormatCounter = 0;
  this->CursorRect.Value.y2 = 0.0;
  this->CursorPos = 0;
  this->CursorTimer = 0.0;
  this->Flags = 0;
  this->CursorColor.Raw = -16777216;
  this->LastAdvanceTime = 0.0;
  this->LastClickTime = 0;
  this->LastHorizCursorPos = -1.0;
  this->CursorRect.Value.x1 = 0.0;
  this->CursorRect.Value.y1 = 0.0;
  pdocviewa = 0.0 + 0.0;
  this->CursorRect.Value.x2 = pdocviewa;
  this->CursorRect.Value.y2 = pdocviewa;
  this->ActiveSelectionBkColor = -16777216;
  this->ActiveSelectionTextColor = -1;
  this->InactiveSelectionBkColor = -8355712;
  this->InactiveSelectionTextColor = -1;
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)this);
  pLib = (Scaleform::RefCountVImpl *)pdocview[13].pLib;
  if ( pLib )
    Scaleform::RefCountImpl::Release(pLib);
  pdocview[13].pLib = (Scaleform::GFx::ResourceLibBase *)this;
}
