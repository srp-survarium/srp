void __thiscall Scaleform::GFx::AS2::AvmCharacter::OnFocus(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::Value *event,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType __formal)
{
  Scaleform::GFx::AS2::Environment *(__thiscall *GetASEnvironment)(Scaleform::GFx::AS2::AvmCharacter *); // edx
  int v7; // eax
  Scaleform::GFx::AS2::Environment *v8; // edi
  unsigned int v9; // ebx
  int v10; // esi
  Scaleform::GFx::AS2::FunctionObject *Function; // ebp
  Scaleform::GFx::AS2::Value *pCurrent; // esi
  long double v13; // st7
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *v15; // eax
  Scaleform::GFx::AS2::Value *v16; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edi
  const Scaleform::GFx::AS2::FnCall *v18; // eax
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  unsigned int v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // [esp-10h] [ebp-88h]
  int v24; // [esp-4h] [ebp-7Ch]
  Scaleform::GFx::ASStringNode *v25[2]; // [esp+Ch] [ebp-6Ch] BYREF
  Scaleform::GFx::AS2::AvmCharacter *v26; // [esp+14h] [ebp-64h]
  Scaleform::GFx::AS2::Value v27; // [esp+18h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::FunctionRef result; // [esp+28h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value v29; // [esp+34h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value ResIn; // [esp+44h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v31; // [esp+54h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value *v; // [esp+7Ch] [ebp+4h]

  GetASEnvironment = this->GetASEnvironment;
  v26 = this;
  v29.T.Type = 0;
  v7 = ((int (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))GetASEnvironment)(this);
  v8 = (Scaleform::GFx::AS2::Environment *)v7;
  if ( v7 )
  {
    v9 = 1;
    v10 = v7 + 116;
    v25[1] = *(Scaleform::GFx::ASStringNode **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v7 + 116) + 20) + 12)
                                              + 4 * ((event != (Scaleform::GFx::AS2::Value *)1) + 88)
                                              + 164);
    ++v25[1]->RefCount;
    if ( this->GetMemberRaw(
           &this->Scaleform::GFx::AS2::ObjectInterface,
           (Scaleform::GFx::AS2::ASStringContext *)(v7 + 116),
           (const Scaleform::GFx::ASString *)&v25[1],
           &v29) )
    {
      Scaleform::GFx::AS2::Value::ToFunction(&v29, &result, 0);
      Function = result.Function;
      if ( result.Function )
      {
        if ( *(_BYTE *)(*(_DWORD *)v10 + 52) == 1 )
        {
          ++v8->Stack.pCurrent;
          *(double *)&v27.T.Type = (double)controllerIdx;
          if ( v8->Stack.pCurrent >= v8->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v8->Stack);
          pCurrent = v8->Stack.pCurrent;
          if ( pCurrent )
          {
            v13 = *(double *)&v27.T.Type;
            pCurrent->T.Type = 3;
            pCurrent->NV.NumberValue = v13;
          }
          v9 = 2;
        }
        if ( oldOrNewFocusCh )
        {
          Scaleform::GFx::AS2::Value::Value(&v27, oldOrNewFocusCh);
          ++v8->Stack.pCurrent;
          p_Stack = &v8->Stack;
          v = v15;
          if ( v8->Stack.pCurrent >= v8->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v8->Stack);
          if ( p_Stack->pCurrent )
            Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, v);
          if ( v27.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v27);
        }
        else
        {
          ++v8->Stack.pCurrent;
          p_Stack = &v8->Stack;
          if ( v8->Stack.pCurrent >= v8->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v8->Stack);
          if ( p_Stack->pCurrent )
            p_Stack->pCurrent->T.Type = 1;
        }
        v24 = p_Stack->pCurrent - p_Stack->pPageStart + 32 * p_Stack->Pages.Data.Size - 32;
        pDispObj = v26->pDispObj;
        ResIn.T.Type = 0;
        Scaleform::GFx::AS2::Value::Value(&v27, pDispObj);
        Scaleform::GFx::AS2::FnCall::FnCall(&v31, &ResIn, v16, v8, v9, v24);
        pLocalFrame = result.pLocalFrame;
        Function->Invoke(Function, v18, result.pLocalFrame, 0);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v31);
        if ( v27.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v27);
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(p_Stack, v9);
        if ( ResIn.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&ResIn);
      }
      else
      {
        pLocalFrame = result.pLocalFrame;
      }
      Flags = result.Flags;
      if ( (result.Flags & 2) == 0 )
      {
        if ( Function )
        {
          RefCount = Function->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      if ( (Flags & 1) == 0 )
      {
        if ( pLocalFrame )
        {
          v21 = pLocalFrame->RefCount;
          if ( (v21 & 0x3FFFFFF) != 0 )
          {
            pLocalFrame->RefCount = v21 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
    }
    v22 = v25[1];
    --v25[1]->RefCount;
    if ( !v22->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  }
  if ( v29.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v29);
}
