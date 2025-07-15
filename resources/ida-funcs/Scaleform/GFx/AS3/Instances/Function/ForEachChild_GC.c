void __thiscall Scaleform::GFx::AS3::Instances::Function::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::Function *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  Scaleform::GFx::AS3::ForEachChild_GC(prcc, &this->StoredScopeStack, op, this);
  if ( (this->This.Flags & 0x1F) > 0xA && (this->This.Flags & 0x200) == 0 )
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &this->This, op, this);
}
