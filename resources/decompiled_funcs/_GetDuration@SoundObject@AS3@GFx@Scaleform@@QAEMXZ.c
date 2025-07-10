double __thiscall Scaleform::GFx::AS3::SoundObject::GetDuration(Scaleform::GFx::AS3::SoundObject *this)
{
  Scaleform::Sound::SoundSample *pObject; // ecx
  float duration; // [esp+0h] [ebp-4h]

  pObject = this->pSample.pObject;
  duration = 0.0;
  if ( pObject )
    return (float)(((double (__thiscall *)(Scaleform::Sound::SoundSample *))pObject->GetDuration)(pObject) * 1000.0);
  return duration;
}
