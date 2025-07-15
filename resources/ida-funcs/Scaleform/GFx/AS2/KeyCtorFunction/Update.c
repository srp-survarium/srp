void __thiscall Scaleform::GFx::AS2::KeyCtorFunction::Update(
        Scaleform::GFx::AS2::KeyCtorFunction *this,
        const Scaleform::GFx::EventId *evt)
{
  char AsciiCode; // al

  *((_DWORD *)&this->pRCC + 3 * evt->ControllerIndex) = evt->KeyCode;
  AsciiCode = evt->AsciiCode;
  if ( !AsciiCode )
    AsciiCode = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(evt);
  *((_BYTE *)&this->RootIndex + 12 * evt->ControllerIndex) = AsciiCode;
  *(&this->RefCount + 3 * evt->ControllerIndex) = evt->WcharCode;
}
