void __thiscall Scaleform::GFx::DisplayObjectBase::OnEventUnload(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *pParent; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  bool (__thiscall *OnEvent)(Scaleform::GFx::DisplayObjectBase *, const Scaleform::GFx::EventId *); // edx
  _DWORD v5[3]; // [esp+8h] [ebp-14h] BYREF
  char v6; // [esp+14h] [ebp-8h]
  char v7; // [esp+18h] [ebp-4h]
  char v8; // [esp+19h] [ebp-3h]
  char v9; // [esp+1Ah] [ebp-2h]
  char v10; // [esp+1Bh] [ebp-1h]

  this->Flags |= 0x1000u;
  if ( (this->Flags & 2) != 0 )
  {
    pParent = this;
    while ( SLOBYTE(pParent->Flags) >= 0 )
    {
      pParent = pParent->pParent;
      if ( !pParent )
      {
        pMovieImpl = 0;
        goto LABEL_6;
      }
    }
    pMovieImpl = pParent->pASRoot->pMovieImpl;
LABEL_6:
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(pMovieImpl, (Scaleform::GFx::InteractiveObject *)this);
  }
  if ( (this->Flags & 0x10) == 0 )
  {
    OnEvent = this->OnEvent;
    v5[0] = 4;
    v5[1] = 0;
    v5[2] = 0;
    v6 = 0;
    v7 = 0;
    v9 = 0;
    v10 = 0;
    v8 = -1;
    OnEvent(this, (const Scaleform::GFx::EventId *)v5);
    this->Flags |= 0x10u;
  }
}
