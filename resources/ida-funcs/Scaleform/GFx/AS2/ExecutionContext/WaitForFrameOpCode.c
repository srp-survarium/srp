void __thiscall Scaleform::GFx::AS2::ExecutionContext::WaitForFrameOpCode(
        Scaleform::GFx::AS2::ExecutionContext *this,
        Scaleform::GFx::AS2::ActionBuffer *pActions,
        int actionId)
{
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  Scaleform::GFx::InteractiveObject *v5; // ebp
  const unsigned __int8 *pBuffer; // ecx
  int PC; // eax
  int v8; // edx
  const unsigned __int8 *v9; // eax
  unsigned int v10; // edi
  char v11; // bl
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // edi
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int BufferLen; // ebp
  unsigned int NextPC; // eax
  int v18; // ebx
  const unsigned __int8 *v19; // ecx
  char v20; // dl
  unsigned int v21; // [esp+10h] [ebp-4h] BYREF
  unsigned int v22; // [esp+1Ch] [ebp+8h]

  pEnv = this->pEnv;
  v21 = 0;
  if ( (*((_BYTE *)pEnv + 194) & 2) != 0 )
    v5 = 0;
  else
    v5 = (pEnv->Target->Flags & 0x400) != 0 ? pEnv->Target : 0;
  if ( actionId == 138 )
  {
    pBuffer = this->pBuffer;
    PC = this->PC;
    v8 = pBuffer[PC + 4];
    v9 = &pBuffer[PC];
    v21 = v9[3] | (v8 << 8);
    v10 = v9[5];
    v11 = 1;
  }
  else
  {
    v11 = Scaleform::GFx::AS2::ActionBuffer::ResolveFrameNumber(pActions, pEnv, pEnv->Stack.pCurrent, 0, &v21);
    pCurrent = this->pEnv->Stack.pCurrent;
    p_Stack = &this->pEnv->Stack;
    v22 = this->pBuffer[this->PC + 3];
    if ( pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
    if ( --p_Stack->pCurrent < p_Stack->pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
    v10 = v22;
  }
  if ( v5 && v11 )
  {
    v14 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v5[1].CreateFrame + 40))(v5[1].CreateFrame);
    if ( v14 && v21 >= v14 )
      v21 = v14 - 1;
    v15 = v5->GetLoadingFrame(v5);
    if ( v21 >= v15 )
    {
      BufferLen = pActions->pBufferData.pObject->BufferLen;
      NextPC = this->NextPC;
      v18 = 0;
      if ( v10 )
      {
        while ( NextPC < BufferLen )
        {
          v19 = this->pBuffer;
          v20 = v19[NextPC++];
          if ( v20 < 0 )
            NextPC += *(unsigned __int16 *)&v19[NextPC] + 2;
          if ( ++v18 >= v10 )
            goto LABEL_22;
        }
      }
      else
      {
LABEL_22:
        if ( NextPC < BufferLen )
        {
          this->NextPC = NextPC;
          return;
        }
      }
      if ( (*((_BYTE *)this + 54) & 1) != 0 )
        Scaleform::GFx::AS2::ActionLogger::LogScriptError(
          &this->LogF,
          "WaitForFrame branch to offset %d - this section only runs to %d",
          this->NextPC,
          this->StopPC);
    }
  }
}
