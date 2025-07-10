void __thiscall Scaleform::GFx::AS3::IMEManager::BroadcastSetConversionStatus(
        Scaleform::GFx::AS3::IMEManager *this,
        char *pString)
{
  Scaleform::GFx::AS3::IMEManager::DispatchEvent(this, pString, "SetConversionStatus", "StatusWindow");
}
