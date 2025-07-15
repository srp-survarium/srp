Scaleform::GFx::Button::CharToRec *__thiscall Scaleform::GFx::AS2::AvmButton::FindCharacterAndRemove(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::Button::CharToRec *result,
        const Scaleform::GFx::ButtonRecord *rec)
{
  int v3; // edx
  Scaleform::WeakPtrProxy **i; // esi
  Scaleform::WeakPtrProxy *v5; // ecx
  unsigned int v6; // edi
  const Scaleform::GFx::ButtonRecord **p_pObject; // eax
  Scaleform::GFx::Button::CharToRec *v8; // eax
  int v9; // ebx
  int RefCount; // ecx
  int v11; // eax
  Scaleform::GFx::DisplayObjectBase *v12; // ebp
  Scaleform::RefCountNTSImpl **v13; // edi
  Scaleform::WeakPtrProxy *v14; // ebx
  const Scaleform::GFx::ButtonRecord *chr_4; // [esp+10h] [ebp-4h]

  v3 = 0;
  for ( i = &this->pDispObj[1].pWeakProxy; ; i += 4 )
  {
    if ( v3 != 3 )
    {
      v5 = i[1];
      v6 = 0;
      if ( v5 )
        break;
    }
LABEL_7:
    if ( (unsigned int)++v3 >= 4 )
    {
      v8 = result;
      result->Char.pObject = 0;
      return v8;
    }
  }
  p_pObject = (const Scaleform::GFx::ButtonRecord **)&(*i)->pObject;
  while ( *p_pObject != rec )
  {
    ++v6;
    p_pObject += 2;
    if ( v6 >= (unsigned int)v5 )
      goto LABEL_7;
  }
  v9 = v6;
  RefCount = (*i)[v6].RefCount;
  v11 = (int)&(*i)[v6];
  if ( RefCount )
    ++*(_DWORD *)(RefCount + 4);
  v12 = *(Scaleform::GFx::DisplayObjectBase **)v11;
  chr_4 = *(const Scaleform::GFx::ButtonRecord **)(v11 + 4);
  if ( i[1] == (Scaleform::WeakPtrProxy *)1 )
  {
    v13 = (Scaleform::RefCountNTSImpl **)*i;
    v14 = i[1];
    do
    {
      if ( *v13 )
        Scaleform::RefCountNTSImpl::Release(*v13);
      v13 -= 2;
      v14 = (Scaleform::WeakPtrProxy *)((char *)v14 - 1);
    }
    while ( v14 );
    if ( ((unsigned int)i[2] & 0xFFFFFFFE) != 0 )
    {
      if ( *i )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *i);
        *i = 0;
      }
      i[2] = 0;
      i[1] = 0;
    }
    else
    {
      i[1] = 0;
    }
  }
  else
  {
    if ( (*i)[v9].RefCount )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)(*i)[v9].RefCount);
    memmove((unsigned __int8 *)&(*i)[v9], (unsigned __int8 *)&(*i)[v9 + 1], 8 * ((_DWORD)i[1] - v6) - 8);
    i[1] = (Scaleform::WeakPtrProxy *)((char *)i[1] - 1);
  }
  if ( v12 )
    ++v12->RefCount;
  result->Char.pObject = v12;
  result->Record = chr_4;
  if ( v12 )
    Scaleform::RefCountNTSImpl::Release(v12);
  return result;
}
