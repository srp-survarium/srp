void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::soundTransformGet(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_media::SoundTransform> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->pTraits.pObject->pVM->UI;
  UI->Output(UI, Output_Warning, "The method Sprite::soundTransformGet() is not implemented\n");
}
