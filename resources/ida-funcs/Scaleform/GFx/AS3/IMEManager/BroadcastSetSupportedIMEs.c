void __thiscall Scaleform::GFx::AS3::IMEManager::BroadcastSetSupportedIMEs(
        Scaleform::GFx::AS3::IMEManager *this,
        char *pString)
{
  Scaleform::GFx::AS3::IMEManager::DispatchEvent(this, pString, "SetSupportedIMENames", "LangBar");
}
