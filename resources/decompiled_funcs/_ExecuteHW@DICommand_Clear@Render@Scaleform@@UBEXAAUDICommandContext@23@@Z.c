void __thiscall Scaleform::Render::DICommand_Clear::ExecuteHW(
        Scaleform::Render::DICommand_Clear *this,
        Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::Size<unsigned long> *v3; // eax
  unsigned int Raw; // ecx
  float Width; // [esp+10h] [ebp-20h]
  float Height; // [esp+14h] [ebp-1Ch]
  _BYTE v7[8]; // [esp+18h] [ebp-18h] BYREF
  _DWORD v8[4]; // [esp+20h] [ebp-10h] BYREF

  Scaleform::Render::HAL::applyBlendMode(context->pHAL, Blend_OverwriteAll, 1, (Scaleform::String::DataDesc *)1);
  v3 = this->pImage.pObject->GetSize(this->pImage.pObject, v7);
  Width = (float)v3->Width;
  Height = (float)v3->Height;
  v8[0] = 0;
  v8[1] = 0;
  v8[2] = (int)Width;
  Raw = this->FillColor.Raw;
  v8[3] = (int)Height;
  ((void (__thiscall *)(Scaleform::Render::HAL *, _DWORD *, unsigned int))context->pHAL->clearSolidRectangle)(
    context->pHAL,
    v8,
    Raw);
  Scaleform::Render::HAL::applyBlendMode(context->pHAL, Blend_None, 0, 0);
}
