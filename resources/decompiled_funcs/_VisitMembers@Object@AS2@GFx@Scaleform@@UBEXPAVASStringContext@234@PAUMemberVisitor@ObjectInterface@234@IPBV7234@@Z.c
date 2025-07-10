void __thiscall Scaleform::GFx::AS2::Object::VisitMembers(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor,
        unsigned int visitFlags,
        Scaleform::GFx::AS2::Object *instance)
{
  unsigned int *p_RefCount; // esi
  unsigned int RefCount; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edx
  _DWORD *v9; // ecx
  Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *v10; // ebp
  unsigned int v11; // ebx
  signed int v12; // edi
  int v13; // eax
  int v14; // esi
  Scaleform::GFx::AS2::Object *v15; // ecx
  unsigned int v16; // eax
  _DWORD *v17; // ecx
  unsigned int RootIndex; // ecx
  Scaleform::GFx::AS2::Object *v19; // eax
  unsigned int it; // [esp+14h] [ebp-18h]
  Scaleform::GFx::AS2::Value value; // [esp+1Ch] [ebp-10h] BYREF

  p_RefCount = &this->RefCount;
  RefCount = this->RefCount;
  if ( RefCount )
  {
    v8 = *(_DWORD *)(RefCount + 4);
    v7 = 0;
    v9 = (_DWORD *)(RefCount + 8);
    do
    {
      if ( *v9 != -2 )
        break;
      ++v7;
      v9 += 6;
    }
    while ( v7 <= v8 );
    RefCount = (unsigned int)p_RefCount;
  }
  else
  {
    v7 = 0;
  }
  v10 = pvisitor;
  v11 = RefCount;
  it = RefCount;
  v12 = v7;
  while ( v11 )
  {
    v13 = *(_DWORD *)v11;
    if ( !*(_DWORD *)v11 || v12 > *(_DWORD *)(v13 + 4) )
      break;
    v14 = 24 * v12;
    LOBYTE(pvisitor) = *(_BYTE *)(24 * v12 + v13 + 17);
    if ( ((unsigned __int8)pvisitor & 1) == 0 || (visitFlags & 4) != 0 )
    {
      if ( *(_BYTE *)(v14 + v13 + 16) == 10 )
      {
        value.T.Type = 0;
        if ( (visitFlags & 8) == 0 )
        {
          v15 = instance;
          if ( !instance )
            v15 = this != (Scaleform::GFx::AS2::Object *)16 ? this : 0;
          ((void (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::GFx::AS2::ASStringContext *, int, Scaleform::GFx::AS2::Value *))v15->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::Object)(
            v15,
            psc,
            v14 + v13 + 12,
            &value);
          v11 = it;
        }
        v10->Visit(
          v10,
          (const Scaleform::GFx::ASString *)(*(_DWORD *)v11 + v14 + 12),
          &value,
          (unsigned __int8)pvisitor);
        if ( value.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&value);
      }
      else
      {
        v10->Visit(
          v10,
          (const Scaleform::GFx::ASString *)(v14 + v13 + 12),
          (const Scaleform::GFx::AS2::Value *)(v14 + v13 + 16),
          (unsigned __int8)pvisitor);
        v11 = it;
      }
    }
    v16 = *(_DWORD *)(*(_DWORD *)v11 + 4);
    if ( v12 <= (int)v16 && ++v12 <= v16 )
    {
      v17 = (_DWORD *)(*(_DWORD *)v11 + 24 * v12 + 8);
      do
      {
        if ( *v17 != -2 )
          break;
        ++v12;
        v17 += 6;
      }
      while ( v12 <= v16 );
    }
  }
  if ( (visitFlags & 1) != 0 )
  {
    RootIndex = this->RootIndex;
    if ( RootIndex )
    {
      v19 = instance;
      if ( !instance )
        v19 = this != (Scaleform::GFx::AS2::Object *)16 ? this : 0;
      (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *, unsigned int, Scaleform::GFx::AS2::Object *))(*(_DWORD *)(RootIndex + 16) + 32))(
        RootIndex + 16,
        psc,
        v10,
        visitFlags,
        v19);
    }
  }
}
