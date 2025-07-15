void __cdecl Scaleform::GFx::AS3::ForEachChild_GC(
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned int v3; // ebp
  int v4; // esi

  v3 = 0;
  if ( v->Data.Size )
  {
    v4 = 0;
    do
    {
      if ( (v->Data.Data[v4].Flags & 0x1F) > 0xA && (v->Data.Data[v4].Flags & 0x200) == 0 )
        Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &v->Data.Data[v4], op);
      ++v3;
      ++v4;
    }
    while ( v3 < v->Data.Size );
  }
}
