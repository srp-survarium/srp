void __thiscall Scaleform::GFx::AMP::ViewStats::SetName(Scaleform::GFx::AMP::ViewStats *this, char *name)
{
  Scaleform::StringLH *p_ViewName; // edi
  unsigned int Length; // eax
  int v4; // esi
  char v5; // dl
  const Scaleform::String *v6; // eax
  void *v7; // esi

  p_ViewName = &this->ViewName;
  Scaleform::String::operator=(&this->ViewName, name);
  Length = Scaleform::String::GetLength(p_ViewName);
  v4 = 0;
  if ( Length )
  {
    while ( 1 )
    {
      v5 = *(_BYTE *)((p_ViewName->HeapTypeBits & 0xFFFFFFFC) + Length - v4 + 7);
      if ( v5 == 47 || v5 == 92 )
        break;
      if ( ++v4 >= Length )
        return;
    }
    v6 = Scaleform::String::Substring(p_ViewName, (Scaleform::String *)&name, Length - v4, Length);
    Scaleform::String::operator=(p_ViewName, v6);
    v7 = (void *)((unsigned int)name & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)name & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  }
}
