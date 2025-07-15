void __thiscall Scaleform::GFx::MovieImpl::HideFocusRect(Scaleform::GFx::MovieImpl *this, unsigned int controllerIdx)
{
  unsigned int v2; // ebx
  int v4; // eax
  char *v5; // ebp
  Scaleform::RefCountNTSImpl *v6; // esi

  v2 = controllerIdx;
  v4 = this->FocusGroupIndexes[controllerIdx] << 6;
  v5 = (char *)this->FocusGroups + v4;
  if ( *(&this->FocusGroups[0].FocusRectShown + v4) )
  {
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)((char *)&this->FocusGroups[0].LastFocused + v4),
      (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&controllerIdx);
    v6 = (Scaleform::RefCountNTSImpl *)controllerIdx;
    if ( controllerIdx )
    {
      ++*(_DWORD *)(controllerIdx + 4);
      Scaleform::RefCountNTSImpl::Release(v6);
      if ( v6[4].__vftable
        && !((unsigned __int8 (__thiscall *)(Scaleform::RefCountNTSImpl *, _DWORD, unsigned int, int))v6->__vftable[90].~Scaleform::RefCountNTSImpl)(
              v6,
              0,
              v2,
              2) )
      {
        Scaleform::RefCountNTSImpl::Release(v6);
        return;
      }
      Scaleform::RefCountNTSImpl::Release(v6);
    }
  }
  v5[48] = 0;
  this->FocusRectChanged = 1;
}
