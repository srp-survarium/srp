void __thiscall Scaleform::GFx::AS3::Traits::ForEachChild_GC(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  Scaleform::GFx::AS3::VTable *pObject; // ecx

  Scaleform::GFx::AS3::Slots::ForEachChild_GC(&this->Scaleform::GFx::AS3::Slots, prcc, op, this);
  if ( this->pConstructor.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->pConstructor.pObject, this);
  if ( this->pParent.pObject )
    op(prcc, &this->pParent.pObject, this);
  pObject = this->pVTable.pObject;
  if ( pObject )
    Scaleform::GFx::AS3::VTable::ForEachChild_GC(pObject, prcc, op);
  Scaleform::GFx::AS3::ForEachChild_GC(prcc, &this->InitScope, op, this);
}
