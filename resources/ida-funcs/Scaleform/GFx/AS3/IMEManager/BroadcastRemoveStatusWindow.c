void __thiscall Scaleform::GFx::AS3::IMEManager::BroadcastRemoveStatusWindow(
        Scaleform::GFx::AS3::IMEManager *this,
        char *pString)
{
  Scaleform::GFx::AS3::IMEManager::DispatchEvent(this, pString, "RemoveStatusWindow", "StatusWindow");
}
