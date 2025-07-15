void __thiscall Scaleform::GFx::AS2::AvmButton::OnEventLoad(Scaleform::GFx::AS2::AvmButton *this)
{
  bool (__thiscall *OnEvent)(Scaleform::GFx::AvmDisplayObjBase *, const Scaleform::GFx::EventId *); // eax
  _DWORD v2[3]; // [esp+0h] [ebp-14h] BYREF
  char v3; // [esp+Ch] [ebp-8h]
  char v4; // [esp+10h] [ebp-4h]
  char v5; // [esp+11h] [ebp-3h]
  char v6; // [esp+12h] [ebp-2h]
  char v7; // [esp+13h] [ebp-1h]

  v2[1] = 0;
  v2[2] = 0;
  v3 = 0;
  v4 = 0;
  v6 = 0;
  v7 = 0;
  OnEvent = this->OnEvent;
  v2[0] = 1;
  v5 = -1;
  OnEvent(this, (const Scaleform::GFx::EventId *)v2);
}


void __thiscall Scaleform::GFx::AS2::AvmButton::OnEventLoad(char *this)
{
  Scaleform::GFx::AS2::AvmButton::OnEventLoad((Scaleform::GFx::AS2::AvmButton *)(this - 24));
}
