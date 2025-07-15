void __thiscall Scaleform::GFx::AS3::Instances::fl::Namespace::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::Namespace *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value *p_Prefix; // ecx

  Flags = this->Prefix.Flags;
  p_Prefix = &this->Prefix;
  if ( (Flags & 0x1F) > 0xA && (Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, p_Prefix, op);
}
