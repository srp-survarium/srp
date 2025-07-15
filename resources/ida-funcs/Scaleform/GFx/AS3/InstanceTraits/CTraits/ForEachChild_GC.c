void __thiscall Scaleform::GFx::AS3::InstanceTraits::CTraits::ForEachChild_GC(
        Scaleform::GFx::AS3::InstanceTraits::CTraits *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))
{
  int v5; // ebp
  Scaleform::GFx::AS3::Multiname *v6; // esi
  void (__cdecl *opa)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *); // [esp+14h] [ebp+8h]

  Scaleform::GFx::AS3::Traits::ForEachChild_GC(this, prcc, op);
  if ( this->Ns.pObject )
    op(prcc, &this->Ns.pObject, this);
  if ( this->ImplementsInterfaces.Data.Size )
  {
    v5 = 0;
    opa = (void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))this->ImplementsInterfaces.Data.Size;
    do
    {
      v6 = &this->ImplementsInterfaces.Data.Data[v5];
      if ( v6->Obj.pObject )
        op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v6->Obj.pObject, this);
      if ( (v6->Name.Flags & 0x1F) > 0xA && (v6->Name.Flags & 0x200) == 0 )
        Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &v6->Name, op, this);
      ++v5;
      opa = (void (__cdecl *)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **, const Scaleform::GFx::AS3::RefCountBaseGC<328> *))((char *)opa - 1);
    }
    while ( opa );
  }
}
