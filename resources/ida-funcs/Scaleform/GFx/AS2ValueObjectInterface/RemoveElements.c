char __thiscall Scaleform::GFx::AS2ValueObjectInterface::RemoveElements(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        int count)
{
  Scaleform::GFx::AMP::ViewStats *v4; // eax
  Scaleform::GFx::AS2::ArrayObject *v5; // ecx
  unsigned int Size; // eax
  Scaleform::AmpStats *v7; // esi
  Scaleform::AmpStats_vtbl *v8; // edi
  unsigned __int64 v9; // rax
  unsigned int v11; // edx
  unsigned int v12; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v14; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v16; // [esp+0h] [ebp-10h] BYREF

  v4 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v16,
    v4,
    "ObjectInterface::RemoveElements",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_RemoveElements);
  if ( pdata )
    v5 = (Scaleform::GFx::AS2::ArrayObject *)(pdata - 16);
  else
    v5 = 0;
  Size = v5->Elements.Data.Size;
  if ( idx < Size )
  {
    v11 = count;
    if ( count < 0 )
      v11 = Size - idx;
    v12 = Size - idx;
    if ( v12 >= v11 )
      v12 = v11;
    Scaleform::GFx::AS2::ArrayObject::RemoveElements(v5, idx, v12);
    Stats = v16.Stats;
    if ( v16.Stats )
    {
      v14 = v16.Stats->__vftable;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v14->NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v16.StartTicks),
        (ProfileTicks - v16.StartTicks) >> 32);
    }
    return 1;
  }
  else
  {
    v7 = v16.Stats;
    if ( v16.Stats )
    {
      v8 = v16.Stats->__vftable;
      v9 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v8->NativePopCallstack)(
        v7,
        v9 - LODWORD(v16.StartTicks),
        (v9 - v16.StartTicks) >> 32);
    }
    return 0;
  }
}
