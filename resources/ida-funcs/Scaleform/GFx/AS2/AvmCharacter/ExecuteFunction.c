char __userpurge Scaleform::GFx::AS2::AvmCharacter::ExecuteFunction@<al>(
        Scaleform::GFx::AS2::AvmCharacter *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const Scaleform::GFx::AS2::FunctionRef *function,
        const Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *params,
        const Scaleform::GFx::AS2::FunctionRef *a6,
        int *a7)
{
  const Scaleform::GFx::AS2::FunctionRef *v7; // ebp
  Scaleform::GFx::AS2::AvmCharacter *v8; // esi
  Scaleform::GFx::AS2::Environment *(__thiscall *GetASEnvironment)(Scaleform::GFx::AS2::AvmCharacter *); // edx
  int v10; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // edi
  int v12; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v13; // esi
  int v14; // ebp
  int v15; // edi
  const Scaleform::GFx::AS2::Value *v16; // edi
  Scaleform::GFx::AS2::LocalFrame *v17; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v18; // esi
  Scaleform::GFx::AS2::FunctionObject *v19; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v21; // [esp+10h] [ebp-38h]
  Scaleform::GFx::AS2::Value v22; // [esp+14h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v23; // [esp+24h] [ebp-24h] BYREF
  Scaleform::GFx::ASStringNode *retaddr; // [esp+48h] [ebp+0h]

  v7 = function;
  v8 = this;
  if ( !function->Function )
    return 0;
  GetASEnvironment = this->GetASEnvironment;
  v22.T.Type = 0;
  v10 = ((int (__thiscall *)(Scaleform::GFx::AS2::AvmCharacter *, int, int))GetASEnvironment)(this, a3, a2);
  pStringNode = (Scaleform::GFx::ASStringNode *)a7[1];
  *(_QWORD *)&v22.T.Type = __PAIR64__((unsigned int)pStringNode, v10);
  if ( (int)pStringNode > 0 )
  {
    v12 = (int)&pStringNode[-1].Size + 3;
    if ( (int)&pStringNode[-1].Size + 3 >= 0 )
    {
      v13 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v10 + 4);
      v14 = 16 * v12;
      do
      {
        v15 = *a7;
        ++v13->pCurrent;
        v16 = (const Scaleform::GFx::AS2::Value *)(v14 + v15);
        if ( v13->pCurrent >= v13->pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v13);
        if ( v13->pCurrent )
          Scaleform::GFx::AS2::Value::Value(v13->pCurrent, v16);
        --v12;
        v14 -= 16;
      }
      while ( v12 >= 0 );
      v8 = v21;
      v7 = a6;
      pStringNode = v22.V.pStringNode;
      v10 = *(_DWORD *)&v22.T.Type;
    }
  }
  v17 = (Scaleform::GFx::AS2::LocalFrame *)&v8->Scaleform::GFx::AS2::ObjectInterface;
  v18 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v10 + 4);
  v23.ThisFunctionRef.Function = (Scaleform::GFx::AS2::FunctionObject *)((char *)&v22.NV.NumberValue + 4);
  v23.ThisFunctionRef.pLocalFrame = v17;
  v19 = v7->Function;
  v23.FirstArgBottomIndex = v10;
  v23.ThisPtr = (Scaleform::GFx::AS2::ObjectInterface *)&Scaleform::GFx::AS2::FnCall::`vftable';
  memset(&v23.ThisFunctionRef.Flags, 0, 9);
  retaddr = pStringNode;
  ((void (__thiscall *)(Scaleform::GFx::AS2::FunctionObject *, Scaleform::GFx::AS2::ObjectInterface **))v19->Invoke)(
    v19,
    &v23.ThisPtr);
  Scaleform::GFx::AS2::FnCall::~FnCall(&v23);
  if ( (int)pStringNode > 0 )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(v18, (unsigned int)pStringNode);
  if ( v22.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
  return 1;
}
