char __thiscall Scaleform::GFx::AS2ValueObjectInterface::Invoke(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        Scaleform::GFx::Value *presult,
        char *name,
        const Scaleform::GFx::Value *pargs,
        unsigned int nargs,
        bool isdobj)
{
  Scaleform::GFx::AMP::ViewStats *v8; // eax
  Scaleform::GFx::AS2::ObjectInterface *pObject; // edi
  Scaleform::AmpStats *v10; // edi
  void (__thiscall **v11)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v12; // rax
  Scaleform::GFx::AS2::Environment *pEnv; // ebp
  Scaleform::AmpStats *v15; // edi
  void (__thiscall **v16)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v17; // rax
  Scaleform::GFx::AS2::Value **p_pCurrent; // esi
  const Scaleform::GFx::Value *v19; // edi
  unsigned int v20; // ebx
  char v21; // bl
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::Value_AS2ObjectData v25; // [esp+8h] [ebp-4Ch] BYREF
  Scaleform::AmpFunctionTimer v26; // [esp+14h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value value; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v28; // [esp+34h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value pdestVal; // [esp+44h] [ebp-10h] BYREF

  v8 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v26,
    v8,
    "ObjectInterface::Invoke",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_Invoke);
  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&v25, this, pdata, isdobj);
  pObject = v25.pObject;
  if ( v25.pObject )
  {
    pEnv = v25.pEnv;
    v28.T.Type = 0;
    value.T.Type = 0;
    if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(
           v25.pObject,
           (Scaleform::GFx::ASStringNode *)&v25.pEnv->StringContext,
           name,
           &v28) )
    {
      pdestVal.T.Type = 0;
      if ( (int)(nargs - 1) > -1 )
      {
        p_pCurrent = &pEnv->Stack.pCurrent;
        v19 = &pargs[nargs - 1];
        v20 = nargs;
        do
        {
          Scaleform::GFx::AS2::MovieRoot::Value2ASValue(v25.pRoot, v19, &pdestVal);
          ++*p_pCurrent;
          if ( pEnv->Stack.pCurrent >= pEnv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&pEnv->Stack);
          if ( *p_pCurrent )
            Scaleform::GFx::AS2::Value::Value(*p_pCurrent, &pdestVal);
          --v19;
          --v20;
        }
        while ( v20 );
        pObject = v25.pObject;
      }
      v21 = Scaleform::GFx::AS2::GAS_Invoke(
              &v28,
              &value,
              pObject,
              pEnv,
              nargs,
              pEnv->Stack.pCurrent - pEnv->Stack.pPageStart + 32 * pEnv->Stack.Pages.Data.Size - 32,
              0);
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&pEnv->Stack, nargs);
      if ( presult )
        Scaleform::GFx::AS2::MovieRoot::ASValue2Value(v25.pRoot, pEnv, &value, presult);
      if ( pdestVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pdestVal);
      if ( value.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&value);
      if ( v28.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v28);
      Stats = v26.Stats;
      if ( v26.Stats )
      {
        p_NativePopCallstack = &v26.Stats->NativePopCallstack;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(v26.StartTicks),
          (ProfileTicks - v26.StartTicks) >> 32);
      }
      return v21;
    }
    else
    {
      if ( value.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&value);
      if ( v28.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v28);
      v15 = v26.Stats;
      if ( v26.Stats )
      {
        v16 = &v26.Stats->NativePopCallstack;
        v17 = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v16)(
          v15,
          v17 - LODWORD(v26.StartTicks),
          (v17 - v26.StartTicks) >> 32);
      }
      return 0;
    }
  }
  else
  {
    v10 = v26.Stats;
    if ( v26.Stats )
    {
      v11 = &v26.Stats->NativePopCallstack;
      v12 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v11)(
        v10,
        v12 - LODWORD(v26.StartTicks),
        (v12 - v26.StartTicks) >> 32);
    }
    return 0;
  }
}
