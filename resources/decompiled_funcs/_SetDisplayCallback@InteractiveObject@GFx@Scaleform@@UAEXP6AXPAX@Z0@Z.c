void __thiscall Scaleform::GFx::InteractiveObject::SetDisplayCallback(
        Scaleform::GFx::InteractiveObject *this,
        void (__cdecl *callback)(void *),
        void *userPtr)
{
  this->pDisplayCallback = callback;
  this->DisplayCallbackUserPtr = userPtr;
}
