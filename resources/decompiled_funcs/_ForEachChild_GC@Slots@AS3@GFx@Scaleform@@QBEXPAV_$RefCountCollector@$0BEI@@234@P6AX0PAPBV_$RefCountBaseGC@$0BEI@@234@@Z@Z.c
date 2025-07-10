void __thiscall Scaleform::GFx::AS3::Slots::ForEachChild_GC(
        Scaleform::GFx::AS3::Slots *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  int v3; // edi
  Scaleform::GFx::AS3::SlotInfo *p_Value; // esi
  unsigned int Size; // [esp+0h] [ebp-8h]
  Scaleform::GFx::AS3::Slots *v6; // [esp+4h] [ebp-4h]

  v6 = this;
  if ( this->VArray.Data.Size )
  {
    v3 = 0;
    Size = this->VArray.Data.Size;
    while ( 1 )
    {
      p_Value = &this->VArray.Data.Data[v3].Value;
      if ( this->VArray.Data.Data[v3].Value.File.pObject )
        op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->VArray.Data.Data[v3].Value.File.pObject);
      if ( p_Value->pNs.pObject )
        op(prcc, &p_Value->pNs.pObject);
      if ( p_Value->CTraits.pObject )
        op(prcc, &p_Value->CTraits.pObject);
      ++v3;
      if ( !--Size )
        break;
      this = v6;
    }
  }
}
