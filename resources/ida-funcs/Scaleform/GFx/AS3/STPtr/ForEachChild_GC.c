void __thiscall Scaleform::GFx::AS3::STPtr::ForEachChild_GC<328>(
        Scaleform::GFx::AS3::STPtr *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *),
        const Scaleform::GFx::AS3::RefCountBaseGC<328> *owner)
{
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // eax
  int v6; // esi
  const Scaleform::GFx::AS3::GASRefCountBase *addr; // [esp+4h] [ebp-4h] BYREF

  pObject = this->pObject;
  if ( this->pObject )
  {
    addr = (const Scaleform::GFx::AS3::GASRefCountBase *)((unsigned int)pObject & 0xFFFFFFF9);
    v6 = (unsigned __int8)pObject & 6;
    op(prcc, &addr, owner);
    this->pObject = (Scaleform::GFx::AS3::GASRefCountBase *)(v6 | (unsigned int)addr);
  }
}
