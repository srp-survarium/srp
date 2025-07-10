void __thiscall Scaleform::GFx::AS3ValueObjectInterface::VisitElements(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value::ObjectInterface::ArrVisitor *visitor,
        unsigned int idx,
        int count)
{
  unsigned int v5; // eax
  unsigned int v6; // esi
  int v7; // edx
  Scaleform::GFx::Value::ObjectInterface *pObjectInterface; // ecx
  unsigned int v9; // ebx
  Scaleform::GFx::AS3::Value *v10; // eax
  Scaleform::GFx::AS3::MovieRoot *root; // [esp+4h] [ebp-1Ch]
  Scaleform::GFx::Value val; // [esp+8h] [ebp-18h] BYREF

  v5 = *((_DWORD *)pdata + 8);
  v6 = idx;
  root = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  if ( idx < v5 )
  {
    v7 = count;
    pObjectInterface = 0;
    if ( count < 0 )
      v7 = v5 - idx;
    v9 = idx + v7;
    val.pObjectInterface = 0;
    val.Type = VT_Undefined;
    if ( v5 < idx + v7 )
      v9 = v5;
    if ( idx < v9 )
    {
      do
      {
        v10 = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Impl::SparseArray::At(
                                              (Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 32),
                                              v6);
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(root, v10, (Scaleform::GFx::ASStringNode *)&val);
        visitor->Visit(visitor, v6++, &val);
      }
      while ( v6 < v9 );
      pObjectInterface = val.pObjectInterface;
    }
    if ( (val.Type & 0x40) != 0 )
      pObjectInterface->ObjectRelease(pObjectInterface, &val, val.mValue.pStringManaged);
  }
}
