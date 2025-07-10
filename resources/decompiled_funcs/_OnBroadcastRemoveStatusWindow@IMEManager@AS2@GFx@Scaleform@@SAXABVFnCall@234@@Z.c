void __cdecl Scaleform::GFx::AS2::IMEManager::OnBroadcastRemoveStatusWindow(const Scaleform::GFx::AS2::FnCall *fn)
{
  if ( fn->Env )
    Scaleform::GFx::AS2::GASIme::BroadcastOnRemoveStatusWindow(fn->Env);
}
