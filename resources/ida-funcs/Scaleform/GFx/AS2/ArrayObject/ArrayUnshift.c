void __cdecl Scaleform::GFx::AS2::ArrayObject::ArrayUnshift(Scaleform::GFx::AS2::ArrayObject *fn)
{
  unsigned int RootIndex; // ebx
  Scaleform::GFx::AS2::ArrayObject *v3; // ebx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // eax
  int i; // edi
  Scaleform::GFx::AS2::Object *pObject; // ecx
  int v7; // ebx
  Scaleform::GFx::AS2::Object *v8; // ebp
  $C9E2C53B7BF33D1B05D56CCE19B38030 *v9; // ecx
  unsigned int v10; // eax
  const Scaleform::GFx::AS2::Value *v11; // edx
  Scaleform::GFx::AS2::Value *pRCC; // esi
  unsigned int Size; // ebx
  Scaleform::GFx::AS2::ArrayObject *v14; // [esp+8h] [ebp+4h]

  if ( fn->RootIndex && (*(int (__thiscall **)(unsigned int))(*(_DWORD *)fn->RootIndex + 8))(fn->RootIndex) == 7 )
  {
    RootIndex = fn->RootIndex;
    if ( RootIndex )
      v3 = (Scaleform::GFx::AS2::ArrayObject *)(RootIndex - 16);
    else
      v3 = 0;
    v3->LengthValueOverriden = 0;
    pTable = fn->Members.mHash.pTable;
    v14 = v3;
    if ( (int)pTable > 0 )
    {
      Scaleform::GFx::AS2::ArrayObject::InsertEmpty(v3, 0, (int)pTable);
      for ( i = 0; i < (int)fn->Members.mHash.pTable; ++i )
      {
        pObject = fn->pProto.pObject;
        v7 = (int)pObject->pRCC - pObject->RootIndex;
        v8 = pObject->pProto.pObject;
        v9 = &pObject->4;
        v10 = (unsigned int)fn->ResolveHandler.Function - i;
        v11 = 0;
        if ( v10 <= 32 * (int)(&v8[-1].IsListenerSet + 2) + (v7 >> 4) )
          v11 = (const Scaleform::GFx::AS2::Value *)&(&v9[4].pRCC->__vftable)[v10 >> 5][4 * (v10 & 0x1F)];
        v3 = v14;
        Scaleform::GFx::AS2::ArrayObject::SetElement(v14, i, v11);
      }
    }
    pRCC = (Scaleform::GFx::AS2::Value *)fn->pRCC;
    Size = v3->Elements.Data.Size;
    if ( pRCC->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pRCC);
    pRCC->NV.Int32Value = Size;
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
