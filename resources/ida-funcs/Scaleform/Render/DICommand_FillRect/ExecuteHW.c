void __thiscall Scaleform::Render::DICommand_FillRect::ExecuteHW(
        Scaleform::Render::DICommand_FillRect *this,
        Scaleform::Render::DICommandContext *context)
{
  int x2; // ecx
  int y1; // eax
  int y2; // edx
  _DWORD v7[4]; // [esp+8h] [ebp-10h] BYREF
  unsigned int Raw; // [esp+1Ch] [ebp+4h]

  Scaleform::Render::HAL::applyBlendMode(context->pHAL, Blend_OverwriteAll, 1, (Scaleform::String::DataDesc *)1);
  Raw = this->FillColor.Raw;
  if ( !this->pImage.pObject->Transparent )
    HIBYTE(Raw) = -1;
  x2 = this->ApplyRect.x2;
  y1 = this->ApplyRect.y1;
  v7[0] = this->ApplyRect.x1;
  y2 = this->ApplyRect.y2;
  v7[1] = y1;
  v7[2] = x2;
  v7[3] = y2;
  ((void (__thiscall *)(Scaleform::Render::HAL *, _DWORD *, unsigned int))context->pHAL->clearSolidRectangle)(
    context->pHAL,
    v7,
    Raw);
}
