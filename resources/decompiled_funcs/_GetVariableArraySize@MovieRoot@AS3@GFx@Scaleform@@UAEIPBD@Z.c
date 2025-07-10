int __thiscall Scaleform::GFx::AS3::MovieRoot::GetVariableArraySize(
        Scaleform::GFx::AS3::MovieRoot *this,
        const char *ppathToVar)
{
  int v3; // eax
  int v4; // esi
  void *pWeakProxy; // eax
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+4h] [ebp-18h] BYREF
  unsigned int _CurrentState; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value resolvedVal; // [esp+Ch] [ebp-10h] BYREF

  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  resolvedVal.Flags = 0;
  resolvedVal.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &resolvedVal, ppathToVar)
    && resolvedVal.value.VS._1.VInt
    && (v3 = *(_DWORD *)(resolvedVal.value.VS._1.VInt + 20), *(_DWORD *)(v3 + 60) == 7)
    && (*(_DWORD *)(v3 + 56) & 0x20) == 0 )
  {
    v4 = *(_DWORD *)(resolvedVal.value.VS._1.VInt + 32);
    Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
    _controlfp_s((unsigned int *)&ppathToVar, dpg.fpc, 0x30000u);
    return v4;
  }
  else
  {
    if ( (resolvedVal.Flags & 0x1F) > 9 )
    {
      if ( (resolvedVal.Flags & 0x200) != 0 )
      {
        pWeakProxy = resolvedVal.Bonus.pWeakProxy;
        if ( resolvedVal.Bonus.pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&resolvedVal);
      }
    }
    _controlfp_s((unsigned int *)&ppathToVar, dpg.fpc, 0x30000u);
    return 0;
  }
}
