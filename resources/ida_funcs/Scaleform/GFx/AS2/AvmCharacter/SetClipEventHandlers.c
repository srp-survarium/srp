void __thiscall Scaleform::GFx::AS2::AvmCharacter::SetClipEventHandlers(
        Scaleform::GFx::AS2::AvmCharacter *this,
        const Scaleform::GFx::EventId *id,
        const Scaleform::GFx::AS2::Value *method)
{
  unsigned int v3; // ebx
  unsigned __int8 v4; // dl
  unsigned int v5; // ebx
  unsigned int v6; // ebp
  unsigned int v7; // edi
  unsigned int KeyCode; // eax
  unsigned int WcharCode; // edx
  unsigned int TouchID; // ecx
  Scaleform::GFx::EventId copied; // [esp+10h] [ebp-14h] BYREF

  v3 = (((((id->Id & 0x55555555) + ((id->Id >> 1) & 0x55555555)) & 0x33333333)
       + ((((id->Id & 0x55555555) + ((id->Id >> 1) & 0x55555555)) >> 2) & 0x33333333))
      & 0xF0F0F0F)
     + ((((((id->Id & 0x55555555) + ((id->Id >> 1) & 0x55555555)) & 0x33333333)
        + ((((id->Id & 0x55555555) + ((id->Id >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4)
      & 0xF0F0F0F);
  v4 = v3 + v3 / 0xFF;
  v5 = v4;
  if ( v4 == 1 )
  {
    Scaleform::GFx::AS2::AvmCharacter::SetSingleClipEventHandler(this, (int)id, method);
  }
  else
  {
    v6 = 0;
    v7 = 1;
    if ( v4 )
    {
      do
      {
        if ( (v7 & id->Id) != 0 )
        {
          KeyCode = id->KeyCode;
          WcharCode = id->WcharCode;
          copied.Id = id->Id;
          TouchID = id->TouchID;
          copied.KeyCode = KeyCode;
          copied.TouchID = TouchID;
          copied.WcharCode = WcharCode;
          ++v6;
          *(_DWORD *)&copied.RollOverCnt = *(_DWORD *)&id->RollOverCnt;
          copied.Id = v7;
          Scaleform::GFx::AS2::AvmCharacter::SetSingleClipEventHandler(this, (int)&copied, method);
        }
        v7 *= 2;
      }
      while ( v6 < v5 );
    }
  }
}
