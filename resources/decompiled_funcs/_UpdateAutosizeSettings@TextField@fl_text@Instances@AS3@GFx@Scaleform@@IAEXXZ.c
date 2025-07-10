void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::UpdateAutosizeSettings(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this)
{
  Scaleform::GFx::DisplayObject *pObject; // esi
  char v2; // bl

  pObject = this->pDispObj.pObject;
  v2 = pObject[1].ClipDepth & 1;
  if ( v2 && (BYTE1(pObject[1].pRenNode.pObject[9].pNative) & 8) == 0 )
    Scaleform::Render::Text::DocView::SetAutoSizeX((Scaleform::Render::Text::DocView *)pObject[1].pRenNode.pObject);
  else
    BYTE1(pObject[1].pRenNode.pObject[9].pNative) &= ~1u;
  if ( v2 )
    Scaleform::Render::Text::DocView::SetAutoSizeY((Scaleform::Render::Text::DocView *)pObject[1].pRenNode.pObject);
  else
    BYTE1(pObject[1].pRenNode.pObject[9].pNative) &= ~2u;
  *(_DWORD *)&pObject[1].ClipDepth |= 0x2000u;
  Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)pObject);
}
