int __userpurge Scaleform::GFx::AS3::MovieRoot::GetVariableArraySize@<eax>(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        int a2@<ebx>,
        const char *ppathToVar)
{
  int v4; // eax
  int v5; // esi
  void *pWeakProxy; // eax
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+4h] [ebp-18h] BYREF
  unsigned int _CurrentState; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value resolvedVal; // [esp+Ch] [ebp-10h] BYREF

  _controlfp_s(a2, &dpg.fpc, 0, 0);
  _controlfp_s(a2, &_CurrentState, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  resolvedVal.Flags = 0;
  resolvedVal.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &resolvedVal, ppathToVar)
    && resolvedVal.value.VS._1.VInt
    && (v4 = *(_DWORD *)(resolvedVal.value.VS._1.VInt + 20), *(_DWORD *)(v4 + 60) == 7)
    && (*(_DWORD *)(v4 + 56) & 0x20) == 0 )
  {
    v5 = *(_DWORD *)(resolvedVal.value.VS._1.VInt + 32);
    Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
    _controlfp_s(a2, (unsigned int *)&ppathToVar, dpg.fpc, (unsigned int)&loc_30000);
    return v5;
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
    _controlfp_s(a2, (unsigned int *)&ppathToVar, dpg.fpc, (unsigned int)&loc_30000);
    return 0;
  }
}
