void __thiscall Scaleform::GFx::AS3ValueObjectInterface::VisitElements(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value::ObjectInterface::ArrVisitor *visitor,
        unsigned int idx,
        int count)
{
  Scaleform::GFx::AMP::ViewStats *v6; // eax
  Scaleform::GFx::ASMovieRootBase *pObject; // ecx
  unsigned int v8; // eax
  unsigned int v9; // esi
  Scaleform::AmpStats *Stats; // edi
  int v11; // edx
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ebx
  Scaleform::GFx::AS3::Value *v15; // eax
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::AS3::MovieRoot *root; // [esp+Ch] [ebp-2Ch]
  Scaleform::AmpFunctionTimer _amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitElements; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::Value val; // [esp+20h] [ebp-18h] BYREF

  v6 = this->GetAdvanceStats(this);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &_amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitElements,
    v6,
    "ObjectInterface::VisitElements",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_ObjectInterface_VisitElements);
  pObject = this->pMovieRoot->pASMovieRoot.pObject;
  v8 = *((_DWORD *)pdata + 8);
  v9 = idx;
  root = (Scaleform::GFx::AS3::MovieRoot *)pObject;
  if ( idx >= v8 )
  {
    Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitElements.Stats;
    if ( !_amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitElements.Stats )
      return;
    goto LABEL_14;
  }
  v11 = count;
  if ( count < 0 )
    v11 = v8 - idx;
  pObjectInterface = 0;
  v13 = idx + v11;
  val.pObjectInterface = 0;
  val.Type = VT_Undefined;
  v14 = v8;
  if ( v8 >= v13 )
    v14 = v13;
  if ( idx < v14 )
  {
    do
    {
      v15 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                            (Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32),
                                            v9);
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(root, v15, (Scaleform::GFx::ASStringNode *)&val);
      visitor->Visit(visitor, v9++, &val);
    }
    while ( v9 < v14 );
    pObjectInterface = val.pObjectInterface;
  }
  if ( (val.Type & 0x40) != 0 )
  {
    pObjectInterface->ObjectRelease(pObjectInterface, &val, val.mValue.pStringManaged);
    val.pObjectInterface = 0;
  }
  Stats = _amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitElements.Stats;
  val.Type = VT_Undefined;
  if ( _amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitElements.Stats )
  {
LABEL_14:
    p_NativePopCallstack = &_amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitElements.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(_amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitElements.StartTicks),
      (ProfileTicks - _amp_timer_Amp_Native_Function_Id_ObjectInterface_VisitElements.StartTicks) >> 32);
  }
}
