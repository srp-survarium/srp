void __thiscall Scaleform::GFx::AS3::Instances::fl_media::Sound::isBufferingGet(
        Scaleform::GFx::AS3::Instances::fl_media::Sound *this,
        bool *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Sound::isBufferingGet() is not implemented\n");
}
