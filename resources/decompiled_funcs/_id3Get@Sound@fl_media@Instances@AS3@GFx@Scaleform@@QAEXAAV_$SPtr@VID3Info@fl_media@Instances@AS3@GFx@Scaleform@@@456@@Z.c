void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::id3Get(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_media::ID3Info> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Sound::id3Get() is not implemented\n");
}
