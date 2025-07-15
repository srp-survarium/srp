void (__thiscall *dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_media::SoundChannel_1_double_::Method__())(Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *this, long double *result)
{
  void (__thiscall *result)(Scaleform::GFx::AS3::Instances::fl_media::SoundChannel *, long double *); // eax

  result = Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::positionGet;
  LODWORD(Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_media::SoundChannel,1,double>::Method) = Scaleform::GFx::AS3::Instances::fl_media::SoundChannel::positionGet;
  dword_8F12F4 = 0;
  return result;
}
