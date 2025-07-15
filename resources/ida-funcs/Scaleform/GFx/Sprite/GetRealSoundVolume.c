double __thiscall Scaleform::GFx::Sprite::GetRealSoundVolume(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  Scaleform::GFx::InteractiveObject *pParent; // eax
  float LastHitTestY; // ecx
  int Volume; // [esp+0h] [ebp-8h]
  float i; // [esp+0h] [ebp-8h]
  int v7; // [esp+4h] [ebp-4h]

  pActiveSounds = this->pActiveSounds;
  if ( pActiveSounds )
    Volume = pActiveSounds->Volume;
  else
    Volume = 100;
  pParent = this->pParent;
  for ( i = (double)Volume / 100.0; pParent; pParent = pParent->pParent )
  {
    if ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
    {
      LastHitTestY = pParent[1].LastHitTestY;
      if ( LastHitTestY == 0.0 )
        v7 = 100;
      else
        v7 = *(_DWORD *)LODWORD(LastHitTestY);
      i = (double)v7 / 100.0 * i;
    }
  }
  return i;
}
