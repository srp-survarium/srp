void __thiscall Scaleform::GFx::AS2::AvmTextField::UpdateAutosizeSettings(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // esi
  char v2; // bl

  pDispObj = this->pDispObj;
  v2 = pDispObj[1].Id.Id & 1;
  if ( v2 && (*(_BYTE *)(pDispObj[1].RefCount + 261) & 8) == 0 )
    Scaleform::Render::Text::DocView::SetAutoSizeX((Scaleform::Render::Text::DocView *)pDispObj[1].RefCount);
  else
    *(_BYTE *)(pDispObj[1].RefCount + 261) &= ~1u;
  if ( v2 )
    Scaleform::Render::Text::DocView::SetAutoSizeY((Scaleform::Render::Text::DocView *)pDispObj[1].RefCount);
  else
    *(_BYTE *)(pDispObj[1].RefCount + 261) &= ~2u;
  pDispObj[1].Id.Id |= 0x2000u;
  Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)pDispObj);
}
