int __thiscall Scaleform::GFx::AS3::SoundObject::GetBytesLoaded(Scaleform::GFx::AS3::SoundObject *this)
{
  Scaleform::Sound::SoundSample *pObject; // ecx
  int result; // eax

  pObject = this->pSample.pObject;
  result = 0;
  if ( pObject )
    return pObject->GetBytesLoaded(pObject);
  return result;
}
