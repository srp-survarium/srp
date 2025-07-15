void __thiscall Scaleform::GFx::AS3::IMEManager::BroadcastDisplayStatusWindow(
        Scaleform::GFx::AS3::IMEManager *this,
        char *pString)
{
  Scaleform::GFx::AS3::IMEManager::DispatchEvent(this, pString, "DisplayStatusWindow", "StatusWindow");
}
