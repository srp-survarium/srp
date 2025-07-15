char __userpurge Scaleform::GFx::AS3::MovieRoot::GetVariable@<al>(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::Value *pval,
        const char *ppathToVar)
{
  Scaleform::GFx::ASStringNode *v5; // esi
  const char *v7; // [esp-4h] [ebp-24h]
  Scaleform::GFx::DoublePrecisionGuard dpg; // [esp+8h] [ebp-18h] BYREF
  unsigned int _CurrentState; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value resolvedVal; // [esp+10h] [ebp-10h] BYREF

  resolvedVal.Flags = 0;
  resolvedVal.Bonus.pWeakProxy = 0;
  _controlfp_s(a2, &dpg.fpc, 0, 0);
  _controlfp_s(a2, &_CurrentState, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  v5 = (Scaleform::GFx::ASStringNode *)pval;
  if ( (pval->Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(pval, pval->mValue.IValue);
    v5->pData = 0;
  }
  v7 = ppathToVar;
  v5->pManager = 0;
  if ( Scaleform::GFx::AS3::MovieRoot::GetASVariableAtPath(this, &resolvedVal, v7) )
  {
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &resolvedVal, v5);
    _controlfp_s(a2, (unsigned int *)&pval, dpg.fpc, (unsigned int)&loc_30000);
    Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
    return 1;
  }
  else
  {
    _controlfp_s(a2, (unsigned int *)&pval, dpg.fpc, (unsigned int)&loc_30000);
    Scaleform::GFx::AS3::Value::~Value(&resolvedVal);
    return 0;
  }
}
