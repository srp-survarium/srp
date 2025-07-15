void __thiscall Scaleform::GFx::InteractiveObject::DoDisplayCallback(Scaleform::GFx::InteractiveObject *this)
{
  void (__cdecl *pDisplayCallback)(void *); // eax

  pDisplayCallback = this->pDisplayCallback;
  if ( pDisplayCallback )
    pDisplayCallback(this->DisplayCallbackUserPtr);
}
