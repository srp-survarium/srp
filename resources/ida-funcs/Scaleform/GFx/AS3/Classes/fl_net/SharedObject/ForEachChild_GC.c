void __thiscall Scaleform::GFx::AS3::Classes::fl_net::SharedObject::ForEachChild_GC(
        Scaleform::GFx::AS3::Classes::fl_net::SharedObject *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  _DWORD *p_EntryCount; // eax
  unsigned int v5; // ecx
  unsigned int v6; // edx
  _DWORD *v7; // eax
  _DWORD *v8; // edi
  signed int v9; // esi
  int v10; // eax
  bool v11; // zf
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **v12; // eax
  unsigned int v13; // eax
  _DWORD *v14; // ecx

  Scaleform::GFx::AS3::Class::ForEachChild_GC(this, prcc, op);
  p_EntryCount = &this->SharedObjects.mHash.pTable->EntryCount;
  if ( p_EntryCount )
  {
    v6 = p_EntryCount[1];
    v5 = 0;
    v7 = p_EntryCount + 2;
    do
    {
      if ( *v7 != -2 )
        break;
      ++v5;
      v7 += 3;
    }
    while ( v5 <= v6 );
    p_EntryCount = &this->SharedObjects.mHash.pTable;
  }
  else
  {
    v5 = 0;
  }
  v8 = p_EntryCount;
  v9 = v5;
  while ( v8 )
  {
    v10 = *v8;
    if ( !*v8 || v9 > *(_DWORD *)(v10 + 4) )
      break;
    v11 = *(_DWORD *)(v10 + 12 * v9 + 16) == 0;
    v12 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v10 + 12 * v9 + 16);
    if ( !v11 )
      op(prcc, v12, this);
    v13 = *(_DWORD *)(*v8 + 4);
    if ( v9 <= (int)v13 && ++v9 <= v13 )
    {
      v14 = (_DWORD *)(*v8 + 12 * v9 + 8);
      do
      {
        if ( *v14 != -2 )
          break;
        ++v9;
        v14 += 3;
      }
      while ( v9 <= v13 );
    }
  }
}
