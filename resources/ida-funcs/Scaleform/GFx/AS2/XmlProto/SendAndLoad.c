void __cdecl Scaleform::GFx::AS2::XmlProto::SendAndLoad(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::LogState *Log; // eax

  if ( Scaleform::GFx::AS2::FnCall::CheckThisPtr(fn, 0x1Cu) )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr && ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
    {
      Log = (Scaleform::GFx::LogState *)Scaleform::GFx::AS2::FnCall::GetLog(fn);
      if ( Log )
        Scaleform::GFx::LogState::LogMessageByType(
          Log,
          (Scaleform::LogMessageId)212992,
          "XML.sendAndLoad is not implemented.");
    }
  }
  else
  {
    Scaleform::GFx::AS2::FnCall::ThisPtrError(fn, "XML", 0, 0);
  }
}
