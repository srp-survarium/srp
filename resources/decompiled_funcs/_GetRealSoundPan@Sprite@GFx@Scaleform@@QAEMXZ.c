double __thiscall Scaleform::GFx::Sprite::GetRealSoundPan(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax
  Scaleform::GFx::InteractiveObject *pParent; // eax
  float LastHitTestY; // ecx
  int v; // [esp+0h] [ebp-8h]
  float va; // [esp+0h] [ebp-8h]
  int v7; // [esp+4h] [ebp-4h]

  pActiveSounds = this->pActiveSounds;
  if ( pActiveSounds )
    v = pActiveSounds->Pan;
  else
    v = 0;
  pParent = this->pParent;
  for ( va = (double)v / 100.0; pParent; pParent = pParent->pParent )
  {
    if ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
    {
      LastHitTestY = pParent[1].LastHitTestY;
      if ( LastHitTestY == 0.0 )
        v7 = 0;
      else
        v7 = *(_DWORD *)(LODWORD(LastHitTestY) + 8);
      va = (double)v7 / 100.0 * va;
    }
  }
  return va;
}
