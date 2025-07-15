void __thiscall Scaleform::GFx::AS3::Tracer::Output(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::FlashUI::OutputMessageType type,
        const char *msg)
{
  Scaleform::GFx::AS3::FlashUI *UI; // ecx

  UI = this->CF->pFile->VMRef->UI;
  UI->Output(UI, type, msg);
}
