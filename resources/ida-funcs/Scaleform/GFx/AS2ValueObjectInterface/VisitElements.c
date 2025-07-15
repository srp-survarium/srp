void __thiscall Scaleform::GFx::AS2ValueObjectInterface::VisitElements(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value::ObjectInterface::ArrVisitor *visitor,
        unsigned int idx,
        int count)
{
  Scaleform::GFx::AMP::ViewStats *v6; // eax
  Scaleform::GFx::AS2::MovieRoot *pObject; // edi
  int v8; // ecx
  unsigned int v9; // esi
  unsigned int v10; // eax
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  Scaleform::AmpStats *Stats; // edi
  int v13; // edx
  unsigned int v14; // edx
  unsigned int v15; // ebp
  Scaleform::GFx::AS2::Value *v16; // eax
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS2::Environment *penv; // [esp+14h] [ebp-2Ch]
  Scaleform::AmpFunctionTimer v20; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::Value pdestVal; // [esp+28h] [ebp-18h] BYREF
  char *v22; // [esp+44h] [ebp+4h]

  v6 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v20,
    v6,
    "ObjectInterface::VisitElements",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_VisitElements);
  if ( pdata )
    v22 = pdata - 16;
  else
    v22 = 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v8 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v9 = idx;
  penv = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 124))(v8);
  v10 = *((_DWORD *)v22 + 15);
  pObjectInterface = 0;
  pdestVal.pObjectInterface = 0;
  pdestVal.Type = VT_Undefined;
  if ( idx >= v10 )
  {
    Stats = v20.Stats;
    pdestVal.Type = VT_Undefined;
    if ( !v20.Stats )
      return;
    goto LABEL_21;
  }
  v13 = count;
  if ( count < 0 )
    v13 = v10 - idx;
  v14 = idx + v13;
  v15 = v10;
  if ( v10 >= v14 )
    v15 = v14;
  if ( idx < v15 )
  {
    do
    {
      v16 = *(Scaleform::GFx::AS2::Value **)(*((_DWORD *)v22 + 14) + 4 * v9);
      if ( v16 )
      {
        Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, penv, v16, &pdestVal);
      }
      else
      {
        if ( (pdestVal.Type & 0x40) != 0 )
        {
          pObjectInterface->ObjectRelease(pObjectInterface, &pdestVal, pdestVal.mValue.pStringManaged);
          pdestVal.pObjectInterface = 0;
        }
        pdestVal.Type = VT_Undefined;
      }
      visitor->Visit(visitor, v9, &pdestVal);
      pObjectInterface = pdestVal.pObjectInterface;
      ++v9;
    }
    while ( v9 < v15 );
  }
  if ( (pdestVal.Type & 0x40) != 0 )
  {
    pObjectInterface->ObjectRelease(pObjectInterface, &pdestVal, pdestVal.mValue.pStringManaged);
    pdestVal.pObjectInterface = 0;
  }
  Stats = v20.Stats;
  pdestVal.Type = VT_Undefined;
  if ( v20.Stats )
  {
LABEL_21:
    p_NativePopCallstack = &v20.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v20.StartTicks),
      (ProfileTicks - v20.StartTicks) >> 32);
  }
}
