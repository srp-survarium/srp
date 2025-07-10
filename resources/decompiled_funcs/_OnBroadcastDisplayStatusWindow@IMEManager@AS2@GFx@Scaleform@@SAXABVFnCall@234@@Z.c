void __cdecl Scaleform::GFx::AS2::IMEManager::OnBroadcastDisplayStatusWindow(const Scaleform::GFx::AS2::FnCall *fn)
{
  if ( fn->Env )
    Scaleform::GFx::AS2::GASIme::BroadcastOnDisplayStatusWindow(fn->Env);
}
