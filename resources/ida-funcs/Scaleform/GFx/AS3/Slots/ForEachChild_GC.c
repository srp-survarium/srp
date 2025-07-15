void __thiscall Scaleform::GFx::AS3::Slots::ForEachChild_GC(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *),
        const Scaleform::GFx::AS3::RefCountBaseGC<328> *owner)
{
  Scaleform::GFx::AS3::Slots::Pair *Data; // eax
  int p_Value; // esi
  bool v6; // zf
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **p_pObject; // eax
  int v8; // [esp+0h] [ebp-Ch]
  unsigned int Size; // [esp+4h] [ebp-8h]
  Scaleform::GFx::AS3::Slots *v10; // [esp+8h] [ebp-4h]

  v10 = this;
  if ( this->VArray.Data.Size )
  {
    v8 = 0;
    Size = this->VArray.Data.Size;
    while ( 1 )
    {
      Data = this->VArray.Data.Data;
      p_Value = (int)&Data[v8].Value;
      v6 = Data[v8].Value.File.pObject == 0;
      p_pObject = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&Data[v8].Value.File.pObject;
      if ( !v6 )
        op(prcc, p_pObject, owner);
      if ( *(_DWORD *)(p_Value + 4) )
        op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)(p_Value + 4), owner);
      if ( *(_DWORD *)(p_Value + 8) )
        op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)(p_Value + 8), owner);
      ++v8;
      if ( !--Size )
        break;
      this = v10;
    }
  }
}
