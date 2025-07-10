void *__thiscall Scaleform::GFx::AS3::SoundObject::GetOwner(Scaleform::GFx::AS3::SoundObject *this)
{
  int Volume; // eax

  Volume = this->Volume;
  if ( Volume )
    return *(void **)(Volume + 52);
  else
    return 0;
}
