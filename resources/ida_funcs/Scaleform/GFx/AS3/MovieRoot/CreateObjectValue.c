char __thiscall Scaleform::GFx::AS3::MovieRoot::CreateObjectValue(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pval,
        Scaleform::GFx::Value::ObjectInterface *pobjifc,
        _DWORD *pdata,
        bool isdobj)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edi

  v5 = pdata[5];
  v6 = *(_DWORD *)(v5 + 60);
  v7 = 8;
  if ( (unsigned int)(v6 - 17) >= 0xC || (*(_DWORD *)(v5 + 56) & 0x20) != 0 )
  {
    if ( v6 == 7 )
      v7 = 9;
  }
  else
  {
    v7 = 10;
  }
  if ( (pval->Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))pval->pObjectInterface->ObjectRelease)(pval, pval->mValue.IValue);
    pval->pObjectInterface = 0;
  }
  pval->Type = v7 | 0x40;
  pval->mValue.IValue = (int)pdata;
  pval->pObjectInterface = pobjifc;
  pobjifc->ObjectAddRef(pobjifc, pval, pdata);
  return 1;
}
