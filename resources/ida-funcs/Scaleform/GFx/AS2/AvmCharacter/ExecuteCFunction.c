char __thiscall Scaleform::GFx::AS2::AvmCharacter::ExecuteCFunction(
        Scaleform::GFx::AS2::AvmCharacter *this,
        void (__cdecl *const function)(const Scaleform::GFx::AS2::FnCall *),
        const Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *params)
{
  Scaleform::GFx::AS2::AvmCharacter *v3; // esi
  Scaleform::GFx::AS2::Environment *(__thiscall *GetASEnvironment)(Scaleform::GFx::AS2::AvmCharacter *); // edx
  Scaleform::GFx::AS2::Environment *v5; // eax
  int Size; // edi
  int v7; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  int v9; // ebp
  Scaleform::GFx::AS2::Value *Data; // edi
  const Scaleform::GFx::AS2::Value *v11; // edi
  Scaleform::GFx::AS2::ObjectInterface *v12; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v13; // esi
  int v14; // edx
  Scaleform::GFx::AS2::Environment *v17; // [esp+8h] [ebp-3Ch]
  int v18; // [esp+Ch] [ebp-38h]
  Scaleform::GFx::AS2::Value v19; // [esp+10h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v20; // [esp+20h] [ebp-24h] BYREF

  v3 = this;
  if ( !function )
    return 0;
  GetASEnvironment = this->GetASEnvironment;
  v19.T.Type = 0;
  v5 = GetASEnvironment(this);
  Size = params->Data.Size;
  v17 = v5;
  v18 = Size;
  if ( Size > 0 )
  {
    v7 = Size - 1;
    if ( Size - 1 >= 0 )
    {
      p_Stack = &v5->Stack;
      v9 = v7;
      do
      {
        Data = params->Data.Data;
        ++p_Stack->pCurrent;
        v11 = &Data[v9];
        if ( p_Stack->pCurrent >= p_Stack->pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
        if ( p_Stack->pCurrent )
          Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, v11);
        --v7;
        --v9;
      }
      while ( v7 >= 0 );
      v3 = this;
      v5 = v17;
      Size = v18;
    }
  }
  v12 = &v3->Scaleform::GFx::AS2::ObjectInterface;
  v13 = &v5->Stack;
  v14 = v5->Stack.pCurrent - v5->Stack.pPageStart + 32 * v5->Stack.Pages.Data.Size - 32;
  v20.Env = v5;
  v20.Result = &v19;
  v20.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
  v20.ThisPtr = v12;
  memset(&v20.ThisFunctionRef, 0, 9);
  v20.NArgs = Size;
  v20.FirstArgBottomIndex = v14;
  function(&v20);
  Scaleform::GFx::AS2::FnCall::~FnCall(&v20);
  if ( Size > 0 )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(v13, Size);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  return 1;
}
