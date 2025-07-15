void __thiscall Scaleform::GFx::AS3::VTable::ForEachChild_GC(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  int v4; // esi
  unsigned int Size; // ebp
  Scaleform::GFx::AS3::Value *Data; // eax
  unsigned int Flags; // ecx
  const Scaleform::GFx::AS3::Value *v8; // eax

  if ( this->VTMethods.Data.Size )
  {
    v4 = 0;
    Size = this->VTMethods.Data.Size;
    do
    {
      Data = this->VTMethods.Data.Data;
      Flags = Data[v4].Flags;
      v8 = &Data[v4];
      if ( (Flags & 0x1F) > 0xA && (Flags & 0x200) == 0 )
        Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, v8, op, this->pTraits);
      ++v4;
      --Size;
    }
    while ( Size );
  }
}
