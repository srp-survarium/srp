void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayPush(Scaleform::GFx::AS2::ArrayObject *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *RootIndex; // ebx
  Scaleform::GFx::AS2::ArrayObject *p_pProto; // ebx
  int v4; // edi
  Scaleform::GFx::AS2::Environment *pObject; // ecx
  int v6; // ebx
  unsigned int Size; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // ecx
  unsigned int v9; // eax
  const Scaleform::GFx::AS2::Value *v10; // edx
  Scaleform::GFx::AS2::Value *pRCC; // esi
  int v12; // ebx
  Scaleform::GFx::AS2::ArrayObject *pThis; // [esp+8h] [ebp+4h]

  if ( fn->RootIndex && (*(int (__thiscall **)(unsigned int))(*(_DWORD *)fn->RootIndex + 8))(fn->RootIndex) == 7 )
  {
    RootIndex = (Scaleform::GFx::AS2::ObjectInterface *)fn->RootIndex;
    if ( RootIndex )
      p_pProto = (Scaleform::GFx::AS2::ArrayObject *)&RootIndex[-2].pProto;
    else
      p_pProto = 0;
    v4 = 0;
    p_pProto->LengthValueOverriden = 0;
    for ( pThis = p_pProto; v4 < (int)fn->Members.mHash.pTable; ++v4 )
    {
      pObject = (Scaleform::GFx::AS2::Environment *)fn->pProto.pObject;
      v6 = (char *)pObject->Stack.pCurrent - (char *)pObject->Stack.pPageStart;
      Size = pObject->Stack.Pages.Data.Size;
      p_Stack = &pObject->Stack;
      v9 = (unsigned int)fn->ResolveHandler.Function - v4;
      v10 = 0;
      if ( v9 <= 32 * (Size - 1) + (v6 >> 4) )
        v10 = &p_Stack->Pages.Data.Data[v9 >> 5]->Values[v9 & 0x1F];
      p_pProto = pThis;
      Scaleform::GFx::AS2::ArrayObject::PushBack(pThis, v10);
    }
    pRCC = (Scaleform::GFx::AS2::Value *)fn->pRCC;
    v12 = p_pProto->Elements.Data.Size;
    if ( pRCC->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pRCC);
    pRCC->NV.Int32Value = v12;
    pRCC->T.Type = 4;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      (Scaleform::GFx::AS2::Environment *)fn->pProto.pObject,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Array");
  }
}
