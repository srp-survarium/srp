void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLAttr::ForEachChild_GC(
        Scaleform::GFx::AS3::Instances::fl::XMLAttr *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  __int16 Flags; // ax
  Scaleform::GFx::AS3::Value v; // [esp+Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS3::Object::ForEachChild_GC(this, prcc, op);
  if ( this->Parent.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Parent.pObject);
  if ( this->Ns.pObject )
    op(prcc, (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)&this->Ns.pObject);
  Scaleform::GFx::AS3::Value::Value(&v, &this->Data);
  Flags = v.Flags;
  if ( (v.Flags & 0x1F) > 0xA && (v.Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, &v, op);
    Flags = v.Flags;
  }
  if ( (Flags & 0x1Fu) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}
