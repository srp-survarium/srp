void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayUnshift(Scaleform::GFx::AS2::ArrayObject *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *RootIndex; // ebx
  Scaleform::GFx::AS2::ArrayObject *p_pProto; // ebx
  int pTable; // eax
  int i; // edi
  Scaleform::GFx::AS2::Environment *pObject; // ecx
  int v7; // ebx
  unsigned int Size; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // ecx
  unsigned int v10; // eax
  const Scaleform::GFx::AS2::Value *v11; // edx
  Scaleform::GFx::AS2::Value *pRCC; // esi
  unsigned int v13; // ebx
  Scaleform::GFx::AS2::ArrayObject *pThis; // [esp+8h] [ebp+4h]

  if ( fn->RootIndex && (*(int (__thiscall **)(unsigned int))(*(_DWORD *)fn->RootIndex + 8))(fn->RootIndex) == 7 )
  {
    RootIndex = (Scaleform::GFx::AS2::ObjectInterface *)fn->RootIndex;
    if ( RootIndex )
      p_pProto = (Scaleform::GFx::AS2::ArrayObject *)&RootIndex[-2].pProto;
    else
      p_pProto = 0;
    p_pProto->LengthValueOverriden = 0;
    pTable = (int)fn->Members.mHash.pTable;
    pThis = p_pProto;
    if ( pTable > 0 )
    {
      Scaleform::GFx::AS2::ArrayObject::InsertEmpty(p_pProto, 0, pTable);
      for ( i = 0; i < (int)fn->Members.mHash.pTable; ++i )
      {
        pObject = (Scaleform::GFx::AS2::Environment *)fn->pProto.pObject;
        v7 = (char *)pObject->Stack.pCurrent - (char *)pObject->Stack.pPageStart;
        Size = pObject->Stack.Pages.Data.Size;
        p_Stack = &pObject->Stack;
        v10 = (unsigned int)fn->ResolveHandler.Function - i;
        v11 = 0;
        if ( v10 <= 32 * (Size - 1) + (v7 >> 4) )
          v11 = &p_Stack->Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
        p_pProto = pThis;
        Scaleform::GFx::AS2::ArrayObject::SetElement(pThis, i, v11);
      }
    }
    pRCC = (Scaleform::GFx::AS2::Value *)fn->pRCC;
    v13 = p_pProto->Elements.Data.Size;
    if ( pRCC->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pRCC);
    pRCC->NV.Int32Value = v13;
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
