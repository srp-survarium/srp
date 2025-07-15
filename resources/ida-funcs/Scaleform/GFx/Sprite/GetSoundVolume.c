int __thiscall Scaleform::GFx::Sprite::GetSoundVolume(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite::ActiveSounds *pActiveSounds; // eax

  pActiveSounds = this->pActiveSounds;
  if ( pActiveSounds )
    return pActiveSounds->Volume;
  else
    return 100;
}
