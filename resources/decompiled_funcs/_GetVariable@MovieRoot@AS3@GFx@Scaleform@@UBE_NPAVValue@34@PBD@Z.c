char __thiscall Scaleform::GFx::AS3::MovieRoot::GetVariable(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pval,
        const char *ppathToVar)
{
  Scaleform::GFx::ASStringNode *v4; // esi
  const char *v6; // [esp-4h] [ebp-24h]
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+8h] [ebp-18h] BYREF
  unsigned int _CurrentState; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value resolvedVal; // [esp+10h] [ebp-10h] BYREF

  resolvedVal.Flags = 0;
  resolvedVal.Bonus.pWeakProxy = 0;
  _controlfp_s(&dpg.fpc, 0, 0);
  _controlfp_s(&_CurrentState, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  v4 = (Scaleform::GFx::ASStringNode *)pval;
  if ( (pval->Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(pval, pval->mValue.IValue);
    v4->pData = 0;
  }
  v6 = ppathToVar;
  v4->pManager = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &resolvedVal, v6) )
  {
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &resolvedVal, v4);
    _controlfp_s((unsigned int *)&pval, dpg.fpc, 0x30000u);
    Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
    return 1;
  }
  else
  {
    _controlfp_s((unsigned int *)&pval, dpg.fpc, 0x30000u);
    Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
    return 0;
  }
}
