void __thiscall Scaleform::GFx::AS3::Instances::Function::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::Function *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  const Scaleform::GFx::AS3::Value *p_This; // eax
  unsigned int Flags; // esi

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  Scaleform::GFx::AS3::ForEachChild_GC(prcc, &this->StoredScopeStack, op);
  p_This = &this->This;
  Flags = this->This.Flags;
  if ( (Flags & 0x1F) > 0xA && (Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, p_This, op);
}
