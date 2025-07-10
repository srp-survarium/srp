void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_media::Sound_3_bool_::Method__())(Scaleform::GFx::AS3::Instances::fl_media::Sound *this, bool *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_media::Sound *, bool *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_media::Sound::isBufferingGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::Sound,3,bool>::Method) = Scaleform::GFx::AS3::Instances::fl_media::Sound::isBufferingGet;
  dword_AACB64 = 0;
  return result;
}
