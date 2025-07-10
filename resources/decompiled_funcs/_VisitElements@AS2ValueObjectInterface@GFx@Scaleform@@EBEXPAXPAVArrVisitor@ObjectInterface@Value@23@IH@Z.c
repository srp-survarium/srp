void __thiscall Scaleform::GFx::AS2ValueObjectInterface::VisitElements(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ArrayObject *pdata,
        Scaleform::GFx::Value::ObjectInterface::ArrVisitor *visitor,
        unsigned int idx,
        int count)
{
  Scaleform::GFx::AS2::MovieRoot *pObject; // edi
  int v6; // ecx
  unsigned int v7; // esi
  unsigned int Size; // eax
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  int v10; // edx
  unsigned int v11; // edx
  unsigned int v12; // ebp
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::AS2::Environment *penv; // [esp+Ch] [ebp-1Ch]
  Scaleform::GFx::Value val; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS2::ArrayObject *parr; // [esp+2Ch] [ebp+4h]

  if ( pdata )
    parr = (Scaleform::GFx::AS2::ArrayObject *)((char *)pdata - 16);
  else
    parr = 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v6 = (int)pObject->pMovieImpl->pMainMovie + 4 * pObject->pMovieImpl->pMainMovie->AvmObjOffset;
  v7 = idx;
  penv = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 124))(v6);
  Size = parr->Elements.Data.Size;
  pObjectInterface = 0;
  val.pObjectInterface = 0;
  val.Type = VT_Undefined;
  if ( idx < Size )
  {
    v10 = count;
    if ( count < 0 )
      v10 = Size - idx;
    v11 = idx + v10;
    v12 = Size;
    if ( Size >= v11 )
      v12 = v11;
    if ( idx < v12 )
    {
      do
      {
        v13 = parr->Elements.Data.Data[v7];
        if ( v13 )
        {
          Scaleform::GFx::AS2::MovieRoot::ASValue2Value(pObject, penv, v13, &val);
        }
        else
        {
          if ( (val.Type & 0x40) != 0 )
          {
            pObjectInterface->ObjectRelease(pObjectInterface, &val, val.mValue.pStringManaged);
            val.pObjectInterface = 0;
          }
          val.Type = VT_Undefined;
        }
        visitor->Visit(visitor, v7, &val);
        pObjectInterface = val.pObjectInterface;
        ++v7;
      }
      while ( v7 < v12 );
    }
    if ( (val.Type & 0x40) != 0 )
      pObjectInterface->ObjectRelease(pObjectInterface, &val, val.mValue.pStringManaged);
  }
}
