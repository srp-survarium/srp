int __thiscall Scaleform::GFx::Sprite::GetSoundPan(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax

  pActiveSounds = this->pActiveSounds;
  if ( pActiveSounds )
    return pActiveSounds->Pan;
  else
    return 0;
}
