void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_media::Sound_0_unsigned_long_::Method__())(Scaleform::GFx::AS3::Instances::fl_media::Sound *this, unsigned int *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_media::Sound *, unsigned int *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_media::Sound::bytesLoadedGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,0,unsigned long>::Method) = Scaleform::GFx::AS3::Instances::fl_media::Sound::bytesLoadedGet;
  dword_AACB4C = 0;
  return result;
}
