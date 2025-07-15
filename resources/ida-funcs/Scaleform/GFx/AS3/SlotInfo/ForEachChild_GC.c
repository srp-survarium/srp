void __thiscall Scaleform::GFx::AS3::SlotInfo::ForEachChild_GC(
        Scaleform::GFx::AS3::SlotInfo *this,
        Scaleform::GFx::AS3::RefCountCollector<328> *prcc,
        const Scaleform::GFx::AS3::Object *obj,
        void (__cdecl *op)(Scaleform::GFx::AS3::RefCountCollector<328> *, const Scaleform::GFx::AS3::RefCountBaseGC<328> **))
{
  int v4; // ecx
  const Scaleform::GFx::AS3::Value *v5; // ecx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> **v6; // ecx

  v4 = *(_DWORD *)this;
  switch ( v4 << 22 >> 27 )
  {
    case 1:
      v5 = (const Scaleform::GFx::AS3::Value *)((char *)obj[4].__vftable + 16 * ((32 * v4) >> 15));
      goto LABEL_4;
    case 2:
      v5 = (const Scaleform::GFx::AS3::Value *)((char *)obj + ((32 * v4) >> 15));
LABEL_4:
      if ( (v5->Flags & 0x1F) > 0xA && (v5->Flags & 0x200) == 0 )
        Scaleform::GFx::AS3::ForEachChild_GC_Internal(prcc, v5, op);
      break;
    case 3:
      Scaleform::GFx::AS3::STPtr::ForEachChild_GC<328>(
        (Scaleform::GFx::AS3::STPtr *)((char *)obj + ((32 * v4) >> 15)),
        prcc,
        op);
      break;
    case 4:
      v6 = (const Scaleform::GFx::AS3::RefCountBaseGC<328> **)((char *)obj + ((32 * v4) >> 15));
      if ( *v6 )
        op(prcc, v6);
      break;
    default:
      return;
  }
}
