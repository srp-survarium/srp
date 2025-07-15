void __thiscall Scaleform::GFx::AS3::MovieRoot::Output(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::FlashUI::OutputMessageType type,
        const char *msg)
{
  Scaleform::LogMessageId v3; // ebp
  unsigned int v4; // esi
  unsigned int v5; // edi
  Scaleform::Log *log; // [esp+10h] [ebp-7D4h]
  char buffStr[2000]; // [esp+14h] [ebp-7D0h] BYREF

  log = Scaleform::GFx::MovieImpl::GetCachedLog((Scaleform::GFx::MovieImpl *)this[-1].Sockets.Data.Size);
  if ( log )
  {
    switch ( type )
    {
      case Output_Error:
        v3.Id = (int)&loc_34000;
        break;
      case Output_Warning:
        v3.Id = 147456;
        break;
      case Output_Action:
        v3.Id = 24576;
        break;
      default:
        v3.Id = 4096;
        break;
    }
    v4 = strlen(msg);
    v5 = v4;
    if ( v4 >= 0x7D0 )
      v5 = 1999;
    strncpy_s(buffStr, 0x7D0u, msg, v5);
    buffStr[v5] = 0;
    if ( v4 >= 0x7D0 )
      Scaleform::GFx::LogState::LogMessageByType((Scaleform::GFx::LogState *)log, v3, "%s ...<truncated>", buffStr);
    else
      Scaleform::GFx::LogState::LogMessageByType((Scaleform::GFx::LogState *)log, v3, "%s", buffStr);
  }
}
