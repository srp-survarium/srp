void __thiscall Scaleform::GFx::AS3::IMEManager::BroadcastSetSupportedIMEs(
        Scaleform::GFx::AS3::IMEManager *this,
        Scaleform::GFx::ASStringNode *pString)
{
  Scaleform::GFx::AS3::IMEManager::DispatchEvent(this, pString, (__m128i *)"SetSupportedIMENames", "LangBar");
}
